#include <iostream>

int getCountOfADigit(int number, int digit) {
    int count = 0;

    while (number != 0) {
        int lastDigit = number % 10;
        number /= 10;

        if (digit == lastDigit) {
            count++;
        }
    }

    return count;
}

unsigned int sortDigits(unsigned int number) {
    int result = 0;

    for (int i = 1; i <= 9; i++) {
        int count = getCountOfADigit(number, i);

        while (count--) {
            result *= 10;
            result += i;
        }
    }

    return result;
}

int main()
{
    std::cout << sortDigits(1234) << std::endl;
    std::cout << sortDigits(1000) << std::endl;
    std::cout << sortDigits(6592) << std::endl;
}
