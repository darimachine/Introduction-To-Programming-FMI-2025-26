#include <iostream>

int getLength(unsigned int number) {
    int count = 0;

    do {
        count++;
        number /= 10;
    } while (number != 0);

    return count;
}

int power(int base, unsigned int exponent) {
    int result = 1;

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

unsigned int concat(unsigned int first, unsigned int second) {
    int lengthSecond = getLength(second);
    int multy = power(10, lengthSecond);
    first *= multy;

    first += second;
    return first;
}

int main()
{
    std::cout << concat(123, 456) << std::endl;
    std::cout << concat(0, 45) << std::endl;
    std::cout << concat(5, 0) << std::endl;
}

