#include <iostream>

using namespace std;

bool equals(double, double, double);
bool areLinearlyDependent(const int[], size_t, const int[], size_t);

bool equals(double a, double b, double epsilon = 1e-4) {
    return abs(a - b) < epsilon;
}

bool areLinearlyDependent(const int first[], size_t firstSize, const int second[], size_t secondSize) {
    if (firstSize != secondSize) {
        return false;
    } else if (firstSize == 0 && secondSize == 0) {
        return true;
    }

    double coeff = (double)first[0] / second[0];

    for (size_t i = 1; i < firstSize; i++)
    {
        double currentCoeff = (double)first[i] / second[i];

        if (!equals(coeff, currentCoeff)) {
            return false;
        }
    }
    
    return true;
}

int main() {
    constexpr size_t SIZE1 = 5;
    int arr1[SIZE1] = { 1, 2, 3, 4, 5 };
    int arr2[SIZE1] = { 6, 7, 8, 9, 10};

    cout << areLinearlyDependent(arr1, SIZE1, arr2, SIZE1) << endl;

    constexpr size_t SIZE2 = 3;
    int arr3[SIZE2] = { 1, 2, 3 };
    int arr4[SIZE2] = { 2, 4, 6 };

    cout << areLinearlyDependent(arr3, SIZE2, arr4, SIZE2) << endl;

    cout << areLinearlyDependent(arr1, SIZE1, arr3, SIZE2) << endl;

}