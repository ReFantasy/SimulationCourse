# Simulator
[![linux](https://github.com/ReFantasy/SimulationCourse/actions/workflows/linux.yaml/badge.svg)](https://github.com/ReFantasy/Simulator/actions/workflows/linux.yaml)
[![macOS](https://github.com/ReFantasy/SimulationCourse/actions/workflows/macos.yaml/badge.svg)](https://github.com/ReFantasy/Simulator/actions/workflows/macos.yaml)
[![windows](https://github.com/ReFantasy/SimulationCourse/actions/workflows/windows.yaml/badge.svg)](https://github.com/ReFantasy/Simulator/actions/workflows/windows.yaml)

**A mass-spring cloth simulator using *Polyscope* for visualization and *Eigen* for numerical computation.**
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
cd SimulationCourse
cmake -S . -B build 
cmake --build build -j8
```
## Homework
Complete the function 
- `void EulerStep(System& system, REAL dt)` in src/timestepper/euler.cpp
- `void MassSpringSystem::CalculateForces()` in src/mass_spring_sytem.cpp
