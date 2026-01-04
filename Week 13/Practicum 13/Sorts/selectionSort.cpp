#include <iostream>

void myswap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int* arr, size_t size) {
    if (!arr) {
        return;
    }

    for (size_t i = 0; i < size; i++) {
        int minInd = i;

        for (size_t j = i + 1; j < size; j++) {
            if (arr[j] < arr[minInd]) {
                minInd = j;
            }
        }

        if (minInd != i) {
            myswap(arr[i], arr[minInd]);
        }
    }
}
