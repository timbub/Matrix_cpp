#include "Matrix_chain.hpp"

int main() {
    try {
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
            chain.add_matrix(matrix::Matrix<double>{dims[i], dims[i+1]});
        }
        chain.analysis_optimal();
        chain.print_order_(0,count_m - 1);
        std::cout << '\n';
    } catch(const std::out_of_range& e) {
        std::cerr << e.what() << "\n";
    } catch(const std::invalid_argument& e) {
        std::cerr << e.what() << "\n";
    }
}
