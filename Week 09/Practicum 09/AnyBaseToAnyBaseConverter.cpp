#include  <iostream>
using namespace std;

constexpr int MAX_SIZE=1024;

void swap(int&a, int& b) {
    int temp = a;
    a = b;
    b=temp;
}
void reverseArray(char arr[], int size) {
    for (int i = 0; i < size/2; i++) {
        swap(arr[i],arr[size-1-i]);
    }
}

char decimalToChar(unsigned num) {
    if (num>=0 && num<=9) {
        return num+'0';
    }
    if (num>=10 && num<=32) {
        return (num-10) + 'A';
    }
    return 0;
}
void fromDecimalToAnyBase(unsigned decimalNumber, char* result, unsigned& numberLength, unsigned base ) {

    while (decimalNumber != 0) {
        unsigned remainder = decimalNumber % base;
        result[numberLength++] = decimalToChar(remainder);
        decimalNumber = decimalNumber / base;
    }

    reverseArray(result,numberLength);
}

unsigned charToDecimal(char ch) {
    if (ch>='0'&& ch<='9') {
        return ch-'0';
    }
    if (ch>='A' && ch<='F') {
        return ch-'A' + 10;
    }
}
unsigned fromAnyBaseToDecimal(const char* number, unsigned numberLength, unsigned base) {
    unsigned result =0;
    unsigned multiplier = 1;
    for (int i=numberLength-1;i>=0;i--) {
        unsigned currentNumber = charToDecimal(number[i]);
        result+= currentNumber * multiplier;
        multiplier *= base;
    }
    return result;
}

void fromAnyBaseToAnyBase(const char* number, unsigned numberLength, unsigned fromBase, char* result,unsigned& resultLength, unsigned toBase) {
    unsigned decimal = fromAnyBaseToDecimal(number, numberLength, fromBase);
    fromDecimalToAnyBase(decimal,result,resultLength,toBase);

}
int main() {
    {

        char number[MAX_SIZE] = {'F','2','\0'};
        unsigned numberLength = 2;

        char result[MAX_SIZE] = {};
        unsigned resultLength=0;
        fromAnyBaseToAnyBase(number,numberLength,16,result,resultLength,8);
        cout<<result<<endl;
    }

}
