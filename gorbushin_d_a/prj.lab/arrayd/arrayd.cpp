#include "arrayd/arrayd.hpp"
#include <algorithm>
#include <stdexcept>

ArrayD::ArrayD() {
    data_ = nullptr;
    size_ = 0;
    capacity_ = 1;
}

ArrayD::ArrayD(const ArrayD &rhs) {
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    data_ = new int[capacity_];
    for (std::ptrdiff_t i = 0; i < size_; i += 1) {
        data_[i] = rhs.data_[i];
    }
}

ArrayD::ArrayD(const std::ptrdiff_t size) {
    size_ = size;
    data_ = new int[size];
    for (size_t i = 0; i < size; i += 1) {
        data_[i] = int();
    }
    capacity_ = size;
}

ArrayD::ArrayD(std::initializer_list<int> lst) {
    size_ = lst.size();
    capacity_ = size_;
    data_ = new int[capacity_];
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
    data_ = new int[capacity_];
    for (size_t i = 0; i < size_; i += 1) {
        data_[i] = rhs.data_[i];
    }
    return *this;
}

int &ArrayD::operator[](const std::ptrdiff_t i) {
    if (i < 0 || i >= size_ || (i == 0 && size_ == 0)) {
        throw std::out_of_range("The index is out of range");
    }
    return data_[i];
}

const int &ArrayD::operator[](const std::ptrdiff_t i) const {
    if (i < 0 || i >= size_ || (i == 0 && size_ == 0)) {
        throw std::out_of_range("The index is out of range");
    }
    return data_[i];
}

void ArrayD::push_back(const int val) {
    if (size_ == capacity_) {
        capacity_ += 1;
    }
    size_ += 1;
    int *new_data = new int[size_];
    for (size_t i = 0; i < size_ - 1; i += 1) {
        new_data[i] = data_[i];
    }
    delete[] data_;
    new_data[size_ - 1] = val;
    data_ = new_data;
}

std::ptrdiff_t ArrayD::ssize() const noexcept {
    return size_;
}

void ArrayD::insert(const std::ptrdiff_t i, const int val) {
    if (i < 0 || i > size_) {
        throw std::invalid_argument("The index is out of range");
    } else {
        if (size_ == capacity_) {
            capacity_ *= 2;
        }
        int *new_data = new int[capacity_];
        std::copy(data_, data_ + i, new_data);
        new_data[i] = val;
        std::copy(data_ + i, data_ + size_, new_data + i + 1);
        delete[] data_;
        data_ = new_data;
        size_ += 1;
    }
}

void ArrayD::remove(const std::ptrdiff_t i) {
    if (i < 0 || i >= size_) {
        throw std::out_of_range("The index is out of range");
    } else {
        int *new_data = new int[capacity_];
        std::copy(data_, data_ + i, new_data);
        std::copy(data_ + i + 1, data_ + size_, new_data + i);
        delete[] data_;
        data_ = new_data;
        size_ -= 1;
    }
}

void ArrayD::resize(const std::ptrdiff_t new_size) {
    if (new_size <= 0) {
        throw std::invalid_argument("The new size should be greater than 0");
    } else {
        if (new_size > size_) {
            int *new_data = new int[new_size];
            std::copy(data_, data_ + size_, new_data);
            delete[] data_;
            data_ = new_data;
            for (size_t i = size_; i < new_size; i += 1) {
                new_data[i] = int();
            }
            size_ = new_size;
            capacity_ = new_size;
        } else if (new_size < size_) {
            int *new_data = new int[new_size];
            for (size_t i = 0; i < new_size; i += 1) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
            size_ = new_size;
            capacity_ = new_size;
        }
    }
}

bool ArrayD::operator==(const ArrayD &rhs) const noexcept {
    if (size_ != rhs.size_) {
        return false;
    } else {
        for (size_t i = 0; i < size_; i += 1) {
            if (data_[i] != rhs.data_[i]) {
                return false;
            }
        }
    }
    return true;
}

