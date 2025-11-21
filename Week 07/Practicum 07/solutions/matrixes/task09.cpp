#include <iostream>

using namespace std;

constexpr size_t MAX_SIZE = 64;

int getElementInProductMatrix(const int row[], size_t len, const int matrix2[][MAX_SIZE], size_t colInd) {
    int element = 0;

    for (size_t i = 0; i < len; i++)
    {
        element += ( row[i] * matrix2[i][colInd] );
    }
    
    return element;
}

bool multiplyMatrixes(const int m1[][MAX_SIZE], size_t rows1, size_t cols1, 
                const int m2[][MAX_SIZE], size_t rows2, size_t cols2, 
                int m3[][MAX_SIZE], size_t rows3, size_t cols3) {
    if (cols1 != rows2 || rows1 != rows3 || cols2 != cols3) {
        return false;
    }

    for (size_t i = 0; i < rows1; i++)
    {
        for (size_t j = 0; j < cols2; j++)
        {
            
            // Матриците реално са масиви от масиви и с m1[i] взимаме масива на индекс i
            // или иначе казано - редът на индекс i, тъй като ни е досстатъчно да подадем само него
            // за умножението вместо цялата първа матрица.
            // От втората матрица ни е нужна i-тата колона, която обаче няма как да се "вземе" от
            // матрицата, затова подаваме цялата втора матрица.
            m3[i][j] = getElementInProductMatrix(m1[i], cols1, m2, j);
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
    constexpr size_t ROWS1 = 2, COLS1 = 2, ROWS2 = 2, COLS2 = 3;
    int m1[MAX_SIZE][MAX_SIZE] = { 
        {1, 2}, 
        {2, 3} 
    };
    int m2[MAX_SIZE][MAX_SIZE] = { 
        {0, 1, 2}, 
        {-5, 10, 3} 
    };

    constexpr size_t ROWS3 = ROWS1, COLS3 = COLS2;
    int m3[MAX_SIZE][MAX_SIZE]{0};
    if(!multiplyMatrixes(m1, ROWS1, COLS1, m2, ROWS2, COLS2, m3, ROWS3, COLS3)) {
        cout << "Unsuccessful matrix multiplication, wrong matrix dimensions\n\n";
    }
    printMatrix(m3, ROWS3, COLS3);

    constexpr size_t ROWS4 = ROWS2, COLS4 = COLS1;
    int m4[MAX_SIZE][MAX_SIZE]{0};
    if(!multiplyMatrixes(m1, ROWS1, COLS1, m2, ROWS2, COLS2, m4, ROWS4, COLS4)) {
        cout << "Unsuccessful matrix multiplication, wrong matrix dimensions\n\n";
    }
    printMatrix(m4, ROWS4, COLS4);
}