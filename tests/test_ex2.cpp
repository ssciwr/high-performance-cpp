#include "hpcpp/ex2.hpp"
#include <catch2/catch.hpp>

using namespace hpcpp;

TEST_CASE("Particles", "[ex2]") {
  // make some particles
  Particle p0{};
  p0.active = true;
  p0.x = 0.1;
  p0.y = 0.2;
  p0.z = 0.3;
  p0.mass = 0.9;
  Particle p1{};
  p1.active = false;
  p1.x = 0.5;
  p1.y = 0.4;
  p1.z = -0.6;
  p1.mass = 1.2;
  Particle p2{};
  p2.active = true;
  p2.x = -0.5;
  p2.y = -1;
  p2.z = -2;
  p2.mass = 3;
  // store as an array of structs
  std::vector<Particle> aos{p0, p1, p2};
  // store as a struct of arrays
  Particles soa;
  for (const auto &p : aos) {
    soa.push_back(p);
  }
  // check they are equivalent
  REQUIRE(soa.size() == aos.size());
  for (std::size_t i = 0; i < aos.size(); ++i) {
    REQUIRE(soa.active[i] == aos[i].active);
    REQUIRE(soa.x[i] == aos[i].x);
    REQUIRE(soa.y[i] == aos[i].y);
    REQUIRE(soa.z[i] == aos[i].z);
    REQUIRE(soa.mass[i] == aos[i].mass);
  }
}
