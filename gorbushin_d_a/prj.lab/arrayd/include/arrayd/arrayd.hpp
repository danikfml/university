#pragma once
#ifndef ARRAYT_ARRAYT_HPP_09042023
#define ARRAYT_ARRAYT_HPP_09042023

#include <iosfwd>
#include <initializer_list>
#include <cstddef>

class ArrayD {
public:
    ArrayD();

    ArrayD(const ArrayD &rhs);

    explicit ArrayD(const std::ptrdiff_t size);

    explicit ArrayD(std::initializer_list<int> lst);

    ~ArrayD();

    ArrayD &operator=(const ArrayD &rhs);

    int &operator[](const std::ptrdiff_t i);

    const int &operator[](const std::ptrdiff_t i) const;

    void push_back(const int val);

    std::ptrdiff_t ssize() const noexcept;

    void insert(const std::ptrdiff_t i, const int val);

    void remove(const std::ptrdiff_t i);

    void resize(const std::ptrdiff_t new_size);

    bool operator==(const ArrayD &rhs) const noexcept;

private:
    std::ptrdiff_t size_ = 0;
    int *data_ = nullptr;
    std::ptrdiff_t capacity_ = 1;
};

#endif