add_executable(bench bench.cpp bench_ex1.cpp)
target_link_libraries(bench PUBLIC hpcpp benchmark::benchmark)
