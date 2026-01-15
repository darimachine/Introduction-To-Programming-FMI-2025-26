#include <iostream>

enum class Color {
    red,
    green,
    blue
};

int main() {
    Color myFavoriteColor = Color::blue;

    // error:
    // std::cout << myFavoriteColor << std::endl;

    // error
    // int toIntImplicit = myFavoriteColor;

    int toIntExplicit = (int)myFavoriteColor;
    std::cout << toIntExplicit << std::endl;

    return 0;
}
