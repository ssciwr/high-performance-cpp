#include "bench.hpp"

BENCHMARK_MAIN();

hpcpp::Particle make_random_particle(std::mt19937 &gen) {
  std::uniform_real_distribution<float> dist(-1.0, +1.0);
  hpcpp::Particle p{};
  p.active = dist(gen) > 0;
  p.x = dist(gen);
  p.y = dist(gen);
  p.z = dist(gen);
  p.mass = dist(gen);
  return p;
}

std::string make_random_gene(std::size_t n, std::mt19937 &gen) {
  std::string s;
  s.reserve(n);
  std::uniform_int_distribution<> distrib(0, 4);
  std::array<char, 5> c{'A', 'C', 'G', 'T', '-'};
  for (std::size_t i = 0; i < n; ++i) {
    s.push_back(c[distrib(gen)]);
  }
  return s;
}
