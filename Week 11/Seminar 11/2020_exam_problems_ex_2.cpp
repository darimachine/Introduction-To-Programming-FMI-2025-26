#include <iostream>

void swap(char &a, char &b);
int strlen(const char *str);

void revandreplace(char *str);

void revandreplace(char *str) {
    if (str == nullptr) {
        return;
    }

    int size = strlen(str);

    for (int i = 0; i < size / 2; i++) {
        swap(str[i], str[size - i - 1]);
    }

    for (int i = 0; i < size; i++) {
        if (str[i] == 'e') {
            str[i] = '!';
        }

        if (str[i] == 'y') {
            str[i] = '*';
        }
    }
}

int main() {
    char str[] = "I left you alone";

    revandreplace(str);

    std::cout << str << std::endl;

    return 0;
}

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

int strlen(const char *str) {
    int size = 0;

    while (str[size] != '\0') {
        size++;
    }

    return size;
}
