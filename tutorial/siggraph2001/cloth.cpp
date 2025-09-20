#include "Eigen/Dense"
#include "glm/fwd.hpp"
#include "imgui.h"
#include "mass_spring_sytem.h"
#include "polyscope/options.h"
#include "polyscope/point_cloud.h"
#include "polyscope/polyscope.h"
#include "polyscope/surface_mesh.h"
#include "polyscope/types.h"
#include "polyscope/view.h"
#include "system.h"
#include "timestepper/euler.h"
#include "types.h"
#include <chrono>
std::vector<snow::VECTOR3I> faces_index;

snow::MassSpringSystem                  mass_spring_system;
polyscope::SurfaceVertexScalarQuantity* surface_vertex_scalar_quantity;

double        ball_radius = 0.2;
snow::VECTOR3 ball_center(0.5, 0.5, 0.5);
int           N = 40;

void Advance()
{
    static snow::MATRIX init_x  = mass_spring_system._x;
    auto                surface = polyscope::getSurfaceMesh("surface_mesh");
    surface->updateVertexPositions(mass_spring_system._x);

    snow::REAL  dt                 = 0.001;
    static bool running_simulation = false;
    if (running_simulation)
    {
        for (int n = 0; n < 20; n++)
        {

            snow::EulerStep(mass_spring_system, dt);
            for (int i = 0; i < mass_spring_system._x.rows(); i++)
            {
                // collision with ball
                snow::VECTOR3 xi = mass_spring_system._x.row(i);

                if ((xi - ball_center).norm() < ball_radius)
                {
                    snow::VECTOR3 dir            = (xi - ball_center).normalized();
                    mass_spring_system._x.row(i) = ball_center + dir * ball_radius;

                    mass_spring_system._v.row(i) = snow::VECTOR3(0, 0, 0);

                    // snow::VECTOR3 v_normal       = dir * (mass_spring_system._v.row(i).dot(dir));
                    // snow::VECTOR3 v_tangent      = mass_spring_system._v.row(i).transpose() - v_normal;
                    // mass_spring_system._v.row(i) = v_tangent - 0.5 * v_normal;
                }
            }
        }
    }

    surface->addVertexScalarQuantity("velocity norm", mass_spring_system._v.rowwise().norm());

    if (ImGui::Button("Reset"))
    {
        mass_spring_system._x = init_x;
        mass_spring_system._v.setZero();
        mass_spring_system._f.setZero();
    }

    if (ImGui::Button("Start/Pause"))
        running_simulation = !running_simulation;

    static float k = mass_spring_system._k, ks = mass_spring_system._ks, kd = mass_spring_system._kd;

    if (ImGui::SliderFloat("k", &k, 0.0, 5.0))
    {
        mass_spring_system._k = k;
    }
    if (ImGui::SliderFloat("ks", &ks, 0.0, 2000.0))
    {
        mass_spring_system._ks = ks;
    }
    if (ImGui::SliderFloat("kd", &kd, 0.0, 5.0))
    {
        mass_spring_system._kd = kd;
    }
}

void init_polyscope();
void CreateCloth(snow::MATRIX& x, snow::MATRIXI& s);

int main(int argc, char* argv[])
{
    init_polyscope();

    snow::MATRIX  x;
    snow::MATRIXI springs;
    CreateCloth(x, springs);
    mass_spring_system._x = x;
    mass_spring_system._v = snow::MATRIX::Zero(x.rows(), x.cols());
    mass_spring_system._m = snow::VECTOR::Ones(x.rows()) * (90.0 / (N * N));
    mass_spring_system.SetSprings(springs);
    mass_spring_system._k  = 1.5;
    mass_spring_system._ks = 1000.0;
    mass_spring_system._kd = 1.5;

    auto surface_mesh = polyscope::registerSurfaceMesh("surface_mesh", mass_spring_system._x, faces_index);
    surface_mesh->setEdgeWidth(0.4);
    surface_mesh->setSmoothShade(true);

    // generate points
    std::vector<glm::vec3> points;
    points.push_back(glm::vec3(ball_center[0], ball_center[1], ball_center[2]));

    // visualize!
    polyscope::PointCloud* psCloud = polyscope::registerPointCloud("really great points", points);
    psCloud->setPointRadius(ball_radius - 0.01);

    // visualize velocity
    surface_vertex_scalar_quantity =
        surface_mesh->addVertexScalarQuantity("velocity norm", mass_spring_system._v.rowwise().norm());
    surface_vertex_scalar_quantity->setColorMap("coolwarm");
    surface_vertex_scalar_quantity->setEnabled(false);
    surface_vertex_scalar_quantity->refresh();
    polyscope::show();
}

void init_polyscope()
{
    polyscope::options::programName                      = " Physically Based Simulator";
    polyscope::options::ssaaFactor                       = 2;
    polyscope::options::maxFPS                           = -1;
    polyscope::options::usePrefsFile                     = false;
    polyscope::options::groundPlaneMode                  = polyscope::GroundPlaneMode::TileReflection;
    polyscope::options::groundPlaneHeightMode            = polyscope::GroundPlaneHeightMode::Manual;
    polyscope::options::groundPlaneHeight                = -0.3;
    polyscope::view::initWindowPosY                      = 100;
    polyscope::options::automaticallyComputeSceneExtents = false;
    polyscope::state::lengthScale                        = 1.0;

    polyscope::init();

    polyscope::state::userCallback = Advance; // specify the callback
}
void CreateCloth(snow::MATRIX& x, snow::MATRIXI& s)
{

    double quad_size = 1.0 / (N - 1);
    x.resize(N * N, 3);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            x.row(i * N + j) = snow::VECTOR3(i * quad_size, 0.8, j * quad_size);
        }
    }
    std::cout << "num vertices: " << x.rows() << std::endl;

    faces_index.clear();
    faces_index.resize((N - 1) * (N - 1) * 2);
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            faces_index[(i * (N - 1) + j) * 2 + 0] = snow::VECTOR3I(i * N + j, (i + 1) * N + j, i * N + j + 1);
            faces_index[(i * (N - 1) + j) * 2 + 1] =
                snow::VECTOR3I((i + 1) * N + j, (i + 1) * N + j + 1, i * N + j + 1);
        }
    }

    // build springs
    std::vector<std::vector<int>> springs;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            springs.push_back({i * N + j, i * N + j + 1});
            springs.push_back({i * N + j, (i + 1) * N + j});
            springs.push_back({i * N + j, (i + 1) * N + j + 1});

            springs.push_back({i * N + j + 1, (i + 1) * N + j});
            springs.push_back({i * N + j + 1, (i + 1) * N + j + 1});
            springs.push_back({(i + 1) * N + j, (i + 1) * N + j + 1});
        }
    }
    for (auto& s : springs)
    {
        if (s[0] > s[1])
            std::swap(s[0], s[1]);
    }

    std::sort(springs.begin(), springs.end());
    auto end_unique = std::unique(springs.begin(), springs.end());
    while (end_unique != springs.end())
    {
        springs.erase(end_unique, springs.end());
        std::sort(springs.begin(), springs.end());
        end_unique = std::unique(springs.begin(), springs.end());
    }
    std::cout << "num springs: " << springs.size() << std::endl;

    s.resize(springs.size(), 2);
    for (int i = 0; i < springs.size(); i++)
    {
        s(i, 0) = springs[i][0];
        s(i, 1) = springs[i][1];
    }
}
