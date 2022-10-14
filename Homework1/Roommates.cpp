#include <iostream>

size_t deletedLetters(char* list, size_t listSize) {
	size_t minChanges = 0;
	for (size_t i = 0; i < listSize; ++i) {
		if (list[i] == list[i + 1]) {
			minChanges++;
		}
	}
	return minChanges;
}

int main()
{	
	size_t listCount;
	std::cin >> listCount;
	int* results = new int[listCount];
	for (size_t i = 0; i < listCount; ++i) {
		size_t size;
		std::cin >> size;
		char* list = new char[size+1];
		std::cin >> list;
		results[i] = deletedLetters(list, size);
	}
	for (size_t i = 0; i < listCount; ++i)
		std::cout << results[i] << std::endl;
}

