#include <iostream>

using namespace std;

void getElementsInInterval(const int arr[], size_t arrSize, int res[], size_t& resSize, int begin, int end);
void printArray(const int[], size_t);
bool isNumInClosedInterval(int, int, int);

void printArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

bool isNumInClosedInterval(int num, int begin, int end) {
    return num >= begin && num <= end;
}

void getElementsInInterval(const int arr[], size_t arrSize, int res[], size_t& resSize, int begin, int end) {
    for (size_t i = 0; i < arrSize; i++)
    {
        if (isNumInClosedInterval(arr[i], begin, end)) {
            res[resSize++] = arr[i];
        }
    }
}

int main() {
    constexpr size_t SIZE = 7;
    int arr[SIZE] = { 5, 7, 1, 4, 3, 9, 10 };
    int A = 2, B = 8;

    int res[SIZE]{0};
    size_t resSize = 0;

    getElementsInInterval(arr, SIZE, res, resSize, A, B);

    printArray(res, resSize);
}