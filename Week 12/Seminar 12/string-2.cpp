#include <iostream>

char *repeat(char c, int times);

char *repeat(char c, int times) {
    char *str = new char[times + 1];

    for (int i = 0; i < times; i++) {
        str[i] = c;
    }
    str[times] = '\0';

    return str;
}

int main() {
    int n;
    std::cin >> n;

    char *dynamicString = repeat('*', n);

    std::cout << dynamicString << std::endl;

    delete[] dynamicString;

    return 0;
}
