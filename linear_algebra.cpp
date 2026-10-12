#include "linear_algebra.h"

#include <cmath>

double dot_product(const std::vector<double>& a,
                   const std::vector<double>& b)
{
    double result = 0.0;

    for (std::size_t i = 0; i < a.size(); ++i)
    {
        result = result + a[i] * b[i];
    }

    return result;
}

double l2_norm(const std::vector<double>& v)
{
    double result = dot_product(v, v);

    return std::sqrt(result);
}

void matrix_vector_multiply(const Matrix& A,
                            const std::vector<double>& x,
                            std::vector<double>& result)
{
    result.resize(A.rows());

    for (std::size_t i = 0; i < A.rows(); ++i)
    {
        double sum = 0.0;

        for (std::size_t j = 0; j < A.cols(); ++j)
        {
            sum = sum + A(i, j) * x[j];
        }

        result[i] = sum;
    }
}