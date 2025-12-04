#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>

void printFloat(float num) {
    if (num > 1000000) {
        std::cout << std::setprecision(50);
    } else {
        std::cout << std::setprecision(7);
    }

    std::cout << num;
}

bool isWhole(float num) { return std::floor(num) == num; }

void printRange(float start, float critical, float end, float interval) {
    bool shownCritical = false;

    float num = start;

    for (int i = 0; num <= end; i++) {
        float offset = i * interval;

        num = start + offset;

        printFloat(start);
        std::cout << " + ";
        printFloat(offset);
        std::cout << " = ";
        printFloat(num);

        if (!shownCritical && num == critical && isWhole(offset)) {
            std::cout << "          <---------------";
            shownCritical = true;
        }

        std::cout << std::endl;
    }
}

int main() {
    std::cout << "After 2^21 = 2097152: floats are 0.25 apart" << std::endl;
    printRange(2097151.0, 2097152.0, 2097154.0, 0.1);
    std::cout << std::endl;

    std::cout << "After 2^22 = 4194304: floats are 0.5 apart" << std::endl;
    printRange(4194303.0, 4194304.0, 4194306.0, 0.1);
    std::cout << std::endl;

    std::cout << "After 2^23 = 8388608: floats are 1 apart (only whole numbers)"
              << std::endl;
    printRange(8388606.0, 8388608.0, 8388610.0, 0.25);
    std::cout << std::endl;

    std::cout << "After 2^24 = 16777216: floats are 2 apart (only even numbers)"
              << std::endl;
    printRange(16777210.0, 16777216.0, 16777220.0, 1.0);
    std::cout << std::endl;

    std::cout << "Note: float uses a 24-bit mantissa" << std::endl;
    std::cout << "=> 2^24 - 1 = 16777215 - max safe integer for float"
              << std::endl;
    std::cout << std::endl;

    std::cout << "After 2^25 = 33554432: floats are 4 apart (only numbers "
                 "divisible by 4)"
              << std::endl;
    printRange(33554428.0, 33554432.0, 33554436.0, 1.0);
    std::cout << std::endl;

    std::cout << "Note: float uses a 7-bit exponent" << std::endl;
    std::cout << "Maximum float value: close to 2^(2^7) = 2^128:" << std::endl;
    std::cout << "FLT_MAX = ";
    printFloat(FLT_MAX);
    std::cout << std::endl;
    std::cout << "2 * FLT_MAX = ";
    printFloat(2 * FLT_MAX);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Note: double uses a 53-bit mantissa" << std::endl;
    std::cout << "=> 2^53 - 1 = 9007199254740991 - max safe integer for double"
              << std::endl;
    std::cout << std::endl;

    std::cout << "Note: double uses a 10-bit exponent" << std::endl;
    std::cout << "Maximum double value: close to 2^(2^10) = 2^1024"
              << std::endl;
    std::cout << "DBL_MAX = " << DBL_MAX << std::endl;

    return 0;
}
