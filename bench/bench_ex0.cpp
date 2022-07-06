#include "bench.hpp"

constexpr int n_min{8};
constexpr int n_max{1 << 16};

template <typename Container>
static void bench_data_structure_back(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  for (auto _ : state) {
    Container c{};
    for (auto i = 0; i < n; ++i) {
      c.insert(c.end(), i);
    }
  }
  state.SetComplexityN(n);
}

template <typename Container>
static void bench_data_structure_front(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  for (auto _ : state) {
    Container c{};
    for (auto i = 0; i < n; ++i) {
      c.insert(c.begin(), i);
    }
  }
  state.SetComplexityN(n);
}

BENCHMARK_TEMPLATE(bench_data_structure_front, std::vector<double>)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max);
BENCHMARK_TEMPLATE(bench_data_structure_front, std::list<double>)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max);
BENCHMARK_TEMPLATE(bench_data_structure_back, std::vector<double>)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max);
BENCHMARK_TEMPLATE(bench_data_structure_back, std::list<double>)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max);
