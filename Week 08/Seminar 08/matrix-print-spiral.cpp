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

void printMatrixSpiral(int matrix[][COLS], int rows, int cols) {
    int left = 0;
    int right = cols - 1;
    int top = 0;
    int bottom = rows - 1;

    while (left <= right && top <= bottom) {
        for (int j = left; j <= right; j++) {
            std::cout << matrix[top][j] << " ";
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            std::cout << matrix[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                std::cout << matrix[bottom][j] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                std::cout << matrix[i][left] << " ";
            }
            left++;
        }
    }

    std::cout << std::endl;
}

int main() {
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    printMatrix(matrix, ROWS, COLS);

    std::cout << std::endl;

    printMatrixSpiral(matrix, ROWS, COLS);

    return 0;
}
