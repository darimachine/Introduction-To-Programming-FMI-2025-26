#include <iostream>
using namespace std;

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
    constexpr size_t SIZE = 30;
    int arr[SIZE] = {
        2, 6, 9, 10, 14, 18, 19, 19, 23, 29,
        34, 39, 39, 45, 49, 54, 58, 64, 65, 67,
        68, 72, 74, 74, 76, 77, 90, 95, 96, 98
    };

    int index = binarySearch(arr, SIZE, 74);
    cout << index << endl;

    return 0;
}
