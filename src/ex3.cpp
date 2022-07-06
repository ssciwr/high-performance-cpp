#include "hpcpp/ex3.hpp"
#include <cassert>

namespace hpcpp {

std::size_t dist_0(const std::string &a, const std::string &b) {
  assert(a.size() == b.size());
  std::size_t dist{0};
  std::size_t n{a.size()};
  for (std::size_t i = 0; i < n; ++i) {
    if (a[i] != b[i] && a[i] != '-' && b[i] != '-') {
      ++dist;
    }
  }
  return dist;
}

std::size_t dist_1(const std::string &a, const std::string &b) {
  assert(a.size() == b.size());
  std::size_t dist{0};
  std::size_t n{a.size()};
  for (std::size_t i = 0; i < n; ++i) {
    dist +=
        static_cast<std::size_t>(a[i] != b[i] && a[i] != '-' && b[i] != '-');
  }
  return dist;
}

std::size_t dist_2(const std::string &a, const std::string &b) {
  assert(a.size() == b.size());
  std::size_t dist{0};
  std::size_t n{a.size()};
#pragma omp simd reduction(+ : dist)
  for (std::size_t i = 0; i < n; ++i) {
    dist +=
        static_cast<std::size_t>(a[i] != b[i] && a[i] != '-' && b[i] != '-');
  }
  return dist;
}

} // namespace hpcpp
