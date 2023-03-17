#include "rational/rational.hpp"

Rational::Rational(int32_t num, int32_t denom) : num_(num), denom_(denom) {
    normalize();
}

Rational::Rational(int32_t num) : Rational(num, 1) {}

Rational::Rational() : num_(0), denom_(1) {}

Rational::Rational(const Rational& other) : num_(other.num_), denom_(other.denom_) {}

Rational& Rational::operator=(const Rational& other) {
    if (this != &other) {
        num_ = other.num_;
        denom_ = other.denom_;
    }
    return *this;
}

Rational::~Rational() {}

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

void Rational::normalize() {
    int32_t localGCD = denom_;
    if (num_ != 0) {
        localGCD = gcd(std::abs(num_), denom_);
    }
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
    return operator+=(Rational(-r.num(), r.denom()));
}

Rational& Rational::operator*=(const Rational& r) {
    num_ *= r.num();
    denom_ *= r.denom();
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& r) {
    num_ *= r.denom();
    denom_ *= r.num();
    normalize();
    return *this;
}

Rational &Rational::operator++() {
    return operator+=(Rational(1));
}

Rational Rational::operator++(int) {
    Rational temp(*this);
    operator++();
    return temp;
}

Rational &Rational::operator--() {
    return operator-=(Rational(1));
}

Rational Rational::operator--(int) {
    Rational temp(*this);
    operator--();
    return temp;
}

bool Rational::operator==(const Rational& r) const {
    return num_ == r.num() && denom_ == r.denom();
}

bool Rational::operator!=(const Rational& r) const {
    return !operator==(r);
}

bool Rational::operator>(const Rational& r) const {
    return static_cast<double>(num_) / denom_ > static_cast<double>(r.num()) / r.denom();
}

bool Rational::operator<(const Rational& r) const {
    return static_cast<double>(num_) / denom_ < static_cast<double>(r.num()) / r.denom();
}

bool Rational::operator>=(const Rational& r) const {
    return !operator<(r);
}

bool Rational::operator<=(const Rational& r) const {
    return !operator>(r);
}

std::istream& Rational::read_from(std::istream& istream) {
    int32_t numI = 0;
    int32_t denomI = 0;
    char separator = 0;

    // Skip whitespace (including newlines) before the rational number
    while(std::isspace(istream.peek())) {
        istream.ignore(1);
    }

    istream >> numI >> separator >> denomI;
    if (istream.good()) {
        if (denomI == 0 || separator != '/') {
            istream.setstate(std::ios_base::failbit);
        } else {
            num_ = numI;
            denom_ = denomI;
            normalize();
        }
    }
    return istream;
}

std::ostream& Rational::write_to(std::ostream& ostream) const {
    ostream << num() << '/' << denom();
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

std::ostream& operator<<(std::ostream& ostream, const Rational& r) {
    r.write_to(ostream);
    return ostream;
}

std::istream& operator>>(std::istream& istream, Rational& r) {
    r.read_from(istream);
    return istream;
}
