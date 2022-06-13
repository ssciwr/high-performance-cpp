#include "bench.hpp"
#include <array>
#include <list>
#include <vector>

constexpr int n_min{8};
constexpr int n_max{1 << 16};

static void bench_ds_vector_back(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  for (auto _ : state) {
    std::vector<double> v{};
    for (auto i = 0; i < n; ++i) {
      v.push_back(i);
    }
  }
  state.SetComplexityN(n);
}

static void bench_ds_vector_front(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  for (auto _ : state) {
    std::vector<double> v{};
    for (auto i = 0; i < n; ++i) {
      v.insert(v.begin(), i);
    }
  }
  state.SetComplexityN(n);
}

static void bench_ds_list(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  for (auto _ : state) {
    std::list<double> l{};
    for (auto i = 0; i < n; ++i) {
      l.insert(l.begin(), i);
    }
  }
  state.SetComplexityN(n);
}

BENCHMARK(bench_ds_vector_front)->RangeMultiplier(2)->Range(n_min, n_max);
BENCHMARK(bench_ds_vector_back)->RangeMultiplier(2)->Range(n_min, n_max);
BENCHMARK(bench_ds_list)->RangeMultiplier(2)->Range(n_min, n_max);
