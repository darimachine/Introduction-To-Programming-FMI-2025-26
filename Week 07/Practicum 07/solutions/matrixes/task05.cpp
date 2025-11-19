#include <iostream>
#include <climits>

using namespace std;

constexpr size_t MAX_SIZE = 1024;

void readRow(int[][MAX_SIZE], size_t, size_t);
void readMatrix(int[][MAX_SIZE], size_t, size_t);

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

void printRow(const int matrix[][MAX_SIZE], size_t cols, size_t rowInd) {
    for (size_t i = 0; i < cols; i++)
    {
        cout << matrix[rowInd][i] << " ";
    }

    cout << endl;
}

void printMatrix(const int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++)
    {
        printRow(matrix, cols, i);
    }
}

void myswap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void transpose(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    if (rows != cols) {
        cout << "ne\n\n";
        return;
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            myswap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    size_t rows = 0, cols = 0;
    cin >> rows >> cols;
    
    int matrix[MAX_SIZE][MAX_SIZE]{0};

    readMatrix(matrix, rows, cols);

    transpose(matrix, rows, cols);

    printMatrix(matrix, rows, cols);
}