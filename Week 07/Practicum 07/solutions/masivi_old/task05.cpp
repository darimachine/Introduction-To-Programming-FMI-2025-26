#include <iostream>

using namespace std;

bool isPalindrome(const char[], size_t);

bool isPalindrome(const char arr[], size_t size) {
    for (size_t i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    constexpr size_t N_MAX = 50;
    int N;
    cin >> N;
    char arr[N_MAX];

    for (size_t i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << isPalindrome(arr, N) << endl;
}