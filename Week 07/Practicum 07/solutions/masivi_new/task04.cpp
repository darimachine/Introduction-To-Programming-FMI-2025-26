#include <iostream>

using namespace std;

void populateArrayHistogram(const int[], size_t, int[]);
bool arePermutations(const int[], const int[], size_t);
bool areArraysEqual(const int[], size_t, const int[], size_t);

bool areArraysEqual(const int first[], size_t firstSize, const int second[], size_t secondSize) {
    if (firstSize != secondSize) {
        return false;
    }

    for (size_t i = 0; i < firstSize; i++)
    {
        if (first[i] != second[i]) {
            return false;
        }
    }

    return true;    
}

void populateArrayHistogram(const int arr[], size_t size, int histogram[]) {
    for (size_t i = 0; i < size; i++)
    {
        histogram[arr[i]]++;
    }
}

bool arePermutations(const int first[], const int second[], size_t size) {
    constexpr int HISTOGRAM_SIZE = 10;
    
    int histogramFirst[HISTOGRAM_SIZE]{0};
    populateArrayHistogram(first, size, histogramFirst);
    
    int histogramSecond[HISTOGRAM_SIZE]{0};
    populateArrayHistogram(second, size, histogramSecond);

    return areArraysEqual(histogramFirst, HISTOGRAM_SIZE, histogramSecond, HISTOGRAM_SIZE);
}

int main() {
    constexpr size_t SIZE = 6;
    int arr1[] = { 1, 4, 4, 0, 4, 2 };
    int arr2[] = { 0, 4, 4, 4, 1, 2 };

    cout << arePermutations(arr1, arr2, SIZE) << endl;

    int arr3[] = { 1, 4, 9, 8, 4, 2 };
    int arr4[] = { 9, 6, 7, 4, 5, 2 };

    cout << arePermutations(arr3, arr4, SIZE) << endl;
}