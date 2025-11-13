#include <iostream>

const int MAX_SIZE = 50;

void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[][MAX_SIZE], int rows, int cols);

void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    // O(n^2)

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    // O(n^2)

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

void transposeMatrix(const int matrix[][MAX_SIZE], int transposed[][MAX_SIZE],
                     const int rows, const int cols) {
    // O(n^2)

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE] = {};

    int rows;
    std::cin >> rows;

    int cols;
    std::cin >> cols;

    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    int transposed[MAX_SIZE][MAX_SIZE] = {};

    transposeMatrix(matrix, transposed, rows, cols);

    std::cout << std::endl;
    printMatrix(matrix, rows, cols);
    std::cout << std::endl;
    printMatrix(transposed, cols, rows);

    return 0;
}
