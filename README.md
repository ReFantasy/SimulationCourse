# Simulator
**A mass-spring cloth simulator using Polyscope for visualization and Eigen for numerical computation.**
## Setup
### Clone Repository
```bash
git clone --depth=1 --recurse-submodules https://github.com/ReFantasy/SimulationCourse.git
```
or
```bash
git clone https://github.com/ReFantasy/SimulationCourse.git
cd SimulationCourse
git submodule update --init --recursive
```
### Build Project
```bash
cd Simulator
cmake -S . -B build 
cmake --build build -j8
```
### Homework
Complete the implementation of function `void EulerStep(System& system, REAL dt)` in **src/timestepper/euler.cpp** 
and `void MassSpringSystem::CalculateForces()` in **src/mass_spring_sytem.cpp**.
