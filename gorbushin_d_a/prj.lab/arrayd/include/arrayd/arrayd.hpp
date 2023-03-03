// Copyright 2023 by Polevoy Dmitry under Free Public License 1.0.0

#pragma once
#ifndef ARRAYD_ARRAYD_HPP_20230303
#define ARRAYD_ARRAYD_HPP_20230303

#include <iosfwd>
#include <cstdint>

class Rational {
public:
    Rational() = default;
    Rational(const Rational&) = default;
    Rational(Rational&&) = default;
    Rational(const int32_t num) noexcept ;
    Rational(const int32_t num, const int32_t den);
    ~Rational() = default;
    Rational& operator=(const Rational&) = default;
    Rational& operator=(Rational&&) = default;

    int32_t GetNum() const noexcept { return num_; }
    int32_t GetDen() const noexcept { return den_; }

    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;
    bool operator>(const Rational& rhs) const;
    bool operator<(const Rational& rhs) const;
    bool operator>=(const Rational& rhs) const;
    bool operator<=(const Rational& rhs) const;

    explicit operator bool() const noexcept;

    Rational& operator*=(const Rational& rhs);

    Rational& operator+=(const Rational& rhs);

    Rational& operator-=(const Rational& rhs);

    Rational& operator/=(const Rational& rhs);

    Rational& operator++();

    Rational operator++(int);

    Rational& operator--();

    Rational operator--(int);

    std::istream& read_from(std::istream& istrm);
    std::ostream& write_to(std::ostream& ostrm) const;

private:
    int32_t num_ = 0;
    int32_t den_ = 1;
    static const char delimiter_ = '/';
    void normalize();
};

std::istream &operator>>(std::istream& istrm, Rational& rhs);

std::ostream &operator<<(std::ostream& ostrm, const Rational& rhs);

Rational operator-(const Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);
#endif