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
<br>

```c++
#include <iostream>
using namespace std;

int main() {
  cout << ((true || (false && true)) && !true);
}
```
<br>

```c++
#include <iostream>
using namespace std;

int main() {
  cout << (true || false && true && !true);
}
```
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

## ASCII примери

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
