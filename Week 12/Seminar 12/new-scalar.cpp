#include <iostream>

int main() {
    int *dynamicNumber = new int;

    *dynamicNumber = 123;

    std::cout << *dynamicNumber << std::endl;

    delete dynamicNumber;

    // use-after-free
    // std::cout << *dynamicNumber << std::endl;

    // double-free
    // delete dynamicNumber;

    return 0;
}
