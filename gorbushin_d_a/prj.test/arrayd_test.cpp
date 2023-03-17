#include <iostream>
#include "arrayd/arrayd.hpp"

int main()
{
    ArrayD arr1(3);
    arr1[0] = 1.1;
    arr1[1] = 2.2;
    arr1[2] = 3.3;

    ArrayD arr2 = arr1;
    arr2[0] = 4.4;

    std::cout << "arr1: ";
    for (int i = 0; i < arr1.ssize(); ++i)
        std::cout << arr1[i] << ' ';
    std::cout << std::endl;

    std::cout << "arr2: ";
    for (int i = 0; i < arr2.ssize(); ++i)
        std::cout << arr2[i] << ' ';
    std::cout << std::endl;

    arr1.insert(0.0, 0);
    arr1.remove(2);
    arr2.clear();

    std::cout << "arr1: ";
    for (int i = 0; i < arr1.ssize(); ++i)
        std::cout << arr1[i] << ' ';
    std::cout << std::endl;

    std::cout << "arr2: ";
    for (int i = 0; i < arr2.ssize(); ++i)
        std::cout << arr2[i] << ' ';
    std::cout << std::endl;

    arr1.resize(5);
    arr1[3] = 4.4;
    arr1[4] = 5.5;

    std::cout << "arr1: ";
    for (int i = 0; i < arr1.ssize(); ++i)
        std::cout << arr1[i] << ' ';
    std::cout << std::endl;

    return 0;
}
