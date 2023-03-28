#include "rational/rational.hpp"

#include <iostream>

Rational::Rational(int32_t num, int32_t denom) : num_(num), denom_(denom) {
    if (denom_ == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    normalize();
}

void Rational::normalize() {
    int32_t localGCD = gcd(num_, denom_);
    num_ /= localGCD;
    denom_ /= localGCD;
    if (denom_ < 0) {
        num_ = -num_;
        denom_ = -denom_;
    }
}

Rational& Rational::operator+=(const Rational& r) {
    num_ = num_ * r.denom() + r.num() * denom_;
    denom_ *= r.denom();
    normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& r) {
    num_ = num_ * r.denom() - r.num() * denom_;
    denom_ *= r.denom();
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& r) {
    num_ *= r.num();
    denom_ *= r.denom();
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& r) {
    if (r.num() == 0 || r.denom() == 0) {
        throw std::invalid_argument("Division by zero");
    }
    num_ *= r.denom();
    denom_ *= r.num();
    normalize();
    return *this;
}

Rational& Rational::operator++() {
    num_ += denom_;
    normalize();
    return *this;
}

Rational Rational::operator++(int) {
    Rational temp(*this);
    operator++();
    return temp;
}

Rational& Rational::operator--() {
    num_ -= denom_;
    normalize();
    return *this;
}

Rational Rational::operator--(int) {
    Rational temp(*this);
    operator--();
    return temp;
}

bool Rational::operator==(const Rational& r) const {
    return num_ == r.num_ && denom_ == r.denom_;
}

bool Rational::operator!=(const Rational& r) const {
    return !operator==(r);
}

bool Rational::operator>(const Rational& r) const {
    return num_ * r.denom_ > denom_ * r.num_;
}

bool Rational::operator<(const Rational& r) const {
    return num_ * r.denom_ < denom_ * r.num_;
}

bool Rational::operator>=(const Rational& r) const {
    return !operator<(r);
}

bool Rational::operator<=(const Rational& r) const {
    return !operator>(r);
}

std::istream& Rational::read_from(std::istream& istream) {
    int32_t numI = 0;
    int32_t denomI = 1;
    char separator = 0;
    istream >> numI >> separator >> denomI;
    if (istream.fail() || separator != '/') {
        istream.setstate(std::ios_base::failbit);
        return istream;
    }
    num_ = numI;
    denom_ = denomI;
    normalize();
    return istream;
}

std::ostream& Rational::write_to(std::ostream& ostream) const {
    if (denom_ == 1) {
        ostream << num_;
    } else {
        if (num_ >= 0) {
            ostream << num_ << "/" << denom_;
        } else {
            ostream << "-" << -num_ << "/" << denom_;
        }
    }
    return ostream;
}



int32_t Rational::num() const noexcept {
    return num_;
}

int32_t Rational::denom() const noexcept {
    return denom_;
}

Rational operator-(const Rational& r) {
    return Rational(-r.num(), r.denom());
}

Rational operator+(const Rational& l, const Rational& r) {
    Rational rational = l;
    rational += r;
    return rational;
}

Rational operator-(const Rational& l, const Rational& r) {
    Rational rational = l;
    rational -= r;
    return rational;
}

Rational operator*(const Rational& l, const Rational& r) {
    Rational rational = l;
    rational *= r;
    return rational;
}

Rational operator/(const Rational& l, const Rational& r) {
    Rational rational = l;
    rational /= r;
    return rational;
}

std::ostream& operator<<(std::ostream& ostream, const Rational& rational) {
    return rational.write_to(ostream);
}

std::istream& operator>>(std::istream& istream, Rational& rational) {
    return rational.read_from(istream);
}

int32_t gcd(int32_t a, int32_t b) {
    if (a < b) {
        std::swap(a, b);
    }
    while (a % b != 0) {
        a = a % b;
        std::swap(a, b);
    }
    return b;
}