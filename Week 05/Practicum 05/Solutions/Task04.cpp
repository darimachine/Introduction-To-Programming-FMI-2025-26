#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void simplify(int& numerator, int& denominator) {
    int GCD = gcd((numerator), (denominator));
    numerator /= GCD;
    denominator /= GCD;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

void addFractions(int numerator1, int denominator1, int numerator2, int denominator2, int& resultNumerator, int& resultDenominator) {
    resultNumerator = numerator1 * denominator2 + numerator2 * denominator1;
    resultDenominator = denominator1 * denominator2;

    simplify(resultNumerator, resultDenominator);
}

int main()
{
    int numerator1, denominator1, numerator2, denominator2;
    std::cin >> numerator1 >> denominator1 >> numerator2 >> denominator2;

    int resultNumerator, resultDenominator;
    addFractions(numerator1, denominator1, numerator2, denominator2, resultNumerator, resultDenominator);

    std::cout << resultNumerator << " " << resultDenominator << std::endl;
    return 0;
}
