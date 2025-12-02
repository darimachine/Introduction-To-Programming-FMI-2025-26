

```cpp
int *pt;
int a[3]={4,11,13};
pt=&a[i];
pt+=1;
cout<<*pt<<endl;
```


```cpp
void f(int arr[5]) {
    cout<<sizeof(arr)<<endl;
}
int main() {
    int a[5];
    cout<<sizeof(a)<<endl;
    f(a);
}
```

```cpp
void f(int (*p)[3]);

int main() {
    int a[2][3];
    int * b[2];
    f(a);
    f(b);
}
```

```cpp
int* foo() {
    int x = 42;
    return &x;
}

int main() {
    int* p = foo();
    cout << *p << endl;
}
```


```cpp
#include <iostream>

void setToZero(int*& p) {
    *p = 0;   
}

int main() {
    int a = 5;
    int* p = &a;
    setToZero(p);
    std::cout << a << std::endl; 
}
```


```cpp
#include <iostream>

void setToZero(int*& p, int & b) {
    *p = 0;
    p = &b;
}

int main() {
    int a = 5;
    int b = 8;
    int* p = &a;
    setToZero(p,b);
    std::cout << a << std::endl;
    std::cout << *p << std::endl;
}
```

```cpp
#include <iostream>

int main() {
    int a = 10;
    const int* p = &a;
    a = 20;
    std::cout << *p << std::endl;
}

```

```cpp
#include <iostream>

int main() {
    int m[3][4] = {
        { 1,  2,  3,  4 },
        { 5,  6,  7,  8 },
        { 9, 10, 11, 12 }
    };

    int (*p)[4] = m;

    int value = *(*(p + 1) + 2);

    std::cout << value << std::endl;
}

```

```cpp
#include <iostream>

int main() {
    int a = 1;
    int b = 2;

    int* const p = &a;

    *p = 10;
    p = &b;

    std::cout << a << " " << *p << std::endl;
}

```

```cpp
#include <iostream>

int main() {
    int arr[3] = {4, 7, 9};
    int* p = arr;

    p++;
    *p = 100;

    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << std::endl;
}

```