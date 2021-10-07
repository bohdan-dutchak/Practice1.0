#include "SortResult.h"
SortResult::SortResult() {
	type = "not speified type";
	comparisons = 0;
	elements = 0;
}

SortResult::SortResult(string t, int c, int e, chrono::duration<float> d) {
	type = t;
	comparisons = c;
	elements = e;
	duration = d;
}

void SortResult::out(ofstream &file){
	file << type << " " << elements << " " << comparisons << " " << duration.count()<<endl;
}
