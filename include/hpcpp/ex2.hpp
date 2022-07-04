#pragma once
#include <vector>

namespace hpcpp {

// an example struct containing some data
struct Particle {
  float x;
  float y;
  float z;
  double mass;
  bool active;
}; // __attribute__((packed));

// a simple interface for data in a StructOfArrays layout
struct Particles {
  std::vector<bool> active;
  std::vector<float> x;
  std::vector<float> y;
  std::vector<float> z;
  std::vector<double> mass;
  void push_back(const Particle &particle);
  std::size_t size() const;
};

} // namespace hpcpp
