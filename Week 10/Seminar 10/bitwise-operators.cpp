#include <iomanip>
#include <iostream>

int convertToBinary(unsigned int num, char *result);
void printResult(const char *str, unsigned int num);

int main() {
    unsigned int a = 123;
    unsigned int b = 456;

    printResult("a", a);
    printResult("b", b);
    std::cout << std::endl;

    printResult("a & b", a & b);
    printResult("a | b", a | b);
    printResult("a ^ b", a ^ b);
    std::cout << std::endl;

    printResult("~a", ~a);
    printResult("a ^ 0xFFFFFFFF", a ^ 0xFFFFFFFF);
    std::cout << std::endl;

    printResult("a << 1", a << 1);
    printResult("a << 2", a << 2);
    printResult("a << 3", a << 3);
    printResult("a << 4", a << 4);
    std::cout << std::endl;

    printResult("a >> 1", a >> 1);
    printResult("a >> 2", a >> 2);
    printResult("a >> 3", a >> 3);
    printResult("a >> 4", a >> 4);
    std::cout << std::endl;

    return 0;
}

int convertToBinary(unsigned int num, char *result) {
    const int bits = 8 * sizeof(num);

    int firstNonZero = -1;

    for (int i = 8 * sizeof(num); i >= 0; i--) {
        int bit = num & (1 << i);

        result[bits - i - 1] = (bit == 0) ? '0' : '1';

        if (firstNonZero == -1 && bit != 0) {
            firstNonZero = bits - i - 1;
        }
    }

    result[bits] = '\0';

    if (firstNonZero == -1) {
        firstNonZero = bits - 1;
    }

    return firstNonZero;
}

const int STR_WIDTH = 16;
const int NUM_WIDTH = 10;

void printResult(const char *str, unsigned int num) {
    char binary[8 * sizeof(num) + 1];
    int firstNonZero = convertToBinary(num, binary);

    std::cout << std::setw(STR_WIDTH) << str << " = " << std::setw(NUM_WIDTH)
              << num << " = 0b" << binary << " = 0b" << (binary + firstNonZero)
              << std::endl;
}
