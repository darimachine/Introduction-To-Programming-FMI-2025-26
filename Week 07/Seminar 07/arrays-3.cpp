#include <iostream>

void inputArray(int array[], int size);
void printArray(int array[], int size);

void mergeSortedArrays(const int arr1[], const int arr2[], int merged[],
                       const int size1, const int size2, int &sizeMerged);

void inputArray(int array[], int size) {
    // O(n)

    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
}

void printArray(int array[], int size) {
    // O(n)

    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

void mergeSortedArrays(const int arr1[], const int arr2[], int merged[],
                       const int size1, const int size2, int &sizeMerged) {
    // O(n)

    sizeMerged = size1 + size2;

    int index1 = 0;
    int index2 = 0;
    int idxMerged = 0;

    while (idxMerged < sizeMerged && index1 < size1 && index2 < size2) {
        if (arr1[index1] < arr2[index2]) {
            merged[idxMerged] = arr1[index1];
            index1++;
        } else {
            merged[idxMerged] = arr2[index2];
            index2++;
        }

        idxMerged++;
    }

    while (index1 < size1) {
        merged[idxMerged] = arr1[index1];
        index1++;
        idxMerged++;
    }

    while (index2 < size2) {
        merged[idxMerged] = arr2[index2];
        index2++;
        idxMerged++;
    }
}

const int MAX_SIZE = 100;

int main() {
    int arr1[] = {1, 60};
    int arr2[] = {-5, 3, 5, 6};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int merged[MAX_SIZE] = {};
    int sizeMerged;

    mergeSortedArrays(arr1, arr2, merged, size1, size2, sizeMerged);

    printArray(arr1, size1);
    printArray(arr2, size2);
    printArray(merged, sizeMerged);
}
