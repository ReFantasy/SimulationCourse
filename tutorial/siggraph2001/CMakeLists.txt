add_executable(cloth cloth.cpp)
target_link_libraries(cloth ${simulator_name} Eigen3::Eigen polyscope)
