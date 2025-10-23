#include <iomanip>
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int max_num = b * b;
    int digits = 0;

    while (max_num != 0) {
        digits++;
        max_num /= 10;
    }

    std::cout << std::setw(digits) << " ";
    for (int i = a; i <= b; i++) {
        std::cout << " | " << std::setw(digits) << i;
    }
    std::cout << std::endl;

    int columns = b - a + 2;
    int width = columns * digits + 3 * (columns - 1);

    for (int i = 1; i <= width; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;

    for (int i = a; i <= b; i++) {
        std::cout << std::setw(digits) << i;

        for (int j = a; j <= b; j++) {
            std::cout << " | " << std::setw(digits) << (i * j);
        }

        std::cout << std::endl;
    }

    return 0;
}
