#include "hpcpp/ex1.hpp"
#include <catch2/catch.hpp>

using namespace hpcpp;

TEST_CASE("doit", "[ex1]") { REQUIRE(doit() == 1); }
