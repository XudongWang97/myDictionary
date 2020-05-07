#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include "dicframe.h"

using namespace std;

DicFrame::DicFrame(){
    iofile.initDatabase(this->database);
}

void DicFrame::run(){
    this->display.shellInit();
    this->display.userInterface(0);
    cout << this->database.init("dicnew.txt");
    for(int i=0;i<this->database.getSize();++i) this->database.showWord(i);
    this->iofile.readTextthenShow("article.txt");
}
