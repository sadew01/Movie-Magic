#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Movie {

private:
	string title = "";
	vector<string> genre = {};
	int year = 0;
	int length = 0;
	float rating = 0.0;
public:
	Movie() {

	}
	string getTitle();
	vector<string>& getGenre();
	int getYear();
	int getLength();
	float getRating();
	int partition(int arr[], int low, int high);	// helper functions for Quick Sort
	void swap(int* a, int* b);
	void quickSort(int arr[], int low, int high);
	void PrintArray(int arr[], int size);
};
