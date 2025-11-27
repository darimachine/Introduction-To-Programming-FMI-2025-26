#include <iostream>

void swap(int *ptrToA, int *ptrToB) {
    int temp = *ptrToA;
    *ptrToA = *ptrToB;
    *ptrToB = temp;
}

int main() {
    int a = 2;
    int b = 3;

    swap(&a, &b);

    std::cout << a << " " << b << std::endl;

    return 0;
}
