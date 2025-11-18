#include <iostream>

using namespace std;

void populateArrayHistogram(const int[], size_t, int[]);
void printHistogram(const int[], size_t);
void printCountForEachElementInArray(const int[], size_t);

void printHistogram(const int histogram[], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << i << " - " << histogram[i] << endl;
    }

    cout << endl;
}

void populateArrayHistogram(const int arr[], size_t size, int histogram[]) {
    for (size_t i = 0; i < size; i++)
    {
        histogram[arr[i]]++;
    }
}

void printCountForEachElementInArray(const int arr[], size_t size) {
    constexpr size_t HISTOGRAM_SIZE = 20;
    int histogram[HISTOGRAM_SIZE]{0};

    populateArrayHistogram(arr, size, histogram);

    printHistogram(histogram, HISTOGRAM_SIZE);
}

int main() {
    constexpr size_t SIZE = 20;
    int arr[20] = {7, 14, 3, 3, 19, 0, 12, 8, 8, 5, 17, 1, 14, 6, 4, 4, 10, 18, 2, 7};

    printCountForEachElementInArray(arr, SIZE);
}