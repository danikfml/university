#pragma once
#ifndef RATIONAL_RATIONAL_HPP_20230317
#define RATIONAL_RATIONAL_HPP_20230317
#include <iostream>
#include <cstdint>

class Rational {
public:
    Rational(int32_t num, int32_t denom);
    Rational(int32_t num);
    Rational();
    Rational(const Rational& other);
    Rational& operator=(const Rational& other);
    ~Rational();

    int32_t num() const noexcept;
    int32_t denom() const noexcept;

    Rational& operator+=(const Rational& r);
    Rational& operator-=(const Rational& r);
    Rational& operator*=(const Rational& r);
    Rational& operator/=(const Rational& r);

    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator--(int);

    bool operator==(const Rational& r) const;
    bool operator!=(const Rational& r) const;
    bool operator>(const Rational& r) const;
    bool operator<(const Rational& r) const;
    bool operator>=(const Rational& r) const;
    bool operator<=(const Rational& r) const;

    std::istream& read_from(std::istream& istream);
    std::ostream& write_to(std::ostream& ostream) const;

private:
    int32_t num_;
    int32_t denom_;

    void normalize();
};

Rational operator-(const Rational& r);
Rational operator+(const Rational& l, const Rational& r);
Rational operator-(const Rational& l, const Rational& r);
Rational operator*(const Rational& l, const Rational& r);
Rational operator/(const Rational& l, const Rational& r);

std::ostream& operator<<(std::ostream& ostream, const Rational& r);
std::istream& operator>>(std::istream& istream, Rational& r);int32_t gcd(int32_t a, int32_t b);

#endif
