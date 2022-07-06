#include "hpcpp/ex3.hpp"
#include <catch2/catch.hpp>

using namespace hpcpp;

TEST_CASE("two genes with distance 2", "[ex3]") {
  std::vector<std::vector<std::string>> expr;
  expr.push_back({{"AC"}, {"CA"}});
  expr.push_back({{"AC"}, {"TG"}});
  expr.push_back({{"ACG"}, {"AGT"}});
  expr.push_back({{"ACG"}, {"-TT"}});
  expr.push_back({{"ACG"}, {"T-T"}});
  expr.push_back({{"ACG"}, {"TA-"}});
  expr.push_back({{"ACG"}, {"CCC"}});
  expr.push_back({{"ACGT"}, {"AGGG"}});
  expr.push_back({{"ACGTGTCGTGTCGACGTGTCG"}, {"ACGTGTCGTTTCGACGAGTCG"}});
  expr.push_back({{"ACGTGTCGTGTCGACGTGTCGT"}, {"ACGTGTCGTTTCGACGAGTCGT"}});
  expr.push_back({{"ACGTGTCGTGTCGACGTGTCGT-"}, {"ACGTGTCGTTTCGACGAGTCGTA"}});
  expr.push_back({{"ACGTGTCGTGTCGACGTGTCG----------"},
                  {"ACGTGTCGTTTCGACGAGTCGGGG-------"}});
  expr.push_back({{"ACGTGTCGTGTCGACGTGTCG----------A"},
                  {"ACGTGTCGTTTCGACGAGTCGGGG-------A"}});
  expr.push_back({{"ACGTGTCGTGTCGACGTGTCG----------AG"},
                  {"ACGTGTCGTTTCGACGAGTCGGGG-------AG"}});
  expr.push_back({{"ACGTGTCGTGTCGACGTGTCG---ACGTGTCGTGTCGACGTGTCG---"
                   "ACGTGTCGTGTCGACGTGTCG---"},
                  {"ACGTGTCGTTTCGACGAGTCGGGGACGTGTCGTGTCGACGTGTCG---"
                   "ACGTGTCGTGTCGACGTGTCG---"}});
  for (auto &v : expr) {
    REQUIRE(dist_0(v[0], v[1]) == 2);
    REQUIRE(dist_1(v[0], v[1]) == 2);
    REQUIRE(dist_2(v[0], v[1]) == 2);
  }
}
