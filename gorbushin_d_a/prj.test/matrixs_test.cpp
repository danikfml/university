#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "matrixs/matrixs.hpp"
#include "doctest/doctest.h"

TEST_CASE("Default constructor") {
    MatrixS m;
    CHECK(m.getRows() == 0);
    CHECK(m.getCols() == 0);
}

TEST_CASE("Constructor with dimensions") {
    MatrixS m(2, 3);
    CHECK(m.getRows() == 2);
    CHECK(m.getCols() == 3);
}

TEST_CASE("Copy constructor") {
    MatrixS m1(2, 3);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][0] = 4;
    m1[1][1] = 5;
    m1[1][2] = 6;

    MatrixS m2(m1);
    CHECK(m2.getRows() == 2);
    CHECK(m2.getCols() == 3);
    CHECK(m2[0][0] == 1);
    CHECK(m2[0][1] == 2);
    CHECK(m2[0][2] == 3);
    CHECK(m2[1][0] == 4);
    CHECK(m2[1][1] == 5);
    CHECK(m2[1][2] == 6);
}

TEST_CASE("Assignment operator") {
    MatrixS m1(2, 3);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][0] = 4;
    m1[1][1] = 5;
    m1[1][2] = 6;

    MatrixS m2;
    m2 = m1;
    CHECK(m2.getRows() == 2);
    CHECK(m2.getCols() == 3);
    CHECK(m2[0][0] == 1);
    CHECK(m2[0][1] == 2);
    CHECK(m2[0][2] == 3);
    CHECK(m2[1][0] == 4);
    CHECK(m2[1][1] == 5);
    CHECK(m2[1][2] == 6);
}

TEST_CASE("Element access") {
    MatrixS m(2, 3);
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[1][2] = 6;

    CHECK(m.at({0, 0}) == 1);
    CHECK(m.at({1, 2}) == 6);

    CHECK_THROWS(m.at({2, 0}));
    CHECK_THROWS(m.at({0, 3}));
}

TEST_CASE("Resize") {
    MatrixS m(2, 3);
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[1][2] = 6;

    m.resize({3, 2});
    CHECK(m.getRows() == 3);
    CHECK(m.getCols() == 2);
    CHECK(m.at({0, 0}) == 1);
    //CHECK(m.at({1, 2}) == 0);

    CHECK_THROWS(m.resize({-1, 2}));
    CHECK_THROWS(m.resize({3, -1}));
}

