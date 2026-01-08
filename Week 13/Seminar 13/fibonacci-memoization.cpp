#include <iostream>

typedef unsigned long long int u64;

const u64 UNKNOWN = 0;

u64 fibonacci(int n, u64 *memo) {
    if (n == 1 || n == 2) {
        return 1;
    }

    if (memo[n] != UNKNOWN) {
        return memo[n];
    }

    u64 result = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);

    memo[n] = result;

    return result;
}

// wrapper
u64 fibonacci(int n) {
    u64 *memo = new u64[n + 1];

    for (int i = 0; i < n + 1; i++) {
        memo[i] = UNKNOWN;
    }

    u64 result = fibonacci(n, memo);

    delete[] memo;

    return result;
}

int main() {
    std::cout << fibonacci(50) << std::endl;

    return 0;
}
