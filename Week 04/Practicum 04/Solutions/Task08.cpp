#include <iostream>

bool isPrime(unsigned int number) {
    if (number <= 1) {
        return false;
    }

    double squareRoot = sqrt(number);

    for (int i = 2; i <= squareRoot; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    std::cout << isPrime(21) << std::endl;
    std::cout << isPrime(7) << std::endl;
}
