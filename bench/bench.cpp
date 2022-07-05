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
