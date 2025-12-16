# Библиотеки, std::vector



## Кратко въведение в библиотеки
Библиотека в C++ е набор от готов код, който можем да използваме наготово.
Има два вида библиотеки:
- стандартната c++ библиотека STL (Standard Template Library) - `<iostream>`, `<cmath>`, `<vector>`
- third-party библиотеки - написани от други хора

Използваме една библиотека чрез `#include <nameoflib>` най-отгоре във .cpp файла. Една библиотека, която използваме от началото на курса е `<iostream>`. Друга такава е `<cmath>`, от която използваме `sqrt()` функцията.

Примерно: 
```c++
#include <iostream> // includes library for input/output
#include <cmath> // includes library for math expressions

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
```

Сега ще се запознаем с `vector` библиотеката.

## std::vector

### ⚠️ std::vector <span style="color: red">НЕ</span> е част от стандартния курс по УП и може да се използва САМО в курсовите проекти и то САМО ако ръководителят на курсовия проект, който сте записали, разрешава. Демек, <span style="color: red">НЕ МОЖЕ</span> да го използвате на контролни, <span style="color: red">НЕ МОЖЕ</span> да го използвате за решаването на задачите в семинарите и практикумите и <span style="color: red">НЕ МОЖЕ</span> да го използвате на изпита.

### Какво е std::vector?
std::vector е контейнер в C++, който представлява динамичен масив.
- Динамичен означава, че може да променя размера си по време на работа на програмата, за разлика от обикновения масив, който има фиксиран размер.
- Съхранява елементи подредено, като масив, и можем да имаме достъп по индекс: v[i].
- Позволява лесно добавяне и премахване на елементи

### Защо ни е std::vector?
- Не трябва да знаем размера на масива предварително.
- Не се налага да управляваме ръчно паметта (ще си говорим повече като вземем указатели).
- Много по-гъвкав за употреба от масивите с фиксирана дължина.

### Въведение в `std::vector` и основни операции

#### 1. Включване на библиотеката

За да използваме `std::vector`, трябва да включим библиотеката:

```cpp
#include <vector>
```

#### 2. Създаване на вектор

```cpp
std::vector<int> v;          // празен вектор
std::vector<int> v2(5);      // вектор с 5 елемента, всички със стойност 0
std::vector<int> v2(5, 30);      // вектор с 5 елемента, всички със стойност 30
std::vector<int> v3 = {1, 2, 3}; // инициализиран с конкретни стойности
```

* `v` – празен
* `v2` – фиксиран начален размер
* `v3` – инициализиран с конкретни числа

#### 3. Добавяне на елементи

```cpp
v.push_back(10); // добавя елемент в края
v.push_back(20);
```

#### 4. Достъп до елементи

```cpp
for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << " ";
}
std::cout << std::endl;
```

* `v[i]` – достъп по индекс
* `v.size()` – текущ брой елементи

#### 5. Премахване на елементи

```cpp
v.pop_back(); // премахва последния елемент
```

#### 6. Вмъкване и премахване на елементи в средата

##### Вмъкване с `.insert`

```cpp
    std::vector<int> v = {1, 2, 4, 5};
    v.insert(v.begin() + 2, 3); // добавя 3 на позиция 2
```
- `.insert(pos, value)` добавя елемент на дадена позиция.
- Позицията се задава с итератор (`v.begin() + индекс`).

##### Премахване с `.erase`

```cpp
v.erase(v.begin() + 1); // премахва елемента на позиция 1
```
- `.erase(pos)` премахва елемент на конкретна позиция.
- Може да се използва и диапазон: `v.erase(v.begin()+1, v.begin()+3)`.

