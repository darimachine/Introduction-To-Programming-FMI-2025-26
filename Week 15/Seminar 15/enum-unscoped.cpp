#include <iostream>

enum Color {
    red,
    green,
    blue
};

int main() {
    Color myFavoriteColor = blue;

    std::cout << myFavoriteColor << std::endl;

    int toIntImplicit = myFavoriteColor;
    std::cout << toIntImplicit << std::endl;

    int toIntExplicit = (int)myFavoriteColor;
    std::cout << toIntExplicit << std::endl;

    return 0;
}
