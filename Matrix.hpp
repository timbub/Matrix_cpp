#pragma once
#include "BufMatrix.hpp"
#include <math.h>
#include <algorithm>
#include <iostream>

namespace compare_double {
    static constexpr double EPS = 1e-7;
    bool is_zero(double n) {
        return std::abs(n) < EPS;
    }
};

namespace matrix {
    template <typename ElemT>
    class Matrix {
    private:
        size_t rows_;
        size_t cols_;
        BufMatrix<ElemT> data_;
    public:
        size_t get_rows() const {return rows_;}
        size_t get_cols() const {return cols_;}

        Matrix(size_t rows, size_t cols) : data_(rows * cols), cols_(cols), rows_(rows) {}
        Matrix(const Matrix& other) : data_(other.rows_ * other.cols_), cols_(other.cols_), rows_(other.rows_) {
            for (size_t i = 0; i < rows_*cols_; i++) {
                data_[i] = other.data_[i];
            }
        }
        Matrix(Matrix&& other) noexcept : rows_{std::exchange(other.rows_, 0)},
                                          cols_{std::exchange(other.cols_, 0)},
                                          data_{std::move(other.data_)} {}

        Matrix& operator=(Matrix&& other) noexcept {
            if (this == &other) return *this;
            swap(other);
            return *this;
        }

        Matrix& operator=(const Matrix& other) {
            Matrix tmp(other);
            swap(tmp);
            return *this;
        }

        ~Matrix() = default;

        double determinate() {
            if (rows_ != cols_) throw std::invalid_argument("Matrix is not square");
            double det = 1.0;
            Matrix<double> tmp(*this);

            for (int j = 0; j < cols_; j++) {
                double pivot   = tmp[j][j];
                size_t p_index = j;
                for (int i = j; i < rows_; i++) {
                    if (std::abs(tmp[i][j]) > std::abs(pivot)) {
                        pivot   = tmp[i][j];
                        p_index = i;
                    }
                }
                if (p_index != j) {
                    tmp[j].swap_rows(tmp[p_index]);
                    det *= -1.0;
                }
                if (compare_double::is_zero(pivot)) return 0;
                for (int i = j + 1; i < cols_; i++) {
                    double factor = tmp[i][j] / tmp[j][j];
                    tmp[i].sub_factor(tmp[j], factor, j + 1);
                }
                det *= tmp[j][j];
            }
            return det;
        }
        private:
        void swap(Matrix& other) noexcept {
            std::swap(other.rows_, rows_);
            std::swap(other.cols_, cols_);
            data_.swap(other.data_);
        }

        class Row {
        private:
            ElemT* row_;
            size_t len_;
        public:
            explicit Row(ElemT* row, size_t len) : row_{row}, len_(len) {}
            ElemT& operator[](size_t index) { return row_[index];}
            const ElemT& operator[](size_t index) const { return row_[index];}

            void swap_rows(Row other) {
                std::swap_ranges(row_, row_ + len_, other.row_);
            }
            void sub_factor(const Row& other, double factor, size_t first_position) {
                for(int i = first_position; i < len_; i++) {
                    row_[i] -= other.row_[i] * factor;
                }
            }


        };

        public:
        Row          operator[](size_t row)       { return Row(data_.get_row_ptr(row, cols_), cols_); }
        const ElemT* operator[](size_t row) const { return data_ + row*cols_; }
    };
};
