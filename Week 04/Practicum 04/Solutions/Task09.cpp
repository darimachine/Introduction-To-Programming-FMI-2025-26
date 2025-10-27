#include <iostream>

int getLength(int number) {
    int count = 0;

    do {
        count++;
        number /= 10;
    } while (number != 0);

    return count;
}

int main()
{
    std::cout << getLength(123) << std::endl;
    std::cout << getLength(0) << std::endl;
}
