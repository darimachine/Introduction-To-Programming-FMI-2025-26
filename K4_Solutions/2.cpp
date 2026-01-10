#include <iostream>

constexpr int TOTAL_ASCII_SYMBOLS = 256;

size_t my_strlen(const char* str)
{
    if (str == nullptr)
        return 0;

    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

char* extractDuplicates(const char* str)
{

    size_t length = my_strlen(str);
    if (length == 0)
    {
        char* empty = new char[1];
        empty[0] = '\0';
        return empty;
    }

    unsigned short seen[TOTAL_ASCII_SYMBOLS] = {};
    for (size_t i = 0; i < length; i++)
    {
        seen[str[i]]++;
    }

    size_t count = 0;
    for (size_t i = 0; i < TOTAL_ASCII_SYMBOLS; i++)
    {
        if (seen[i] > 1)
            count++;
    }

    char* result = new char[count + 1];

    size_t index = 0;
    for (size_t i = 0; i < TOTAL_ASCII_SYMBOLS; i++)
    {
        if (seen[i] > 1)
        {
            result[index++] = i;
        }
    }
    result[index] = '\0';

    return result;
}

int main()
{

    constexpr int BUFFER_SIZE = 1024;
    char input[BUFFER_SIZE];
    std::cin.getline(input, BUFFER_SIZE);

    char* output = extractDuplicates(input);
    std::cout << output;

    delete[] output;

    return 0;
}