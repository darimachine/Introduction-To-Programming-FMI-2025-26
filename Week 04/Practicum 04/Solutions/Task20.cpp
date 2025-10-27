#include <iostream>

int getDivision(int first, int second) {
    if (second == 0) {
        return 0; //Division by zero!
    }

    int quotient = 0;
    int sign = 1;

    if (first < 0) {
        first = -first;
        sign *= -1;
    }
    if (second < 0) {
        second = -second;
        sign *= -1;
    }
    
    while (first >= second) {
        first -= second;
        quotient++;
    }

    return quotient * sign;
}

int main()
{
    std::cout << getDivision(30, 7) << std::endl;
    std::cout << getDivision(-18, 3) << std::endl;
}

