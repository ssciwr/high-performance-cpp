#include "bench.hpp"
#include "hpcpp/ex1.hpp"

constexpr int n_min{8};
constexpr int n_max{1 << 10};

#define BENCH_MATMUL(MATMULFUNC)                                               \
  static void bench_##MATMULFUNC(benchmark::State &state) {                    \
    auto n{state.range(0)};                                                    \
    std::mt19937 gen(123);                                                     \
    std::vector<double> res(n);                                                \
    auto mat{make_random_vector<double>(n * n, gen)};                          \
    auto vec{make_random_vector<double>(n, gen)};                              \
    for (auto _ : state) {                                                     \
      hpcpp::MATMULFUNC(mat, vec, res);                                        \
    }                                                                          \
    state.SetComplexityN(n);                                                   \
  }                                                                            \
  BENCHMARK(bench_##MATMULFUNC)->RangeMultiplier(2)->Range(n_min, n_max);

BENCH_MATMUL(matmul_1);
BENCH_MATMUL(matmul_2);
BENCH_MATMUL(matmul_3);
BENCH_MATMUL(matmul_4);
BENCH_MATMUL(matmul_5);
