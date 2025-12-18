#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = 123;
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }

    delete[] arr;

    return 0;
}
