#include <iostream>

bool isUpper(char symbol) {
	return symbol >= 'A' && symbol <= 'Z';
}

bool isLower(char symbol) {
	return symbol >= 'a' && symbol <= 'z';
}

char toUpper(char symbol) {
	if (isLower(symbol)) {
		return symbol - 'a' + 'A';
	}
	else if (isUpper(symbol)) {
		return symbol;
	}

	return '\0';
}

char toLower(char symbol) {
	if (isUpper(symbol)) {
		return symbol - 'A' + 'a';
	}
	else if (isLower(symbol)) {
		return symbol;
	}

	return '\0';
}

int main()
{
	std::cout << toLower('H') << std::endl;
	std::cout << toUpper('d') << std::endl;
	std::cout << toUpper('&') << std::endl;
	std::cout << toUpper('Y') << std::endl;
}

