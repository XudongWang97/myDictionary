#ifndef LEARNINGMODE_H
#define LEARNINGMODE_H

#include<iostream>
#include<string>
#include<vector>
#include "database.h"
#include "display.h"

class LearningMode{
    Database database;
    virtual void showWord(int index);
    virtual void showMeaning(int index);
    virtual void showSelection(int index);
    virtual void showAnswer(int index);
public:
    LearningMode(Database& db);
    //virtual void learn(int index);
    //virtual void review(int index);
    //virtual void check(int index);
};

#endif // LEARNINGMODE_H
