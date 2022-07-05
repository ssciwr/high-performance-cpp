# High Performance C++

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/ssciwr/high-performance-cpp/CI)](https://github.com/ssciwr/high-performance-cpp/actions?query=workflow%3ACI)
[![codecov](https://codecov.io/gh/ssciwr/high-performance-cpp/branch/main/graph/badge.svg)](https://codecov.io/gh/ssciwr/high-performance-cpp)

Sample code to accompany the SSC compact course High Performance C++

- [pdf slides](https://github.com/ssciwr/high-performance-cpp/raw/main/slides/slides.pdf)
- [pdf course description](https://ssc.iwr.uni-heidelberg.de/sites/default/files/high-performance-cpp-ss22.pdf)

## Getting started

To clone the repo, compile the code and run the benchmarks:

```
git clone --recursive https://github.com/ssciwr/high-performance-cpp.git
cd high-performance-cpp
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
./bench/bench
```

## Plots

Matrix-vector multiplication:

![plots/data_structure.png](plots/matmul.png)

List versus Vector:

![plots/data_structure.png](plots/data_structure.png)

Struct of Arrays versus Array of Structs:

![plots/data_structure.png](plots/particles_m.png)

![plots/data_structure.png](plots/particles_xy.png)
