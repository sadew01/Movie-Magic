
#include <iostream>
#include <vector>
#include<fstream>
#include <sstream>
#include "Movie.h"
using namespace std;

void ReadInMovies (vector<Movie>& movies) {
    ifstream file("combined.data.tsv");

    if(file.is_open()) {
        string line;
        while(std::getline(file, line)) {
            istringstream stream(line);
            string title;
            string year;
            string runtime;
            string genres;
            string directors;
            string rating;
            string numRatings;

            getline(stream, title, '\t');
            getline(stream, year, '\t');
            getline(stream, runtime, '\t');
            getline(stream, genres, '\t');
            getline(stream, directors, '\t');
            getline(stream, rating, '\t');
            getline(stream, numRatings, '\t');

            istringstream stream1(genres);
            string genre;
            vector<string> g;
            while(getline(stream1, genre, ',')) {
                g.push_back(genre);
            }

            istringstream stream2(directors);
            string director;
            vector<string> d;
            while(getline(stream2, director, ',')) {
                d.push_back(director);
            }

            movies.emplace_back(title, g, d, stoi(year), stoi(runtime), stof(rating), stoi(numRatings));
        }
    }
}

int main() {
	Movie obj;
	int data[] = { 15, 0, 5, 6 };
	int n = sizeof(data) / sizeof(data[0]);
	obj.quickSort(data, 0, n - 1);
	obj.PrintArray(data, n);
	return 0;
	
	vector<Movie> movies;
    	ReadInMovies(movies);
	
	cout << "* Welcome to Movie Magic! *" << endl;
	cout << "Our goal is to make finding movies suited to your tastes easier." << endl;
	cout << endl;
	cout << "Please enter the numbers corresponding to your favorite genres or type in your favorite director." << endl;
	cout << "(ex. \"1 2 4 6\" or \"Ryan Coogler\")" << endl;
	cout << "1. Comedy" << endl;
	cout << "2. Sci-Fi" << endl;
	cout << "3. Horror" << endl;
	cout << "4. Romance" << endl;
	cout << "5. Action" << endl;
	cout << "6. Thriller" << endl;
	cout << "7. Drama" << endl;
	cout << "8. Mystery" << endl;
	cout << "9. Crime" << endl;
	cout << "10. Animation" << endl;
	cout << "11. Adventure" << endl;
	cout << "12. Fantasy" << endl;
	cout << "Type 0 to exit." << endl;
	return 0;
}
