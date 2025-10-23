#include <iostream>

int main() {
    int num;
    std::cin >> num;

    int result = 1;

    for (int i = 2; i <= num; i++) {
        result *= i;
    }

    std::cout << result << std::endl;

    return 0;
}
