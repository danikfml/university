#pragma once
#ifndef ARRAYD_HPP
#define ARRAYD_HPP

#include <cstddef>
#include <algorithm>

template<typename T>
class ArrayT {
private:
    T *data_;
    size_t size_;

public:
    ArrayT() : data_(nullptr), size_(0) {}

    explicit ArrayT(size_t size) : data_(new T[size]), size_(size) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = T();
        }
    }

    ArrayT(size_t size, const T &value) : data_(new T[size]), size_(size) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = value;
        }
    }

    ArrayT(const ArrayT &other) : data_(new T[other.size_]), size_(other.size_) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    ~ArrayT() {
        delete[] data_;
    }

    T &operator[](size_t index) {
        return data_[index];
    }

    const T &operator[](size_t index) const {
        return data_[index];
    }

    void resize(size_t newSize) {
        T *newData = new T[newSize];
        for (size_t i = 0; i < newSize; ++i) {
            newData[i] = i < size_ ? data_[i] : T();
        }
        delete[] data_;
        data_ = newData;
        size_ = newSize;
    }

    void resize(size_t newSize, const T &value) {
        T *newData = new T[newSize];
        for (size_t i = 0; i < newSize; ++i) {
            newData[i] = i < size_ ? data_[i] : value;
        }
        delete[] data_;
        data_ = newData;
        size_ = newSize;
    }

    void push_back(const T &value) {
        resize(size_ + 1, value);
    }

    void pop_back() {
        resize(size_ - 1);
    }

    bool empty() const {
        return size_ == 0;
    }

    size_t size() const {
        return size_;
    }

    void fill(const T &value) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = value;
        }
    }

    void swap(ArrayT &other) {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
    }
};

#endif