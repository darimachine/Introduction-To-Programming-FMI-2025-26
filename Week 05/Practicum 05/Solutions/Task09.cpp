#include <iostream>

int pow(int base, unsigned int exponent) {
    int result = 1;

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int getLength(int number) {
    int count = 0;

    do {
        count++;
        number /= 10;
    } while (number != 0);

    return count;
}

void digitTransfer(int& first, int& second, int k) {
    if (k > getLength(first)) {
        return;
    }

    int pow10k = pow(10, k);
    int lastKDigits = first % pow10k;
    first /= pow10k;

    int secondLength = getLength(second);
    second = lastKDigits * pow(10, secondLength) + second;
}

int main()
{
    int first, second, k;
    std::cin >> first >> second >> k;

    if (k > getLength(first)) {
        std::cout << "Error: k is larger than the number of digits in a" << std::endl;
        return 0;
    }

    digitTransfer(first, second, k);
    std::cout << first << " " << second << std::endl;
}

