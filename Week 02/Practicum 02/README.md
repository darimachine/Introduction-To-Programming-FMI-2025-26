## Live Coding
Даден е **затворен интервал от ASCII кодове [a, b]**, **начален символ (код) x** и **цяло число k.** Да се намери **ASCII кодът**, получен при **циклично изместване** на символа **x** с **k** позиции в рамките на интервала **[a, b].**

**Вход:**
На един ред са дадени четири цели числа (или символи, ако предпочетете въвеждане като букви):
```
a b x k
```
където:
- **a** – ASCII код (или символ) на началото на интервала;
- **b** – ASCII код (или символ) на края на интервала;
- **x** – ASCII код (или символ), който ще изместваме;
- **k** – цяло число, показващо броя позиции за изместване (може да е отрицателно или много голямо).

**Изход:**
Едно цяло число – **ASCII кодът на символа**, получен след изместването.

**Детайли** (какво означава “циклично”): ако минем края **b, “прескачаме” в началото a**, и обратно при отрицателни стъпки.

**Примери:**

**Вход:**

```
a d c 3
```

**Изход:**
```
b
```

**Вход:**

```
a d c -3
```

**Изход:**
```
d
```


## Задачи

**Задача 1.** Напишете програма, която чете 3 символа и изписва 1, ако сборът от ASCII кодовете им е четен, и 0, ако не е.


Вход:
```
 a f X
```
Изход:
```
 0
```

<!-- <details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    char a,b,c;
    cin >> a >> b >> c;

    cout << ((a + b + c) % 2 == 0);
}
```
</details> -->

**Задача 2.** Напишете програма която приема номер на кредитна карта(16 цифри). Програмата да изведе същия този номер, но със скрити първите 12 цифри.

Вход:
```
 7834952438523794
```

Изход:
```
 ХХХХХХХХХХХХ3794
```

<!-- <details>
 <summary>Решение</summary>

```c++

#include <iostream>
using namespace std;

int main() {
    unsigned long long a;
    cin >> a;
    int last = (a % 10000);
    cout << "XXXXXXXXXXXX" << last << endl;
}
```
</details> -->

**Задача 3.** Напишете програма, която чете 2 числа(>=10) от конзолата и извежда число, образувано от последните две цифри на първото, долепени вляво от последните две цифри на второто.


Вход:
```
 1234 5678
```
Изход:
```
 3478
```

<!-- <details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;

    cout << (a % 100) << (b % 100);
}
```
</details> -->


**Задача 4.** Напишете програма, която чете 3 положителни числа и изписва 1, ако съществува триъгълник с такива страни, и 0, ако не съществува.


Вход:
```
 3 4 5
```
Изход:
```
 1
```

Вход:
```
 1 2 3
 ```
Изход:
```
 0
```
<!-- <details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    bool first = a + b > c;
    bool second = a + c > b;
    bool third = b + c > a;

    cout << (first && second && third);
}
```
</details> -->

**Задача 5.** Напишете програма, която въвежда три естествени числа `a`, `b` и `c` и като резултат връща корените на квадратното уравнение `a`<sup>2</sup>x + `b`x + `c` = 0 (приемете, че винаги ще има реални корени).

Hint:

```cpp
#include <math.h>
using namespace std;
int main() {
    double x = 49;
    cout << sqrt(x); // 7.0
}
```

**Пример**:<br>
Вход:

```text
1 2 1
```

Изход:

```text
x1 = -1
x2 = -1
```

<!-- <details>
<summary>Решение</summary>

```cpp
#include <iostream>
#include <math.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int discriminant = 0;
	double x1 = 0;
	double x2 = 0;

	std::cout << "Please enter a, b and c: "; std::cin >> a >> b >> c;

	discriminant = b * b - 4 * a * c;

	if (discriminant < 0) {
		std::cout << "Roots are complex conjugate" << std::endl;
	} else if (!discriminant) {
		x1 = -b / 2 * a;
		std::cout << "x1 = " << x1 << std::endl;
		std::cout << "x2 = " << x1 << std::endl;
	} else {
		x1 = -b + sqrt(discriminant) / 2 * a;
		x2 = -b - sqrt(discriminant) / 2 * a;

		std::cout << "x1 = " << x1 << std::endl;
		std::cout << "x2 = " << x2 << std::endl;
	}

	return 0;
}
```
</details> -->


**Задача 6.** Напишете програма, която чете цяло число - брой секунди, и изчислява колко дни, часове, минути и секунди са.


Вход:
```
 533628
```
Изход:
```
 6 дена, 4 часа, 13 минути и 48 секунди
```

<!-- <details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    int s;
    cin >> s;

    // calculate days
    const int secsInDay = 60*60*24;
    int days = s / secsInDay;
    // leave only remaining seconds
    // which dont make a full day
    int remSecs = s % secsInDay;

    // calc hours from remaining seconds
    const int secsInHour = 60*60;
    int hours = remSecs / secsInHour;
    // leave only remaining seconds
    // which dont make an hour
    remSecs %= secsInHour;

    // calc minutes
    const int secsInMinute = 60;
    int mins = remSecs / secsInMinute;
    // leave only seconds
    remSecs %= secsInMinute;

    cout << days << " days, " << hours
    << " hours, " << mins << " minutes, "
    << remSecs << " seconds";
}
```
</details> -->

**Задача 7.** Напишете програма, която чете 4 цели числа - *a*,*b*,*c* и *d*. Програмата да извежда:

- 0, ако *c* и *d* са извън интервала [a,b];
- 1, aко *c* или *d* е в интервала [a,b];
- 2, ако *c* и *d* са в интервала [a,b].

 Можем да приемем, че във всеки вход *a* ще е по-малко от *b*.


Вход:
```
 1 3 2 0
```
Изход:
```
 1
```

<!-- <details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool cIn = (c >= a && c <= b);
    bool dIn = (d >= a && d <= b);

    cout << cIn + dIn;
}
```
</details> -->

**Задача 8.** Напишете програма, която чете ***четирицифрено*** число и извежда сумата, произведението и средноаритметичното на цифрите му.


Вход:
```
 1234
```
Изход:
```
 Сбор: 10
 Произведение: 24
 Средноаритметично: 2.5
```

<!-- <details>
 <summary>Решение</summary>

```c++
#include <iostream>
using std::cout;
using std::cin;

int main() {
    int num;
    cin >> num;

    double sum = 0, product = 1;

    int digit = num % 10;
    num /= 10;
    sum += digit;
    product *= digit;

    digit = num % 10;
    num /= 10;
    sum += digit;
    product *= digit;

    digit = num % 10;
    num /= 10;
    sum += digit;
    product *= digit;

    digit = num % 10;
    num /= 10;
    sum += digit;
    product *= digit;

    cout << "Sbor: " << sum << endl;
    cout << "Proizvedenie: " << product << endl;
    cout << "Average: " << sum / 4 << endl;
}
```
</details> -->

**Задача 9.** Напишете програма, която чете цяло число - година, и извежда 1, ако годината е високосна, и 0, ако не е.

- година, деляща се на числото 4 без остатък, е високосна;
- ако годината обаче също се дели без остатък на 100, то тя не е високосна;
- но ако годината също се дели без остатък и на 400, то тя пак ще е високосна.


Вход:
```
 1900
```
Изход:
```
 0
```
Вход:
```
 2000
```
Изход:
```
 1
```

<!-- <details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    int y;
    cin >> y;
    bool firstCond = (y % 4 == 0);
    bool secondCond = (y % 100 != 0);
    bool thirdCond = (y % 400 == 0);
    
    cout << (thirdCond || (firstCond && secondCond));
}
```
</details> -->