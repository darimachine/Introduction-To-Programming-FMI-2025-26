#include <iostream>

using namespace std;

constexpr size_t MAX_SIZE = 64;

long long sumRow(const int matrix[][MAX_SIZE], size_t size, size_t rowInd) {
    long long sum = 0;
    
    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[rowInd][i];
    }
    
    return sum;
}

long long sumCol(const int matrix[][MAX_SIZE], size_t size, size_t colInd) {
    long long sum = 0;
    
    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[i][colInd];
    }
    
    return sum;
}

long long getMainDiagSum(const int matrix[][MAX_SIZE], size_t size) {
    long long sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[i][i];
    }
    
    return sum;
}

long long getSecondaryDiagSum(const int matrix[][MAX_SIZE], size_t size) {
    long long sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[i][size - i - 1];
    }
 
    return sum;
}

bool isMagicSquare(const int matrix[][MAX_SIZE], size_t size) {
    if (size == 0) {
        return false;
    }

    long long sum = sumRow(matrix, size, 0);

    // start from 1 because 0 is already calculated
    for (size_t i = 1; i < size; i++)
    {
        if (sumRow(matrix, size, i) != sum) {
            return false;
        }
    }
    
    for (size_t i = 0; i < size; i++)
    {
        if (sumCol(matrix, size, i) != sum) {
            return false;
        }
    }
    
    if (getMainDiagSum(matrix, size) != sum) {
        return false;
    }

    if (getSecondaryDiagSum(matrix, size) != sum) {
        return false;
    }

    return true;
}

int main() {
    constexpr size_t SIZE1 = 3;
    int m1[MAX_SIZE][MAX_SIZE] = { 
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9} 
    };
    cout << isMagicSquare(m1, SIZE1) << endl;

    constexpr size_t SIZE2 = 4;
    int m2[MAX_SIZE][MAX_SIZE] = {
        {16, 3, 2, 13}, 
        {5, 10, 11, 8}, 
        {9, 6, 7, 12}, 
        {4, 15, 14, 1} 
    };
    cout << isMagicSquare(m2, SIZE2) << endl;
}