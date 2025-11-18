#include <iostream>

using namespace std;

void printArray(const int[], size_t);
void printFirstDuplicateInArray(const int[], size_t);

void printArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void printFirstDuplicateInArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (arr[j] == arr[i]) {
                cout << arr[j] << endl;
                return;
            }
        }
    }

    cout << "No duplicate elements found." << endl;
}

int main() {
    constexpr size_t SIZE1 = 7, SIZE2 = 3;
    int arr1[SIZE1] = { 1, 2, 3, 2, 4, 3, 1 };
    int arr2[SIZE2] = { 1, 2, 3 };

    printFirstDuplicateInArray(arr1, SIZE1);
    printFirstDuplicateInArray(arr2, SIZE2);
}