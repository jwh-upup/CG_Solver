#ifndef CG_H
#define CG_H

#include "matrix.h"

#include <cstddef>
#include <vector>

//结果存储
struct CGResult
{
    std::vector<double> x;
    std::size_t iterations;
    double residual_norm;
    bool converged;

    std::vector<double> residual_history;
};

CGResult cg_solve(
    const Matrix& A,
    const std::vector<double>& b,
    const std::vector<double>& x0,
    double tolerance,
    std::size_t max_iterations
);

#endif