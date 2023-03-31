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
    int64_t new_num = static_cast<int64_t>(num_) * r.denom() + static_cast<int64_t>(r.num()) * denom_;
    int64_t new_denom = static_cast<int64_t>(denom_) * r.denom();
    int64_t localGCD = gcd(new_num, new_denom);
    num_ = static_cast<int32_t>(new_num / localGCD);
    denom_ = static_cast<int32_t>(new_denom / localGCD);
    if (denom_ < 0) {
        num_ = -num_;
        denom_ = -denom_;
    }
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
    istream >> numI;
    if (istream.fail()) {
        istream.setstate(std::ios_base::failbit);
        return istream;
    }
    char delim;
    istream >> std::ws >> delim >> std::ws;
    if (delim != '/' && delim != '\\') {
        istream.setstate(std::ios_base::failbit);
        return istream;
    }
    if (delim == '\\' && istream.peek() == '\\') {
        istream.ignore(1);
    }
    istream >> denomI;
    if (istream.fail() || denomI == 0) {
        istream.setstate(std::ios_base::failbit);
        return istream;
    }
    int sign = 1;
    if (numI < 0) {
        sign = -1;
        numI = -numI;
    }
    if (denomI < 0) {
        sign = -sign;
        denomI = -denomI;
    }
    num_ = sign * numI;
    denom_ = denomI;
    normalize();
    return istream;
}

std::ostream &Rational::write_to(std::ostream &ostream) const {
    if (denom_ == 1) {
        ostream << num_ << "/" << denom_;
    } else {
        if (num_ >= 0) {
            ostream << num_ << "/" << denom_;
        } else {
            // знак "-" перед числом, а не после
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

Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.num() * rhs.denom() + rhs.num() * lhs.denom(),
                    lhs.denom() * rhs.denom());
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
    if (a == 0 || b == 0) {
        return a + b;
    }
    if (a < b) {
        std::swap(a, b);
    }
    while (a % b != 0) {
        a = a % b;
        std::swap(a, b);
    }
    return b;
}
