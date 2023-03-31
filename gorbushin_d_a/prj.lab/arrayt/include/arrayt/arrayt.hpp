#pragma once

#include <cstddef>

template<typename T>
class ArrayT {
public:
    ArrayT();

    explicit ArrayT(const std::ptrdiff_t size);

    ~ArrayT();

    ArrayT(const ArrayT &other);

    ArrayT &operator=(const ArrayT &other);

    T &operator[](const std::ptrdiff_t i);

    const T &operator[](const std::ptrdiff_t i) const;

    std::ptrdiff_t ssize() const noexcept;

    void resize(const std::ptrdiff_t new_size);

    void insert(const std::ptrdiff_t i, const T value);

    void remove(const std::ptrdiff_t i);

    std::ptrdiff_t capacity() const noexcept;

private:
    std::ptrdiff_t size_{0};
    std::ptrdiff_t capacity_{0};
    T *data_{nullptr};
};
