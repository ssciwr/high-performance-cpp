#include "hpcpp/ex1.hpp"
#include <catch2/catch.hpp>

using namespace hpcpp;

TEST_CASE("matmul", "[ex1]") {
  std::vector<double> m{1.426341, 0.1234214, -12.123213, 21.13542};
  std::vector<double> v{-0.8235346, 1.235623};
  std::vector<double> r{0.0, 0.0};
  double r0{m[0] * v[0] + m[1] * v[1]};
  double r1{m[2] * v[0] + m[3] * v[1]};
  matmul_1(m, v, r);
  REQUIRE(r[0] == Approx(r0).epsilon(1e-13));
  REQUIRE(r[1] == Approx(r1).epsilon(1e-13));
  matmul_2(m, v, r);
  REQUIRE(r[0] == Approx(r0).epsilon(1e-13));
  REQUIRE(r[1] == Approx(r1).epsilon(1e-13));
  matmul_3(m, v, r);
  REQUIRE(r[0] == Approx(r0).epsilon(1e-13));
  REQUIRE(r[1] == Approx(r1).epsilon(1e-13));
  matmul_4(m, v, r);
  REQUIRE(r[0] == Approx(r0).epsilon(1e-13));
  REQUIRE(r[1] == Approx(r1).epsilon(1e-13));
  matmul_5(m, v, r);
  REQUIRE(r[0] == Approx(r0).epsilon(1e-13));
  REQUIRE(r[1] == Approx(r1).epsilon(1e-13));
}
