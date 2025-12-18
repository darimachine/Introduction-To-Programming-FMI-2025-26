#include <iostream>

int **createMatrix(int rows, int cols);
void freeMatrix(int **matrix, int rows);

int **createMatrix(int rows, int cols) {
    int **matrix = new int *[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    return matrix;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main() {
    int rows = 2;
    int cols = 3;

    int **matrix = createMatrix(rows, cols);

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    // ...

    std::cout << matrix[0][1] << std::endl;

    freeMatrix(matrix, rows);

    return 0;
}
