#ifndef ARRAYD_HPP
#define ARRAYD_HPP

class ArrayD {
public:
    ArrayD(int size_1);

    ArrayD(const ArrayD &n);

    ArrayD &operator=(const ArrayD &n);

    ~ArrayD();

    double &operator[](int index);

    const double &operator[](int index) const;

    int ssize() const;

    void resize(int new_size);

    void insert(double value);

    void remove();

    void clear();

private:
    double *data = nullptr;
    int size;
};

#endif
