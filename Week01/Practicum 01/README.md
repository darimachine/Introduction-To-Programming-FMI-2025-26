## Задачи

**Задача 1.** Напишете програма, която извежда следния текст на конзолата:

```
UP kursut e
mnogo gotin!
Da, vsichki nie
obichame UP kursa!
```

<details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    cout << "UP kursut e" << endl;
    cout << "mnogo gotin!\n";
    cout << "Da, vsichki nie\n";
    cout << "obichame UP kursa!\n";
}
```
</details>

**Задача 2.** Напишете програма, която извежда следната фигура на конзолата:

```
  *
 ***
*****
```

<details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    cout << "  *  \n";
    cout << " *** \n";
    cout << "*****\n";
}
```
</details>

**Задача 3.** Напишете програма, която чете 2 числа(>=10) от конзолата и извежда число, образувано от последните две цифри на първото, долепени вляво от последните две цифри на второто.

```
Вход:
 1234 5678
Изход:
 3478
```

<details>
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
</details>

**Задача 4.** Напишете програма, която чете 2 числа и изписва техните сбор, разлика, произведение и частно.

```
Вход:
 10 4
Изход:
 Сбор: 14
 Разлика: 6
 Произведение: 40
 Частно: 2
```

<details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;

    cout << "Sbor: " << a+b << endl;
    cout << "Razlika: " << a-b << endl;
    cout << "Proizvedenie: " << a*b << endl;
    cout << "Chastno: " << a/b << endl;
}
```
</details>

**Задача 5.** Напишете програма, която чете число - диаметър на окръжност, и отпечатва нейните лице и обиколка(използвайте Pi=3.14).

```
Вход:
 10
Изход:
 Лице: 78.5
 Обиколка: 31.4
```

<details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    double d;
    cin >> d;
    const double Pi = 3.14;

    cout << "Lice: " << (d/2)*(d/2)*Pi << endl;
    cout << "Obikolka: " << d*Pi << endl;
}
```
</details>

**Задача 6.** Напишете програма, която чете цяло число - брой секунди, и изчислява колко дни, часове, минути и секунди са.

```
Вход:
 533628
Изход:
 6 дена, 4 часа, 13 минути и 48 секунди
```

<details>
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
</details>

**Задача 7.** Напишете програма, която чете две реални числа и разменя стойностите им(пробвайте и без допълнителна променлива).

```
Вход:
 A: 1.6
 B: 2.1
Изход:
 A: 2.1
 B: 1.6
```

<details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    double a,b;
    cin >> a >> b;

    cout << "a: " << a << ", b: " << b << endl;

    a = a + b;
    b = a - b;
    a = a - b;

    cout << "a: " << a << ", b: " << b << endl;
}
```
</details>

**Задача 8.** Напишете програма, която чете 3 символа и изписва 1, ако сборът от ASCII кодовете им е четен, и 0, ако не е.

```
Вход:
 a f X
Изход:
 0
```

<details>
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
</details>

**Задача 9.** Напишете програма, която чете цяло число - година, и извежда 1, ако годината е високосна, и 0, ако не е.

- година, деляща се на числото 4 без остатък, е високосна;
- ако годината обаче също се дели без остатък на 100, то тя не е високосна;
- но ако годината също се дели без остатък и на 400, то тя пак ще е високосна.

```
Вход:
 1900
Изход:
 0

Вход:
 2000
Изход:
 1
```

<details>
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
</details>

**Задача 10.** Напишете програма, която чете ***четирицифрено*** число и извежда сумата, произведението и средноаритметичното на цифрите му.

```
Вход:
 1234
Изход:
 Сбор: 10
 Произведение: 24
 Средноаритметично: 2.5
```

<details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

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
</details>

**Задача 11.** Напишете програма, която чете 4 цели числа - *a*,*b*,*c* и *d*. Програмата да извежда:

- 0, ако *c* и *d* са извън интервала [a,b];
- 1, aко *c* или *d* е в интервала [a,b];
- 2, ако *c* и *d* са в интервала [a,b].

 Можем да приемем, че във всеки вход *a* ще е по-малко от *b*.

```
Вход:
 1 3 2 0
Изход:
 1
```

<details>
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
</details>

**Задача 12.** Напишете програма, която чете 3 положителни числа и изписва 1, ако съществува триъгълник с такива страни, и 0, ако не съществува.

```
Вход:
 3 4 5
Изход:
 1

Вход:
 1 2 3
Изход:
 0
```

<details>
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
</details>

**Задача 13.** Напишете програма, която приема 4 цели числа и отпечатва 1, ако числата образуват *аритметична* прогресия в реда, в който са въведени, и 0, ако не образуват.

```
Вход:
 1 2 3 4
Изход:
 1

Вход:
 7 6 3 2
Изход:
 0
```

<details>
 <summary>Решение</summary>

```c++
#include <iostream>
using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    cout << ((b - a) == (c - b)) && ((c - b) == (d - c));
}
```
</details>

**Задача 14.** Аналогично на задача 13, напишете програма, която проверява дали 4 числа са *геометрична* прогресия.

```
Вход:
 1 2 4 8
Изход:
 1

Вход:
 1 3 5 7
Изход:
 0
```

<details>
 <summary>Решение</summary>

```c++

#include <iostream>
using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    double q1 = 1.00 * b / a;
    double q2 = 1.00 * c / b;
    double q3 = 1.00 * d / c;
    
    cout << (q1 == q2) && (q2 == q3);
}
```
</details>

**Задача 15.** Напишете програма която приема номер на кредитна карта(16 цифри). Програмата да изведе същия този номер, но със скрити първите 12 цифри.

```
Вход:
 7834952438523794
Изход:
 ХХХХХХХХХХХХ3794
```

<details>
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
</details>
