#include <cstdlib>
#include <ctime>
#include <iostream>

int randomBetween(int min, int max);

int randomBetween(int min, int max) {
    return min + std::rand() % (max - min + 1);
}

int main() {
    std::srand(std::time(0));

    for (int i = 0; i < 10; i++) {
        std::cout << randomBetween(2, 11) << std::endl;
    }

    return 0;
}
