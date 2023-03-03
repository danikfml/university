#include <iostream>
#include "arrayd/arrayd.hpp"

int32_t gcd(int32_t a, int32_t b) {
    if (b > a) std::swap(a, b);
    return b ? gcd(b, a % b) : a;
}

void Rational::normalize() {
    if (num_ < 0 && den_ < 0) { num_ *= -1; den_ *= -1; }
    int g = gcd(std::abs(num_), std::abs(den_));
    num_ /= g;
    den_ /= g;
}

Rational::Rational(int32_t num, int32_t den) {
    num_ = num;
    den_ = den;
    if (den_ == 0) {
        throw "Denominator can't be zero";
    }
    normalize();
}

Rational operator-(const Rational& rhs) {
    return {-rhs.GetNum(), rhs.GetDen()};
}
Rational& Rational::operator+=(const Rational& rhs) {
    int32_t lmc = den_ * rhs.GetDen() / gcd(den_, rhs.GetDen());
    num_ = lmc / den_;
    den_ *= lmc / den_;
    num_ += rhs.GetNum() * lmc / rhs.GetDen();
    normalize();
    return *this;
}
Rational operator+(const Rational& lhs, const Rational& rhs) {
    /*int den = GetDen() * rhs.GetDen();
    int num = GetNum() * rhs.GetDen() + rhs.GetNum() * GetDen();
    return Rational(num, den);*/
    Rational rational = lhs;
    rational += rhs;
    return rational;
}
Rational& Rational::operator-=(const Rational& rhs) {
    this->operator+=(-rhs);
    return *this;
}
Rational operator-(const Rational& lhs, const Rational& rhs) {
    Rational rational = lhs;
    rational -= rhs;
    return rational;
}
Rational operator*(const Rational& lhs, const Rational& rhs) {
    Rational rational = lhs;
    rational *= rhs;
    return rational;
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational rational = lhs;
    rational /= rhs;
    return rational;
}
Rational& Rational::operator*=(const Rational& rhs) {
    this->num_ *= rhs.GetNum();
    this->num_ *= rhs.GetDen();
    normalize();
    return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs.GetNum() == 0) {
        throw "Denominator can't be zero";
    }
    this->num_ *= rhs.GetDen();
    this->den_ *= rhs.GetNum();
    normalize();
    return *this;
}
Rational Rational::operator++(int) {
    Rational tmp(*this);
    *this += 1;
    return tmp;
}
Rational& Rational::operator++() {
    return *this += Rational(1);
}
Rational Rational::operator--(int) {
    Rational tmp(*this);
    *this -= 1;
    return tmp;
}
Rational& Rational::operator--() {
    return *this -= Rational(1);
}

bool Rational::operator==(const Rational& rhs) const { return (GetNum() == rhs.GetNum() && GetDen() == rhs.GetDen()); }
bool Rational::operator!=(const Rational& rhs) const { return (GetNum() != rhs.GetNum() || GetDen() != rhs.GetDen()); }
bool Rational::operator>=(const Rational& rhs) const { return (GetNum() * rhs.GetDen() >= rhs.GetNum() * GetDen()); }
bool Rational::operator<=(const Rational& rhs) const { return (GetNum() * rhs.GetDen() <= rhs.GetNum() * GetDen()); }
bool Rational::operator>(const Rational& rhs) const { return (GetNum() * rhs.GetDen() > rhs.GetNum() * GetDen()); }
bool Rational::operator<(const Rational& rhs) const { return (GetNum() * rhs.GetDen() < rhs.GetNum() * GetDen()); }


std::istream& Rational::read_from(std::istream& istrm) {
    int32_t numm = 0, denomm = 0;
    char c = 0;
    istrm >> numm >> c >> denomm;
    if (istrm.good()) {
        if (den_ == 0) {
            istrm.setstate(std::ios_base::failbit);
        }
        if (denomm < 0 || c != '/') {
            istrm.setstate(std::ios_base::failbit);
        } else {
            num_ = numm;
            den_ = denomm;
            normalize();
        }
    }
    return istrm;
}
inline std::ostream& Rational::write_to(std::ostream& ostrm) const {
    ostrm << GetNum() << delimiter_ << GetDen() << "\n";
    return ostrm;
}
std::ostream& operator<<(std::ostream& ostream, const Rational& rhs) {
    rhs.write_to(ostream);
    return ostream;
}
std::istream& operator>>(std::istream& istream, Rational& rhs) {
    rhs.read_from(istream);
    return istream;
}