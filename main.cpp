#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include "Movie.h"
using namespace std;

// storing movie objects from file
void ReadInMovies(vector<Movie>& movies) {
    ifstream file("combined.data.tsv");

    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
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
            while (getline(stream1, genre, ',')) {
                g.push_back(genre);
            }

            istringstream stream2(directors);
            string director;
            vector<string> d;
            while (getline(stream2, director, ',')) {
                d.push_back(director);
            }
            // creating movie object and pushing into movies vector
            movies.emplace_back(title, g, d, stoi(year), stoi(runtime), stof(rating), stoi(numRatings));
        }
    }
}

int main() {
    Movie movie;

    // variables to parse input
    string action = "Action", adventure = "Adventure", animation = "Animation", biography = "Biography", comedy = "Comedy",
        crime = "Crime", documentary = "Documentary", drama = "Drama", family = "Family", fantasy = "Fantasy", filmNoir = "Film-Noir",
        history = "History", horror = "Horror", music = "Music", musical = "Musical", mystery = "Mystery", romance = "Romance",
        sciFi = "Sci-Fi", shortFilm = "Short", sport = "Sport", superhero = "Superhero", thriller = "Thriller", war = "War",
        western = "Western";

    // vector to store movies after reading from the file
    vector<Movie> movies;
    ReadInMovies(movies);
    cout << movies.size() << endl;

    cout << "* Welcome to Movie Magic! *" << endl;
    cout << "Our goal is to make finding movies suited to your tastes easier." << endl;
    cout << endl;
    cout << "Please enter up to three numbers corresponding to your favorite genres or type in your favorite director." << endl;
    cout << "(Ex. \"1 2 4\" or \"Ryan Coogler\")" << endl;
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
    cout << endl;

    string line, read;
    istringstream stream(line);
    vector<int> input;
    set<Movie> movieSet;
    Movie* movieArray;
    bool exit = false;

    while (true) {
        getline(cin, line);

        if (line.at(0) == '0' && line.length() == 1) {
            exit = true;
            break;
        }

        if (movie.validInput(line)) {
            if (movie.isName(line)) {
                for (int i = 0; i < movies.size(); i++) {
                    vector<string> directors = movies.at(i).getDirector();
                    for (int j = 0; j < directors.size(); j++) {
                        if (directors.at(j).compare(line) == 0) {
                            movieSet.insert(movies.at(i));
                        }
                    }
                }

                set<Movie> ::iterator iter;
                int count = 0;
                movieArray = new Movie[movieSet.size()];
                for (iter = movieSet.begin(); iter != movieSet.end(); ++iter) {
                    movieArray[count] = *iter;
                }
                break;
            }
            else if (movie.isNumber(line)) {
                while (getline(stream, read, ' ')) {
                    input.push_back(stoi(read));
                }

                int index = 0;
                while (index != input.size()) {
                    for (int i = 0; i < movies.size(); i++) {
                        int genre = input.at(index);
                        vector<string> genres = movies.at(i).getGenre();

                        for (int j = 0; j < genres.size(); j++) {
                            if (genre == 1 && genres.at(j).compare(action) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 2 && genres.at(j).compare(adventure) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 3 && genres.at(j).compare(animation) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 4 && genres.at(j).compare(biography) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 5 && genres.at(j).compare(comedy) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 6 && genres.at(j).compare(crime) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 7 && genres.at(j).compare(documentary) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 8 && genres.at(j).compare(drama) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 9 && genres.at(j).compare(family) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 10 && genres.at(j).compare(fantasy) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 11 && genres.at(j).compare(filmNoir) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 12 && genres.at(j).compare(history) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 13 && genres.at(j).compare(horror) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 14 && genres.at(j).compare(music) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 15 && genres.at(j).compare(musical) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 16 && genres.at(j).compare(mystery) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 17 && genres.at(j).compare(romance) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 18 && genres.at(j).compare(sciFi) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 19 && genres.at(j).compare(shortFilm) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 20 && genres.at(j).compare(sport) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 21 && genres.at(j).compare(superhero) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 22 && genres.at(j).compare(thriller) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 23 && genres.at(j).compare(war) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                            else if (genre == 24 && genres.at(j).compare(western) == 0) {
                                movieSet.insert(movies.at(i));
                            }
                        }
                    }
                    index++;
                }
                set<Movie> ::iterator iter;
                int count = 0;
                movieArray = new Movie[movieSet.size()];
                for (iter = movieSet.begin(); iter != movieSet.end(); ++iter) {
                    movieArray[count] = *iter;
                }
                break;
            }
        }
        else {
            cout << "Please enter valid input" << endl;
            cout << endl;
        }
    }

    while (true) {
        if (exit) {
            break;
        }
        cout << endl;
        cout << "Please enter the criteria you would like to sort the movies on." << endl;
        cout << "Ex. \"1\" or \"2\"" << endl;
        cout << endl;
        cout << "1. Length (from longest)" << endl;
        cout << "2. Length (from shortest)" << endl;
        cout << "3. Rating (from highest)" << endl;
        cout << "4. Rating (from lowest)" << endl;
        cout << "5. Number of Ratings (from highest)" << endl;
        cout << "6. Number of Ratings (from lowest)" << endl;
        while (true) {
            string option;
            cin >> option;
            if (isdigit(option.at(0)) != 0) {
                if (stoi(option) == 1) { // length from longest
                    // radix sort

                    // quick sort
                    break;
                }
                else if (stoi(option) == 2) { // length from shortest
                    // radix sort

                    // quick sort

                    break;
                }
                else if (stoi(option) == 3) { // rating from highest
                    // radix sort

                    // quick sort
                    break;
                }
                else if (stoi(option) == 4) { // rating from lowest
                    // radix sort

                    // quick sort

                    break;
                }
                else if (stoi(option) == 5) { // number of ratings from highest
                    // radix sort

                    // quick sort
                    break;
                }
                else if (stoi(option) == 6) { // number of ratings from lowest
                    // radix sort

                    // quick sort
                    break;
                }
            }
            else {
                cout << "Please enter a valid option." << endl;
            }
        }
        break;
    }
    cout << endl;

    cout << "Thank you for making Movie Magic!" << endl;

    return 0;
}
