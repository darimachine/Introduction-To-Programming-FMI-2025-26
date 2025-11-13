#include <iostream>

void inputArray(int array[], int size);
void printArray(int array[], int size);

void inputArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

const int MAX_SIZE = 100;

int main() {
    int size;
    std::cin >> size;

    if (size > MAX_SIZE) {
        std::cout << "Size is too large" << std::endl;
        return 1;
    }

    int myArray[MAX_SIZE];

    inputArray(myArray, size);
    printArray(myArray, size);
}
