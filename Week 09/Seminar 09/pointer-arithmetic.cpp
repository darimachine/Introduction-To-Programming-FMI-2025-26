#include <iostream>

int main() {
    int arr[3] = {10, 20, 30};

    // "pointer to int"
    int *ptr1 = &arr[0];
    std::cout << ptr1 << std::endl;
    std::cout << ptr1 + 1 << std::endl;
    std::cout << std::endl;

    // "pointer to int" (after array-to-pointer decay)
    int *ptr2 = arr;
    std::cout << ptr2 << std::endl;
    std::cout << ptr2 + 1 << std::endl;
    std::cout << std::endl;

    // "pointer to array of 3 ints"
    int(*ptr3)[3] = &arr;
    std::cout << ptr3 << std::endl;
    std::cout << ptr3 + 1 << std::endl;
    std::cout << std::endl;

    // "array of 3 pointers to int"
    int *ptr4[3] = {};
    std::cout << sizeof(ptr4[0]) << std::endl;
    std::cout << sizeof(ptr4[1]) << std::endl;
    std::cout << sizeof(ptr4[2]) << std::endl;

    return 0;
}
