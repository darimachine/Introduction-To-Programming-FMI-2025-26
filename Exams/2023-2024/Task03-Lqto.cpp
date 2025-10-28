#include <iostream>

// Връща 10^e
int power10(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= 10;
    }
    return result;
}

// Брои цифрите на положително число
int countDigits(long number) {
    int count = 0;
    while (number > 0) {
        count++;
        number /= 10;
    }
    return count;
}

// Обръща числото: 12345 -> 54321
long reverseNumber(long number) {
    long reversed = 0;
    while (number > 0) {
		    int lastDigit = number%10;
        reversed = reversed * 10 + lastDigit;
        number /= 10;
    }
    return reversed;
}

// Сглобява първия прозорец от n цифри (четем от rev, което носи цифрите в правилен ред)
int buildInitialWindow(long& reversed, int windowSize) {
    int windowValue = 0;
    for (int i = 0; i < windowSize; ++i) {
        int nextDigit = reversed % 10;
        reversed /= 10;
        windowValue = windowValue * 10 + nextDigit;
    }
    return windowValue;
}
// 12345 -> 54321 = 123 = 23*10 + 4 = 234
// Плъзга прозореца: маха най-лявата цифра и добавя новата
int slideWindow(int currentWindow, int cutPower, int newDigit) {
    
    int removedLeftDigit = currentWindow % cutPower;
    return removedLeftDigit * 10 + newDigit;
}

// Главна функция: най-голямото число от n последователни цифри в N
int Find(long N, int n) {
    // Валидации по условие
    if (N <= 0 || n <= 0 || n >= 8) return -1;

    int totalDigits = countDigits(N);
    if (n > totalDigits) return -1;

    // Обръщаме, за да четем цифрите на N отляво надясно чрез %10
    long reversed = reverseNumber(N);

    // Първи прозорец
    int windowValue = buildInitialWindow(reversed, n);
    int bestValue = windowValue;

    // Подготовка за плъзгане
    int cutPower = power10(n - 1); // 10^(n-1)

    // Плъзгаме прозореца през останалите цифри
    for (int i = n; i < totalDigits; i++) {
        int nextDigit = reversed % 10;
        reversed /= 10;

        windowValue = slideWindow(windowValue, cutPower, nextDigit);
        if (windowValue > bestValue) bestValue = windowValue;
    }

    return bestValue;
}

// Демонстрация
int main() {
    std::cout << Find(225, 1) << "\n";      // 5
    std::cout << Find(225, 2) << "\n";      // 25
    std::cout << Find(225, 3) << "\n";      // 225
    std::cout << Find(987654, 3) << "\n";   // 987
    std::cout << Find(101209, 2) << "\n";   // 20
    std::cout << Find(7, 2) << "\n";        // -1
    return 0;
}
