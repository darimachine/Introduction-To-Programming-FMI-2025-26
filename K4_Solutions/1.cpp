
#include <iostream>
using std::cin;
using std::cout;


int getEncryptedTextLength(const char* str, int offset) {
    int counter = 0;

    while (*str) {
        if (*str == ' ') {
            counter++;
            str++;
            continue;
        }
        int letterIndex = *str - 'a' + 1;
        if (letterIndex % offset == 0) {
            counter++;
        }
        counter++;
        str++;
    }

    return counter;
}
char* encrypt(const char* str, int offset) {
    if (!str) {
        return nullptr;
    }

    if (offset == 0) {
        return nullptr;
    }

    if (offset < 0) {
        offset *= -1;
    }

    int length = getEncryptedTextLength(str, offset);
    char* result = new char[length + 1];

    int resultIndex = 0;
    int strIndex = 0;
    while (str[strIndex] != '\0') {

        if (str[strIndex] == ' ') {
            result[resultIndex++] = str[strIndex];
            strIndex++;
            continue;
        }
        int letterIndex = str[strIndex] - 'a' + 1;

        if (letterIndex % offset == 0) {
            result[resultIndex++] = str[strIndex];
            result[resultIndex++] = str[strIndex];
        }
        else {
            int realOffset = (letterIndex - 1 + offset) % 26;
            result[resultIndex++] = 'a' + realOffset;
        }

        strIndex++;
    }

    result[resultIndex] = '\0';

    return result;
}
int main()
{
    char buffer[1024];
    cin.getline(buffer, 1024);
    int offset;
    cin >> offset;

    char* result = encrypt(buffer, offset);
    cout << result;

    delete[] result;
}

