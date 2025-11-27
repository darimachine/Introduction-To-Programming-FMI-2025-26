#include <iostream>
#include <climits>

using namespace std;

constexpr size_t MAX_SIZE = 64;

void readRow(int[][MAX_SIZE], size_t, size_t);
void readMatrix(int[][MAX_SIZE], size_t, size_t);
bool isRowValid(const int[][MAX_SIZE], size_t, size_t);
bool isTriangularMatrix(const int[][MAX_SIZE], size_t, size_t);

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

bool isRowValid(const int matrix[][MAX_SIZE], size_t cols, size_t rowInd) {
    for (size_t i = 0; i < rowInd; i++)
    {
        if (matrix[rowInd][i] != 0) {
            return false;
        }
    }
    
    return true;
}

bool isTriangularMatrix(const int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++)
    {
        if (!isRowValid(matrix, cols, i)) {
            return false;
        }
    }
    
    return true;
}

int main() {
    size_t rows = 0, cols = 0;
    cin >> rows >> cols;
    
    int matrix[MAX_SIZE][MAX_SIZE]{0};

    readMatrix(matrix, rows, cols);

    cout << isTriangularMatrix(matrix, rows, cols) << endl;
}