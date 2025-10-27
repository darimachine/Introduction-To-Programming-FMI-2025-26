#include <iostream>

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

int main()
{
	std::cout << gcd(15, 25) << std::endl;
}

