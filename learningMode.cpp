#include<iostream>

#include<string>
#include<vector>
#include "learningMode.h"

LearningMode::LearningMode(Database& db){
    this->database = db;
}

void LearningMode::showWord(int index){
    cout << "   " << this->database.getWord(index).get_word() << "   " << this->database.getWord(index).get_pos() << endl;
}

void LearningMode::showMeaning(int index){
    cout << "   " << this->database.getWord(index).get_meaning() << endl;
}

void LearningMode::showSelection(int index){

}

void LearningMode::showAnswer(int index){
    cout << "The Right Answer is:" << this->database.getWord(index).get_meaning() << endl;
}
