#include <hpx/hpx_main.hpp>
#include <hpx/include/parallel_for_loop.hpp>
#include <hpx/include/iostreams.hpp>
#include <vector>
#include <chrono>

using Matrix = std::vector<std::vector<double>>;

Matrix multiply(const Matrix &A, const Matrix &B)
{
    std::size_t n = A.size();
    std::size_t m = B[0].size();
    std::size_t k = B.size();

    Matrix C(n, std::vector<double>(m, 0.0));

    hpx::parallel::for_loop(
        hpx::execution::par, 0, n, [&](std::size_t i)
        {
            for (std::size_t j = 0; j < m; ++j) {
                for (std::size_t l = 0; l < k; ++l) {
                    C[i][j] += A[i][l] * B[l][j];
                }
            } });

    return C;
}

int main()
{
    constexpr std::size_t N = 500;

    Matrix A(N, std::vector<double>(N, 1.0));
    Matrix B(N, std::vector<double>(N, 2.0));

    auto start = std::chrono::high_resolution_clock::now();
    Matrix C = multiply(A, B);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    hpx::cout << "Parallel matrix multiplication completed in "
              << duration.count() << " seconds.\n"
              << hpx::flush;

    return 0;
}
