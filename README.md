# Simulator
## Setup
### Clone Repository
```bash
git clone --depth=1 --recurse-submodules https://github.com/ReFantasy/SimulationCourse.git
```
or
```bash
git clone git@github.com:ReFantasy/Simulator.git
git submodule update --init --recursive
```
### Build Project
```bash
cd Simulator
cmake -S . -B build 
cmake --build build -j8
```

