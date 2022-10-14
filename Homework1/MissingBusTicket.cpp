#include <iostream>
using namespace std;

int ticket(int* arr, int size, int max) {

		int* result = new int[max + 1];
		for (int i = 0; i < max + 1; ++i) {
			result[i] = 0;
		}
		for (int i = 0; i < size; ++i) {
			if (arr[i] > 0)
				result[arr[i]] = 1;
		}
		for (int i = 1; i < max+1; ++i) {
			if (result[i] == 0)
				return i;
		}
		delete[] result;
	return max+1;
}

int main()
{
	int size;
	int max = 0;
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
		if (array[i] > max)
			max = array[i];
	}
	cout << ticket(array, size, max);
	delete[] array;
}


