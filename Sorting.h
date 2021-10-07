#pragma once
#include "SortResult.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

SortResult SelectionSort(vector<int>& v);
SortResult InsertionSort(vector<int>& v);
SortResult MergeSort(vector<int>& v);
SortResult ShellSort(vector<int>& v);

vector<int> GenerateRandom(int power);
vector<int> GenerateGrowing(int power);
vector<int> GenerateDegressive(int power);
vector<int> GenerateOfThree(int power);

void condition(int opt, ofstream &file);

SortResult avg(SortResult r1, SortResult r2, SortResult r3, SortResult r4, SortResult r5);
SortResult avg(SortResult r1, SortResult r2, SortResult r3);