#include<iostream>
#include<climits>

void readArray(int arr[], size_t);
int min(int, int);
int max(int, int);
double abs(double);
int findMinValueInArray(const int arr[], size_t);
int findMaxValueInArray(const int arr[], size_t);
double getAverageOfArray(const int arr[], size_t);
int findClosestToAverageInArray(const int arr[], size_t);
int findMinMax(const int arr[], size_t, int&, int&);
long long getSumOfArray(const int arr[], size_t size);

void readArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

int min(int a, int b) {
    return a < b ? a : b;
}

int findMinValueInArray(const int arr[], size_t size) {
    int minValue = INT_MAX;
    
    for (size_t i = 0; i < size; i++) {
        minValue = min(minValue, arr[i]);
    }

    return minValue;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int findMaxValueInArray(const int arr[], size_t size) {
    int maxValue = INT_MIN;
    
    for (size_t i = 0; i < size; i++) {
        maxValue = max(maxValue, arr[i]);
    }

    return maxValue;
}

long long getSumOfArray(const int arr[], size_t size) {
    long long sum = 0;

    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

double getAverageOfArray(const int arr[], size_t size) {
    return getSumOfArray(arr, size) / size;
}

double abs(double a) {
    return a < 0 ? -a : a;
}

int findClosestToAverageInArray(const int arr[], size_t size) {
    double average = getAverageOfArray(arr, size);
    double minDiff = INT_MAX;
    int closest = 0;

    for (size_t i = 1; i < size; i++) {
        double currentDiff = abs(average - arr[i]);

        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            closest = arr[i];
        }
    }

    return closest;
}

int findMinMax(const int arr[], size_t size, int& minValue, int& maxValue) {
    minValue = findMinValueInArray(arr, size);
    maxValue = findMaxValueInArray(arr, size);
    return findClosestToAverageInArray(arr, size);
}

int main() {
    constexpr size_t SIZE = 5;
    int arr[SIZE];
    readArray(arr, SIZE);

    int minValue = INT_MAX, maxValue = INT_MIN;
    int closestToAverage = findMinMax(arr, SIZE, minValue, maxValue);
    
    std::cout << "Min: " << minValue << "\nMax: " << maxValue << "\nClosest to average: " << closestToAverage << '\n';
}