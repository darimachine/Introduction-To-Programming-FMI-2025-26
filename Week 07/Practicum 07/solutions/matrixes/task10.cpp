#include <iostream>

using namespace std;

constexpr size_t SIZE = 3;

void myswap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void transpose(int matrix[][SIZE], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            myswap(matrix[i][j], matrix[j][i]);
        }
    }
}

void flipHorizontally(int matrix[][SIZE], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size / 2; j++)
        {
            myswap(matrix[i][j], matrix[i][size - j - 1]);
        }
        
    }
    
}

void rotateMatrix(int matrix[][SIZE], size_t size) {
    transpose(matrix, size);
    flipHorizontally(matrix, size);
}

void printMatrix(const int matrix[][SIZE], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int matrix[SIZE][SIZE] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    // може да се пробвате с 2-3 поредни завъртания
    constexpr int rotations = 1;

    printMatrix(matrix, SIZE);

    for (size_t i = 0; i < rotations; i++)
    {
        rotateMatrix(matrix, SIZE);
        printMatrix(matrix, SIZE);
    }
}