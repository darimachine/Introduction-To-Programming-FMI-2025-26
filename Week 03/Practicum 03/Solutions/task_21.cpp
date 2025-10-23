
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n,current;
	cin >> n;
	for (int row=0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (col % 2 == 0) {
				current = (col * n) + row + 1;
			}
			else {
				current = (col + 1)* n - row;
			}
			cout << current << " ";
		}
		cout << endl;
	}
}
