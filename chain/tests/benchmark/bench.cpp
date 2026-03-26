#include <iostream>
#include <chrono>
#include "Matrix_chain.hpp"

int main() {
    size_t count_dims = 0;
    if (!(std::cin >> count_dims)) {
        std::cerr << "Error of input count\n";
    }
    using ElemT = double;
    matrix::Matrix_chain<ElemT> chain;
    std::vector<size_t> dims;
    size_t dim = 0;

    for (size_t i = 0; i < count_dims; ++i)
    {
       std::cin >> dim;
       dims.push_back(dim);
    }

    size_t count_m = count_dims - 1;
    for (size_t i = 0; i < count_m; ++i)
    {
        size_t row_ = dims[i];
        size_t col_ = dims[i+1];

        matrix::Matrix<double> matrix{row_, col_};
        ElemT elem = 0;
        for (size_t row = 0; row < row_; row++)
        {
            for (size_t col = 0; col < col_; col++) {
                if(!(std::cin >> elem)) {
                    std::cerr << "Elem is not readed\n";
                }
                matrix[row][col] = elem;
            }
        }
        chain.add_matrix(matrix);
    }
    chain.analysis_optimal();

    using Clock = std::chrono::high_resolution_clock;
    using Us    = std::chrono::microseconds;
    long long total_time = 0;

    auto start = Clock::now();
    chain.multiply_optimal(0, chain.get_count() - 1);
    auto end = Clock::now();
    total_time = std::chrono::duration_cast<Us>(end - start).count();
    std::cout << "OPTIMAL: " << total_time << "\n";

    start = Clock::now();
    chain.multiply_naively(0, chain.get_count() - 1);
    end = Clock::now();
    total_time = std::chrono::duration_cast<Us>(end - start).count();
    std::cout << "NAIVELY: " << total_time << "\n";

}

