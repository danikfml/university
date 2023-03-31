#include "arrayt/arrayt.hpp"

template<typename T>
ArrayT<T>::ArrayT() = default;

template<typename T>
ArrayT<T>::ArrayT(const std::ptrdiff_t size) : size_{size}, capacity_{size}, data_{new T[capacity_]} {}

template<typename T>
ArrayT<T>::~ArrayT() {
    delete[] data_;
}

template<typename T>
ArrayT<T>::ArrayT(const ArrayT &other) : size_{other.size_}, capacity_{other.capacity_}, data_{new T[capacity_]} {
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template<typename T>
ArrayT<T> &ArrayT<T>::operator=(const ArrayT &other) {
    if (this != &other) {
        if (capacity_ < other.size_) {
            delete[] data_;
            data_ = new T[other.capacity_];
            capacity_ = other.capacity_;
        }
        size_ = other.size_;
        for (std::ptrdiff_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template<typename T>
T &ArrayT<T>::operator[](const std::ptrdiff_t i) {
    return data_[i];
}

template<typename T>
const T &ArrayT<T>::operator[](const std::ptrdiff_t i) const {
    return data_[i];
}

template<typename T>
std::ptrdiff_t ArrayT<T>::ssize() const noexcept {
    return size_;
}

template<typename T>
void ArrayT<T>::resize(const std::ptrdiff_t new_size) {
    if (new_size > capacity_) {
        T *new_data = new T[new_size];
        for (std::ptrdiff_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_size;
    }
    size_ = new_size;
}

template<typename T>
void ArrayT<T>::insert(const std::ptrdiff_t i, const T value) {
    if (size_ == capacity_) {
        T *new_data = new T[capacity_ * 2];
        for (std::ptrdiff_t j = 0; j < i; ++j) {
            new_data[j] = data_[j];
        }
        new_data[i] = value;
        for (std::ptrdiff_t j = i + 1; j <= size_; ++j) {
            new_data[j] = data_[j - 1];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ *= 2;
    } else {
        for (std::ptrdiff_t j = size_; j > i; --j) {
            data_[j] = data_[j - 1];
        }
        data_[i] = value;
    }
    ++size_;
}

template<typename T>
void ArrayT<T>::remove(const std::ptrdiff_t i) {
    for (std::ptrdiff_t j = i; j < size_ - 1; ++j) {
        data_[j] = data_[j + 1];
    }
    --size_;
}

template<typename T>
std::ptrdiff_t ArrayT<T>::capacity() const noexcept {
    return capacity_;
}
