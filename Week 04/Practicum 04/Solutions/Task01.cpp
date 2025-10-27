#include <iostream>

int absoluteValue(int number) {
    return (number >= 0 ? number : -number);
}

int main()
{
    std::cout << absoluteValue(-12) << std::endl;
    std::cout << absoluteValue(8) << std::endl;
}

