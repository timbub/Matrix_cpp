#include <utility>
#include "../../Matrix.hpp"
#include "gtest/gtest.h"

namespace {
    struct ThrowingElement {
        double value_;
        static inline int current_copies_ = 0;
        static inline int throw_after = -1;

        static void reset() {
            current_copies_ = 0;
            throw_after = -1;
        }

        explicit ThrowingElement(double value) : value_(value) {}

        ThrowingElement(const ThrowingElement& other) : value_(other.value_) {
            if (throw_after != -1 && ++current_copies_ >= throw_after) throw std::bad_alloc();
        }

        auto operator <=>(const ThrowingElement& other) const = default;

    };
};

TEST (BUFFER, move_ctor) {
    matrix::BufMatrix<int> buf1(3);
    buf1[0] = 5;
    buf1[1] = 10;
    auto buf2(std::move(buf1));
    EXPECT_EQ(buf2[0] + buf2[1], 15);
}

TEST (BUFFER, move_assigments) {
    matrix::BufMatrix<int> buf1(3);
    buf1[0] = 5;
    buf1[1] = 10;
    auto buf2 = std::move(buf1);
    EXPECT_EQ(buf2[0] + buf2[1], 15);
}

TEST (MATRIX, copy_ctor) {
    matrix::Matrix<double> matrix1{3,3};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix1[i][j] = i;
        }
    }
    auto matrix2(matrix1);
    EXPECT_EQ(matrix1.determinate(), matrix2.determinate());
}

TEST (MATRIX, move_ctor) {
    matrix::Matrix<double> matrix1{3,3};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix1[i][j] = i;
        }
    }
    double expected = matrix1.determinate();
    auto matrix2(std::move(matrix1));
    EXPECT_EQ(expected, matrix2.determinate());
}

TEST (MATRIX, copy_assigment) {
    matrix::Matrix<double> matrix1{3,3};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix1[i][j] = i;
        }
    }
    auto matrix2 = matrix1;
    EXPECT_EQ(matrix1.determinate(), matrix2.determinate());
}

TEST (MATRIX, move_assigment) {
    matrix::Matrix<double> matrix1{3,3};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix1[i][j] = i;
        }
    }
    double expected = matrix1.determinate();
    auto matrix2 = std::move(matrix1);
    EXPECT_EQ(expected, matrix2.determinate());
}



