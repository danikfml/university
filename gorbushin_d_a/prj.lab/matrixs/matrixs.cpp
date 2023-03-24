#include "matrixs/matrixs.hpp"

MatrixS::MatrixS() noexcept : m{0}, n{0}, data{nullptr} {}

MatrixS::MatrixS(std::ptrdiff_t m, std::ptrdiff_t n) : m{m}, n{n} {
    data = new int*[m];
    for (std::ptrdiff_t i = 0; i < m; ++i) {
        data[i] = new int[n]();
    }
}

MatrixS::MatrixS(const MatrixS& other) : m{other.m}, n{other.n} {
    data = new int*[m];
    for (std::ptrdiff_t i = 0; i < m; ++i) {
        data[i] = new int[n];
        for (std::ptrdiff_t j = 0; j < n; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

MatrixS& MatrixS::operator=(const MatrixS& other) {
    if (this != &other) {
        MatrixS tmp{other};
        std::swap(m, tmp.m);
        std::swap(n, tmp.n);
        std::swap(data, tmp.data);
    }
    return *this;
}

void MatrixS::resize(const size_type& new_size) {
    if (new_size.first <= 0 || new_size.second <= 0) {
        throw std::invalid_argument("Invalid size");
    }

    int** new_data = new int*[new_size.first];
    for (std::size_t i = 0; i < new_size.first; ++i) {
        new_data[i] = new int[new_size.second]();
    }

    for (std::ptrdiff_t i = 0; i < std::min(m, new_size.first); ++i) {
        for (std::ptrdiff_t j = 0; j < std::min(n, new_size.second); ++j) {
            new_data[i][j] = data[i][j];
        }
    }

    for (std::ptrdiff_t i = 0; i < m; ++i) {
        delete[] data[i];
    }
    delete[] data;

    m = new_size.first;
    n = new_size.second;
    data = new_data;
}

std::ptrdiff_t MatrixS::getRows() const noexcept {
    return m;
}

std::ptrdiff_t MatrixS::getCols() const noexcept {
    return n;
}

int* MatrixS::operator[](std::ptrdiff_t i) noexcept {
    return data[i];
}

const int* MatrixS::operator[](std::ptrdiff_t i) const noexcept {
    return data[i];
}

int& MatrixS::at(const size_type& pos) {
    if (pos.first < 0 || pos.first >= m || pos.second < 0 || pos.second >= n) {
        throw std::out_of_range("Index out of range");
    }
    return data[pos.first][pos.second];
}

const int& MatrixS::at(const size_type& pos) const {
    if (pos.first < 0 || pos.first >= m || pos.second < 0 || pos.second >= n) {
        throw std::out_of_range("Index out of range");
    }
    return data[pos.first][pos.second];
}