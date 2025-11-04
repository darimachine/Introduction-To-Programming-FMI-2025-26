#include <iostream>

unsigned int countDistinctPrimeFactors(unsigned int n) {
    unsigned int count = 0;
    double squareRoot = sqrt(n);

    for (int i = 2; i <= squareRoot; i++) {
        if (n % i == 0) {
            count++;

            while (n % i == 0) {
                n /= i; // remove all occurrences of this prime factor
            }
        }
    }

    if (n > 1) {
        count++; // n itself is a prime number greater than 1
    }

    return count;
}

void updateABWithKPrimeFactors(unsigned int& a, unsigned int& b, unsigned int k) {
    unsigned int minVal = 0, maxVal = 0;

    for (unsigned int i = a; i <= b; i++) {
        if (countDistinctPrimeFactors(i) == k) {
            if (minVal == 0) {
                minVal = i;
            }

            maxVal = i;
        }
    }

    if (minVal != 0) {
        a = minVal;
        b = maxVal;
    }
}

int main()
{
    unsigned int a, b, k;
    std::cin >> a >> b >> k;

    updateABWithKPrimeFactors(a, b, k);

    std::cout << a << " " << b << std::endl;
}

