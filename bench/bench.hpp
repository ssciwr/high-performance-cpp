#pragma once

#include <benchmark/benchmark.h>
#include <list>
#include <random>
#include <vector>

template <typename T>
std::vector<T> make_random_vector(std::size_t n, std::mt19937 &gen) {
  std::vector<T> v(n);
  std::uniform_real_distribution<T> dist(-1.0, +1.0);
  std::generate(begin(v), end(v), [&dist, &gen]() { return dist(gen); });
  return v;
}

template <typename T>
std::list<T> make_random_list(std::size_t n, std::mt19937 &gen) {
  std::list<T> l;
  std::uniform_real_distribution<T> dist(-1.0, +1.0);
  std::generate_n(std::inserter(l, l.begin()), n,
                  [&dist, &gen]() { return dist(gen); });
  return l;
}
