
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
	cout << "Please enter up to three numbers corresponding to your favorite genres or type in your favorite director." << endl;
	cout << "(ex. \"1 2 4\" or \"Ryan Coogler\")" << endl;
	cout << endl;
	cout << "1. Action         9.  Family        17. Romance" << endl;
	cout << "2. Adventure      10. Fantasy       18. Sci-Fi" << endl;
	cout << "3. Animation      11. Film Noir     19. Short Film" << endl;
	cout << "4. Biography      12. History       20. Sport" << endl;
	cout << "5. Comedy         13. Horror        21. Superhero" << endl;
	cout << "6. Crime          14. Music         22. Thriller" << endl;
	cout << "7. Documentary    15. Musical       23. War" << endl;
	cout << "8. Drama          16. Mystery       24. Western" << endl;
	cout << "Type 0 to exit." << endl;
	
	return 0;
}
