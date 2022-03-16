#pragma once

#include <benchmark/benchmark.h>
#include <random>
#include <vector>

template <typename T>
std::vector<T> make_random_vector(std::size_t n, std::mt19937 &gen) {
  std::vector<T> v(n);
  std::uniform_real_distribution<T> dist(-1.0, +1.0);
  std::generate(begin(v), end(v), [&dist, &gen]() { return dist(gen); });
  return v;
}
