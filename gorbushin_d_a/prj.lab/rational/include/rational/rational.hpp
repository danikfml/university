#pragma once
#ifndef RATIONAL_RATIONAL_HPP_20230215
#define RATIONAL_RATIONAL_HPP_20230215

#include <iosfwd>
#include <cstdint>
#include <numeric>

class Rational {
public:
    Rational() = default;

    Rational(const Rational& r) = default;

    Rational(int64_t num, int64_t denom);

    ~Rational() = default;

    Rational& operator=(const Rational& r) = default;

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

    inline std::ostream& write_to(std::ostream& ostream) const;

    int64_t num() const noexcept { return num_; }
    int64_t denom() const noexcept { return den_; }
private:
    int64_t num_ = 1;
    int64_t den_ = 1;

    void normalize();
};

Rational operator-(const Rational& r);

Rational operator+(const Rational& l, const Rational& r);

Rational operator-(const Rational& l, const Rational& r);

Rational operator*(const Rational& l, const Rational& r);

Rational operator/(const Rational& l, const Rational& r);

std::ostream& operator<<(std::ostream& ostream, const Rational& r);

std::istream& operator>>(std::istream& istream, Rational& r);
#endif