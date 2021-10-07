#include "Sorting.h"
#include <iostream>

int MergeSortComps = 0;
SortResult SelectionSort(vector<int>& v) {
	auto start = chrono::high_resolution_clock::now();

	int index;
	int comps = 0;
	for (int i = 0; i < v.size(); i++) {
		index = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] < v[index]) {
				index = j;
			}
			comps++;
		}
		swap(v[i], v[index]);
	}

	auto finish = chrono::high_resolution_clock::now();
	SortResult temp("selection", comps, v.size(), finish - start);
	return temp;
}

SortResult InsertionSort(vector<int>& v)
{
	auto start = chrono::high_resolution_clock::now();

	int comps = 0;
	int key;
	for (int i = 1; i < v.size(); i++) {
		key = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > key) {
			comps++;
			v[j + 1] = v[j];
			j--;
		}
		comps++;
		v[j + 1] = key;
	}

	auto finish = chrono::high_resolution_clock::now();
	SortResult temp("insertion", comps, v.size(), finish - start);
	return temp;
}

void merge(vector<int>& v, int low, int mid, int high) {
	vector<int> temp;

	int i, j;
	i = low;
	j = mid + 1;

	while (i <= mid && j <= high) { //=here
		MergeSortComps++;
		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			i++;
		}
		else {
			temp.push_back(v[j]);
			j++;
		}
	}
	while (i <= mid) {
		temp.push_back(v[i]);
		i++;
	}
	while (j <= high) { //=here
		temp.push_back(v[j]);
		j++;
	}
	for (int i = low; i <= high; i++) {  //=here
		v[i] = temp[i - low];
	}
}

void ms(vector<int>& v, int low, int high)
{
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		ms(v, low, mid);
		ms(v, mid + 1, high);
		merge(v, low, mid, high);
	}
}

SortResult MergeSort(vector<int>& v)
{
	auto start = chrono::high_resolution_clock::now();


	ms(v, 0, v.size() - 1);


	auto finish = chrono::high_resolution_clock::now();
	SortResult temp("merge", MergeSortComps, v.size(), finish - start);
	MergeSortComps = 0;
	return temp;
}

SortResult ShellSort(vector<int>& v)
{
	auto start = chrono::high_resolution_clock::now();
	
	int comps = 0;
	int h = 1;
	while (h < v.size() / 3)
		h = 3 * h + 1;
	while (h >= 1) {
		for (int i = h; i < v.size(); i++){
			comps++;
			for (int j = i; j >= h && v[j] < v[j - h]; j -= h) {
				comps++;
				swap(v[j], v[j-h]);
			}
		}
		h = h / 3;
	}


	auto finish = chrono::high_resolution_clock::now();
	SortResult temp("shell", comps, v.size(), finish - start);
	return temp;
}




//========================arrays=================================



vector<int> GenerateRandom(int power) {
	vector<int> temp(pow(2, power));
	for (int i = 0; i < temp.size(); i++){
		temp[i] = rand();
	}
	return temp;
}
vector<int> GenerateGrowing(int power) {
	vector<int> temp(pow(2, power));
	for (int i = 0; i < temp.size(); i++) {
		temp[i] = i;
	}
	return temp;
}
vector<int> GenerateDegressive(int power) {
	vector<int> temp(pow(2, power));
	for (int i = 0; i < temp.size(); i++) {
		temp[i] = temp.size()-i-1;
	}
	return temp;
}
vector<int> GenerateOfThree(int power) {
	vector<int> temp(pow(2, power));
	for (int i = 0; i < temp.size(); i++) {
		temp[i] = rand()%3+1;
	}
	return temp;
}



//=====================================condition=====================

