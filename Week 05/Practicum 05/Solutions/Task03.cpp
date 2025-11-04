#include <iostream>

void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

void sort3(int& min, int& mid, int& max) {
    if (min > mid) {
        swap(min, mid);
    }

    if (mid > max) {
        swap(mid, max);
    }

    if (min > mid) {
        swap(min, mid);
    }
}

int main()
{
    int min, mid, max;
    std::cin >> min >> mid >> max;
    sort3(min, mid, max);
    std::cout << min << " " << mid << " " << max << std::endl;
}

