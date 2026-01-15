#include <iostream>

int *combineArrays(int *arrayA, int *arrayB, int size, int &resultSize,
                   int (*operation)(int, int), bool (*filter)(int));

int add(int a, int b);
int multiply(int a, int b);

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int* combineArrays(
    int* arrayA,
    int* arrayB,
    int size,
    int& resultSize,
    int (*operation)(int, int),
    bool (*filter)(int)
) {
    resultSize = 0;

    for (int i = 0; i < size; i++) {
        if (filter(arrayA[i]) && filter(arrayB[i])) {
            resultSize++;
        }
    }

    if(resultSize == 0) {
        return nullptr;
    }

    int* result = new int[resultSize];
    int resultIndex = 0;

    for (int i = 0; i < size; i++) {
        if (filter(arrayA[i]) && filter(arrayB[i])) {
            result[resultIndex] = operation(arrayA[i], arrayB[i]);
            resultIndex++;
        }
    }

    return result;
}

int main() {
    int a[] = {1, 4, 3, 5, 6};
    int b[] = {2, 8, 2, 10, 2};

    int resultSize;

    int* result = combineArrays(
        a,
        b,
        5,
        resultSize,
        add,
        [](int num) { return num % 2 == 0; }
    );

    for (int i = 0; i < resultSize; i++) {
        std::cout << result[i] << std::endl;
    }

    delete[] result;

    return 0;
}
