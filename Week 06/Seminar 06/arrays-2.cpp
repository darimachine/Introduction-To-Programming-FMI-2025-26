#include <iostream>

void inputArray(int array[], int size);
void printArray(int array[], int size);
void printArrayBackwards(int array[], int size);
void copyArray(int src[], int dest[], int size);
bool compareArrays(int arr1[], int arr2[], int size1, int size2);
void reverseArray(int arr[], int size);

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

void printArrayBackwards(int array[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

bool compareArrays(int arr1[], int arr2[], int size1, int size2) {
    if (size1 != size2) {
        return false;
    }

    for (int i = 0; i < size1; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        std::swap(arr[i], arr[size - i - 1]);
    }
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
    reverseArray(myArray, size);
    printArray(myArray, size);
}
