#include <iostream>

// McCarthy 91 function
int mccarthy(int n) {
    if (n > 100) {
        return n - 10;
    }

    return mccarthy(mccarthy(n + 11));
}

int main() {
    std::cout << mccarthy(95) << std::endl;

    return 0;
}
