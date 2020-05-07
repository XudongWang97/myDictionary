//database.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "database.h"
#include "compare.cpp"

using namespace std;

Database::Database() {
}

int Database::init(string fileName) {
	ifstream fin(fileName);
	if (!fin) {
		cout << "Database reading file failed.";
		return -1;
	}
	string tempWord, tempMeaning, tempPos, temp;
	while (fin >> temp >> tempWord >> tempPos >> tempMeaning) {
		word.set_english(tempWord);
		word.set_pos(tempPos);
		word.set_chinese(tempMeaning);
		words.push_back(word);
	}
	fin.close();
	return 0;
}

int Database::getSize() {
	return words.size();
}

bool Database::isEmpty() {
	if (words.size() <= 0)
		return true;
	return false;
}

//bool Database::Comp(const Word &a, const Word &b) {
//	return a.get_word() > b.get_word();
//}

void Database::sortWord() {
	sort(words.begin(), words.end(), Compare());
}

Word Database::getWord(int i) {
	if (i < 0 || i >= words.size()) {
		cout << "Database::getWord: Can not find this index!";
		Word tempWord;
		return tempWord;
	}
	return words[i];
}

int Database::addWord(Word newWord) {
	words.push_back(newWord);
	sortWord();
	return 0;
}

int Database::deleteWord(int i) {
	if (i < 0 || i >= words.size()) {
	 cout << "Database::deleteWord: Can not find this index!";
	return -1;
	}
	words.erase(words.begin() + i);
	return 0;
}

int Database::binarySearch(string word) {
	int left = 0;
	int right = words.size() - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (words[middle].get_word() == word) {
			return middle;
		}
		if (words[middle].get_word() > word) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	return -1;
}

void Database::initDiffBase() {
	for (int i = 0; i < 5; i ++) {
		difficulty_base[i].init(i + 1);
	}
	for (int i = 0; i < words.size(); i ++) {
		difficulty_base[words[i].get_difficulty() - 1].addEntry(i);
	}
	for (int i = 0; i < 5; i ++) {
		difficulty_base[i].sortEntries();
	}
}

int Database::setDiff(string word, int newDiff) {
	int i = binarySearch(word);
	if (i < 0) {
		cout << "Database::setDiff: Can not find this word!";
		return -1;
	}
	difficulty_base[words[i].get_difficulty() - 1].deleteEntry(i);
	difficulty_base[words[i].get_difficulty() - 1].sortEntries();
	words[i].set_difficulty(newDiff);
	difficulty_base[words[i].get_difficulty() - 1].addEntry(i);
	difficulty_base[words[i].get_difficulty() - 1].sortEntries();
	return 0;
}

int Database::getSizeDiff(int diff) {
	return difficulty_base[diff - 1].getSize();
}

Word Database::getRandomDiff(int diff) {
	return words[difficulty_base[diff - 1].randomEntry()];
}


void Database::showWord(int i){
    Word w = this->getWord(i);
    cout << "   " << w.get_word() << "       " << w.get_pos() << "  " << w.get_meaning() << endl;
}

void Database::giveRecord(ofstream& out){
    if(!this-isEmpty()){
        for(unsigned i=0;i<this->getSize();++i)
            words[i-1].show(out);
    }
}
