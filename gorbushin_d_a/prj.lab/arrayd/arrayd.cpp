#include "arrayd/arrayd.hpp"
#include <algorithm>

ArrayD::ArrayD() {
    data_ = nullptr;
    size_ = 0;
    capacity_ = 1;
}

ArrayD::ArrayD(const ArrayD &rhs) {
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    data_ = new double[capacity_];
    std::copy(rhs.data_, rhs.data_ + size_, data_);
}

ArrayD::ArrayD(const std::ptrdiff_t size) {
    size_ = size;
    data_ = new double[size];
    for (size_t i = 0; i < size; i += 1) {
        data_[i] = 0.0;
    }
    capacity_ = size;
}

ArrayD::ArrayD(std::initializer_list<double> lst) {
    size_ = lst.size();
    capacity_ = size_;
    data_ = new double[capacity_];
    std::copy(lst.begin(), lst.end(), data_);
}

ArrayD::~ArrayD() {
    delete[] data_;
}

ArrayD &ArrayD::operator=(const ArrayD &rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete[] data_;
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
    data_ = new double[capacity_];
    std::copy(rhs.data_, rhs.data_ + size_, data_);
    return *this;
}

double &ArrayD::operator[](const std::ptrdiff_t i) {
    return data_[i];
}

const double &ArrayD::operator[](const std::ptrdiff_t i) const {
    return data_[i];
}

void ArrayD::push_back(const double val) {
    if (size_ >= capacity_) {
        resize(size_ * 2);
    }
    data_[size_] = val;
    size_ += 1;
}

std::ptrdiff_t ArrayD::ssize() const noexcept {
    return size_;
}

void ArrayD::insert(const std::ptrdiff_t i, const double val) {
    if (size_ >= capacity_) {
        resize(size_ * 2);
    }
    std::copy_backward(data_ + i, data_ + size_, data_ + size_ + 1);
    data_[i] = val;
    size_ += 1;
}

void ArrayD::remove(const std::ptrdiff_t i) {
    std::copy(data_ + i + 1, data_ + size_, data_ + i);
    size_ -= 1;
}

void ArrayD::resize(const std::ptrdiff_t new_size) {
    if (new_size < size_) {
        size_ = new_size;
    }
    double *new_data = new double[new_size];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = new_size;
}

bool ArrayD::operator==(const ArrayD &rhs) const noexcept {
    if (size_ != rhs.size_) {
        return false;
    }
    for (std::ptrdiff_t i = 0; i < size_; i += 1) {
        if (data_[i] != rhs.data_[i]) {
            return false;
        }
    }
    return true;
}
