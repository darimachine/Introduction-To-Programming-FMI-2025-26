#include <iostream>

int *collect(int **matrix, int rows, int cols, int &resultSize);

bool hasRepeatingDigits(int number);

void printArray(int *arr, int size);
void inputMatrix(int **matrix, int rows, int cols);
int **createMatrix(int rows, int cols);
void freeMatrix(int **matrix, int rows);

int *collect(int **matrix, int rows, int cols, int &resultSize) {
    if (matrix == nullptr) {
        return nullptr;
    }

    resultSize = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (hasRepeatingDigits(matrix[i][j])) {
                resultSize++;
            }
        }
    }

    if (resultSize == 0) {
        return nullptr;
    }

    int *result = new int[resultSize];
    int resultIndex = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (hasRepeatingDigits(matrix[i][j])) {
                result[resultIndex] = matrix[i][j];
                resultIndex++;
            }
        }
    }

    return result;
}

int main() {
    size_t rows, cols;
    std::cin >> rows >> cols;

    int **matrix = createMatrix(rows, cols);
    inputMatrix(matrix, rows, cols);

    int resultSize;
    int *result = collect(matrix, rows, cols, resultSize);

    freeMatrix(matrix, rows);

    printArray(result, resultSize);

    delete[] result;

    return 0;
}

bool hasRepeatingDigits(int number) {
    // Not the implementation from the real exam

    bool digits[10] = {};

    number = std::abs(number);

    while (number > 0) {
        int digit = number % 10;

        if (digits[digit]) {
            return true;
        }

        digits[digit] = true;

        number /= 10;
    }

    return false;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void inputMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

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
