#include "Matrix_chain.hpp"

int main() {
    size_t count_dims = 0;
    if (!(std::cin >> count_dims)) {
        std::cerr << "Error of input count\n";
    }
    using ElemT = double;
    matrix::Matrix_chain<ElemT> chain;
    size_t dim = 0;
    for (size_t i = 0; i < count_dims; ++i)
    {
       std::cin >> dim;
       chain.add_dim(dim);
    }

    size_t count_m = count_dims - 1;
    for (size_t i = 0; i < count_m - 1; ++i)
    {
        chain.add_matrix(matrix::Matrix<double>{chain.dims_[i], chain.dims_[i+1]});
    }
    //todo: add getters


    chain.analysis_optimal();
    chain.print_order_(0,count_dims - 1);
}
