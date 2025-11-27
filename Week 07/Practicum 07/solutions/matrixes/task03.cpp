#include <iostream>
#include <climits>

using namespace std;

constexpr size_t MAX_SIZE = 64;

void readRow(int[][MAX_SIZE], size_t, size_t);
void readMatrix(int[][MAX_SIZE], size_t, size_t);
void printRow(const int[][MAX_SIZE], size_t, size_t);
void printMatrixZigZag(const int[][MAX_SIZE], size_t, size_t);

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
    bool isEven = (rowInd % 2 == 0);

    int i = isEven ? 0 : (cols - 1);
    int incr = isEven ? 1 : (-1);

    for ( ; i >= 0 && i < cols; i += incr)
    {
        cout << matrix[rowInd][i] << " ";
    }
 
    cout << endl;
}

void printMatrixZigZag(const int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++)
    {
        printRow(matrix, cols, i);
    }
    
}

int main() {
    size_t rows = 0, cols = 0;
    cin >> rows >> cols;
    
    int matrix[MAX_SIZE][MAX_SIZE]{0};

    readMatrix(matrix, rows, cols);

    printMatrixZigZag(matrix, rows, cols);
}