**Въпрос 1:** Какво ще се изведе след изпълнение на кода?

```c++
#include <iostream> 

int& tricky(int& a) { 
	a++; 
	return a; 
}

int main() { 
	int x = 10;
	int& y = tricky(x);
	int z = tricky(x); 
	y++; 
	std::cout << x << " " << y << " " << z; 
}
```

**Въпрос 2:** Какво ще се изведе след изпълнение на кода?

```c++
#include <iostream>

int global = 1;

int& getRef() {
    return global;
}

int getVal() {
    return global;
}

int main() {
    getRef() = 5;
    std::cout << global << std::endl; // ?
   // getVal() = 10; //will it compile?
}
```

**Въпрос 3:** Какво ще се изведе след изпълнение на кода?

```c++
#include <iostream>

void print(int a, int b = 5, char c = 'z') {
    std::cout << a << " " << b << " " << c<<std::endl;
}

int main() {
    print(8); 
    print(4, 6); 
    print(3, 'a'); 
}
```

**Въпрос 4:** Какво ще се изведе след изпълнение на кода?

```c++
#include <iostream>

int main() {
    int arr[];
    int arr[2];
    int arr[2] = { 1 };
    int arr[2] = { 1, 2, 3 };
}
```

**Въпрос 5:** Правилно ли бива обходен следният масив?

```c++
#include <iostream>

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };

    for (int i = 0; i <= 5; i++) {
        std::cout << arr[i] << " ";
    }
}
```

**Въпрос 6:** Има ли грешка в тази функция?

```c++
#include <iostream>

void printArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    
}
```

**Въпрос 7:** Двете извиквания на printArray() едно и също ли ще принтират?

```c++
#include <iostream>

void printArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

void incrementArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i]++;
    }
}

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    printArray(arr, 5);
    incrementArray(arr, 5);
    printArray(arr, 5);
}
```

**Въпрос 8:** Следният код компилира ли се?

```c++
#include <iostream>

void incrementArray(int[], size_t);

void printArray(const int arr[], size_t size) {
    incrementArray(arr, size);

    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void incrementArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i]++;
    }
}

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    printArray(arr, 5);
    incrementArray(arr, 5);
    printArray(arr, 5);
}
```

**Въпрос 9:** Какво ще изведе следният код?

```c++
#include <iostream>

void printArray(const int arr[], size_t size);

void f(const int arr[], size_t size) {
    int arr2[] = { 0, 0, 0, 0, 0 };
    arr = arr2;
    printArray(arr, size);
}

void printArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    printArray(arr, 5);
    f(arr, 5);
    printArray(arr, 5);
}
```


```cpp
    void cout(char a) { std::cout << a; } //1

    void cout(int a) { std::cout << a; } //2

    void cout(char a, int b) { std::cout << a << '-' << b; } //3

    void cout(double a, char b) { std::cout << b << '-' << a; } //4

    void cout(bool a) { std::cout << a; } //5

    void cout(char a, bool b, int c) { std::cout << a <<b << c; } //6

    void cout(const int a) { std::cout << a; } //7

    void cout(char a, unsigned b) { std::cout << a << '-' <<b; } //8

    void cout(char a, int b) { std::cout << a << '-' << b; } // 8.1

    char cout(char a) { return a; } //9

```