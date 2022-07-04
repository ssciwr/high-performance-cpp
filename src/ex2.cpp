#include "hpcpp/ex2.hpp"

namespace hpcpp {

void Particles::push_back(const Particle &particle) {
  active.push_back(particle.active);
  x.push_back(particle.x);
  y.push_back(particle.y);
  z.push_back(particle.z);
  mass.push_back(particle.mass);
}

std::size_t Particles::size() const { return active.size(); }

} // namespace hpcpp
