//difficulty_base.cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "word.h"
#include "difficulty_base.h"

using namespace std;

void Difficulty_Base::init(int i) {
	difficulty = i;
}

int Difficulty_Base::getSize() {
	return entries.size();
}

bool Difficulty_Base::isEmpty() {
	if (getSize() <= 0)
		return true;
	return false;
}

void Difficulty_Base::sortEntries() {
	sort(entries.begin(), entries.end());
}

//二分法查找i在entries中的下标，如果未找到则返回负值
int Difficulty_Base::binarySearch(int i) {
	int left = 0;
	int right = getSize() - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (entries[middle] == i)
			return middle;
		if (entries[middle] < i) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	return -1;
}

int Difficulty_Base::addEntry(int i) {
	entries.push_back(i);
	sortEntries();
	return 0;
}

//删除entries中数值为i的元素
int Difficulty_Base::deleteEntry(int i) {
	int j = binarySearch(i);
	if (j < 0) {
		return -1;
	}
	else {
		entries.erase(entries.begin() + j);
		return 0;
	}
}

//随机返回entries中存储的某个数值
int Difficulty_Base::randomEntry() {
	srand((unsigned)time(NULL));
	return entries[rand() % (entries.size())];
}
