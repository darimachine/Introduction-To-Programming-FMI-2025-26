#include <iostream>

int main() {
    char *dynamicString = new char[6];

    dynamicString[0] = 'h';
    dynamicString[1] = 'e';
    dynamicString[2] = 'l';
    dynamicString[3] = 'l';
    dynamicString[4] = 'o';
    dynamicString[5] = '\0';

    std::cout << dynamicString << std::endl;

    delete[] dynamicString;

    return 0;
}
