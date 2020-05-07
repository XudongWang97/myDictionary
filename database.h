//database.h
#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "difficulty_base.h"

using std::string;

class Database{
	vector<Word> words;
	Word word;
	Difficulty_Base difficulty_base[5];

public:
	Database();
	virtual int init(string fileName);
	int getSize();
	bool isEmpty();
//	//按字典序比较的函数，辅助排序函数
//	bool Comp(const Word &a, const Word &b);
	void sortWord();
	//返回下标为i的单词，错误则返回空
	Word getWord(int i);
	int addWord(Word newWord);
	int deleteWord(int i);
	//二分法查找返回word的下标,没有则返回-1
	int binarySearch(string word);

	void initDiffBase();
	//更新单词word的难度级别为newDiff
	int setDiff(string word, int newDiff);
	//得到难度级别为diff的单词的总数
	int getSizeDiff(int diff);
	//随机得到一个难度级别为diff的单词
	Word getRandomDiff(int diff);
    void showWord(int i);
    void giveRecord(ofstream& out);
};

#endif // DATABASE_H
