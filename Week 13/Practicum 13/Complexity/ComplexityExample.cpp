#include <iostream>

// N
void example1(size_t n) {
    for (size_t i = 0; i < n; i++) {
        /* code */
    }
}

// N^2
void example2(size_t n) {
    for(size_t i = 0; i < n; i++) {
        for(size_t j = 0; j < n; j += 2) {
            /* code */
        }
    }
}

// NLogN
void example3(size_t n) {
    for(size_t i = 0; i < n; i++) {
        for(size_t j = 1; j < n; j *= 2) {
            /* code */
        }
    }
}

// O(1) - constans
void example4(size_t n) {
    for (size_t i = 0; i < 6432; i++) {
        /* code */
    }
}

// N^2
void example5(const char* str) {
    for(size_t i = 0; i < strlen(str); i++) {
        /* code */
    }
}

// NLogN
void example6(size_t n) {
    for(size_t i = 0; i < n; i++) {
        for(size_t j = 1; j < n; j *= 2) {
            /* code */
        }
    }
    
    for(size_t i = 0; i < n; i++) {
        for(size_t j = 1; j < n; j *= 2) {
            /* code */
        }
    }
}

// N + M
void brothers(int N, int M) {
    for (int i = 0; i < N; i++) {
        std::cout << i << std::endl;
    }

    for (int j = 0; j < M; j++) {
        std::cout << j << std::endl;
    }
}

int main() {
}