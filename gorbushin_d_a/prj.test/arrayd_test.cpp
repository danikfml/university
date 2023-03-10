#include <iostream>
#include "arrayd/arrayd.hpp"

int main() {
    ArrayD my_array(10);

    for (int i = 0; i < 20; i++) {
        my_array.push_back(i);
    }

    for (int i = 0; i < 20; i++) {
        std::cout << my_array[i] << " ";
    }
    std::cout << std::endl;

    my_array.pop_back();

    for (int i = 0; i < my_array.get_size(); i++) {
        std::cout << my_array[i] << " ";
    }
    std::cout << std::endl;

    my_array.clear();

    std::cout << "Size: " << my_array.get_size() << std::endl;

    return 0;
}
