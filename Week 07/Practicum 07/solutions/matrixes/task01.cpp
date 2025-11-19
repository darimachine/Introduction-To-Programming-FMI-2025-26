#include <iostream>
#include <climits>

using namespace std;

constexpr size_t MAX_SIZE = 1024;

int min(int, int);
int getMinElInRow(const int[][MAX_SIZE], size_t, size_t);
int getMinInMatrix(const int[][MAX_SIZE], size_t, size_t);
void readRow(int[][MAX_SIZE], size_t, size_t);
void readMatrix(int[][MAX_SIZE], size_t, size_t);

int min(int a, int b) {
    return a < b ? a : b;
}

int getMinElInRow(const int matrix[][MAX_SIZE], size_t cols, size_t rowInd) {
    int minEl = INT_MAX;

    for (size_t i = 0; i < cols; i++) {
        minEl = min(minEl, matrix[rowInd][i]);
    }
    
    return minEl;
}

int getMinInMatrix(const int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    int minEl = INT_MAX;

    for (size_t i = 0; i < rows; i++) {
        minEl = min(minEl, getMinElInRow(matrix, cols, i));
    }
    
    return minEl;
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
    size_t rows = 0, cols = 0;
    cin >> rows >> cols;
    
    int matrix[MAX_SIZE][MAX_SIZE]{0};

    readMatrix(matrix, rows, cols);

    cout << getMinInMatrix(matrix, rows, cols) << endl;
}