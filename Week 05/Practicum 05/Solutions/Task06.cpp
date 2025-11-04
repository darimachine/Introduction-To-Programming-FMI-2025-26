#include <iostream>

void reverseNum(int& num) {
    int result = 0;

    while (num != 0) {
        int lastDigit = num % 10;
        num /= 10;
        result = result * 10 + lastDigit;
    }

    num = result;
}

int getLength(int num) {
    int count = 0;

    do {
        count++;
        num /= 10;
    } while (num != 0);

    return count;
}

void evenAndOdd(int num, int& even, int& odd) {
    reverseNum(num);
    int length = getLength(num);
    even = 0;
    odd = 0;

    for (int i = 1; i <= length; i++) {
        int lastDigit = num % 10;
        num /= 10;

        if (i % 2 == 0) {
            even = even * 10 + lastDigit;
        }
        else {
            odd = odd * 10 + lastDigit;
        }
    }

}

int main() {
    int num;
    std::cin >> num;

    int even = 0;
    int odd = 0;
    evenAndOdd(num, even, odd);
    std::cout << even << " " << odd << std::endl;
}
