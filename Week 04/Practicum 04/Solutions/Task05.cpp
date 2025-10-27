#include <iostream>

int power(int base, unsigned int exponent) {
    int result = 1;

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int main()
{
    std::cout<< power(5,2 ) << std::endl;
    std::cout << power(8, 0) << std::endl;
}
