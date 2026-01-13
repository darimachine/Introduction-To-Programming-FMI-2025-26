#include <iostream>
using namespace std;

void freeMatrix(bool** matrix, size_t size) {
    for (size_t i = 0; i < size; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

bool insideMatrix(size_t rows, size_t cols, int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

constexpr size_t DIRECTIONS_COUNT = 4;
int dx[DIRECTIONS_COUNT] = { 1, -1, 0, 0 };
int dy[DIRECTIONS_COUNT] = { 0, 0, 1, -1 };

bool canEscape(bool** labyrinth, size_t rows, size_t cols, int x, int y) {
    if (!labyrinth) {
        return false;
    }
    if (!insideMatrix(rows, cols, x, y) || labyrinth[x][y] == 0) {
        return false;
    }

    labyrinth[x][y] = 0;

    if (x == rows - 1 && y == cols - 1) {
        return true;
    }

    for (size_t i = 0; i < DIRECTIONS_COUNT; i++) {
        if (canEscape(labyrinth, rows, cols, x + dx[i], y + dy[i])) {
            return true;
        }
    }

    return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    bool** labyrinth = new bool* [N];
    for (size_t i = 0; i < N; i++) {
        labyrinth[i] = new bool[M];
        for (size_t j = 0; j < M; j++) {
            cin >> labyrinth[i][j];
        }
    }

    cout << boolalpha << canEscape(labyrinth, N, M, 0, 0) << endl << endl;

    freeMatrix(labyrinth, N);
}

/*
6 6
1 1 0 1 0 1
0 1 0 1 1 1
0 1 1 1 0 0
1 1 0 1 0 1
1 0 1 1 0 1
0 0 0 1 1 1
*/
