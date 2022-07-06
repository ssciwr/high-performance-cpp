#include "bench.hpp"
#include "hpcpp/ex3.hpp"

constexpr int n_min{8};
constexpr int n_max{1 << 16};

#define BENCH_DIST(DISTFUNC)                                                   \
  static void bench_##DISTFUNC(benchmark::State &state) {                      \
    auto n{state.range(0)};                                                    \
    std::mt19937 gen(123);                                                     \
    auto a{make_random_gene(n, gen)};                                          \
    auto b{make_random_gene(n, gen)};                                          \
    std::size_t s{0};                                                          \
    for (auto _ : state) {                                                     \
      s += hpcpp::DISTFUNC(a, b);                                              \
    }                                                                          \
    state.SetComplexityN(n);                                                   \
  }                                                                            \
  BENCHMARK(bench_##DISTFUNC)->RangeMultiplier(2)->Range(n_min, n_max);

BENCH_DIST(dist_0);
BENCH_DIST(dist_1);
BENCH_DIST(dist_2);
