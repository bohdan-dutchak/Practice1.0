#pragma once
#include <string>
#include <chrono>
#include <fstream>

using namespace std;

class SortResult
{
public:
	string type;
	int comparisons;
	int elements;
	chrono::duration<float> duration;

	SortResult();
	SortResult(string t, int c, int e, chrono::duration<float> d);

	void out(ofstream &file);
};
