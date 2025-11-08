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
<details>
    <summary>Обяснение</summary>
- префиксен '--а' връща lvalue, значи и върнатият резултат може да го извика и да се "наслагат" '----а' -> първият цикъл е ок<br>
- постфиксен 'а--' връща rvalue, което е просто някаква стойност, незаписана в паметта, която не може да извика '--' -> не се компилира, заради втория цикъл, в който има 'а----'
</details>
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
<details>
    <summary>Обяснение</summary>
main() не знае за f(), заради реда, в който са дефинирани, и затова кодът не се компилира(за main() не съществува функция f(), която да извика). Трябва или дефиницията на f() да се изнесе над тази на main(), или f() просто да се декларира над main(), без да се мести дефиницията ѝ.

void f(); -> добавяме този код над main() и вече няма проблеми
</details>
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
<details>
    <summary>Обяснение</summary>
В първото извикване се ползва стойността по подразбиране на параметъра, а във второто - подадената, нищо особено.
</details>
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
Не се компилира. Параметрите със стойности по подразбиране винаги трябва да са изредени след тези, които нямат стойност по подразбиране, колкото и да са на брой.
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
върнатата в main() референция вече не сочи към валиден обект и е невалидна. Накратко, Undefined Behavior.
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
<br>

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
<br>

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
Не се компилира, защото f() не е декларирана преди дефиницията на h(). Ако е, програмата ще се компилира, но ще се изпълнява безкрайно(или поне докато паметта се запълни).
</details>
<br>

**11.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
int& getValue(int& num) {
    return num; 
}


int main() {
    int x = 5;
    getValue(x) = 10;
    // x = 10;
    std::cout << "x: " << x << std::endl;
}
```
<details>
    <summary>Обяснение</summary>
int& getValue(int& arg) връща референция към подадения по референция arg, т.е. самият адрес на променливата, която сме подали при извикване на функцията. Значи върнатият резултат е lvalue и на него могат да се присвояват стойности(2ри и 3ти ред в main() означават абсолютно същото нещо в този контекст).
</details>
<br>

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
<details>
    <summary>Обяснение</summary>
Тук getValue() прави почти същото, само че и инкрементира променливата преди да я върне по референция.<br><br>
getValue(x) ще ни върне референция към 'х', което вече е увеличено с 1, но това не ни интересува, понеже му присвояваме getValue(b), което аналогично си връща референция към 'b', което вече е инкрементирано. -> принтира "х: 2"
</details>