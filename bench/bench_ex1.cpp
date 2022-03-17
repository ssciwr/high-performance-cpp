#include "bench.hpp"
#include "hpcpp/ex1.hpp"

static void bench_matmul1(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  std::vector<double> res(n);
  auto mat{make_random_vector<double>(n * n, gen)};
  auto vec{make_random_vector<double>(n, gen)};
  for (auto _ : state) {
    hpcpp::matmul1(mat, vec, res);
  }
  state.SetComplexityN(n);
}

static void bench_matmul2(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  std::vector<double> res(n);
  auto mat{make_random_vector<double>(n * n, gen)};
  auto vec{make_random_vector<double>(n, gen)};
  for (auto _ : state) {
    hpcpp::matmul2(mat, vec, res);
  }
  state.SetComplexityN(n);
}

static void bench_matmul3(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  std::vector<double> res(n);
  auto mat{make_random_vector<double>(n * n, gen)};
  auto vec{make_random_vector<double>(n, gen)};
  for (auto _ : state) {
    hpcpp::matmul3(mat, vec, res);
  }
  state.SetComplexityN(n);
}

constexpr int n_min{32};
constexpr int n_max{1 << 10};
BENCHMARK(bench_matmul1)->Range(n_min, n_max)->Complexity();
BENCHMARK(bench_matmul2)->Range(n_min, n_max)->Complexity();
BENCHMARK(bench_matmul3)->Range(n_min, n_max)->Complexity();
