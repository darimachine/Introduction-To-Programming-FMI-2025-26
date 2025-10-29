#include <iostream>

bool isPrime(int number);

bool isPrime(int number) {
    if (number % 2 == 0) {
        return false;
    }

    for (int i = 3; i * i < number; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int number;
    std::cin >> number;

    std::cout << std::boolalpha << isPrime(number) << std::endl;

    return 0;
}
