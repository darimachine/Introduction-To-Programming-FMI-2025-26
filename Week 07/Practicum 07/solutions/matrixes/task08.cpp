#include <iostream>

using namespace std;

constexpr size_t MAX_SIZE = 64;

void multiplyMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols, int scalar) {
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] *= scalar;
        }
    }
}

void printMatrix(const int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    constexpr size_t SIZE1 = 2;
    int m1[MAX_SIZE][MAX_SIZE] = { {1, 2}, {2, 3} };

    printMatrix(m1, SIZE1, SIZE1);

    multiplyMatrix(m1, SIZE1, SIZE1, 5);
    printMatrix(m1, SIZE1, SIZE1);

    multiplyMatrix(m1, SIZE1, SIZE1, -3);
    printMatrix(m1, SIZE1, SIZE1);
}