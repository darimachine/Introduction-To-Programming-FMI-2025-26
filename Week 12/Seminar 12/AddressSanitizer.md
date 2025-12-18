# AddressSanitizer (ASan)

Инструмент за засичане на грешки в използването на паметта. Работи заедно с компилатора, за да добави (инструментира) код към програмата, който да проверява работата с памет, което води до забавяне (около 2 пъти).

## Използване

### Visual Studio

https://learn.microsoft.com/en-us/cpp/sanitizers/asan?view=msvc-170#ide-msbuild

### CLion под Windows

https://www.jetbrains.com/help/clion/google-sanitizers.html#clang-cl-configure

### CLion под Linux и macOS

Добавете във файла `CMakeLists.txt` следния ред:

```cmake
set(CMAKE_CXX_FLAGS "-fsanitize=address")
```

### Команден ред под Linux (вкл. и WSL)

Стандартно компилиране:

```bash
g++ main.cpp -o main
```

Компилиране с ASan:

```bash
g++ main.cpp -o main -fsanitize=address
```

Изисква предварително инсталиран компилатор. Например, под Debian/Ubuntu:

```bash
sudo apt install build-essential
```

## LeakSanitizer (LSan)

Засича memory leaks (неосвободена динамична памет).

### Под Windows

Не се поддържа. Използвайте WSL (или друга виртуална машина с Linux).

### Под Linux и macOS

Вграден в AddressSanitizer.

Алтернативно, за да използвате само LeakSanitizer без AddressSanitizer, използвайте `-fsanitize=leak` вместо `-fsanitize=address`.

## Valgrind

Подобно на AddressSanitizer засича грешки в работата с динамична памет (вкл. memory leaks), но също хваща употреба на неинициализирани стойности. Не може да проверява грешки в стековата памет.

Работи само под Linux (вкл. WSL). Не може да се използва заедно с AddressSanitizer.

### CLion

https://www.jetbrains.com/help/clion/memory-profiling-with-valgrind.html

### Команден ред

Стандартно пускане на програма:

```bash
./main
```

Пускане на програма под Valgrind:

```bash
valgrind ./main
```

Изисква предварително да бъде инсталиран. Например, под Debian/Ubuntu:

```bash
sudo apt install valgrind
```
