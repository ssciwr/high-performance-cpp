#pragma once
#include <vector>

namespace hpcpp {

void matmul1(const std::vector<double> &matrix,
             const std::vector<double> &vector, std::vector<double> &result);

void matmul2(const std::vector<double> &matrix,
             const std::vector<double> &vector, std::vector<double> &result);

void matmul3(const std::vector<double> &matrix,
             const std::vector<double> &vector, std::vector<double> &result);

void matmul4(const std::vector<double> &matrix,
             const std::vector<double> &vector, std::vector<double> &result);

void matmul5(const std::vector<double> &matrix,
             const std::vector<double> &vector, std::vector<double> &result);

} // namespace hpcpp