#### 7. Примерна програма

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    numbers.push_back(5);
    numbers.push_back(10);
    numbers.push_back(15);

    std::cout << "Nums:";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << " " << numbers[i];
    }

    numbers.pop_back();
    std::cout << "Size after pop_back:" << numbers.size() << std::endl;

    numbers.insert(numbers.begin() + 1, 7);
    std::cout << "After insertion at pos 1:";
    for (int n : numbers) 
        std::cout << " " << n;

    numbers.erase(numbers.begin());
    std::cout << "After erase at pos 1:";
    for (int n : numbers) 
        std::cout << " " << n;

    return 0;
}
```

# Потоци и файлове. Текстови файлове.

### Видове потоци

Поток (stream) - последователност от байтове данни влизащи в и излизащи от програмата.

- При операциите за вход, байтовете идват от източник за вход (клавиатура, файл, мрежа или друга програма)
- При операциите за изход, байтовете данни излизат от програмата и се "вливат" във външно "устройство" (конзола, файл, мрежа или друга програма)
- Потоците служат като посредници между програмите и самите IO устройства по начин, който освобождава програмиста от боравене с тях.
- Потокът дефинира интерфейс с операции върху него, които не зависят от избора на IO устройство

  ![enter image description here](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/raw/main/Sem.%2002/img/streams.png)  
  За да извърши вход или изход, една C++ програма:

  - Създава поток;
  - Свързва потока с IO устройството (напр. конзола, клавиатура, файл, мрежа или друга програма);
  - Извършва операции за вход/изход върху потока;
  - Прекъсва връзка с потока;
  - Освобождава потока;

Видове потоци:

- Потоци за вход ([istream](https://en.cppreference.com/w/cpp/io/basic_istream)).
- Потоци за изход ([ostream](https://en.cppreference.com/w/cpp/io/basic_ostream)).

![enter image description here](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/raw/main/Sem.%2002/img/hierarchy.png)

##### Пример за работа с вход от конзолата. [cin](https://en.cppreference.com/w/cpp/io/cin) (обект от тип istream).

```c++
#include <iostream>

int main() {
	int a, b;
	std::cin >> a >> b; // read two integers from the console input stream
}
```

Четем от стандартния вход.

##### Пример за работа с поток за изход. [cout](https://en.cppreference.com/w/cpp/io/cout) (обект от тип ostream).

```c++
#include <iostream>

int main() {
	int a = 10;
	int b = 12;
	int c = a + b;

	std::cout << a << " + " << b << " = " << c << std::endl; // write two integers in the console output stream
}
```

### Работа с поток за вход от файл ([ifstream](https://en.cppreference.com/w/cpp/io/basic_ifstream))

Пример за четене от файл!

```c++
#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "myFile.txt";

int main() {
	std::ifstream file(FILE_NAME); // create input file stream associated with myFile.txt

	if (!file.is_open()) {
		std::cout << "Error!" << std::endl;
		return -1;
	}

	int a, b;
	file >> a >> b;

	file.close();
}
```

Пример за прочитане на цялото съдържание файл:

```c++
#include <iostream>
#include <fstream>

constexpr int BUFF_SIZE = 1024;
constexpr char FILE_NAME[] = "myFile.txt";

int main() {
	std::ifstream file(FILE_NAME);

	if (!file.is_open()) {
		std::cout << "Error!" << std::endl;
		return -1;
	}

	while (!file.eof()) {
		char buff[BUFF_SIZE];
		file.getline(buff, BUFF_SIZE);

		//do something with the line
		std::cout << buff << std::endl;
	}

	file.close();
}
```

### Работа с поток за изход към файл ([ofstream](https://en.cppreference.com/w/cpp/io/basic_ofstream))

```c++
#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "myFile.txt";

int main() {
	std::ofstream file(FILE_NAME);  // create output file stream associated with myFile.txt

	if (!file.is_open()) {
		std::cout << "Error!" << std::endl;
		return -1;
	}

	int a = 3;
	int b = 10;

	file << a << " " << b << " " << a + b << std::endl; // write into the output file stream

	if(!file.eof()) { //check if the file has ended
		std::cout << "The file contains more data after the two integers!" << std::endl;
	}

	file.close();
}
```

- (istream) [get](https://en.cppreference.com/w/cpp/io/basic_istream/get) - функция, която чете следващия character в потока.
- (ostream) [put](https://en.cppreference.com/w/cpp/io/basic_ostream/put) - функция, която поставя на следваща позиция character в потока.
- ifstream или istream - съдържа get указател, който реферира елемента, който ще се прочете при следващата входна операция.
- ofstream или ostream - съдържа put указател, който реферира мястото, където ще се запише следващият елемент.
- put и get не са [форматирани](https://www.geeksforgeeks.org/unformatted-input-output-operations-in-cpp/) за разлика от operator<< и operator>>, тоест не пропускат whitespaces и др.
---


```plaintext
                 ios
              /        \
       istream          ostream
      /       \        /       \
  ifstream     iostream      ofstream
              /       \
        fstream      stringstream
