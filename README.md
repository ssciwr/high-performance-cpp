# High Performance C++

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/ssciwr/high-performance-cpp/ci.yml?branch=main)](https://github.com/ssciwr/high-performance-cpp/actions/workflows/ci.yml)
[![codecov](https://codecov.io/gh/ssciwr/high-performance-cpp/branch/main/graph/badge.svg)](https://codecov.io/gh/ssciwr/high-performance-cpp)

## Slides

<iframe src="https://docs.google.com/presentation/d/e/2PACX-1vSsQgXEWShyBmv29hURbcjWcCXJmAKv-PvT-6vIaIHqgV33GyhPa8tWnzT8fM1Gl3XzEXjzpfuWieXS/embed?start=false&loop=false&delayms=3000" frameborder="0" width="960" height="569" allowfullscreen="true" mozallowfullscreen="true" webkitallowfullscreen="true"></iframe>

[download slides as pdf](https://github.com/ssciwr/high-performance-cpp/raw/main/slides/slides.pdf) | [download course description as pdf](https://ssc.iwr.uni-heidelberg.de/sites/default/files/high-performance-cpp-ss22.pdf)

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

Notes

- CMake 3.16 gave a `target "BLAS::BLAS"` error on Ubuntu (see [#13](https://github.com/ssciwr/high-performance-cpp/issues/13))
  - Using a more recent CMake version is one solution to this problem
- Apple clang on M1 mac doesn't support the `-march=native` flag
  - Possible alternatives: `-mcpu=apple-m1` or `-mcpu=apple-a14`
  - `-march=native` will be supported by on M1 by clang 15

## Plots

List versus Vector inserting elements:

![](plots/data_structure-llvm.png)
![](plots/data_structure-gcc.png)

Matrix-vector multiplication:

![](plots/matmul-llvm.png)
![](plots/matmul-gcc.png)

Struct of Arrays versus Array of Structs:

![](plots/particles_m-llvm.png)
![](plots/particles_m-gcc.png)

![](plots/particles_xy-llvm.png)
![](plots/particles_xy-gcc.png)
