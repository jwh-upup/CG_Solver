#include "cg.h"
#include "linear_algebra.h"

#include <cmath>
#include <vector>

CGResult cg_solve(
    const Matrix& A,
    const std::vector<double>& b,
    const std::vector<double>& x0,
    double tolerance,
    std::size_t max_iterations
)
{
    CGResult result;

    result.x = x0;
    result.iterations = 0;
    result.residual_norm = 0.0;
    result.converged = false;

    std::size_t n = b.size();

    std::vector<double> Ax(n, 0.0);
    std::vector<double> r(n, 0.0);
    std::vector<double> p(n, 0.0);
    std::vector<double> Ap(n, 0.0);

    matrix_vector_multiply(A, result.x, Ax);

    for (std::size_t i = 0; i < n; ++i)
    {
        r[i] = b[i] - Ax[i];
    }

    p = r;

    double rr_old = dot_product(r, r);

    result.residual_norm = std::sqrt(rr_old);

    result.residual_history.push_back(result.residual_norm);

    if (result.residual_norm <= tolerance)
    {
        result.converged = true;
        return result;
    }

    for (std::size_t k = 0; k < max_iterations; ++k)
    {
        matrix_vector_multiply(A, p, Ap);

        double pAp = dot_product(p, Ap);

        if (pAp == 0.0)
        {
            break;
        }

        double alpha = rr_old / pAp;

        for (std::size_t i = 0; i < n; ++i)
        {
            result.x[i] = result.x[i] + alpha * p[i];
            r[i] = r[i] - alpha * Ap[i];
        }

        double rr_new = dot_product(r, r);

        result.residual_norm = std::sqrt(rr_new);
        result.iterations = k + 1;

        result.residual_history.push_back(result.residual_norm);

        if (result.residual_norm <= tolerance)
        {
            result.converged = true;
            return result;
        }

        double beta = rr_new / rr_old;

        for (std::size_t i = 0; i < n; ++i)
        {
            p[i] = r[i] + beta * p[i];
        }

        rr_old = rr_new;
    }

    return result;
}