#include <iostream>

int main() {
    int num = 123;
    int otherNum = 456;
    short int smallNum = 10;

    // Pointer
    int *ptrToNum = &num;

    std::cout << "ptrToNum = " << ptrToNum << std::endl;
    std::cout << std::endl;

    short int *ptrToSmallNum = &smallNum;

    std::cout << "sizeof(num)           = " << sizeof(num) << std::endl;
    std::cout << "sizeof(smallNum)      = " << sizeof(smallNum) << std::endl;
    std::cout << "sizeof(ptrToNum)      = " << sizeof(ptrToNum) << std::endl;
    std::cout << "sizeof(ptrToSmallNum) = " << sizeof(ptrToSmallNum)
              << std::endl;
    std::cout << std::endl;

    ptrToNum = &otherNum;

    *ptrToNum = 420;

    // Dereference
    std::cout << "*ptrToNum = " << *ptrToNum << std::endl;
    std::cout << "num       = " << num << std::endl;
    std::cout << "otherNum  = " << otherNum << std::endl;

    std::cout << std::endl;

    // Array-to-pointer decay
    int arr[3] = {2, 6, 5};

    std::cout << "arr     = " << arr
              << std::endl; // points to arr[0] ("pointer to int")
    std::cout << "&arr[0] = " << &arr[0]
              << std::endl; // points to arr[0] ("pointer to int")
    std::cout << "&arr    = " << &arr
              << std::endl; // points to arr ("pointer to array of 3 ints")

    return 0;
}
