#include<iostream>
#include<string>
#include "display.h"

#define cls system("cls")
#define pause system("pause")

using namespace std;

Display::Display(){}

void Display::shellInit(){
    system("title Word Hurricane!");
    this->userInterface(0);
}

void Display::init(){
    cls;
    this->printBlankLines(4);
}

void Display::printBlankLines(unsigned n){
    for(int i=0;i<n;i++)
        cout << endl;
    return;
}

void Display::printCenter(string s){
    int l = s.length();
    for(int i=0;i<(80-l)/2;++i) cout << ' ';
    cout << s;
    for(int i=0;i<80-l-(80-l)/2;++i) cout << ' ';
    cout << endl;
}

void Display::printCenter(string s, char c){
    int l = s.length();
    for(int i=0;i<(80-l)/2;++i) cout << c;
    cout << s;
    for(int i=0;i<80-l-(80-l)/2;++i) cout << c;
    cout << endl;
}

void Display::userInterface(unsigned faceno){
    switch(faceno) {
        case 0:{
            this->init();
            this->printCenter("Welcome to Word Hurricane!", '-');
            break;
        }
        case 10:{
            this->init();
            this->printCenter("Settings");
            break;
        }
        case 20:{
            this->init();
            this->printCenter("Word Library Modification");
            break;
        }
        case 30:{
            this->init();
            this->printCenter("Learning Mode");
            break;
        }
        case 40:{
            this->init();
            this->printCenter("Testing Mode");
            break;
        }
        case 50:{
            this->init();
            this->printCenter("Search Mode");
            break;
        }

    }
}
