#include <iostream>

int strlen(const char *str);

const int MAX_SIZE = 1024;

int main() {
    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);

    std::cout << "strlen(str) = " << strlen(str) << std::endl;
    std::cout << "str = " << str << std::endl;

    return 0;
}

int strlen(const char *str) {
    int size = 0;

    while (str[size] != '\0') {
        size++;
    }

    return size;
}
