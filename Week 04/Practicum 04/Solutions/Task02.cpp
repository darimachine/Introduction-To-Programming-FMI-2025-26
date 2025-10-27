#include <iostream>

bool isUpper(char symbol) {
	return symbol >= 'A' && symbol <= 'Z';
}

bool isLower(char symbol) {
	return symbol >= 'a' && symbol <= 'z';
}

bool isDigit(char symbol) {
	return symbol >= '0' && symbol <= '9';
}

int main()
{
	std::cout << isUpper('D') << std::endl;;
	std::cout << isLower('D') << std::endl;;
	std::cout << isDigit('8') << std::endl;
	std::cout << isDigit('s') << std::endl;
}

