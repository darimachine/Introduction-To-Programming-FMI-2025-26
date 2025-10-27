#include <iostream>

int getLength(int number) {
    int count = 0;

    do {
        count++;
        number /= 10;
    } while (number != 0);

    return count;
}

int getDigitOnPosition(int number, unsigned int position) {
    int length = getLength(number);

    if (position == 0 || position > length) {
        return -1;
    }

    int digitsToRemove = length - position;

    while (digitsToRemove != 0) {
        number /= 10;
        digitsToRemove--;
    }

    int result = number % 10;
    return result;
}

int main()
{
    std::cout << getDigitOnPosition(6289, 3) << std::endl;
    std::cout << getDigitOnPosition(5, 2) << std::endl;
    std::cout << getDigitOnPosition(5000, 1) << std::endl;
}

