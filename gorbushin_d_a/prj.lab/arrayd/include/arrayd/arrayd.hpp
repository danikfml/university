#pragma once
#ifndef ARRAYD_HPP
#define ARRAYD_HPP

#include <cstddef>
#include <stdexcept>

class ArrayD {
public:
    explicit ArrayD(const std::ptrdiff_t size = 0);

    ~ArrayD();

    ArrayD(const ArrayD &);

    ArrayD &operator=(const ArrayD &);

    [[nodiscard]] double &operator[](const std::ptrdiff_t i);

    [[nodiscard]] const double &operator[](const std::ptrdiff_t i) const;

    [[nodiscard]] std::ptrdiff_t ssize() const noexcept;

    void resize(const std::ptrdiff_t new_size);

    void insert(const std::ptrdiff_t i, const double value);

    void remove(const std::ptrdiff_t i);

    [[nodiscard]] std::ptrdiff_t capacity() const noexcept;

    bool operator==(const ArrayD &other) const noexcept;


private:
    double *data_;
    std::ptrdiff_t size_;
    std::ptrdiff_t capacity_;
};

#endif
