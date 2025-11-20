#include <iostream>

using namespace std;

void populateArrayHistogram(const int[], size_t, int[]);
int getMissingElement(const int[], size_t);

void populateArrayHistogram(const int arr[], size_t size, int histogram[]) {
    for (size_t i = 0; i < size; i++)
    {
        histogram[arr[i]]++;
    }
}

int getMissingElement(const int arr[], size_t size) {
    constexpr size_t HISTOGRAM_SIZE = 21;
    int histogram[HISTOGRAM_SIZE]{0};

    populateArrayHistogram(arr, size, histogram);
    
    int missingElement = 0;

    for (size_t i = 0; i < HISTOGRAM_SIZE; i++)
    {
        if (histogram[i] == 0) {
            missingElement = i;
            break;
        }
    }

    return missingElement;
}

int main() {
    constexpr size_t SIZE = 20;
    int arr[SIZE] = { 0, 2, 1, 4, 6, 5, 8, 7, 10, 9, 12, 11, 14, 13, 16, 15, 18, 17, 20, 19 };
    cout << getMissingElement(arr, SIZE);
}