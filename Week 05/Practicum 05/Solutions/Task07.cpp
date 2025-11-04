#include <iostream>

void reverse(int& num) {
	int result = 0;

	while (num != 0) {
		int lastDigit = num % 10;
		num /= 10;

		result = result * 10 + lastDigit;
	}

	num = result;
}

int getLength(int num) {
	int count = 0;

	do {
		count++;
		num /= 10;
	} while (num != 0);

	return count;
}

void cut(int& num, int start, int end) {
	int length = getLength(num);
	if (end > length || start <= 0) {
		return;
	}

	reverse(num);

	for (int i = 1; i < start; i++) {
		num /= 10;
	}

	int result = 0;

	for (int i = start; i <= end; i++) {
		int lastDigit = num % 10;
		num /= 10;
		result = result * 10 + lastDigit;
	}

	num = result;
}

int main()
{
	int num, start, end;
	std::cin >> num >> start >> end;

	cut(num, start, end);
	std::cout << num << std::endl;
}
