# Подготовка за контролно 1

**1.** Кой от следните оператори не работи само с булева стойност?

- if
- switch
- &&
- ||

---
**2.** Напишете фунцкия `bool equals(double a, double b)`, която сравнява подадените им числа дали са равни. Ако са равни връща `true` иначе `false`

---
**3.** Дали ще се компилира следния код? Ако да какво ще изведе, Ако не Защо?
```cpp
#include <iostream>
int value = 42;
void f(int value) {
    value = 9;
    ::value = value;
}

int main() {
    int value = 3;
    std::cout << value << "\n";
    std::cout << ::value << "\n";

    f(value);
    std::cout << ::value << "\n";
    std::cout << value << "\n";
    return 0;
}
```
**4.** Какво ще изведе дадената операция Опишете в едно изречение?

```cpp
for (int i = 0; i < 100; i++) {
    for(int i = 0; i < 100; i++) {
        cout << i << " ";
    }
    cout << endl;
}
```


---

**5.** Какво ще се случи при този код?

```cpp
int main() {
    f();
    return 0;
}
void f() {
    cout << "f()" << endl;
}
```

---

**6.**
Какво прави следната функция?

```cpp
void swap(double a, double b) {
    double c = a;
    a = b;
    b = c;
}
```

---

**7.** Какво ще отпечата следния код?

```cpp
#include <iostream>
bool f() {
    std::cout << 5;
    return false;
}
bool g() {
    std::cout << 123;
    return true;
}
bool h() {
    std::cout << 0;
    return true;
}
void k()
{
    std::cout << (h() || g() || f()) << std::endl;
    std::cout << (g() && f() && h()) << std::endl;
}
int main()
{
    k();
}
```

---
**8.** Какво ще върне следната функция?
```cpp
double f()
{
     double num1 = 4;
     double num2 = 4 / 7;
     return (num2-- = ++++num1 + 2);
}
```
---

**9.** Какво ще изведе този код на конзолата?

```cpp
#include <iostream>

int main() {
    int x = 2;
    switch (x) {
        case 1:
            std::cout << "One" << std::endl;
        case 2:
            std::cout << "Two" << std::endl;
        case 3:
            std::cout << "Three" << std::endl;
        default:
            std::cout << "Default" << std::endl;
    }
    return 0;
}
```

---

**10.** Какво ще изведе този код на конзолата?

```cpp
#include <iostream>

int main() {
    for (int i = 0; i < 5; i++); {
        std::cout << "i = " << i << std::endl;
    }
    return 0;
}
```
---

**11.** Какво ще изведе този код на конзолата?

```cpp
#include <iostream>

int main() {
    int i = 10;
    while (i = 5) {
        std::cout << i << " ";
        i--;
    }
    return 0;
}
```
**12** Какво ще изведе този код на конзолата
```cpp
int i = 0;
while (++i, ++i < 14) {
    do
    {
        cout << i * 2 << endl;
    } while (i++ < 5);
}
```
---

**13.** Напишете еквивалентен код на следния програмен фрагмент, като използвате оператор switch веднъж (и не използвате if):

```cpp
int a;
if (a == 1)
    cout << “one”;
if (a != 3)
    cout << “13”;
else if (a > 3)
    cout << “big”;
else
    cout << “error”;
```

**14** Напишете еквивалентен код на следния програмен фрагмент, като използвате оператор switch веднъж (и не използвате if):

```cpp
(x == 10) && cout << "xyz";
((x == 4) || (x == 6)) ? cout << "this" :
	((x >= 6) && (x <= 8)) ? cout << "correct" : cout << "undef";
```

---

**15.** Опишете последователно точно какво ще изведе на екрана следният програмен фрагмент. Обосновете писмено подробно отговора си.

```cpp
for (int i = 9; i <= 16; cout << i << endl) i++;
```

---

**16.** Ще се компилира ли следният програмен фрагмент:

```cpp
int num1 = 5;
int num2 = 13;
num2++ = ++num1 + 12;
```

В случай че компилацията е възможна, каква стойност ще има
променливата num2 след изпълнението му?

**17.** Опишете последователно точно какво ще изведе на екрана следният програмен фрагмент. Обосновете писмено подробно отговора си.
```cpp
for (int i = -10; i++; i++) cout << i << ' ' << endl;
```
