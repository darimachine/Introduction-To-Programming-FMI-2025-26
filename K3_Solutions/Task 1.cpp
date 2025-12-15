#include <iostream>
using std::cin;
using std::cout;
using std::endl;

size_t strLen(const char* s) {
   if (!s) {
      return 0;
   }

   size_t n = 0;

   while (s[n]) n++;

   return n;
}

bool isUpper(char c) {
   return c >= 'A' && c <= 'Z';
}

bool isLower(char c) {
   return c >= 'a' && c <= 'z';
}

bool isDigit(char c) {
   return c >= '0' && c <= '9';
}

char toLower(char c) {
   return c + ('a' - 'A');
}

char digitTransform(char c) {
   return ('9' - c) + '0';
}

char otherTransform(char c) {
   return c == '?' ? c : '*';
}

void transformChar(char& c) {
   if (isUpper(c)) {
       c = toLower(c);
   }
   else if (isDigit(c)) {
       c = digitTransform(c);
   }
   else if (!isLower(c)) {
       c = otherTransform(c);
   }
}

void mySwap(char& a, char& b) {
   char temp = a;
   a = b;
   b = temp;
}

void reverseRange(char* str, size_t start, size_t end) {
   if (!str) {
      return;
   }

   while (start < end) {
       mySwap(str[start], str[end]);
       start++;
       end--;
   }
}

void transformString(char* str, int k) {
   if (!str || k <= 0) {
      return;
   }

   size_t length = strLen(str);

   for (size_t start = 0; start < length; start += k) {
       size_t end = start + k - 1;

       if (end >= length) {
           end = length - 1;
       }

       reverseRange(str, start, end);
   }

   for (size_t i = 0; i < length; i++) {
       transformChar(str[i]);
   }
}

int main() {
   char str[] = "AbC123?!XYZ";
   int k = 3;

   transformString(str, k);
   cout << str << endl;
   return 0;
}
