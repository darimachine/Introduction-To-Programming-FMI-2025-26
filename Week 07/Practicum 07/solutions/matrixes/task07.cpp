#include <iostream>

using namespace std;

constexpr size_t MAX_SIZE = 64;

bool sumMatrixes(const int m1[][MAX_SIZE], size_t rows1, size_t cols1, 
                const int m2[][MAX_SIZE], size_t rows2, size_t cols2, 
                int m3[][MAX_SIZE], size_t rows3, size_t cols3) {
    if (rows1 != rows2 || cols1 != cols2 || rows1 != rows3 || cols1 != cols3) {
        return false;
    }

    for (size_t i = 0; i < rows1; i++)
    {
        for (size_t j = 0; j < cols1; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return true;
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
    int m2[MAX_SIZE][MAX_SIZE] = { {0, 1}, {-5, 10} };

    int m3[MAX_SIZE][MAX_SIZE]{0};
    if(!sumMatrixes(m1, SIZE1, SIZE1, m2, SIZE1, SIZE1, m3, SIZE1, SIZE1)) {
        cout << "Unsuccessful sum, wrong matrix dimensions\n\n";
    }
    printMatrix(m3, SIZE1, SIZE1);

    constexpr size_t SIZE2 = 1;
    int m4[MAX_SIZE][MAX_SIZE] = { {1} };
    if(!sumMatrixes(m1, SIZE1, SIZE1, m4, SIZE2, SIZE2, m3, SIZE1, SIZE1)) {
        cout << "Unsuccessful sum, wrong matrix dimensions\n\n";
    }
    printMatrix(m3, SIZE1, SIZE1);
}