#include <iostream>

void GetWord(const char *str);

bool isWhitespace(char c);

bool isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void GetWord(const char *str) {
    if (str == nullptr) {
        return;
    }

    int wordsWithA = 0;
    int totalWords = 0;

    int currentWordStart = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isWhitespace(str[i])) {
            currentWordStart = -1;
        } else {
            if (currentWordStart == -1) {
                currentWordStart = i;

                totalWords++;

                if (str[i] == 'a') {
                    wordsWithA++;
                }
            }
        }
    }

    std::cout << "wordsWithA = " << wordsWithA << std::endl;
    std::cout << "totalWords = " << totalWords << std::endl;
}

int main() {
    const char *str = " It took      about      an hour to                  "
                      "answer all the questions.               ";

    std::cout << str << std::endl;

    GetWord(str);

    return 0;
}
