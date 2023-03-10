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

    int get_size() const;

    void resize(int new_size);

    void push_back(double value);

    void pop_back();

    void clear();

private:
    double *data;
    int size;
};

#endif
