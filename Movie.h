#pragma once
#include <iostream>
#include <string>
#include <vector>
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
    Movie() {}
    Movie(string title, vector<string>& genre, vector<string>& director, int year, int length, float rating, int numRatings);
    string getTitle();
    vector<string>& getGenre();
    vector<string>& getDirector();
    int getYear();
    int getLength();
    float getRating();
    int getNumRatings();
    int partition(int arr[], int low, int high);	// helper functions for Quick Sort
    void swap(int* a, int* b);
    void quickSort(int arr[], int low, int high);
    void PrintArray(int arr[], int size);
};
