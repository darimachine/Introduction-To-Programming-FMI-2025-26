#include <iostream>

const int ROWS = 4;
const int COLS = 3;

void printMatrix(int matrix[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

void printMatrixAlternating(int matrix[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i % 2 == 0) {
                std::cout << matrix[i][j] << " ";
            } else {
                std::cout << matrix[i][cols - 1 - j] << " ";
            }
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    printMatrix(matrix, ROWS, COLS);

    std::cout << std::endl;

    printMatrixAlternating(matrix, ROWS, COLS);

    return 0;
}
