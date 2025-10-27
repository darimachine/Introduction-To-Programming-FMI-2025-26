#include <iostream>

bool isDivisableByValue(int number, int divisor) {
    if (divisor == 0) {
        return false; 
    }

    return number == (divisor * (number / divisor));
}

int main()
{
    std::cout << isDivisableByValue(6, 3) << std::endl;
    std::cout << isDivisableByValue(14, 5) << std::endl;
}

