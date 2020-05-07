#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include "word.h"

using namespace std;

Word::Word(){}

Word::Word(string english, string part_of_speech, string chinese){
    word = english;
    pos = part_of_speech;
    meaning = chinese;
    sentence[0] = "";
    sentence[1] = "";
    difficulty = 0;
    senNum = 0;
    last_time = time(nullptr);
    next_time = 0;
    is_new = true;
}

void Word::set_english(string english){
    word = english;
}

void Word::set_pos(string part_of_speech){
    pos = part_of_speech;
}

void Word::set_chinese(string chinese){
    meaning = chinese;
}

const string Word::get_word(){ return this->word; }

const string Word::get_pos(){ return this->pos; }

const string Word::get_meaning(){ return this->meaning; }

string Word::get_sentence1(){ if(this->sentence[0]!="") return this->sentence[0]; else return "There is no sentence!"; }
string Word::get_sentence2(){ if(this->sentence[1]!="") return this->sentence[1]; else return "There is no sentence!"; }

void Word::add_sentence1(string sen){
    if(this->sentence[0]=="") ++senNum;
    this->sentence[0] = sen;
}

void Word::add_sentence2(string sen){
    if(this->sentence[1]=="") ++senNum;
    this->sentence[1] = sen;
}

void Word::delete_sentence1(){
    if(this->sentence[0]!="") --senNum;
    this->sentence[0] = "";
}

void Word::delete_sentence2(){
    if(this->sentence[1]!="") --senNum;
    this->sentence[1] = "";
}

unsigned Word::get_sen_num(){ return this->senNum; }

void Word::set_difficulty(unsigned diff){
    this->difficulty = diff;
}

unsigned Word::get_difficulty(){ return this->difficulty; }

void Word::renew_now(time_t tnow){
    this->last_time = tnow;
}

void Word::renew_tonexttime(time_t tnext){
    this->next_time = tnext;
}

bool Word::time_to_recite(){ return (last_time + next_time <= time(nullptr)); }

bool Word::is_new_word(){ return this->is_new; }

void Word::cite(){
    is_new = false;
}

void Word::forget(){
    is_new = true;
}

void Word::show(ofstream& out){
    out << word << endl;
    out << pos << endl;
    out << meaning << endl;
    out << senNum << endl;
    out << sentence[0] << endl;
    out << sentence[1] << endl;
    out << last_time << endl;
    out << next_time << endl;
    out << is_new << endl;
    out << state << endl;
    out << difficulty << endl;
}
