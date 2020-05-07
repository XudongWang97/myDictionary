#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "iofile.h"
#include "database.h"

using namespace std;

IOfile::IOfile(){}

void IOfile::initDatabase(Database& db){
    this->database = db;
}

void IOfile::readTextthenShow(string fileName){
    ifstream in(fileName);
    if(!in) {
        cout << "Cannot read this file!" << endl;
        return;
    }
    int wcount = 0;
    vector<int> vint;
    vint.clear();
    string s;
    while(in >> s){
        if(this->database.binarySearch(s) != -1){
            vint.push_back(this->database.binarySearch(s));
        }
    }
    sort(vint.begin(),vint.end());
    if(!vint.empty()){
        wcount = 1;
        this->database.showWord(*(vint.begin()));
        for(vector<int>::iterator it=vint.begin();it!=vint.end()-1;++it)
            if(*(it+1) > *(it)) {
                ++ wcount;
                this->database.showWord(*(it+1));
            }
    }
    cout << "This article have " << wcount << " words in the Word Library." << endl;
    in.close();
}

void IOfile::initializeFromLog(){}

void IOfile::writeLog(){

}
