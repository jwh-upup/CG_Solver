#include "cg.h"
#include "linear_algebra.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

//g++ main.cpp matrix.cpp linear_algebra.cpp cg.cpp -O2 -o main
int main()
{
    const std::size_t n = 100;

    Matrix A(n, n);
    std::vector<double> b(n, 0.0);
    std::vector<double> x0(n, 0.0);

    for (std::size_t i = 0; i < n; ++i)
    {
        A(i, i) = 5 + std::rand() % 10;

        b[i] = std::rand() % 10;

        if (i + 1 < n)
        {
            double value = std::rand() % 5 - 2;

            A(i, i + 1) = value;
            A(i + 1, i) = value;
        }
    }

    double tolerance = 1e-8;
    std::size_t max_iterations = n;

    CGResult result = cg_solve(A, b, x0, tolerance, max_iterations);

    std::cout << std::scientific << std::setprecision(10);

    std::cout << "Iteration    Residual Norm" << std::endl;

    for (std::size_t i = 0; i < result.residual_history.size(); ++i)
    {
        std::cout << i << "    "
                  << result.residual_history[i] << std::endl;
    }

    std::cout << "\nCG Results:" << std::endl;
    std::cout << "Iterations: " << result.iterations << std::endl;
    std::cout << "Residual norm: " << result.residual_norm << std::endl;
    std::cout << "Converged: " << result.converged << std::endl;

    std::vector<double> Ax(n, 0.0);
    std::vector<double> r(n, 0.0);

    matrix_vector_multiply(A, result.x, Ax);

    for (std::size_t i = 0; i < n; ++i)
    {
        r[i] = b[i] - Ax[i];
    }

    std::cout << "Checked residual: " << l2_norm(r) << std::endl;

    return 0;
}