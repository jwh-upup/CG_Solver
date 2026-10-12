#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <vector>

class Matrix
{
public:
    Matrix(std::size_t rows, std::size_t cols);

    double& operator()(std::size_t row, std::size_t col);
    const double& operator()(std::size_t row, std::size_t col) const;

    std::size_t rows() const;
    std::size_t cols() const;

private:
    std::size_t rows_;
    std::size_t cols_;
    std::vector<double> data_;
};

#endif