```

Всички потоци за вход (`ifstream`) в себе си съдържат **get** указател. Всички потоци за изход (`ofstream`) в себе си съдържат **put** указател. 

В себе си `fstream` съдържа `един` **get** и **put** указател, като при входна операция, след изходна, трябва да се прави синхронизация на потока: `flush() <=> seekg(tellg())`

## Форматиран вход и изход
- **Форматиран вход:** `<Поток за вход> >> <Обект>`
- **Форматиран изход:** `<Поток за изход> << <Обект>`

Операторите `>>` и `<<`:
- Пропускат whitespaces (`' '`), но не и newlines (`\n`)
- Връщат референция към потока, което позволява да ги **chain**-ваме

**Пример:**

```c++
std::cout << "Test product: " << 3 << " * " << 7 << " = " << 21 << std::endl;
```

- `std::cout` е обект от тип `ostream`, като това ни позволява да използваме оператор `<<`
- `std::cin` е обект от тип `istream`, като това ни позволява да използваме оператор `>>`

## Неформатиран вход и изход

### Неформатиран изход:

- `ostream& put(char ch)` - поставя символ на позицията, където сочи **put** указателя, като премества **put** указателя една позиция напред
- `ostream& write(const char* str, size)` - писане в двоичен файл

### Неформатиран вход:

- `int get()` - връща ASCII код, отговарящ на символа, към който сочи **get** указателя, като го премества една позиция напред
- `int peek()` - връща ASCII код, отговарящ на символа, към който сочи **get** указателя, като **НЕ** го мести напред
- `istream& get(<buffer>, <size>, <delimiter>)` - прочита символи от потока, докато не се прочетат **(size - 1)** на брой символа, или докато не се срещне подаденият разделител. По **default**, ако не означим разделител, се използва newline (`\n`).
- `istream& getline(<buffer>, <size>, <delimiter>)` - прочита символи от потока, докато не се прочетат **size** на брой символа, или докато не се срещне подаденият разделител. По **default**, ако не означим разделител, се използва newline (`\n`).
- `istream& read(char* str, size)` - четене от двоичен файл
- `istream& ignore()` - премества **get** указателя с една позиция
- `istream& ignore(<size>, <delimiter>)` - премества **get** указателя с **n** позиции напред, или докато срещне подадения разделител

**ВАЖНО!!!** При `.get()` разделителят не се прочита, докато при `.getline()` се прочита

## Позициониране при потоците за вход и изход

### Позициониране при потоците за изход

- `.tellp()` - връща позицията на **put** указателя
- `.seekp(<position>)` - мести **put** указателя до дадения **position**
- `.seekp(<offset>, <direction>)` - мести **put** указателя с **offset** на брой позиции спрямо **direction**

### Позициониране при потоците за вход

- `.tellg()` - връща позицията на **get** указателя
- `.seekg(<position>)` - мести **get** указателя до дадената позиция
- `.seekg(<offset>, <direction>)` -  мести **get** указателя с **offset** на брой позиции спрямо **direction**

`direction` може да бъде една от следните позиции:
- `std::ios::beg` - начало на файла
- `std::ios::cur` - текуща позиция във файла
- `std::ios::end` - край на файла



### [Режими на работа](https://en.cppreference.com/w/cpp/io/ios_base/openmode)

```c++
std::ifstream str("file.txt", <режим на работа>).
```

### Комбиниране на режими на работа

```c++
std::ofstream ofs(<file_name>, std::ios::out | std::ios::app);
```

Режимът на работа е цяло число. Ако искаме да зададем повече от един ги изреждаме с двоично или('|').

| ios              | Ефект:                                                                                                                           |   Бит  |
| ---------------- | -------------------------------------------------------------------------------------------------------------------------------- | --- |
| ios::in          | Отваря файл за извличане.                                                                                                        | 1   |
| ios::out         | Отваряне на файл за вмъкване. Допуска се вмъкване на произволни места във файла. Ако файлът съществува, съдържанието се изтрива. | 2   |
| ios::ate         | Отваря за вмъкване и установява указателя put в края на файла. Допуска вмъкване на произволни места.                             | 4   |
| ios::app         | Отваря за вмъкване и установява указателя put в края на файла                                                                    | 8   |
| ios::trunc       | Ако файлът съществува, съдържанието се изтрива.                                                                                  | 16  |
| ios::binary      | Превключва режима от текстов в двоичен                                                                                           | 32  |
| ios::\_Nocreate  | Отваря за вмъкване, само ако файлът с указаното име съществува.                                                                  | 64  |
| ios::\_Noreplace | Отваря за вмъкване само ако файлът с указаното име не съществува.                                                                | 128 |

