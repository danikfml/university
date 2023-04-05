#include "arrayd/arrayd.hpp"
#include <algorithm>

ArrayD::ArrayD(const std::ptrdiff_t size) : data_{nullptr}, size_{size}, capacity_{size} {
    if (size_ < 0) {
        throw std::invalid_argument("ArrayD::ArrayD: size must be non-negative");
    }
    if (size_ > 0) {
        data_ = new double[size_];
        std::fill_n(data_, size_, 0.0);
    }
}

ArrayD::~ArrayD() {
    delete[] data_;
}

ArrayD::ArrayD(const ArrayD &other) : data_{nullptr}, size_{other.size_}, capacity_{other.capacity_} {
    if (size_ > 0) {
        data_ = new double[size_];
        std::copy(other.data_, other.data_ + size_, data_);
    }
}

ArrayD &ArrayD::operator=(const ArrayD &other) {
    if (this != &other) {
        ArrayD tmp(other);
        std::swap(data_, tmp.data_);
        std::swap(size_, tmp.size_);
        std::swap(capacity_, tmp.capacity_);
    }
    return *this;
}

double &ArrayD::operator[](const std::ptrdiff_t i) {
    if (i < 0 || i >= size_) {
        throw std::out_of_range("ArrayD::operator[]: index out of range");
    }
    return data_[i];
}

const double &ArrayD::operator[](const std::ptrdiff_t i) const {
    if (i < 0 || i >= size_) {
        throw std::out_of_range("ArrayD::operator[]: index out of range");
    }
    return data_[i];
}

std::ptrdiff_t ArrayD::ssize() const noexcept {
    return size_;
}

std::ptrdiff_t ArrayD::capacity() const noexcept {
    return capacity_;
}

void ArrayD::resize(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("ArrayD::resize: size must be non-negative");
    }

    if (size == size_) {
        return;
    }

    double *new_data{nullptr};
    std::ptrdiff_t new_capacity{capacity_};

    if (size > capacity_) {
        new_capacity = size;
        while (new_capacity < size) {
            new_capacity *= 2;
        }
    }

    if (size > 0) {
        new_data = new double[new_capacity];
        const std::ptrdiff_t min_size{std::min(size, size_)};
        std::copy_n(data_, min_size, new_data);
        std::fill_n(new_data + min_size, size - min_size, 0.0);
    }

    delete[] data_;
    data_ = new_data;
    size_ = size;
    capacity_ = new_capacity;
}

void ArrayD::insert(const std::ptrdiff_t i, const double value) {
    if (i < 0 || i > size_) {
        throw std::out_of_range("ArrayD::insert: index out of range");
    }
    resize(size_ + 1);
    for (std::ptrdiff_t j = size_ - 1; j > i; --j) {
        data_[j] = data_[j - 1];
    }
    data_[i] = value;
}

void ArrayD::remove(const std::ptrdiff_t i) {
    if (i < 0 || i >= size_) {
        throw std::out_of_range("ArrayD::remove: index out of range");
    }
    for (std::ptrdiff_t j = i; j < size_ - 1; ++j) {
        data_[j] = data_[j + 1];
    }
    resize(size_ - 1);
}

bool ArrayD::operator==(const ArrayD &other) const noexcept {
    if (size_ != other.size_)
        return false;
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
        if (data_[i] != other.data_[i])
            return false;
    }
    return true;
}