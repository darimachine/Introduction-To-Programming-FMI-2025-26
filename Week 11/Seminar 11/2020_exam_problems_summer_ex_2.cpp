#include <iostream>

void numOfWords(const char *str);

bool isWhitespace(char c);

bool isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void numOfWords(const char *str) {
    if (str == nullptr) {
        return;
    }

    int totalWords[2] = {0, 0};

    int currentWordStart = -1;
    int currentWordLength = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isWhitespace(str[i])) {
            if (currentWordStart != -1) {
                totalWords[currentWordLength % 2]++;
            }

            currentWordStart = -1;
            currentWordLength = 0;
        } else {
            if (currentWordStart == -1) {
                currentWordStart = i;
            }

            currentWordLength++;
        }
    }

    if (currentWordStart != -1) {
        totalWords[currentWordLength % 2]++;
    }

    std::cout << "totalWords[0] = (even) = " << totalWords[0] << std::endl;
    std::cout << "totalWords[1] = (odd) = " << totalWords[1] << std::endl;
}

int main() {
    const char *str = " This is an example string ";

    std::cout << str << std::endl;

    numOfWords(str);

    return 0;
}
