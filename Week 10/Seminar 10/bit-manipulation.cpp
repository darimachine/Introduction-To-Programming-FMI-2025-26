#include <iomanip>
#include <iostream>

bool testBit(unsigned int num, unsigned int bit);
unsigned int setBit(unsigned int num, unsigned int bit);
unsigned int clearBit(unsigned int num, unsigned int bit);
unsigned int flipBit(unsigned int num, unsigned int bit);
unsigned int extractBits(unsigned int num, unsigned int fromBit,
                         unsigned int toBit);

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

const int STR_WIDTH = 22;
const int NUM_WIDTH = 5;

void printResult(const char *str, unsigned int num) {
    char binary[8 * sizeof(num) + 1];
    int firstNonZero = convertToBinary(num, binary);

    std::cout << std::setw(STR_WIDTH) << str << " = " << std::setw(NUM_WIDTH)
              << num << " = 0b" << binary << " = 0b" << (binary + firstNonZero)
              << std::endl;
}

void printBoolResult(const char *str, bool result) {
    std::cout << std::setw(STR_WIDTH) << str << " = " << std::setw(NUM_WIDTH)
              << std::boolalpha << result << std::endl;
}

bool testBit(unsigned int num, unsigned int bit) {
    return (num & (1 << bit)) != 0;
}

unsigned int setBit(unsigned int num, unsigned int bit) {
    return num | (1 << bit);
}

unsigned int clearBit(unsigned int num, unsigned int bit) {
    return num & ~(1 << bit);
}

unsigned int flipBit(unsigned int num, unsigned int bit) {
    return num | (1 << bit);
}

unsigned int extractBits(unsigned int num, unsigned int fromBit,
                         unsigned int toBit) {
    int mask = 0;

    for (unsigned int bit = fromBit; bit <= toBit; bit++) {
        mask = setBit(mask, bit);
    }

    return (num & mask) >> (toBit - fromBit + 1);
}

int main() {
    unsigned int num = 0b01101110;

    printResult("num", num);
    std::cout << std::endl;

    printBoolResult("testBit(num, 3)", testBit(num, 3));
    printBoolResult("testBit(num, 4)", testBit(num, 4));
    std::cout << std::endl;

    printResult("setBit(num, 3)", setBit(num, 3));
    printResult("setBit(num, 4)", setBit(num, 4));
    std::cout << std::endl;

    printResult("clearBit(num, 3)", clearBit(num, 3));
    printResult("clearBit(num, 4)", clearBit(num, 4));
    std::cout << std::endl;

    printResult("flipBit(num, 3)", flipBit(num, 3));
    printResult("flipBit(num, 4)", flipBit(num, 4));
    std::cout << std::endl;

    printResult("extractBits(num, 3, 4)", extractBits(num, 3, 4));
    std::cout << std::endl;

    return 0;
}
