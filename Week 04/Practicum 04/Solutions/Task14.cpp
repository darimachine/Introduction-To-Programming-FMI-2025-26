#include <iostream>

int absoluteValue(int number) {
	return (number >= 0 ? number : -number);
}

int gcd(int first, int second) {
	if (first < second)
	{
		int temp = first;
		first = second;
		second = temp;
	}

	while (second != 0)
	{
		int temp = first % second;
		first = second;
		second = temp;
	}

	return first;
}

int lcm(int first, int second) {
	if (first == 0 || second == 0) {
		return 0;
	}
	return absoluteValue((first * second) / gcd(first, second));
}

void printLcmAndGcdOfSeveralNumbers() {
	unsigned int N;
	std::cin >> N;

	if (N == 0) {
		std::cout << "LCM: " << 0 << std::endl;
		std::cout << "GCD: " << 0 << std::endl;
		return;
	}

	int num;
	std::cin >> num;
	N--;

	int LCM = num;
	int GCD = num;

	while (N != 0) {
	std:: cin >> num;

	LCM = lcm(LCM, num);
	GCD = gcd(GCD, num);

	N--;
	}

	std::cout << "GCD: " << GCD << std::endl;
	std::cout << "LCM: " << LCM << std::endl;
}

int main()
{
	printLcmAndGcdOfSeveralNumbers();
}
