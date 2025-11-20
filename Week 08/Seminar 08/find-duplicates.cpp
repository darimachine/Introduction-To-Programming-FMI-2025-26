#include <iostream>

const int MAX_SIZE = 100;

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

void findDuplicates(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                std::cout << "Duplicate: " << arr[i] << " at indexes " << i
                          << ", " << j << std::endl;
            }
        }
    }
}

int main() {
    // int arr[] = {3, 5, 8, 2, 5, 0, 1};
    // int size = sizeof(arr) / sizeof(arr[0]);

    int arr[MAX_SIZE];
    int size;

    std::cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        std::cout << "Size is too big" << std::endl;
        return 1;
    }

    inputArray(arr, size);

    findDuplicates(arr, size);

    return 0;
}
