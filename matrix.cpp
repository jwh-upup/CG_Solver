#include "matrix.h"

Matrix::Matrix(std::size_t rows, std::size_t cols)
    : rows_(rows),
      cols_(cols),
      data_(rows * cols, 0.0)
{
}

double& Matrix::operator()(std::size_t row, std::size_t col)
{
    return data_[row * cols_ + col];
}

const double& Matrix::operator()(std::size_t row, std::size_t col) const
{
    return data_[row * cols_ + col];
}

std::size_t Matrix::rows() const
{
    return rows_;
}

std::size_t Matrix::cols() const
{
    return cols_;
}