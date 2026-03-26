#pragma once
#include "Matrix.hpp"
#include <vector>

namespace matrix {
    template <typename ElemT>
    class Matrix_chain {
    private:
        std::vector<matrix::Matrix<ElemT>> matrices_;
        std::vector<size_t> dims_;
        std::vector<std::vector<size_t>> splits_;
    public:
        size_t get_dim(size_t i) const {return dims_.at(i);}
        size_t get_count() const {return matrices_.size();}

        template <typename Arg>
        void add_matrix(Arg&& arg) {
            size_t r = arg.get_rows();
            size_t c = arg.get_cols();

            if (dims_.empty()) {
                dims_.push_back(r);
                dims_.push_back(c);
            } else {
                if (r != dims_.back()) {
                    throw std::invalid_argument("Matrix dimensions mismatch");
                } else {
                    dims_.push_back(c);
                }
            }
            matrices_.emplace_back(std::forward<Arg>(arg));
        }

        void analysis_optimal() {
            int count = matrices_.size();
            if (count < 2) return;
            splits_.assign(count, std::vector<size_t>(count,0));
            std::vector<std::vector<long long>> costs(count,
                               std::vector<long long>(count, 0));
            for (int len = 2; len <= count; ++len) {
                for (int i = 0; i <= count - len; ++i) {
                    int j = i + len - 1;
                    costs[i][j] = -1;
                    for (int k = i; k < j; ++k) {
                        long long current = costs[i][k] + costs[k+1][j]
                                            + dims_[i]*dims_[k+1]*dims_[j+1];
                        if (costs[i][j] == -1 || current <= costs[i][j]) {
                            costs[i][j] = current;
                            splits_[i][j] = k;
                        }
                    }
                }
            }
        }
        void print_order_(int i, int j) {
            if (i == j) return;
            int k = splits_[i][j];

            print_order_(i, k);
            print_order_(k+1, j);

            std::cout << k << " ";
        }

        Matrix<ElemT> multiply_optimal(size_t i, size_t j) {
            if (i == j) return matrices_[i];
            size_t k = splits_[i][j];

            Matrix<ElemT> left  = multiply_optimal(i, k);
            Matrix<ElemT> right = multiply_optimal(k+1, j);
            return left*right;
        }

        Matrix<ElemT> multiply_naively(size_t i, size_t j) {
            Matrix<ElemT> result = matrices_[0];
            size_t count = get_count();
            for(int i = 1; i < count; ++i) {
                result = result * matrices_[i];
            }
            return result;
        }
    };
}
