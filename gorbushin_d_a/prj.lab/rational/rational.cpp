#include <iostream>
#include <rational/rational.hpp>

Rational::Rational(int64_t num, int64_t denom) : num_(num), den_(denom) {
    if (denom == 0) {
        throw std::invalid_argument("Zero division");
    }
    if (num * denom < 0) {
        this->num_ = -std::abs(num);
        this->den_ = std::abs(denom);
    }
    normalize();
}

int64_t gcd(int64_t a, int64_t b) {
    if (a < b) {
        std::swap(a, b);
    }
    while (a % b != 0) {
        a = a % b;
        std::swap(a, b);
    }
    return b;
}

void Rational::normalize() {
    int64_t localGCD = den_;
    if (num_ != 0) {
        localGCD = gcd(num_, den_);
    }
    num_ /= localGCD;
    den_ /= localGCD;
}

Rational operator-(const Rational& r) {
    return {-r.num(), r.denom()};
}

Rational& Rational::operator+=(const Rational& r) {
    int64_t lmc = den_ * r.denom() / gcd(den_, r.denom());

    num_ *= lmc / den_;
    den_ *= lmc / den_;

    num_ += r.num() * lmc / r.denom();

    normalize();
    return *this;
}

Rational operator+(const Rational& l, const Rational& r) {
    Rational rational = l;
    rational += r;
    return rational;
}

Rational& Rational::operator-=(const Rational& r) {
    this->operator+=(-r);
    return *this;
}

Rational operator-(const Rational& l, const Rational& r) {
    Rational rational = l;
    rational -= r;
    return rational;
}

Rational& Rational::operator*=(const Rational& r) {
    this->num_ *= r.num();
    this->den_ *= r.denom();
    normalize();
    return *this;
}

Rational operator*(const Rational& l, const Rational& r) {
    Rational rational = l;
    rational *= r;
    return rational;
}

Rational& Rational::operator/=(const Rational& r) {
    if (r.num() == 0) {
        throw std::invalid_argument("Zero division");
    }

    this->num_ *= r.denom();
    this->den_ *= r.num();
    normalize();
    return *this;
}

Rational operator/(const Rational& l, const Rational& r) {
    Rational rational = l;
    rational /= r;
    return rational;
}

Rational& Rational::operator++() {
    this->operator+=(Rational(1, 1));
    return *this;
}

Rational Rational::operator++(int) {
    Rational temp(*this);
    ++*this;
    return temp;
}

Rational& Rational::operator--() {
    this->operator-=(Rational(1, 1));
    return *this;
}

Rational Rational::operator--(int) {
    Rational temp(*this);
    --*this;
    return temp;
}

bool Rational::operator==(const Rational& r) const {
    return this->num() == r.num() && this->denom() == r.denom();
}

bool Rational::operator!=(const Rational& r) const {
    return !operator==(r);
}

bool Rational::operator>(const Rational& r) const {
    return (this->num() / (double) this->denom()) > (r.num() / (double) r.denom());
}

bool Rational::operator<(const Rational& r) const {
    return !(operator>(r) || operator==(r));
}

bool Rational::operator>=(const Rational& r) const {
    return !operator<(r);
}

bool Rational::operator<=(const Rational& r) const {
    return !operator>(r);
}

std::istream& Rational::read_from(std::istream& istream) {
    int64_t numI = 0;
    int64_t denomI = 0;
    char separator = 0;
    istream >> numI >> separator >> denomI;
    if (istream.good()) {
        if (den_ == 0) {
            istream.setstate(std::ios_base::failbit);
        }
        if (denomI < 0 || separator != '/') {
            istream.setstate(std::ios_base::failbit);
        } else {
            num_ = numI;
            den_ = denomI;
            normalize();
        }
    }
    return istream;
}

inline std::ostream& Rational::write_to(std::ostream& ostream) const {
    ostream << num() << '/' << denom() << "\n";
    return ostream;
}

std::ostream& operator<<(std::ostream& ostream, const Rational& r) {
    r.write_to(ostream);
    return ostream;
}

std::istream& operator>>(std::istream& istream, Rational& r) {
    r.read_from(istream);
    return istream;
}
