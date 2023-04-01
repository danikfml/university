#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <stdexcept>

class Rational {
public:
    Rational(int32_t num = 0, int32_t denom = 1);

    Rational &operator+=(const Rational &);

    Rational &operator-=(const Rational &);

    Rational &operator*=(const Rational &);

    Rational &operator/=(const Rational &);

    Rational &operator++();

    Rational operator++(int);

    Rational &operator--();

    Rational operator--(int);

    bool operator==(const Rational &) const;

    bool operator!=(const Rational &) const;

    bool operator>(const Rational &) const;

    bool operator<(const Rational &) const;

    bool operator>=(const Rational &) const;

    bool operator<=(const Rational &) const;

    int32_t num() const noexcept;

    int32_t denom() const noexcept;

    std::istream &read_from(std::istream &);

    std::ostream &write_to(std::ostream &) const;

private:
    void normalize();

    int32_t num_;
    int32_t denom_;
    static const char delimiter_ = '/';
};

Rational operator-(const Rational &);

Rational operator+(const Rational &, const Rational &);

Rational operator-(const Rational &, const Rational &);

Rational operator*(const Rational &, const Rational &);

Rational operator/(const Rational &, const Rational &);

std::ostream &operator<<(std::ostream &, const Rational &);

std::istream &operator>>(std::istream &, Rational &);

int32_t gcd(int32_t a, int32_t b);

#endif