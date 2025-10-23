#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    unsigned int n = 0;

    cout << "N: ";
    cin >> n;
    int totalRows = n * 2 -1;
    for (int i = 1; i <= totalRows; i++)
    {
        for (int j = 1; j <= n; j++) {
            if (j <= i && j <= totalRows - i +1) {
                cout << j << " ";
            }
            else {
                cout << "  ";
            }
        }

        for (int j = 0; j < n; j++) {
            i == n ? cout << "-" : cout << " ";
        }

        for (int j = n; j >= 1; j--) {
            if (j <= i && j <= totalRows - i + 1) {
                cout << " " << j;
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;

    }

    return 0;
}
