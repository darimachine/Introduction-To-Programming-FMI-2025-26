#include <iostream>

using namespace std;

bool isElementRepeating(int, int, const int[], size_t);

bool isElementRepeating(int el, int index, const int arr[], size_t size) {
    for (size_t i = index + 1; i < size; i++)
    {
        if (arr[i] == el) {
            return true;
        }
    }
    
    return false;
}

int main() {
    constexpr size_t N_MAX = 50;
    int N;
    cin >> N;
    int arr[N_MAX];

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    bool areElementsUnique = true;
    for (size_t i = 0; i < N; i++)
    {
        if (isElementRepeating(arr[i], i, arr, N)) {
            areElementsUnique = false;
        }
    }

    cout << areElementsUnique << endl;
}