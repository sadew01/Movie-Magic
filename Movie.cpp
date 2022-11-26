#pragma once
#include <iostream>
#include <string>
#include "Movie.h"
#include <utility>
using namespace std;


Movie::Movie(string title, vector<string>& genre, vector<string>& director, int year, int length, float rating, int numRatings) {
    this->title = title;
    this->genre = genre;
    this->director = director;
    this->year = year;
    this->length = length;
    this->rating = rating;
    this->numRatings = numRatings;
}

string Movie::getTitle() {
    return this->title;
}
vector<string>& Movie::getGenre() {
    return this->genre;
}
vector<string>& Movie::getDirector() {
    return this->director;
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
int Movie::getNumRatings() {
    return this->numRatings;
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

