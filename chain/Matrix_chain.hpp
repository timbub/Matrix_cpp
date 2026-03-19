#pragma once
#include "Matrix.hpp"
#include <vector>

namespace matrix {
    template <typename ElemT>
    class Matrix_chain {
    private:
        size_t count_;
        std::vector<matrix::Matrix<ElemT>> matrices_;
        std::vector<size_t> dims_;
        std::vector<std::vector<size_t>> splits_;
        long long optimal_cost_ = 0;
    public:
        template <typename Arg>
        void add_matrix(Arg&& arg) {
            if (dims_.empty()) {
                matrices_.emplace_back(std::forward<Arg>(arg));
                count_++;
            } else {
                if (arg.rows_ == dims_.back()) {
                    matrices_.emplace_back(std::forward<Arg>(arg));
                    count_++;
                } else {
                    std::cerr << "Wrong row size";
                }
            }
        }
        void add_dim(size_t dim) {
            dims_.push_back(dim);
        }
        void analysis_optimal() {
            int count = matrices_.size();
            if (count < 2) return;
            splits_.assign(count_, std::vector<size_t>{count_,0});
            std::vector<std::vector<long long>> costs(count, std::vector<long long>(count, 0));
            for (int len = 2; len <= count; ++len) {
                for (int i = 0; i < count - len; ++i) {
                    int j = i + len - 1;
                    costs[i][j] = -1;
                    for (int k = i; k < j; ++k) {
                        long long current = costs[i][k] + costs[k+1][j] + dims_[i]*dims_[k+1]*dims_[j+1];
                        if (costs[i][j] == -1 || current < costs[i][j]) {
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
    };
}
