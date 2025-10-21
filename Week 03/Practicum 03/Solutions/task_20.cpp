
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n;
	cin >> n;
	int totalRows = n * 2 - 1;
	
	for (int i = 1; i <= totalRows; i++)
	{
		// най-голямото число на всеки ред
		int maxNumInRow = i <= n ? maxNumInRow = i : totalRows - i + 1;
		
		// Лява част на панделката за конкретния ред i
		for (int j = 1; j <= maxNumInRow; j++) {
			cout << j << " ";
		}
			
		if (i == n) {
			// когато сме на средния ред, принтираме тирета
			for (int j = 1; j <= n; j++) {
				cout <<"-";
			}
		}
		else {
			// в противен случай принтираме интервали

		   /*
			* Панделката е с широчина 5*n.
			* От цялата широчина вадим броя цифри на реда и броя интервали
			* (по 1 след всяка цифра ако са от лявата част, по 1 преди всяка ако са от дясната част),
			* което е 5*n - 4*maxNumInRow
		   */
			int spaces = n *5 - 4 * maxNumInRow;
			for (int i = 0; i < spaces; i++) {
				cout << " ";
			}
		}
		
		for (int j = maxNumInRow; j >= 1; j--) {
			cout <<" "<< j;
		}
		cout << endl;
		
		
	}
}
