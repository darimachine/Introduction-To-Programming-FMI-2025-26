#include <iostream>

bool isDigit(char symbol) {
	return symbol >= '0' && symbol <= '9';
}

int toNumber(char symbol) {
	if (isDigit(symbol)) {
		return symbol - '0';
	}

	return -1;
}

char toCharacter(int number) {
	if (number >= 0 && number <= 9) {
		return number + '0';
	}

	return '\0';
}

int main()
{
	std::cout << toNumber('9') << std::endl;;
	std::cout << toCharacter(8) << std::endl;
}
