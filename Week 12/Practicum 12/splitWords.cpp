#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool isLetter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

size_t getWordCount(const char* str) {
    size_t count = 0;
    while (*str) {
        if (isLetter(*str) && !isLetter(*(str + 1))) {
            count++;
        }
        str++;
    }

    return count;
}
void skipInvalid(const char*& str) {
    while (*str) {
        if (isLetter(*str)) {
            return;
        }
        str++;
    }
}
char* getNextWord(const char* &str) {
    int wordSize = 0;
    while (isLetter(str[wordSize])) {
        wordSize++;
    }
    char* word = new char[wordSize + 1];
    for (int i = 0; i < wordSize; i++)
    {
        word[i] = *str;
        str++;
    }
    word[wordSize] = '\0';
    return word;

}
char** splitToWords(const char* str, size_t& size) {
    if (str == nullptr) {
        return nullptr;
    }
    size = getWordCount(str);
    if (size == 0) {
        return nullptr;
    }
    char** result = new char* [size];

    int wordCount = 0;
    while (*str) {
        skipInvalid(str);
        if (!*str) {
            break;
        }
        char* currentWord = getNextWord(str);
        result[wordCount] = currentWord;
        wordCount++;

    }
    return result;


}
void printWords(const char* const * arr, size_t size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<endl;
    }
}
void free(char** arr, size_t size) {
    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
int main()
{
  
    size_t size = 0;
    char str[] = " !@  Hi :: Hello  my friend @! ";
    char** result =  splitToWords(str, size);
    printWords(result, size);

    free(result, size);
   
}