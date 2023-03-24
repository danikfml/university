#pragma once
#ifndef MATRIXS_HPP
#define MATRIXS_HPP

#include <cstddef>
#include <utility>
#include <stdexcept>

class MatrixS {
public:
    using size_type = std::pair<std::ptrdiff_t, std::ptrdiff_t>;
    MatrixS() noexcept;
    MatrixS(std::ptrdiff_t m, std::ptrdiff_t n);
    MatrixS(const MatrixS& other);
    MatrixS& operator=(const MatrixS& other);
    void resize(const size_type& new_size);
    std::ptrdiff_t getRows() const noexcept;
    std::ptrdiff_t getCols() const noexcept;
    int* operator[](std::ptrdiff_t i) noexcept;
    const int* operator[](std::ptrdiff_t i) const noexcept;
    int& at(const size_type& pos);
    const int& at(const size_type& pos) const;

private:
    std::ptrdiff_t m;
    std::ptrdiff_t n;
    int** data;
};

#endif
