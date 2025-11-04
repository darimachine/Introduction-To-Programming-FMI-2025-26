#include <iostream>

void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

void swap(double& first, double& second) {
    double temp = first;
    first = second;
    second = temp;
}

void swap(char& first, char& second) {
    char temp = first;
    first = second;
    second = temp;
}

int main()
{
    int first, second;
    std::cin >> first >> second;
    swap(first, second);
    std::cout << first << " " << second << std::endl;
}
