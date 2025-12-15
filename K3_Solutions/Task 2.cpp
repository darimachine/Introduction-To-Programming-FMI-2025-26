#include <cstdint>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

constexpr int TOTAL_DIGITS = 20;
int countDigitsAndPopulateArray(long long N, int* digits) {
    if (!digits) {
        return -1;
    }

    int size = 0;
    
    while (N > 0) {
        digits[size++] = N % 10;
        N /= 10;
    }

    return size;
}

uint8_t markRemainders(const int* digits, int size, int K) {
    if (!digits) {
        return 0;
    }

    uint8_t seen=0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j) { 
                continue;
            }

            int currentNum = 10 * digits[i] + digits[j];
            
            if (currentNum < 10 || currentNum>99) {
                continue;
            }

            int remainder = currentNum % K;
            
            if (remainder != 0) {
                seen |= 1 << (remainder - 1);
            }
        }
    }

    return seen;
}
void printRemainders(uint8_t seen, int K) {
    for (int i = 0; i < K-1; i++)
    {
        if (seen & (1 << i)) {
            cout << i + 1 << " ";
        }
    }
}

int main() {
    long long N;
    cin >> N;

    int K;
    cin >> K;
    if (K < 2 || K>9) {
        return -1;
    }

    int digits[TOTAL_DIGITS]{};
    int numberLength = countDigitsAndPopulateArray(N, digits);
    
    uint8_t seen = markRemainders(digits, numberLength, K);

    printRemainders(seen, K);

}
