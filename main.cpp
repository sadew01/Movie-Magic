
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
}
