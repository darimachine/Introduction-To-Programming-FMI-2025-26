#include <iostream>

using namespace std;

void printArray(const int[], size_t);
void myswap(int&, int&);
void reverseFirstNElementsInArray(int[], size_t, int);

void printArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void myswap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void reverseFirstNElementsInArray(int arr[], size_t size, int N) {
    for (size_t i = 0; i < N / 2; i++)
    {
        myswap(arr[i], arr[N - i - 1]);
    }
}

int main() {
    constexpr size_t SIZE = 7;
    int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7 };

    reverseFirstNElementsInArray(arr, SIZE, 5);

    printArray(arr, SIZE);
}