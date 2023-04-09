#include "matrixs/matrixs.hpp"
#include <stdexcept>
#include <algorithm>

MatrixS::MatrixS(const SizeType& size)
        : MatrixS(std::get<0>(size), std::get<1>(size)) {}

MatrixS::MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n)
        : m_(m), n_(n), data_{new int[m * n]()} {}

MatrixS::~MatrixS() { delete[] data_; }

MatrixS::MatrixS(const MatrixS& other)
        : m_{other.m_}, n_{other.n_}, data_{new int[m_ * n_]()} {
    std::copy(other.data_, other.data_ + m_ * n_, data_);
}

MatrixS& MatrixS::operator=(const MatrixS& other) {
    if (this != &other) {
        int* temp = new int[other.m_ * other.n_]();
        std::copy(other.data_, other.data_ + other.m_ * other.n_, temp);
        delete[] data_;
        data_ = temp;
        m_ = other.m_;
        n_ = other.n_;
    }
    return *this;
}

int& MatrixS::at(const SizeType& elem) {
    return at(std::get<0>(elem), std::get<1>(elem));
}

const int& MatrixS::at(const SizeType& elem) const {
    return at(std::get<0>(elem), std::get<1>(elem));
}

int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) {
    if (i < 0 || i >= m_ || j < 0 || j >= n_) {
        throw std::out_of_range("Invalid index");
    }
    return data_[i * n_ + j];
}

const int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) const {
    if (i < 0 || i >= m_ || j < 0 || j >= n_) {
        throw std::out_of_range("Invalid index");
    }
    return data_[i * n_ + j];
}

void MatrixS::resize(const SizeType& new_size) {
    resize(std::get<0>(new_size), std::get<1>(new_size));
}

void MatrixS::resize(const std::ptrdiff_t i, const std::ptrdiff_t j) {
    if (i <= 0 || j <= 0) {
        throw std::invalid_argument("Negative matrix size");
    }
    if (i == m_ && j == n_) {
        return;
    }
    int* newData = new int[i * j]{};
    std::ptrdiff_t min_m = (i < m_) ? i : m_;
    std::ptrdiff_t min_n = (j < n_) ? j : n_;
    for (std::ptrdiff_t row = 0; row < min_m; ++row) {
        for (std::ptrdiff_t col = 0; col < min_n; ++col) {
            newData[row * j + col] = data_[row * n_ + col];
        }
    }
    delete[] data_;
    data_ = newData;
    m_ = i;
    n_ = j;
}

const MatrixS::SizeType& MatrixS::ssize() const noexcept {
    static SizeType size(m_, n_);
    return size;
}

std::ptrdiff_t MatrixS::nRows() const noexcept {
    return m_;
}

std::ptrdiff_t MatrixS::nCols() const noexcept {
    return n_;
}
