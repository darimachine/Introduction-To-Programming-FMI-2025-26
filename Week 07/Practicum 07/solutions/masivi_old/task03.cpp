#include <iostream>

using namespace std;

int main() {
    constexpr size_t N_MAX = 50;
    int N;
    cin >> N;
    int arr[N_MAX];

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    bool isMonotonicallyDecreasing = true;
    for (size_t i = 0; i < N - 1; i++)
    {
        if (arr[i] < arr[i+1]) {
            isMonotonicallyDecreasing = false;
        }
    }

    cout << isMonotonicallyDecreasing << endl;
}