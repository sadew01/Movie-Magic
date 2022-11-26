
#include <iostream>
#include <vector>
#include<fstream>
#include "Movie.h"
using namespace std;


int main() {
	Movie obj;
	int data[] = { 15, 0, 5, 6 };
	int n = sizeof(data) / sizeof(data[0]);
	obj.quickSort(data, 0, n - 1);
	obj.PrintArray(data, n);
	return 0;
	
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
