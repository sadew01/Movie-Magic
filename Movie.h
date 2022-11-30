#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <array>
using namespace std;

class Movie {
private:
    string title = "";
    vector<string> genre = {};
    vector<string> director = {};
    int year = 0;
    int length = 0;
    float rating = 0.0;
    int numRatings = 0;
public:
    //member functions and constructors
    Movie() {}
    Movie(string title, vector<string>& genre, vector<string>& director, int year, int length, float rating, int numRatings);
    string getTitle();
    vector<string>& getGenre();
    vector<string>& getDirector();
    int getYear();
    int getLength();
    float getRating();
    int getNumRatings();
    
    // print info
    void print();

    // input validation
    bool validInput(string line);
    bool validDirectorName(string director);
    bool validGenreInput(string line);
    bool onlyNumbers(string line);
    bool isNumber(string line);
    bool isName(string line);

    // quick sort
    int partition(int arr[], int low, int high);	// helper functions for Quick Sort
    void swap(int* a, int* b);
    void quickSort(int arr[], int low, int high);
    void PrintArray(int arr[], int size);

    // radix sort length
    void radixSortLength(Movie movies[], int size);
    void radixSortLengthHelper(Movie movies[], int size, int digit);
    int findMaxLength(Movie movies[], int size);

    // radix sort ratings
    void radixSortRatings(Movie movies[], int size);
    void radixSortRatingsHelper(Movie movies[], int size, int digit);
    int findMaxRating(Movie movies[], int size);

    // radix sort numratings
    void radixSortNumRatings(Movie movies[], int size);
    void radixSortNumRatingsHelper(Movie movies[], int size, int digit);
    int findMaxNumRating(Movie movies[], int size);

    // operator overload to add object to set
    bool operator<(const Movie& movie1) const;
};
