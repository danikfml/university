#pragma once
#ifndef ARRAYD_HPP
#define ARRAYD_HPP

#include <cstddef>
#include <initializer_list>

class ArrayD {
public:
    ArrayD();

    ArrayD(const ArrayD &rhs);

    explicit ArrayD(const std::ptrdiff_t size);

    explicit ArrayD(std::initializer_list<double> lst);

    ~ArrayD();

    ArrayD &operator=(const ArrayD &rhs);

    double &operator[](const std::ptrdiff_t i);

    const double &operator[](const std::ptrdiff_t i) const;

    void push_back(const double val);

    std::ptrdiff_t ssize() const noexcept;

    void insert(const std::ptrdiff_t i, const double val);

    void remove(const std::ptrdiff_t i);

    void resize(const std::ptrdiff_t new_size);

    bool operator==(const ArrayD &rhs) const noexcept;

private:
    std::ptrdiff_t size_ = 0;
    double *data_ = nullptr;
    std::ptrdiff_t capacity_ = 1;
};

#endif
