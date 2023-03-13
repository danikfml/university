#include "arrayd/arrayd.hpp"
#include <iostream>

ArrayD::ArrayD(int size_1) {
    size = size_1;
    data = new double[size];
}

ArrayD::ArrayD(const ArrayD &n) {
    size = n.size;
    data = new double[size];
    std::copy(n.data, n.data + size, data);
}

ArrayD &ArrayD::operator=(const ArrayD &n) {
    if (this == &n) {
        return *this;
    }
    delete[] data;
    size = n.size;
    data = new double[size];
    std::copy(n.data, n.data + size, data);
    return *this;
}

ArrayD::~ArrayD() {
    delete[] data;
}

double &ArrayD::operator[](int index) {
    if (index >= size) {
        resize(index * 2);
    }
    return data[index];
}

const double &ArrayD::operator[](int index) const {
    return data[index];
}

int ArrayD::ssize() const {
    return size;
}

void ArrayD::resize(int new_size) {
    double *new_array = new double[new_size];
    std::copy(data, data + size, new_array);
    delete[] data;
    data = new_array;
    size = new_size;
}

void ArrayD::insert(double value) {
    if (size == 0) {
        resize(1);
    } else if (size == 1) {
        resize(2);
    } else if (size % 2 == 0) {
        resize(size + size / 2);
    } else {
        resize(size + size / 2 + 1);
    }
    data[size - 1] = value;
}

void ArrayD::remove() {
    if (size > 0) {
        resize(size - 1);
    }
}

void ArrayD::clear() {
    resize(0);
}
