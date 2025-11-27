#include <iostream>

// int array[] same as: int* array ("pointer to int")
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        // array[i] is the same as: *(array + i)
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

// int matrix[][3] is the same as: int (*matrix)[3] ("pointer to array of 3
// ints")
void printMatrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // matrix[i][j] is the same as: *(*(matrix + i) + j)
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

int main() {
    int arr[3] = {1, 2, 3};
    printArray(arr, 3);

    int num = 5;
    printArray(&num, 1);

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };

    // matrix decays to type "pointer to array of 3 ints"
    printMatrix(matrix, 2, 3);

    return 0;
}
