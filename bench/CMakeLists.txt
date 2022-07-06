add_executable(bench bench.cpp bench_ex0.cpp bench_ex1.cpp bench_ex2.cpp
                     bench_ex3.cpp)
target_link_libraries(bench PUBLIC hpcpp benchmark::benchmark)
