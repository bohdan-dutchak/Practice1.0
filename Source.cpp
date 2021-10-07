#include <iostream>
#include "Sorting.h"
#include "graps.h"

using namespace std;

int main() {
	ofstream tp1;
	tp1.open("data/toparse1.txt");
	ofstream tp2;
	tp2.open("data/toparse2.txt");
	ofstream tp3;
	tp3.open("data/toparse3.txt");
	ofstream tp4;
	tp4.open("data/toparse4.txt");

	if (!tp1.is_open()|| !tp2.is_open() || !tp3.is_open() || !tp4.is_open()) {
		cout << "error! couldnt open the file!!" << endl;
		return 1;
	}
	condition(1, tp1);
	condition(2, tp2);
	condition(3, tp3);
	condition(4, tp4);
	//condition('1', test);
	//condition('2', test);
	//condition('3', test);
	//condition('4', test);
}