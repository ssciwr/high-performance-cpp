#pragma once

#include <array>
#include <benchmark/benchmark.h>
#include <hpcpp/ex2.hpp>
#include <list>
#include <random>
#include <string>
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

hpcpp::Particle make_random_particle(std::mt19937 &gen);

std::string make_random_gene(std::size_t n, std::mt19937 &gen);
