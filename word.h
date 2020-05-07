#ifndef WORD_H
#define WORD_H

#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

class Word{
    unsigned senNum;
    unsigned difficulty;
    unsigned state;
    bool is_new; //Éú´Êtrue¡¢·ÇÉú´Êfalse
    time_t last_time;
    time_t next_time;
    string pos;
    string word;
    string meaning;
    string sentence[2];
public:
    Word();
    Word(string english, string part_of_speech , string chinese);
    virtual void set_english(string english);
    virtual void set_pos(string pos);
    virtual void set_chinese(string chinese);
    virtual const string get_word();
    virtual const string get_pos();
    virtual const string get_meaning();

    virtual string get_sentence1();
    virtual string get_sentence2();
    virtual void delete_sentence1();
    virtual void delete_sentence2();
    virtual void add_sentence1(string sen);
    virtual void add_sentence2(string sen);
    virtual unsigned get_sen_num();

    virtual void set_difficulty(unsigned diff);
    virtual unsigned get_difficulty();

    virtual void renew_now(time_t tnow);
    virtual void renew_tonexttime(time_t tnext);
    virtual bool time_to_recite();//Èôµ½ÁË¼ÇÒäµÄÊ±¼äÔòÊä³ötrue

    virtual bool is_new_word();//ÈôÊÇÉú´ÊÔòÊä³ötrue
    virtual void cite();//±ê¼ÇÎªÉú´Ê
    virtual void forget();//±ê¼ÇÎªÊì´Ê

    virtual void show(ofstream& out);
};

#endif // WORD_H
