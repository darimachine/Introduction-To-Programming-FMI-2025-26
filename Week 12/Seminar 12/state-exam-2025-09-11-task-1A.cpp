#include <iostream>

bool resize(int *&arr, size_t size, size_t new_size);

void printArray(int *arr, int size);

bool resize(int *&arr, size_t size, size_t new_size) {
    if (size == new_size) {
        return true;
    }

    if (new_size == 0) {
        delete[] arr;
        arr = nullptr;

        return true;
    }

    int *new_arr = new int[new_size];

    for (size_t i = 0; i < std::min(size, new_size); i++) {
        new_arr[i] = arr[i];
    }

    delete[] arr;

    arr = new_arr;

    return true;
}

int main() {
    int old_size = 2;
    int new_size = 3;

    int *arr = new int[old_size];
    arr[0] = 123;
    arr[1] = 456;

    resize(arr, old_size, new_size);

    arr[2] = 789;

    printArray(arr, new_size);

    delete[] arr;

    return 0;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
