#include <iostream>
using namespace std;

constexpr size_t ITERS = 3*(1e+5);
constexpr size_t SIZE = 1e+5; // 1e+6 ?

#define pause system("pause");

// stack size ~ 1MB
void createStackArrays() {
	cout << "Creating " << ITERS << " stack arrays...\n\n";
	for (size_t i = 0; i < ITERS; i++) {
		int arr[SIZE];
	}
}

void createHeapArrays() {
	cout << "Creating " << ITERS << " heap arrays...\n\n";
	for (size_t i = 0; i < ITERS; i++) {
		int* arr = new int[SIZE];
		delete[] arr;
	}
}

void eatNGigabytes(int n) {
	cout << "Eating our RAM...\n\n";
	int* arr = new int[n*(1e+9)];
	pause;
	delete[] arr;
}

int main()
{
	pause;
	createStackArrays();
	pause;
	createHeapArrays();
	pause;
	//eatNGigabytes(1);


	{
		// might throw exception(and terminate if not handled)
		// if unable to allocate memory
		int* arr = new int[10];
		delete[] arr;
	}


	{
		// returns nullptr if unable to allocate
		int* arr = new(std::nothrow) int[10];
		if (!arr) {
			cout << "Unsuccessful allocation.\n";
			return 1;
		}

		delete[] arr;
	}


	{
		int* a = new(std::nothrow) int(1);
		if (!a) {
			return 1;
		}
		delete a;
		a = nullptr; // guarantees future nullptr checks to be correct
	}

}
