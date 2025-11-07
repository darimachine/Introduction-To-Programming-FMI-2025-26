## "Теоретични" въпроси

**Ще се компилират ли следните примери код? Какво ще изпишат, ако се компилират? Ако не се компилират, каква е причината?**

```c++
#include <iostream>
using namespace std;

int main() {
  int a = 5;
  a+5;
  cout << a;  
}
```
<details>
    <summary>Обяснение</summary>
Изразът 'a+5' се оценява на 10, но не се записва никъде и програмата изписва '5'.
</details>
<br>

```c++
#include <iostream>
using namespace std;

int main() {
  int a = 5;
  int b = 4;
  int c = 0;
  cout << a / (!c) + b / (!a);
}
```
<details>
    <summary>Обяснение</summary>
c = 0 => 'с' се оценява на false и отрицанието му !с се оценява на true(1). <br>
a = 5 => 'a' се оценява на true(както се оценява всяка стойност, различна от 0) и отрицанието му !a се оценява на false(0) => програмата се компилира, но делим на нула и се хвърля грешка по време на изпълнението ѝ.
</details>
<br>

```c++
#include <iostream>
using namespace std;

int main() {
  int a = 5;
  int b = 0;
  cout << ((b != 0) && (a / b));
}
```
<details>
    <summary>Обяснение</summary>
Short Circuiting:<br>
- операторите && и || оценяват аргументите си отляво надясно<br>
- оператор && спира да оценява аргументите си, когато намери един със стойност false (понеже вече изразът винаги ще е false и останалите аргументи не могат да променят това)<br>
- аналогично, оператор || спира да оценява аргументите си, когато намери един със стойност true<br>
<br>
b != 0 се оценява с false, затова целият израз ((b != 0) && (a / b)) също се оценява с false, 'a / b' не се оценява изобщо и  програмата изписва 0(false)<br>
<br>
Без short circuiting-a, изразът 'а / b' също щеше да се оцени, но в него има деление на 0 => програмата щеше да гръмне
</details>
<br>

```c++
#include <iostream>
using namespace std;

int main() {
  int a = 5;
  int b = 0;
  cout << (b != 0) && (a / b);
}
```
<details>
    <summary>Обяснение</summary>
Заради приоритета на операторите, компилаторът поставя скоби така:<br>

```c++
(cout << (b != 0)) && (a / b);
```

Компилира се и има дефинирано поведение, което обаче няма смисъл и искаме да избягваме, затова винаги поставяме скоби около логически изрази.
</details>
<br>

```c++
#include <iostream>
using namespace std;

int main() {
  cout << ((true || (false && true)) && !true);
}
```
<details>
    <summary>Обяснение</summary>
Обикновено оценяване:<br>
<br>
((true || false) && false)<br>
(true && false)<br>
false<br>

</details>
<br>

```c++
#include <iostream>
using namespace std;

int main() {
  cout << (true || false && true && !true);
}
```
<details>
    <summary>Обяснение</summary>
По приоритет ! > && > ||, т.е. изразът е добре дефиниран, но е добре да се поставят допълнителни скоби за по-добра четимост.
</details>
<br>

```c++
#include <iostream>
using namespace std;

int main() {
  int a = 5;
  double b = 5;
  cout << a / 2 << endl << b / 2;
}
```
<details>
    <summary>Обяснение</summary>
а / 2 -> 2 (целочислено деление)<br>
b / 2 -> 2.5
</details>
<br>

```c++
#include <iostream>
using namespace std;

int main() {
  double a = 4.9, b = 5.5;
  int sum = a + b;
  int bToInt = b;
  int sum2 = a + bToInt;
  cout << sum << endl << sum2;
}
```
<details>
    <summary>Обяснение</summary>
int sum = 4.9 + 5.5 = 10.4, но sum е от тип int и информацията след запетаята се изтрива -> sum = 10<br>
int bToInt = b = 5.5, но отново информацията след запетаята се изтрива -> bToInt = 5<br>
int sum2 = 4.9 + 5 = 9.9 -> sum2 = 9
</details>
<br>

```c++
#include <iostream>
using namespace std;

int main() {
  double d = 4.5;
  cout << (d % 2);

  short s = d;
  cout << (s % 2);
}
```
<details>
    <summary>Обяснение</summary>
Не се компилира, операторът за модулно делене '%' работи само с цели числа(short, int, long, unsigned...).
</details>
<br>

```c++

#include <iostream>
using namespace std;

int main() {
  int num = 2;
  num *= num += 3;
  cout << num;
}
```
<details>
    <summary>Обяснение</summary>
Undefined Behaviour, понеже опитваме в един израз да присвоим стойност на една и съща променлива 'num' повече от веднъж с операторите *= и +=.
</details>

## ASCII примери

<br>
За долните примери погледнете ASCII таблицата, ако нещо не ви е ясно.
<br>

1. Конвертиране на буква от латинската азбука от главна към малка и наобратно:

```c++
#include <iostream>

using std::cout;
using std::endl;

int main() {
  char letterUpper = 'A';
  char toLower = letterUpper + ('a' - 'A');

  char letterLower = 'b';
  char toUpper = letterLower - ('a' - 'A');
    
  // also true
  // char toUpper = letterLower + ('A' - 'a');

  cout << "Original in upper: " << letterUpper << endl;
  cout << "To lower: " << toLower << endl;
  cout << "Original in lower: " << letterLower << endl;
  cout << "To upper: " << toUpper << endl;
}
```

```
Изход:

Original in upper: A
To lower: a
Original in lower: b
To upper: B
```

2. Конвертиране на числов символ към същата числова стойност:

```c++
#include <iostream>

using std::cout;
using std::endl;

int main() {
  char digitChar = '6';
  int digitASCIIcode = digitChar;
  cout << "Digit char: " << digitChar << ", Digit ASCII code: " << digitASCIIcode << endl;

  int digit = digitChar - '0';
  cout << "Digit: " << num << endl;
}
```

```
Изход:

Num char: 6, Num ASCII code: 54
Num: 6
```
<br><br>
**Задача:** Да се напише програма, която чете число от 1 до 26 и изписва съответната буква от азбуката.

<details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
  int num;
  cin >> num;
  char letterUpper = 'A' + num - 1;
  char letterLower = 'a' + num - 1;
  cout << letterUpper << " " << letterLower;
}
```
</details>
