#include <iostream>

void insertionSort(int* arr, size_t size) {
    if (!arr) {
        return;
    }

    for (size_t i = 1; i < size; i++) {
        int currentEl = arr[i];
        int currentInd = i - 1;

        while (currentInd >= 0 && currentEl < arr[currentInd]) {
            arr[currentInd + 1] = arr[currentInd];
            currentInd--;
        }

        arr[currentInd + 1] = currentEl;
    }
}
