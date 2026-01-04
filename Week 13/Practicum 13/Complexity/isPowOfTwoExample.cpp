#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool isPowerOfTwoSlow(size_t number) {
    if (number == 0) return false;

    while (number % 2 == 0) {
        number /= 2;
    }

    return number == 1;
}
bool isPowerOfTwoFast(size_t number) {
    if (number == 0) {
        return false;
    }

    return (number & (number - 1)) == 0;
}
int main()
{
    cout<< isPowerOfTwoFast(4);
    
   
}