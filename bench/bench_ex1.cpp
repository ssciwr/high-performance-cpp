#include "bench.hpp"
#include "hpcpp/ex1.hpp"

static void bench_ex1(benchmark::State &state) {
  auto n{state.range(0)};
  for (auto _ : state) {
    benchmark::DoNotOptimize(hpcpp::doit());
  }
  state.SetComplexityN(n);
}

BENCHMARK(bench_ex1)->Range(1, 32)->Complexity();
