#pragma once
#include <iostream>
#include <string>
#include "Movie.h"
#include <utility>
using namespace std;

string Movie::getTitle() {
	return this->title;
}
vector<string>& Movie::getGenre() {
	return this->genre;
}
void Movie::setGenre(string genre) {
	this->genre = genre;
}
int Movie::getYear() {
	return this->year;
}
int Movie::getLength() {
	return this->length;
}
float Movie::getRating() {
	return this->rating;
}
void Movie::swap(int* a, int* b) { // This code is from the sorting lecture slides
	int t = *a;
	*a = *b;
	*b = t;
}
int Movie::partition(int arr[], int low, int high) { // This code is from the sorting lecture slides
	int pivot = arr[low];
	int up = low;
	int down = high;
	while (up < down) {
		for (int j = up; j < high; j++) {
			if (arr[up] > pivot) {
				break;
			}
			up++;
		}
		for (int j = high; j > low; j--) {
			if (arr[down] < pivot) {
				break;
			}
			down--;
		}
		if (up < down) {
			swap(&arr[up], &arr[down]);
		}
	}
	swap(&arr[low], &arr[down]);
	return down;
}

void Movie::quickSort(int arr[], int low, int high) { // This code is from the sorting lecture slides
	if (low < high) {
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

void Movie::PrintArray(int arr[], int size) {		// This code is from the sorting lecture slides
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
		
	}
}
