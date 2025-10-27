#include <iostream>

int squareRootToLower(int number) {
    if (number < 0) {
        return -1; 
    }

    int i = 0;
    while ((i + 1) * (i + 1) <= number) {
        i++;
    }

    return i;
}

int main()
{
    std::cout << squareRootToLower(24) << std::endl;
}

