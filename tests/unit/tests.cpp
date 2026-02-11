#include <utility>
#include "../../Matrix.hpp"
#include "gtest/gtest.h"

TEST (BUFFER, move_ctor) {
    matrix::BufMatrix<int> buf1(3);
    buf1[0] = 5;
    buf1[1] = 10;
    auto buf2 = std::move(buf1);
    EXPECT_EQ(buf2[0] + buf2[1], 15);
}