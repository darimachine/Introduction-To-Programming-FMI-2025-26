#include <iostream>

void primeFactorization(int number) {
    if (number < 2) {
        std::cout << number << std::endl;
        return;
    }

    bool first = true; // Flag to avoid printing "." before the first factor

    while (number % 2 == 0) {
        if (!first) std::cout << ".";
        std::cout << 2;
        first = false;
        number /= 2;
    }

    double SquareRoot = sqrt(number);
    // Divide by odd numbers from 3 up to the square root
    for (int i = 3; i <= SquareRoot; i += 2) {
        while (number % i == 0) {
            if (!first) std::cout << ".";
            std::cout << i;
            first = false;
            number /= i;
        }
    }

    // If number > 1, it is a prime factor itself
    if (number > 1) {
        if (!first) std::cout << ".";
        std::cout << number;
    }

    std::cout << std::endl;
}

int main()
{
    primeFactorization(225); //3.3.5.5
    primeFactorization(100); //2.2.5.5
}
