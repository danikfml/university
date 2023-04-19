#ifndef ARRAYD_HPP
#define ARRAYD_HPP

#include <iostream>

class ArrayD {
public:
    // Constructors
    ArrayD(const ArrayD &rhs);

    ArrayD(const ptrdiff_t &size);

    ArrayD(const std::initializer_list<double> &in_list);

    // Destructor
    ~ArrayD();

    // Operator Overloading
    ArrayD &operator=(const ArrayD rhs);

    // Member Functions
    const ptrdiff_t ssize() const noexcept;

    void resize(const ptrdiff_t size);

    bool empty() noexcept;

    void insert(ptrdiff_t index, double value);

    void remove(ptrdiff_t index);

    void push_back(const double value);

    double pop_back();

    void push_front(const double value);

    double pop_front();

    double &operator[](const ptrdiff_t index);

    const double &operator[](const ptrdiff_t index) const;

    bool operator==(const ArrayD &rhs) noexcept;

    operator bool() const noexcept;

    void fill(const int &begin, const int &end, const double &value);

private:
    double *data_{nullptr};
    ptrdiff_t size_{0};
    ptrdiff_t capacity_{0};
    const double additional_memory_{0.5};
};

#endif
