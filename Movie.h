#pragma once
#include <iostream>
#include <string>
using namespace std;
class Movie {

private:
	string title = "";
	string genre = "";
	int year = 0;
	int length = 0;
	int rating = 0;
public:
	Movie() {

	}
	string getTitle();
	string getGenre();
	int getYear();
	int getLength();
	int getRating();
	void setGenre(string genre);
	int partition(int arr[], int low, int high);	// helper functions for Quick Sort
	void swap(int* a, int* b);
	void quickSort(int arr[], int low, int high);
	void PrintArray(int arr[], int size);
};
