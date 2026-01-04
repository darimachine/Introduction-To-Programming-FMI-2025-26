## Сложности
- Какво е сложност? Как сравняваме сложности?
- Сложност по време - Best, Worst, Average, Amortized 
- Сложност по памет - Best, Worst, Average, Amortized 
- https://devopedia.org/algorithmic-complexity

### Big O notation
- [cheatsheet](https://www.bigocheatsheet.com/)

### Видове сложности:

- константа - *O(1)*
- логаритмична - *О(logN)*
- линейна - *O(N)*
- енлог - *O(NlogN)*
- квадратична - *O(N<sup>2</sup>)*
- кубична - *O(N<sup>3</sup>)*
- експоненциална - *O(c<sup>N</sup>)*

Ред на нарастване на времето:

>*1 < logN < sqrtN < N < NlogN < N<sup>2</sup> < N<sup>3</sup> < 2<sup>N</sup> < 3<sup>N</sup> < N! < N<sup>N</sup>*

<img width="1201" height="794" alt="image" src="https://github.com/user-attachments/assets/282344ab-b0fc-438a-a463-052450b71b8a" />


### Правила за смятане на Big O изрази:

- константите, които са множители не влияят.
  > *O(100N) = O(N)*

- влияе само най-бързо растящата функция, при сбор от множители.
  > *О(N<sup>2</sup> + NlogN + N + 1) = O(N<sup>2</sup>)*

- при произведение от множители, влияят всички функции.
  > *O(N<sup>2</sup> log<sup>3</sup>N) не може да бъде опростено.

- основата на логаритъма не влияе.
  > *O(log<sub>2</sub>N) = O(log<sub>3</sub>N)*

    Изписва се просто *O(logN)*.
    Това не важи за степента на логаритмична функция (по-горния пример).
    
---

Примери:
- *О(2N) = O(N) = O(10000N)*
- *O(10000000) < O(logN)*
- *O(N + M)*

При невъзможност да се определи коя функция е по-голяма *N* или *М*, изразът *O(N + M)* не може да бъде опростен.


<details>
  <summary><b>Колко разлика оказва сложността? (практичен пример)</b></summary>

Нека имаме 2 компютъра. Компютър А е най-бързият за времето си със производителност 10 милиарда операции в секунда. Компютър Б е обикновен компютър и изчислява 10 милиона операции в секунда.

Задачата на компютрите е да сортират масив с 10 милиона елемента. 

Машина А използва Insertion sort със сложност *2N<sup>2</sup>*. Машина Б използва Мerge sort със сложност *50NlogN*.

За колко време всяка машина ще се справи със задачата?

Суперкомпютър А:
- S<sub>1</sub> = 2N<sup>2</sup> стъпки, за N = 10<sup>7</sup>
- V<sub>1</sub> = 10<sup>10</sup> стъпки/ сек
- => t<sub>1</sub> = 20000 сек. = ~5.5 ч.

Компютър Б:
- S<sub>2</sub> = 50NlogN стъпки, за N = 10<sup>7</sup>
- V<sub>2</sub> = 10<sup>7</sup> стъпки/ сек
- => t<sub>2</sub> = ~1163 сек. = ~20 мин.

Въпреки разликата в производителността и константите в алгоритмите (*2 и 50*), резултатите са коренно различни.

Още по-съществена разлика се наблюдава при увеличаване на големината на масива 10 пъти. При N = 100 милиона числа, компютър **А** отнема **23 дни**, а компютър **Б** - **4 часа**.

</details>

### Изчислете сложностите по време на следните алгоритми:


# Алгоритми за сортиране

- Тест среда да изпробвате някои алгоритми - [hackerrank contest](https://www.hackerrank.com/contests/algorithms-implementation-test-environment/challenges)
- Сайт с визуализация на алгоритмите - [visualalgo](https://visualgo.net/en/sorting)
- Опростена версия на README-то за Python: [линк](./Python_simple_README.md)


## Locality
  - Дефиниране
	- свойството на процесора, при което той прехвърля в своя кеш често използвани или съседни данни, за да ги достъпва по-бързо при следващи операции.
    - CPU cache - малка, бърза памет в процесора, която съхранява често използвани данни и инструкции, за да ускори достъпа до тях и да подобри производителността.
      - instruction cache - съхранява често използвани машинни инструкции
      - data cache - съхранява често използвани данни от програмите
    - Основни видове:
    	- Temporal locality - ако даден елемент от паметта е бил достъпен наскоро, има голяма вероятност да бъде достъпен отново скоро
    	- Spacial locality - ако даден елемент от паметта бъде достъпен, има голяма вероятност скоро да бъдат достъпени и елементи, намиращи се близо до него по адрес.
  - обхождане на матрица (статична и динамична) по редове срещу обхождане колони
  - **Бонус:**
	- https://www.geeksforgeeks.org/locality-of-reference-and-cache-operation-in-cache-memory/
  	- [CPU cache](https://en.wikipedia.org/wiki/CPU_cache) и [Locality of reference](https://en.wikipedia.org/wiki/Locality_of_reference)

## Характеристики на алгоритмите за сортиране

Освен сложност откъм време и откъм памет алгоритмите за сортиране разполагат и със следните характеристики:

- **Stability** - Един алгоритъм е стабилен, ако след сортировка, два равни елемента са в същата последователност, както преди масивът да бъде сортиран.
  - Пример - Вход: $$1, 2, 3_a, 8, 5, 3_b$$. Тук $$3_a$$ и $$3_b$$ са просто две числа, но ги маркираме, за да видим как са подредени в резултата.
  - Stable sort output: $$1,2,3_a,3_b,5,8$$
  - Unstable sort output: $$1,2,3_b,3_a,5,8$$ - поведението не е детерминистично (тоест понякога може да е $$3_a, 3_b$$ друг път $$3_b, 3_a$$ в зависимост от алгоритъма и входа)

- **In-place** - Показва дали алгоритъмът работи директно върху подадените данни и не заделя допълнителна памет пропорционална на входа. Следователно използва константна памет. 
- **Adaptivity** - Показва дали алгоритъмът работи по-бързо за почти сортирани масиви. Ако алгоритъм е неадаптивен, той има едно и също време за изпълнение независимо дали входът е несортиран или почти сортиран.
- **Locality** - Показва дали алгоритъмът се възползва от cache-a на процесора, за да забързва своето изпълнение. За целта данните трябва да бъдат последователни.

Сравнение по капацитет на памет и колко цикъла на процесора са нужни за достъп до нея.

| Memory hierarchy | CPU cycles | size   |
| ---------------- | ---------- | ------ |
| HDD              | 500, 000   | 1 TB   |
| RAM              | 100        | 4 GB   |
| L2 cache         | 10         | 512 kb |
| L1 cache         | 1          | 32 kb  |

- **Number of comparisons** - Показва колко на брой пъти два елемента биват сравнявани помежду си. Много често това съвпада със сложността на алгоритъма откъм време. Минималната стойност за алгоритми, които използват сравнение, е $$\mathcal{O}(n \times log(n))$$ (**Бонус:** Защо?)
- **Number of swaps** - Показва колко на брой пъти два различни елемента биват разменени в паметта. То не влияе на сложността на алгоритъма, но може да повлияе изпълнението на алгоритъма при големи данни и размяна на големи обекти.


## Бавни алгоритми за сортиране

## Bubble sort (Метод на мехурчето)

| Bubble sort           | n = input size       |
| --------------------- | -------------------- |
| Time complexity       | $$\mathcal{O}(n^2)$$ |
| Space complexity      | $$\mathcal{O}(1)$$   |
| Number of comparisons | $$\mathcal{O}(n^2)$$ |
| Number of swaps       | $$\mathcal{O}(n^2)$$ |
| Adaptive              | Yes                  |
| Stable                | Yes                  |
| Local                 | Yes                  |
| Online                | No                   |
| In-place              | Yes                  |
| Parallel              | No                   |
| External              | No                   |

- *N * (N - 1) / 2* брой размени в най-лошия случай. Кога се случва това?

Идея: След всяка итерация на *i*, най-големият елемент "изплува" чрез последователни размени на съседни елементи.

### Имплементация

<details>
  <summary>C++</summary>

```c++
void bubbleSort(std::vector<int>& arr) {
    int N = arr.size();
    
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

Има ли излишни итерации в тази имплементация и ако да - как да ги намалим?

```c++
void optimizedBubbleSort(std::vector<int>& arr) {
	int lastSwappedIndex = arr.size() - 1;
	for (size_t i = 0; i < arr.size(); i++) {
		int currentSwappedIndex = 0; // what if we used -1?
		for (size_t j = 0; j < lastSwappedIndex; j++) {
			if (arr[j] > arr[j + 1]) {
				currentSwappedIndex = j;
				swap(arr[j], arr[j + 1]);
			}
		}

		if (currentSwappedIndex == 0) {
			return;
		}
		lastSwappedIndex = currentSwappedIndex;
	}
}
```
</details>


<details>
  <summary>Python</summary>

```python
arr = [9, 4, 3, 2, 6, 7, 1, 8, 5]
N = len(arr)

for i in range(N - 1):
    for j in range(0, N - 1 - i):
        if arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]

print(arr) # [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

</details>

## Selection sort (Метод на пряката селекция)

| Selection sort        | n = input size       |
| --------------------- | -------------------- |
| Time complexity       | $$\mathcal{O}(n^2)$$ |
| Space complexity      | $$\mathcal{O}(1)$$   |
| Number of comparisons | $$\mathcal{O}(n^2)$$ |
| Number of swaps       | $$\mathcal{O}(n)$$   |
| Adaptive              | No                   |
| Stable                | No                   |
| Local                 | No                   |
| Online                | No                   |
| In-place              | Yes                  |
| Parallel              | No                   |
| External              | No                   |

Идея: Търси се индексът на най-малкия елемент на всяка итерация. След това се разменя с текущия.


### Имплементация

<details>
  <summary>C++</summary>

```c++
void selectionSort(std::vector<int>& arr) {
    int N = arr.size();
    
    for (int i = 0; i < N - 1; ++i) {
        int min_index = i;
        
        for (int j = i + 1; j < N; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

		if(min_index != i) {
            std::swap(arr[min_index], arr[i]);
		}
    }
}
```
</details>

<details>
  <summary>Python</summary>

```python
arr = [9, 4, 3, 2, 6, 7, 1, 8, 5]
N = len(arr)

for i in range(N - 1):
    min_index = i

    for j in range(i + 1, N):
        if arr[j] < arr[min_index]:
            min_index = j

    arr[min_index], arr[i] = arr[i], arr[min_index]

print(arr) # [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

</details>

Предпочитан пред Bubble sort поради по-малкото на брой размени, но за сметка на това не е стабилен. 

## Insertion sort (Метод на картоиграча)

| Insertion sort        | n = input size       |
| --------------------- | -------------------- |
| Time complexity       | $$\mathcal{O}(n^2)$$ |
| Space complexity      | $$\mathcal{O}(1)$$   |
| Number of comparisons | $$\mathcal{O}(n^2)$$ |
| Number of swaps       | $$\mathcal{O}(n^2)$$ |
| Adaptive              | Yes                  |
| Stable                | Yes                  |
| Local                 | Yes                  |
| Online                | Yes                  |
| In-place              | Yes                  |
| Parallel              | No                   |
| External              | No                   |

Идея: Всеки елемент се тегли като карта с гърба надолу. Търси се мястото му в ръката, като се изместват по-големите стойности с една позиция надясно.


### Имплементация


<details>
  <summary>C++</summary>

```c++
void insertionSort(std::vector<int>& arr) {
    int N = arr.size();
    
    for (int i = 1; i < N; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}
```

</details>

<details>
  <summary>Python</summary>

  ```python
arr = [9, 4, 3, 2, 6, 7, 1, 8, 5]
N = len(arr)

for i in range(1, N):
    key = arr[i]

    j = i - 1
    while j >= 0 and key < arr[j]:
        arr[j + 1] = arr[j]
        j -= 1

    arr[j + 1] = key

print(arr) # [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

</details>

**Note:** използваме отмествания, които са по-евтина операция от swap

[Подходящ](https://www.toptal.com/developers/sorting-algorithms) за малки масиви, и почти сортирани масиви. Това се дължи на ранното приключване на вътрешния цикъл при правилно поставено число (Best case сложността на алгоритъма е *O(N)*). Често се ползва в комбинация с други алгоритми.

Защо за малки масиви е полезен insertion sort?
- Ползва локалити(мести елементи един до друг)
- Няма рекурсивни извиквания - O(1) памет
- прави отмествания вместо swap
- Адаптивен. Малките масиви са много често почти сортирани.

---
### Обобщение на бавните алгоритми:

|              | Bubble sort        | Selection sort     | Insertion sort     |
| ------------ | ------------------ | ------------------ | ------------------ |
| Best case    | *O(N)*             | *O(N<sup>2</sup>)* | *O(N)*             |
| Average case | *O(N<sup>2</sup>)* | *O(N<sup>2</sup>)* | *O(N<sup>2</sup>)* |
| Worst case   | *O(N<sup>2</sup>)* | *O(N<sup>2</sup>)* | *O(N<sup>2</sup>)* |
| Памет        | *O(1)*             | *O(1)*             | *O(1)*             |
| Стабилен     | да                 | не                 | да                 |