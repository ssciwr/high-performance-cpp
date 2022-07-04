#include "bench.hpp"
#include "hpcpp/ex2.hpp"

constexpr int n_min{1 << 2};
constexpr int n_max{1 << 24};

static void bench_particles_xy_soa(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  hpcpp::Particles particles{};
  for (auto i = 0; i < n; ++i) {
    particles.push_back(make_random_particle(gen));
  }
  for (auto _ : state) {
    for (auto i = 0; i < n; ++i) {
      benchmark::DoNotOptimize(particles.x[i] + particles.y[i]);
    }
  }
  state.SetComplexityN(n);
}

static void bench_particles_xy_aos(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  std::vector<hpcpp::Particle> particles{};
  for (auto i = 0; i < n; ++i) {
    particles.push_back(make_random_particle(gen));
  }
  for (auto _ : state) {
    for (auto i = 0; i < n; ++i) {
      particles[i].mass += 0.1;
    }
  }
  state.SetComplexityN(n);
}

static void bench_particles_m_soa(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  hpcpp::Particles particles{};
  for (auto i = 0; i < n; ++i) {
    particles.push_back(make_random_particle(gen));
  }
  for (auto _ : state) {
    for (auto i = 0; i < n; ++i) {
      particles.mass[i] += 0.1;
    }
  }
  state.SetComplexityN(n);
}

static void bench_particles_m_aos(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(123);
  std::vector<hpcpp::Particle> particles{};
  for (auto i = 0; i < n; ++i) {
    particles.push_back(make_random_particle(gen));
  }
  for (auto _ : state) {
    for (auto i = 0; i < n; ++i) {
      benchmark::DoNotOptimize(particles[i].x + particles[i].y);
    }
  }
  state.SetComplexityN(n);
}

BENCHMARK(bench_particles_m_soa)->Range(n_min, n_max);
BENCHMARK(bench_particles_m_aos)->Range(n_min, n_max);
BENCHMARK(bench_particles_xy_soa)->Range(n_min, n_max);
BENCHMARK(bench_particles_xy_aos)->Range(n_min, n_max);
