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

bool Movie::validInput(string line) {
    if (isName(line)) {
        if (validDirectorName(line)) {
            return true;
        }
    }
    else if (isNumber(line)) {
        if (validGenreInput(line)) {
            return true;
        }
    }

    return false;
}

bool Movie::validDirectorName(string director) {
    for (int i = 0; i < director.length(); i++) {
        if (isalpha(director.at(i)) != 0 || director.at(i) == ' ') {

        }
        else {
            return false;
        }
    }
    return true;
}

bool Movie::validGenreInput(string line) {
    istringstream stream(line);
    vector<int> input;
    string read;

    // check if the input contains only digits or spaces
    if (!onlyNumbers(line)) {
        return false;
    }

    // read in each number corresponding to a genre
    while (getline(stream, read, ' ')) {
        input.push_back(stoi(read));
    }

    // up to three genres are allowed
    if (input.size() > 3) {
        return false;
    }

    // up to 24 genres
    for (int i = 0; i < input.size(); i++) {
        if (input.at(i) <= 0 || input.at(i) > 24) {
            return false;
        }
    }

    return true;
}

bool Movie::onlyNumbers(string line) {
    // check that genre input only contains numbers or spaces
    for (int i = 0; i < line.length(); i++) {
        if (isdigit(line.at(i)) || line.at(i) == ' ') {

        }
        else {
            return false;
        }
    }
    return true;
}

bool Movie::isName(string line) {
    // if the first char is a letter, indicates director name input
    if (isalpha(line.at(0)) != 0) {
        return true;
    }
    return false;
}

bool Movie::isNumber(string line) {
    // if the first char is a digit, indicates genre input
    if (isdigit(line.at(0)) != 0) {
        return true;
    }
    return false;
}


bool Movie::operator<(const Movie& movie1) const {
    int one = movie1.numRatings;
    return title < movie1.title;
}

// radix sort length
void Movie::radixSortLength(Movie movies[], int size) {
    int max = findMaxLength(movies, size);

    for (int digit = 1; max / digit > 0; digit *= 10) {
        radixSortLengthHelper(movies, size, digit);
    }
}

void Movie::radixSortLengthHelper(Movie movies[], int size, int digit) {

}

int Movie::findMaxLength(Movie movies[], int size) {
    int max = movies[0].getLength();
    for (int i = 0; i < size; i++) {
        if (movies[i].getLength() > max) {
            max = movies[i].getLength();
        }
    }
    return max;
}

// radix sort ratings
void Movie::radixSortRatings(Movie movies[], int size) {
    /*
    int* temp = new int[size];

    for (int i = 0; i < size; i++) {
        temp[i] = (movies[i] * (float)10);
    }

    int max = findMaxVal(temp, size);

    for (int digit = 1; max / digit > 0; digit *= 10) {
        radixSortHelper(temp, size, digit);
    }

    for (int i = 0; i < size; i++) {
        movies[i] = ((float)temp[i] / (float)10);
    }
    */
}

void Movie::radixSortRatingsHelper(Movie movies[], int size, int digit) {

}

int Movie::findMaxRating(Movie movies[], int size) {
    int max = movies[0].getRating();
    for (int i = 0; i < size; i++) {
        if (movies[i].getRating() > max) {
            max = movies[i].getRating();
        }
    }
    return max;
}

// radix sort numratings
void Movie::radixSortNumRatings(Movie movies[], int size) {
    /*
    int max = findMaxVal(movies, size);

    for (int digit = 1; max / digit > 0; digit *= 10) {
        radixSortHelper(movies, size, digit);
    }
    */
}

void Movie::radixSortNumRatingsHelper(Movie movies[], int size, int digit) {

}

int Movie::findMaxNumRating(Movie movies[], int size) {
    int max = movies[0].getNumRatings();
    for (int i = 0; i < size; i++) {
        if (movies[i].getNumRatings() > max) {
            max = movies[i].getNumRatings();
        }
    }
    return max;
}
