#include <iostream>

int absoluteValue(int number) {
    return (number >= 0 ? number : -number);
}

int closestPowerOfTwo(int number) {
    int lower = 1;

    while (lower * 2 <= number) {
        lower *= 2;
    }

    int higher = lower * 2;

    if (std::abs(number - lower) <= absoluteValue(number - higher)) {
        return lower;
    }
    else {
        return higher;
    }
}

int main()
{
    int number;

    do {
        std::cout << "Enter a number between 100 and 100000: ";
        std::cin >> number;
    } while (number < 100 || number > 100000);

    std::cout << closestPowerOfTwo(number) << std::endl;
}

