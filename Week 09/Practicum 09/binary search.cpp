#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

constexpr size_t SIZE = 30;

void getRandomizedSortedArray(int arr[], size_t size) {
    srand(time(nullptr));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 101;  // random numbers 0–100
    }

    sort(arr, arr + size);
}

void printArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int binarySearch(const int arr[], size_t size, int x) {
    int left = 0, right = size - 1;
    int stepsCount = 0;

    while(left <= right) {
        stepsCount++;
        int mid = left + (right - left) / 2;

        if (arr[mid] < x) {
            left = mid + 1;
        } else if (arr[mid] > x) {
            right = mid - 1;
        } else {
            cout << "Steps count: " << stepsCount << endl;
            return mid;
        }
    }

    cout << "Steps count: " << stepsCount << endl;

    return -1;
}

int main() {
    int arr[SIZE]{0};
    getRandomizedSortedArray(arr, SIZE);

    // arr[20] = 1;
    // arr[21] = 1;
    // arr[22] = 1;

    cout << endl;
    printArray(arr, SIZE);
    cout << endl;
    system("pause");

    // cout << binarySearch(arr, SIZE, 1);

    for (size_t i = 0; i <= 100; i+=10)
    {
        cout << "Binary search for {" << i << "}:" << endl;
        int index = binarySearch(arr, SIZE, i);
        cout << "Index: " << index << endl << endl;
        system("pause");
    }
    

    return 0;
}