void condition(int opt, ofstream& file) {
	switch (opt)
	{
	case 1:
		cout << "Condition 1 is processing..." << endl;
		for (int i = 7; i <= 15; i++) {
	
			vector<int>v11, v12, v13, v14, v21, v22, v23, v24, v31, v32, v33, v34, v41, v42, v43, v44, v51, v52, v53, v54;
			vector<int> tempalte1 = GenerateRandom(i);
			vector<int> template2 = GenerateRandom(i);
			vector<int> template3 = GenerateRandom(i);
			vector<int> template4 = GenerateRandom(i);
			vector<int> template5 = GenerateRandom(i);
			v11 = v12 = v13 = v14 = tempalte1;
			v21 = v22 = v23 = v24 = template2;
			v31 = v32 = v33 = v34 = template3;
			v41 = v42 = v43 = v44 = template4;
			v51 = v52 = v53 = v54 = template5;

			SortResult temp1,temp2,temp3,temp4,temp5;

			//file << "2^" << i << " elements." << endl;

			temp1 = InsertionSort(v11);
			temp2 = InsertionSort(v21);
			temp3 = InsertionSort(v31);
			temp4 = InsertionSort(v41);
			temp5 = InsertionSort(v51);
			SortResult average = avg(temp1, temp2, temp3, temp4, temp5);
			average.out(file);

			cout << "Insertion is done!" << endl;

			temp1 = SelectionSort(v12);
			temp2 = SelectionSort(v22);
			temp3 = SelectionSort(v32);
			temp4 = SelectionSort(v42);
			temp5 = SelectionSort(v52);
			SortResult average1 = avg(temp1, temp2, temp3, temp4, temp5);
			average1.out(file);

			cout << "Selection is done!" << endl;

			temp1 = MergeSort(v13);
			temp2 = MergeSort(v23);
			temp3 = MergeSort(v33);
			temp4 = MergeSort(v43);
			temp5 = MergeSort(v53);
			SortResult average2 = avg(temp1, temp2, temp3, temp4, temp5);
			average2.out(file);

			cout << "Merge is done!" << endl;

			temp1 = ShellSort(v14);
			temp2 = ShellSort(v24);
			temp3 = ShellSort(v34);
			temp4 = ShellSort(v44);
			temp5 = ShellSort(v54);
			SortResult average3 = avg(temp1, temp2, temp3, temp4, temp5);
			average3.out(file);
			cout << "Shell is done!" << endl;

			file << "\n\n";
			cout << "2^" << i << " is done successfully!" << endl << endl;
		}
		cout << "==========Condition 1 is done!==========" << endl;
		break;
	case 2:
		cout << "Condition 2 is processing..." << endl;

		for (int i = 7; i <= 15; i++) {
			vector<int> tempalte = GenerateGrowing(i);
			vector<int>v1, v2, v3, v4;
			v1 = v2 = v3 = v4 = tempalte;
			SortResult temp;

			//file << "2^" << i << " elements." << endl;

			temp = InsertionSort(v1);
			temp.out(file);
			cout << "Insertion is done!" << endl;

			temp = SelectionSort(v2);
			temp.out(file);
			cout << "Selection is done!" << endl;

			temp = MergeSort(v3);
			temp.out(file);
			cout << "Merge is done!" << endl;

			temp = ShellSort(v4);
			temp.out(file);
			cout << "Shell is done!" << endl;

			file << "\n\n";
			cout << "2^" << i << " is done successfully!" << endl << endl;
		}
		cout << "==========Condition 2 is done!==========" << endl;
		break;
	case 3:
		cout << "Condition 3 is processing..." << endl;

		for (int i = 7; i <= 15; i++) {
			vector<int> tempalte = GenerateDegressive(i);
			vector<int>v1, v2, v3, v4;
			v1 = v2 = v3 = v4 = tempalte;
			SortResult temp;

			//file << "2^" << i << " elements." << endl;

			temp = InsertionSort(v1);
			temp.out(file);
			cout << "Insertion is done!" << endl;

			temp = SelectionSort(v2);
			temp.out(file);
			cout << "Selection is done!" << endl;

			temp = MergeSort(v3);
			temp.out(file);
			cout << "Merge is done!" << endl;

			temp = ShellSort(v4);
			temp.out(file);
			cout << "Shell is done!" << endl;

			file << "\n\n";
			cout << "2^" << i << " is done successfully!" << endl << endl;
		}
		cout << "==========Condition 3 is done!==========" << endl;
		break;
	case 4:
		cout << "Condition 4 is processing..." << endl;

		for (int i = 7; i <= 15; i++) {
			vector<int> tempalte1 = GenerateDegressive(i);
			vector<int> tempalte2 = GenerateDegressive(i);
			vector<int> tempalte3 = GenerateDegressive(i);
			vector<int>v11, v12, v13, v14, v21, v22, v23, v24, v31, v32, v33, v34;
			v11 = v12 = v13 = v14 = tempalte1;
			v21 = v22 = v23 = v24 = tempalte2;
			v31 = v32 = v33 = v34 = tempalte3;
			SortResult temp1, temp2, temp3;

			//file << "2^" << i << " elements." << endl;

			temp1 = InsertionSort(v11);
			temp2 = InsertionSort(v12);
			temp3 = InsertionSort(v13);
			SortResult average1 = avg(temp1, temp2, temp3);
			average1.out(file);
			cout << "Insertion is done!" << endl;

			temp1 = SelectionSort(v11);
			temp2 = SelectionSort(v12);
			temp3 = SelectionSort(v13);
			SortResult average2 = avg(temp1, temp2, temp3);
			average2.out(file);
			cout << "Selection is done!" << endl;

			temp1 = MergeSort(v11);
			temp2 = MergeSort(v12);
			temp3 = MergeSort(v13);
			SortResult average3 = avg(temp1, temp2, temp3);
			average3.out(file);
			cout << "Merge is done!" << endl;

			temp1 = ShellSort(v11);
			temp2 = ShellSort(v12);
			temp3 = ShellSort(v13);
			SortResult average4 = avg(temp1, temp2, temp3);
			average4.out(file);
			cout << "Shell is done!" << endl;

			file << "\n\n";
			cout << "2^" << i << " is done successfully!" << endl << endl;
		}
		cout << "==========Condition 4 is done!==========" << endl;
		break;
	default:
		cout << "wrong option!!" << endl;
		break;
	}
}

SortResult avg(SortResult r1, SortResult r2, SortResult r3, SortResult r4, SortResult r5) {
	SortResult temp;
	temp.type = r1.type;
	temp.elements = r1.elements;
	temp.comparisons = (r1.comparisons + r2.comparisons + r3.comparisons + r4.comparisons + r5.comparisons) / 5;
	temp.duration = r5.duration;
	return temp;
}
SortResult avg(SortResult r1, SortResult r2, SortResult r3) {
	SortResult temp;
	temp.type = r1.type;
	temp.elements = r1.elements;
	temp.comparisons = (r1.comparisons + r2.comparisons + r3.comparisons) / 3;
	temp.duration = r3.duration;
	return temp;
}
