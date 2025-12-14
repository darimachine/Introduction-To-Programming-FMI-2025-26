#include <iostream>

void processAllWords(const char *str);

bool isWhitespace(char c);
void processWord(const char *str, int start, int length);

bool isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void processWord(const char *str, int start, int length) {
    std::cout << "word at " << start << "; length: " << length << std::endl;
}

void processAllWords(const char *str) {
    if (str == nullptr) {
        return;
    }

    int totalWords = 0;

    int currentWordStart = -1;
    int currentWordLength = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isWhitespace(str[i])) {
            if (currentWordStart != -1) {
                processWord(str, currentWordStart, currentWordLength);
            }

            currentWordStart = -1;
            currentWordLength = 0;
        } else {
            if (currentWordStart == -1) {
                currentWordStart = i;
                totalWords++;
            }

            currentWordLength++;
        }
    }

    if (currentWordStart != -1) {
        processWord(str, currentWordStart, currentWordLength);
    }

    std::cout << "totalWords = " << totalWords << std::endl;
}

int main() {
    char str[] = " use  \t some  silly  string for   testing";

    std::cout << str << std::endl;

    processAllWords(str);

    return 0;
}
