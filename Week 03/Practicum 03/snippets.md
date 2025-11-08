## Code Snippets

```c++
#include <iostream>
int main()
{
    int a = 2;
    int b = 4;
    int c = a * b;
    std::cout << (++a) * c + (b--) / 3 + c;
}
```
<details>
    <summary>Обяснение</summary>
- префиксен оператор ++а -> инкрементира 'а' с 1 и връща референция към 'а', т.е. lvalue, в което се пази новата му стойност<br>
- постфиксен оператор а++ -> инкрементира 'а' с 1 и връща стойността 'а-1', т.е. rvalue
</details>
<br>

```c++
#include<iostream>

int main() {
    int a = 0;

    if (a = 5) {
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }
}
```
<details>
    <summary>Обяснение</summary>
'а = 5' присвоява стойността 5 на 'а' и след това оценява самото 'а', т.е. 5, което е != 0 и се оценява на true.
</details>
<br>

```c++
#include<iostream>

int main() {
    int a = 1;

    if (a == 0); {
        std::cout << "true";
    }
}
```
<details>
    <summary>Обяснение</summary>
Това е обикновен scope, а не тяло на if, понеже след скобите (а == 0) има ';', което означава, че това е краят на if statement-а, т.е. if-ът няма тяло, а в scope-а се влиза винаги, независимо от стойността на 'а'.
</details>
<br>

```c++
#include <iostream>
int main()
{
    int a = 2;
    int b = 4;
    if(a, b - 2* a)
        std::cout << a;
    else
        std::cout << 100;
}
```
<details>
    <summary>Обяснение</summary>
Оператор ',' оценява всички изрази, но връща само оценката на последния, в случая 'b - 2 * a', която е == 0 -> влизаме в else.
</details>
<br>

```c++
#include<iostream>

int main() {
    switch (x) {
    default:
        std::cout << "no match\n";
        break;
    case 1:
        std::cout << "one\n";
        break;
    case 2:
        std::cout << "two\n";
        break;
    }
}
```
<details>
    <summary>Обяснение</summary>
Тук всеки случай в switch-a има break; -> ако х е 1 или 2, влиза в конкретния случай, а за всички останали стойности - в default.
</details>
<br>

```c++
#include<iostream>

int main() {
    int x=3;
    switch (x) {
    default:
        std::cout << "no match -> ";
    case 1:
        std::cout << "one-or-after-default\n";
        break;
    case 2:
        std::cout << "two\n";
        break;
    }
}
```
<details>
    <summary>Обяснение</summary>
Тук в default случая няма 'break;' -> ако х е различно от 1 и 2, ще се влезе в default и ще се изпълнят командите в него, като след това ще започне да се 'пропада' по случаите един по един, докато не се стигне до някой, в който има 'break;'.
</details>
<br>

```c++
#include <iostream>

int main() {
    int x = 1;
    switch (x) {
        case 1:
            std::cout << "A";
        case 2:
            std::cout << "B";
        default:
            std::cout << "C";
    }
}
```
<details>
    <summary>Обяснение</summary>
Нито един случай няма 'break;' -> в който от тях да влезем, ще 'пропаднем' до последния.
</details>
<br>

```c++
#include <iostream>

int main() {
    for (int i = 0, j = 10; i < j; i++, j--)
        std::cout << i << " " << j << "\n";
}
 
```
<details>
    <summary>Обяснение</summary>
int i = 0, j = 10 -> инициализация - изпълнява се само веднъж, в началото на цикъла<br>
i < j -> проверка - изпълнява се преди всяка итерация на цикъла и го прекъсва, ако се оцени с false<br>
i++, j-- -> инкрементация - изпълнява се след всяка итерация на цикъла<br>
<br>
Изписва се:<br>
0 10<br>
1 9<br>
2 8<br>
3 7<br>
4 6
</details>
<br>

```c++
#include <iostream>
int main()
{
    int a = 10;
    while (a)
    {
        a++;
        std::cout << a--<<std::endl;
        a--;
    }
}
```
<details>
    <summary>Обяснение</summary>
На всяка итерация на цикъла:<br>
- оценява се 'а' и цикълът приключва, ако 'а == 0'<br>
- 'а' се увеличава с 1 от 'а++'<br>
- изписва се 'а--' на конзолата, т.е. 'а' се намаля с 1, но се изписва ненамалената стойност<br>
- 'а' отново се намаля с 1 от 'а--'<br>
<br>
На всяка итерация на цикъла се изписва числото 'b = а0 + 1', такова че 'а0' е числото, оценено в началото на текущата итерация на цикъла, а на следващата итерация се оценява числото 'а1 = b - 2' -> ще се изпишат числата от 11 до 2, понеже на първата итерация 'а0 == 10'(b == 10 + 1), а последното 'а1', което ще се оцени, е '0', т.е. последно ще се изпише '0+2'.
</details>                 
<br>

```c++
#include <iostream>
int main()
{
    int a = 0;
    do
    {
        std::cout << "a";
    } while(a);
}
```

<details>
    <summary>Обяснение</summary>
do-while гарантира поне едно изпълнение на тялото си, понеже оценката на условието става СЛЕД изпълнението на тялото, т.е. тук тялото ще се изпълни веднъж и веднага след това ще бъде направена проверката 'while(a)' и цикълът ще спре.
</details> 
<br>