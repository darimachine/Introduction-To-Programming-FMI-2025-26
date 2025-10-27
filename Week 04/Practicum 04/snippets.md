**1.** Какво ще отпечата на екрана следният код?
```cpp
#include <iostream>
using namespace std;

int main()
{
    unsigned int first = 10;
    unsigned int second = 10;

    while (cout << first << endl, ----first);

    while (cout << second << endl, second----);
}
```
<br>

**2.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
using namespace std;

int main() {
    f();
    return 0;
}

void f() {
    cout << "f()" << endl;
}
```
<br>

**3.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
using namespace std;

int func(int param = 10) {
    return param;
}

int main() {
    cout << func() << endl;
    cout << func(0) << endl;
}
```
<br>

**4.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
using namespace std;

void printCharNTimes(char c = '*', int N) {
    for (int i = 0; i < N; i++) {
        cout << c;
    }
}

int main() {
    printCharNTimes('-', 10);
    printCharNTimes(10);
}
```
<details>
    <summary>Обяснение</summary>
Не се компилира.
Параметрите със стойности по подразбиране винаги трябва да са изредени след тези, които нямат стойност по подразбиране.
</details>
<br>

**5.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
using namespace std;

int& foo() {
    int x = 42;
    return x;
}

int main() {
    int& r = foo();
    cout << r << endl;
}
```
<details>
    <summary>Обяснение</summary>
foo() връща референция към int x = 42, което е създадено ВЪТРЕ във foo() и се унищожава след изпълнението на функцията, т.е.
върнатата в main() референция вече не сочи към валиден обект и е невалидна. Накратко Undefined Behavior
</details>
<br>

**6.** Какво ще отпечата на екрана следният код?

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
<details>
    <summary>Обяснение</summary>
Undefined Behavior
</details>

<br>

**7.** Какво ще отпечата на екрана следният код?

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

**8.** Какво ще отпечата на екрана следният код?
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


**9.** Какво ще отпечата на екрана следният код?
```cpp
#include <iostream>
using namespace std;

void f(int p) { cout << p; }

void f(double p) { cout << p; }

int f(int p) { return p; }

int main() {
    f(10);
    f(10.5);
    int a = f(7);
}
```
<br>

**10.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
using namespace std;

void h() { f(); }
void g() { h(); }
void f() { g(); }

int main() {
    f();
}
```
<details>
    <summary>Обяснение</summary>
Не се компилира, защото f() не е декларирана преди дефиницията на h(). Какво става, ако е?
</details>


**11.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
int& getValue(int& num) {
    return num; 
}


int main() {
    int x = 5;
    getValue(x) = 10; 
    std::cout << "x: " << x << std::endl;
}
```
**12.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
int& getValue(int& num) {
    return ++num;
}


int main() {
    int x = 5;
    int b = 1;
    getValue(x) = getValue(b);
    std::cout << "x: " << x << std::endl;
}

```