#include <iostream>

using namespace std;

void printArray(const int[], size_t);
void incrementArray(int[], size_t);

void printArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void incrementArray(int arr[], size_t size) {
    int toAdd = 1;

    for (size_t i = size - 1; i >= 0; i--)
    {
        if (arr[i] + toAdd != 10) {
            arr[i]++;
            return;
        }
        else {
            arr[i] = 0;
            toAdd = 1;
        }
    }
}

int main() {
    constexpr size_t SIZE = 5;
    int arr[SIZE] = { 0, 1, 0, 0, 9 };
    
    incrementArray(arr, SIZE);

    printArray(arr, SIZE);
}