#include <iostream>

using namespace std;

constexpr size_t MAX_ARRAY_SIZE = 1024;

bool isElementInArray(int, const int[], size_t);
void addArrayToUnion(const int[], size_t, int[], size_t&);
void printArray(const int[], size_t);
void getUnionFromTwoArrays(const int[], size_t, const int[], size_t, int[], size_t&);
void printUnion(const int[], size_t, const int[], size_t);
void getIntersectionOfTwoArrays(const int[], size_t, const int[], size_t, int[], size_t&);
void printIntersection(const int[], size_t, const int[], size_t);
void getDifferenceOfTwoArrays(const int[], size_t, const int[], size_t, int[], size_t&);
void printDifference(const int[], size_t, const int[], size_t);

void printArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

bool isElementInArray(int el, const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == el) {
            return true;
        }
    }
    
    return false;
}

void addArrayToUnion(const int arr[], size_t arrSize, int unionArr[], size_t& unionSize) {
    for (size_t i = 0; i < arrSize; i++)
    {
        if (!isElementInArray(arr[i], unionArr, unionSize)) {
            unionArr[unionSize++] = arr[i];
        }
    }
}

void getUnionFromTwoArrays(const int first[], size_t firstSize, const int second[], size_t secondSize, int unionArr[], size_t& unionSize) {
    addArrayToUnion(first, firstSize, unionArr, unionSize);
    addArrayToUnion(second, secondSize, unionArr, unionSize);
}

void printUnion(const int first[], size_t firstSize, const int second[], size_t secondSize) {
    int unionArr[MAX_ARRAY_SIZE * 2]{0};
    size_t unionSize = 0;

    getUnionFromTwoArrays(first, firstSize, second, secondSize, unionArr, unionSize);

    printArray(unionArr, unionSize);
}

void getIntersectionOfTwoArrays(const int first[], size_t firstSize, const int second[], size_t secondSize,
                                int intersection[], size_t& intersectionSize) {
    for (size_t i = 0; i < firstSize; i++)
    {
        if (isElementInArray(first[i], second, secondSize) && !isElementInArray(first[i], intersection, intersectionSize)) {
            intersection[intersectionSize++] = first[i];
        }
    }
}

void printIntersection(const int first[], size_t firstSize, const int second[], size_t secondSize) {
    int intersection[MAX_ARRAY_SIZE]{0};
    size_t intersectionSize = 0;

    getIntersectionOfTwoArrays(first, firstSize, second, secondSize, intersection, intersectionSize);

    printArray(intersection, intersectionSize);
}

void getDifferenceOfTwoArrays(const int first[], size_t firstSize, const int second[], size_t secondSize,
                                int difference[], size_t& differenceSize) {
    for (size_t i = 0; i < firstSize; i++)
    {
        if (!isElementInArray(first[i], second, secondSize) && !isElementInArray(first[i], difference, differenceSize)) {
            difference[differenceSize++] = first[i];
        }
    }
}

void printDifference(const int first[], size_t firstSize, const int second[], size_t secondSize) {
    int difference[MAX_ARRAY_SIZE]{0};
    size_t differenceSize = 0;

    getDifferenceOfTwoArrays(first, firstSize, second, secondSize, difference, differenceSize);

    printArray(difference, differenceSize);
}

int main() {
    constexpr size_t FIRST_SIZE = 8, SECOND_SIZE = 7;
    int first[FIRST_SIZE] = { 2, 3, 4, 2, 5, 0, 4, 5 };
    int second[SECOND_SIZE] = { 1, 2, 7, 7, 7, 3, -1 };

    printUnion(first, FIRST_SIZE, second, SECOND_SIZE);

    printIntersection(first, FIRST_SIZE, second, SECOND_SIZE);

    printDifference(first, FIRST_SIZE, second, SECOND_SIZE);
}