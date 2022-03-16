cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(
  hpcpp
  VERSION 0.0.1
  LANGUAGES CXX)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# compile abseil library
set(ABSL_PROPAGATE_CXX_STD ON)
add_subdirectory(ext/abseil-cpp)

# compile the hpcpp library
add_subdirectory(src)

# compile the tests
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(ext/Catch2)
  include(./ext/Catch2/contrib/Catch.cmake)
  add_subdirectory(tests)
endif()

# compile the benchmarks
option(HPCPP_BUILD_BENCHMARKS "Build benchmarks" ON)
if(HPCPP_BUILD_BENCHMARKS)
  set(BENCHMARK_ENABLE_TESTING OFF) # don't build google benchmark tests
  add_subdirectory(ext/benchmark)
  add_subdirectory(bench)
endif()

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
