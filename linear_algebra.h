#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <vector>
#include "matrix.h"

double dot_product(const std::vector<double>& a, const std::vector<double>& b);

double l2_norm(const std::vector<double>& v);

void matrix_vector_multiply(const Matrix& A,
                            const std::vector<double>& x,
                            std::vector<double>& result);

#endif