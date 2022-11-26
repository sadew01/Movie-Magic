#pragma once
#include <vector>
#include <array>
#include <string>
#include <iostream>
using namespace std;

class RadixSort {
private:
public:
	void radixSort(int movies[], int size);
	void radixSortHelper(int movies[], int size, int digit);
	void radixSortFloat(float movies[], int size);
	void countSort(int movies[], int size);
	int findMaxVal(int movies[], int size);
};