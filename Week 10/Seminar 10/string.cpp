#include <iostream>

int strlen(const char *str) {
    int size = 0;

    while (str[size] != '\0') {
        size++;
    }

    return size;
}

bool areStringsEqual(const char *str1, const char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }

        i++;
    }

    return (str1[i] == '\0' && str2[i] == '\0');
}

int main() {
    const char *stringLiteral = "test";

    char string[] = "test";
    string[0] = 'T';

    std::cout << stringLiteral << std::endl;
    std::cout << string << std::endl;
    std::cout << std::endl;

    std::cout << strlen("test") << std::endl;
    std::cout << std::endl;

    std::cout << std::boolalpha << areStringsEqual("test", "test") << std::endl;
    std::cout << std::boolalpha << areStringsEqual("abc", "def") << std::endl;
    std::cout << std::boolalpha << areStringsEqual("abc", "abcdef")
              << std::endl;

    return 0;
}
