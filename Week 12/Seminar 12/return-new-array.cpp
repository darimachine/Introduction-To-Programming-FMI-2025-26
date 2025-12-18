#include <iostream>

int *createArray(int &outputSize);

int *createArray(int &outputSize) {
    outputSize = 3;

    int *arr = new int[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    return arr;
}

int main() {
    int size;
    int *myNewArray = createArray(size);

    for (int i = 0; i < size; i++) {
        std::cout << myNewArray[i] << std::endl;
    }

    delete[] myNewArray;

    return 0;
}
