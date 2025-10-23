#include <iostream>

int main() {
    for (int i = 99; i >= 2; i--) {
        std::cout << i << " bottle" << (i == 1 ? "" : "s")
                  << " of beer on the wall, " << i << " bottle"
                  << (i == 1 ? "" : "s") << " of beer." << std::endl;
        std::cout << "Take one down and pass it around, " << (i - 1)
                  << " bottle" << ((i - 1) == 1 ? "" : "s")
                  << " of beer on the wall." << std::endl;
        std::cout << std::endl;
    }

    std::cout << "1 bottle of beer on the wall, 1 bottle of beer." << std::endl;
    std::cout << "Take one down and pass it around, no more bottles of beer on "
                 "the wall."
              << std::endl;
    std::cout << std::endl;

    std::cout << "No more bottles of beer on the wall, no more bottles of beer."
              << std::endl;
    std::cout
        << "Go to the store and buy some more, 99 bottles of beer on the wall."
        << std::endl;

    return 0;
}
