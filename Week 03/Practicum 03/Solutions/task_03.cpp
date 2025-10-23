#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        sum += k;
    }

    cout << sum << endl;
    return 0;
}