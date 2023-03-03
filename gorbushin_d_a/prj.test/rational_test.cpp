#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <rational/rational.hpp>

TEST_CASE("testing the Rational arithmetic") {
    Rational first = Rational(4, 12);
    Rational second = Rational(1, 24);

    SUBCASE("Addition") {
        CHECK(first + second == Rational(9, 24));
        CHECK(++first == Rational(4, 3));
        CHECK(first++ == Rational(4, 3));
    }

    SUBCASE("Difference") {
        CHECK(first - second == Rational(7, 24));
        CHECK(--first == Rational(-2, 3));
        CHECK(first-- == Rational(-2, 3));
    }

    SUBCASE("Multiply") {
        CHECK(first * second == Rational(1, 72));
    }

    SUBCASE("Division") {
        CHECK(first / second == Rational(8, 1));
        CHECK_THROWS_AS(Rational(1, 0), const std::runtime_error);
        CHECK_THROWS_AS(first / Rational(0, 1), const std::runtime_error);

        Rational a = {5, -7};
        Rational b = {2, 3};
        b /= a;
        std::cout << b;
    }
}

TEST_CASE("testing comparison of rational") {
    Rational first = Rational(4, 12);
    Rational firstC = Rational(4, 12);
    Rational second = Rational(1, 24);

    SUBCASE("==") {
        CHECK_FALSE(first == second);
        CHECK(first != second);
        CHECK(first == firstC);
        CHECK_FALSE(first != firstC);
    }

    SUBCASE("<>") {
        CHECK(first > second);
        CHECK_FALSE(first > firstC);
        CHECK_FALSE(first < second);
    }

    SUBCASE("<>=") {
        CHECK(first >= second);
        CHECK(first >= firstC);
        CHECK_FALSE(first <= second);
    }
}