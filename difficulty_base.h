//difficulty_base.h
#ifndef DIFFICULTY_BASE_H
#define DIFFICULTY_BASE_H
#include "word.h"
#include <vector>
#include <algorithm>

using namespace std;

class Difficulty_Base{
	int difficulty;
	vector<int> entries;

public:
	void init(int i);
	int getSize();
	bool isEmpty();
	void sortEntries();
	int binarySearch(int i);
	int addEntry(int i);
	int deleteEntry(int i);
	int randomEntry();	
};




#endif //DIFFICULTY_BASE_H
