#include "hpcpp/ex1.hpp"
#include <Eigen/Dense>

namespace hpcpp {

void matmul1(const std::vector<double> &matrix,
             const std::vector<double> &vector, std::vector<double> &result) {
  const std::size_t n{vector.size()};
  result.resize(n, 0.0);
  std::fill(begin(result), end(result), 0);
  for (std::size_t j = 0; j < n; ++j) {
    for (std::size_t i = 0; i < n; ++i) {
      result[i] += matrix[i * n + j] * vector[j];
    }
  }
}

void matmul2(const std::vector<double> &matrix,
             const std::vector<double> &vector, std::vector<double> &result) {
  const std::size_t n{vector.size()};
  result.resize(n, 0.0);
  std::fill(begin(result), end(result), 0);
  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < n; ++j) {
      result[i] += matrix[i * n + j] * vector[j];
    }
  }
}

void matmul3(const std::vector<double> &matrix,
             const std::vector<double> &vector, std::vector<double> &result) {
  const std::size_t n{vector.size()};
  result.resize(n, 0.0);
  std::fill(begin(result), end(result), 0);
  for (std::size_t i = 0; i < n; ++i) {
    double r{0};
#pragma omp simd reduction(+ : r)
    // note: using signed int for MSVC OpenMP:
    // https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-2/compiler-error-c3016?view=msvc-170
    for (int j = 0; j < n; ++j) {
      r += matrix[i * n + j] * vector[j];
    }
    result[i] = r;
  }
}

void matmul4(const std::vector<double> &matrix,
             const std::vector<double> &vector, std::vector<double> &result) {
  const std::size_t n{vector.size()};
  result.resize(n, 0.0);
  std::fill(begin(result), end(result), 0);
#pragma omp parallel for schedule(static) default(none)                        \
    shared(n, matrix, vector, result)
  for (int i = 0; i < n; ++i) {
    double r{0};
#pragma omp simd reduction(+ : r)
    for (int j = 0; j < n; ++j) {
      r += matrix[i * n + j] * vector[j];
    }
    result[i] = r;
  }
}

void matmul5(const std::vector<double> &matrix,
             const std::vector<double> &vector, std::vector<double> &result) {
  const std::size_t n{vector.size()};
  result.resize(n, 0.0);
  Eigen::Map<const Eigen::MatrixXd> m(matrix.data(), n, n);
  Eigen::Map<const Eigen::VectorXd> v(vector.data(), n);
  Eigen::Map<Eigen::VectorXd> r(result.data(), n);
  r = m.transpose() * v;
}

} // namespace hpcpp
