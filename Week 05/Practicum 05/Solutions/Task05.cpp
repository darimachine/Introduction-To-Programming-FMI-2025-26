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

int getDigit(int number, int k) {
    int length = getLength(number);
    if (length < k) {
        return -1;
    }

    int digitFromRight = length - k + 1;
    number /= pow(10, digitFromRight - 1);
    return number % 10;
}

int setDigit(int num, int k, int newDigit) {
    int length = getLength(num);
    int digitFromRight = length - k + 1;
    int pow10 = pow(10, digitFromRight - 1);
    int oldDigit = (num / pow10) % 10;

    return num - oldDigit * pow10 + newDigit * pow10;
}

void swapKthDigits(int& n, int& m, int k) {
    int digitN = getDigit(n, k);
    int digitM = getDigit(m, k);

    if (digitM == -1 || digitN == -1) {
        return;
    }

    n = setDigit(n, k, digitM);
    m = setDigit(m, k, digitN);
}

int main()
{
    int firstNum, secondNum, digitToSwap;
    std::cin >> firstNum >> secondNum >> digitToSwap;

    swapKthDigits(firstNum, secondNum, digitToSwap);
    std::cout << firstNum << " " << secondNum << std::endl;
}
