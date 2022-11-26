#include "RadixSort.h"

void RadixSort::radixSort(int movies[], int size) {
	int max = findMaxVal(movies, size);

	for (int digit = 1; max / digit > 0; digit *= 10) {
		radixSortHelper(movies, size, digit);
	}
}


void RadixSort::radixSortHelper(int movies[], int size, int digit) {
	// create temp array same size as original
	int* temp = new int[size];

	// create a counting array to store count of each digit 0-9
	int count[10] = { 0 };

	// store the number of occurences of each character
	for (int i = 0; i < size; i++) {
		count[(movies[i] / digit) % 10]++;
	}

	// update the count array to reflect the position in the final array
	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	// transfer the values into the temporary array
	for (int i = size - 1; i >= 0; i--) {
		temp[count[(movies[i] / digit) % 10] - 1] = movies[i];
		count[(movies[i] / digit) % 10]--;
	}

	for (int i = 0; i < size; i++) {
		movies[i] = temp[i];
	}

	delete[] temp;
}

void RadixSort::radixSortFloat(float movies[], int size) {
	int* temp = new int[size];

	for (int i = 0; i < size; i++) {
		temp[i] = (movies[i] * (float) 10);
	}

	int max = findMaxVal(temp, size);

	for (int digit = 1; max / digit > 0; digit *= 10) {
		radixSortHelper(temp, size, digit);
	}

	for (int i = 0; i < size; i++) {
		movies[i] = ((float) temp[i] / (float) 10);
	}
}

void RadixSort::countSort(int movies[], int size) {
	const int size1 = size;
	// create temp array same size as original
	int* temp = new int[size];

	// create a counting array to store count of each digit 0-9
	int count[10] = {0};

	// find max value
	int max = findMaxVal(movies, size);

	// store the number of occurences of each character
	for (int i = 0; i < size; i++) {
		count[movies[i]]++;
	}

	// update the count array to reflect the position in the final array
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	// transfer the values into the temporary array
	for (int i = 0; i < size; i++) {
		temp[count[movies[i]] - 1] = movies[i];
		count[movies[i]]--;
	}

	for (int i = 0; i < size; i++) {
		movies[i] = temp[i];
	}
}

// finds the max value int the array to base radix sort off
int RadixSort::findMaxVal(int movies[], int size) {
	int max = movies[0];
	for (int i = 0; i < size; i++) {
		if (movies[i] > max) {
			max = movies[i];
		}
	}
	return max;
}
