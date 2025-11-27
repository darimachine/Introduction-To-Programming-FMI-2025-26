#include <iostream>

using namespace std;

constexpr size_t MAX_SIZE = 64;

void printMainDiagonal(const int matrix[][MAX_SIZE], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << matrix[i][i] << " ";
    }

    cout << endl;
}

void printSecondaryDiagonal(const int matrix[][MAX_SIZE], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << matrix[i][size - i - 1] << " ";
    }

    cout << endl;
}

void printDiagonals(const int matrix[][MAX_SIZE], size_t size) {
    printMainDiagonal(matrix, size);
    printSecondaryDiagonal(matrix, size);
}

void readRow(int matrix[][MAX_SIZE], size_t cols, size_t rowInd) {
    for (size_t i = 0; i < cols; i++)
    {
        cin >> matrix[rowInd][i];
    }
}

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++)
    {
        readRow(matrix, cols, i);
    }
}

int main() {
    size_t size = 0;
    cin >> size;
    
    int matrix[MAX_SIZE][MAX_SIZE]{0};

    readMatrix(matrix, size, size);

    printDiagonals(matrix, size);
}