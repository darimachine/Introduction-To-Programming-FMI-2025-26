#include <cstring>
#include <iostream>

bool isPalAfterRemovingTwo(const char *s, int n, int i, int j) {
    int l = 0, r = n - 1;

    while (l < r) {
        if (l == i || l == j) {
            l++;
            continue;
        }
        if (r == i || r == j) {
            r--;
            continue;
        }

        if (s[l] != s[r])
            return false;

        l++;
        r--;
    }
    return true;
}
int myStrlen(const char *s) {
    if (!s)
        return -1;
    int n = 0;
    while (s[n])
        n++;

    return n;
}
bool checkStr(const char *s) {
    if (!s)
        return false;
    int n = myStrlen(s);
    if (n < 2)
        return false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isPalAfterRemovingTwo(s, n, i, j)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char str[] = "abckgba1";
    std::cout << checkStr(str);
}
