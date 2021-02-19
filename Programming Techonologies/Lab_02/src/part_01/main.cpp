#include <iostream>

template <typename T>
void Sort(T* baseArray, int size) {
	T temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (baseArray[j] > baseArray[j + 1]) {
				temp = baseArray[j];
				baseArray[j] = baseArray[j + 1];
				baseArray[j + 1] = temp;
			}
		}
	}
}

template <typename T>
void SortedFind(T* baseArray, int arraySize) {
	try {
		std::cout << "\nOriginal Array: " << std::endl;
		for (int i = 0; i < arraySize; i++)
			std::cout << baseArray[i] << "  ";

		Sort(baseArray, arraySize);

		std::cout << "\nSorted Array: " << std::endl;
		for (int i = 0; i < arraySize; i++)
			std::cout << baseArray[i] << "  ";

		T searchValue;
		std::cout << "\nEnter search value" << std::endl;
		std::cin >> searchValue;

		bool findDone = false;
		for (int i = 0; i < arraySize; i++) {
			if (baseArray[i] == searchValue) {
				std::cout << "\nThe searchable value " << searchValue
					<< " is " << i + 1 << " element of array" << std::endl;
				findDone = true;
			}
		}

		if (!findDone)
			throw searchValue;
	}
	catch (T invalidValue) {
		std::cout << "Catch exception in func: There is no elements in array with value " << invalidValue << std::endl;
		exit(-1338);
	}
	

}

int main() {
	try {
		int size{ 0 };
		std::cout << "Enter size of array" << std::endl;
		std::cin >> size;

		if (size <= 0)
			throw size;

		float* array1 = new float[size];

		std::cout << "Enter " << size << " values" << std::endl;

		for (size_t i = 0; i < size; i++)
			std::cin >> array1[i];

		SortedFind(array1, size);


	}
	catch (int invalidSize) {
		std::cout << "Size of array must be positive instead " << invalidSize << std::endl;
		exit(-1337);
	}

	return 0;
}