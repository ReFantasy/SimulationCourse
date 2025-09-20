# Simulator
[![linux](https://github.com/ReFantasy/Simulator/actions/workflows/linux.yaml/badge.svg)](https://github.com/ReFantasy/Simulator/actions/workflows/linux.yaml)
[![macOS](https://github.com/ReFantasy/Simulator/actions/workflows/macos.yaml/badge.svg)](https://github.com/ReFantasy/Simulator/actions/workflows/macos.yaml)
[![windows](https://github.com/ReFantasy/Simulator/actions/workflows/windows.yaml/badge.svg)](https://github.com/ReFantasy/Simulator/actions/workflows/windows.yaml)
## Setup
### Clone Repository
```bash
git clone --depth=1 --recurse-submodules git@github.com:ReFantasy/Simulator.git
```
or
```bash
git clone git@github.com:ReFantasy/Simulator.git
git submodule update --init --recursive
```
### Build Project
```bash
cd Simulator
cmake -S . -B build -G Ninja
cmake --build build
```

