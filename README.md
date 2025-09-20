# Simulator
## Setup
### Clone Repository
```bash
git clone --depth=1 --recurse-submodules https://github.com/ReFantasy/SimulationCourse.git
```
or
```bash
git clone https://github.com/ReFantasy/SimulationCourse.git
git submodule update --init --recursive
```
### Build Project
```bash
cd Simulator
cmake -S . -B build 
cmake --build build -j8
```

