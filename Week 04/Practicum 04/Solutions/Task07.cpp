#include <iostream>

int absoluteValue(int number) {
	return (number >= 0 ? number : -number);
}

int gcd(int first, int second) {
	if (first < second)
	{
		//swap
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

int main()
{
	std::cout << lcm(9, 6) << std::endl; // 18
	std::cout << lcm(-12, 15) << std::endl; //60
}
