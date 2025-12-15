#include <iostream>
#include <vector>
using namespace std;

// https://en.cppreference.com/w/cpp/container/vector.html

int main() {
    // в <...> се приема типът от елементи, които
    // искаме да съхраняваме в този вектор
    vector<int> v1 = {1,2,3};
    vector<int> v2({1,2});
    vector<int> v3 = v1;
    //vector<int> v4 = vector({0}); векторът вдясно няма зададен тип -> не работи
    vector<int> v4 = vector<int>({0});

    // векторите обаче нямат предефинирани оператори
    // за четене и писане и елементите им трябва да
    // се обработват един по един, освен ако сами
    // не си предефинираме тези оператори(в ООП курса)
    // cout << v1; не работи

    for (size_t i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl << endl;
    
    for (size_t i = 0; i < v4.size(); i++) {
        cout << v4[i] << " ";
    }
    cout << endl;

    // string е като специализирана версия на vector,
    // така че повечето функции, които разгледахме
    // при стринга, тук работят аналогично
}

// подаването като аргумент във функция работи по същия начин
void passByCopy(vector<int> v) { /*...*/ }

void passByRef(vector<int>& v) { /*...*/ }

void passByConstRef(const vector<int>& v) { /*...*/ }