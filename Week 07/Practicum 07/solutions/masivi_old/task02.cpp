#include <iostream>

using namespace std;

int main() {
    constexpr size_t N_MAX = 50;
    int N;
    cin >> N;
    int arr[N_MAX];
    double sum = 0;

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "Average: " << sum / N << endl;
}