#pragma once
#include <utility>
#include <cstddef>

namespace matrix {

    template <typename ElemT>
    class BufMatrix {
    private:
        ElemT* buf_ = nullptr;
        size_t len_ = 0;
    public:
        BufMatrix() = default;

        explicit BufMatrix(size_t len) : len_(len), buf_(new ElemT[len]) {
        }
        BufMatrix(BufMatrix&& other) noexcept : len_{std::exchange(other.len_, 0)}, buf_{std::exchange(other.buf_, nullptr)} {}
        BufMatrix(const BufMatrix& other) = delete;

        BufMatrix operator=(const BufMatrix& other) = delete;

        BufMatrix& operator=(BufMatrix&& other) {
            if (this == &other) return *this;
            swap(other);
            return *this;
        }

        ~BufMatrix() {
            delete[] buf_;
        }

        ElemT& operator[](size_t index) {return buf_[index];}
        const ElemT& operator[](size_t index) const  {return buf_[index];}
        ElemT* get_row_ptr(size_t row, size_t cols) {
            return buf_ + row*cols;
        }
        const ElemT* get_row_ptr(size_t row, size_t cols) const { 
            return buf_ + row * cols;
        }
        void swap(BufMatrix& other) {
            std::swap(other.buf_, buf_);
            std::swap(other.len_, len_);
        }
    };
}


