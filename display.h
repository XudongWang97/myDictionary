#ifndef DISPLAY_H
#define DISPLAY_H

#include<iostream>
#include<string>

using std::string;
using std::cout;

class Display{
    virtual void init();
    virtual void printBlankLines(unsigned n);
    virtual void printCenter(string s);
    virtual void printCenter(string s, char c);
public:
    Display();
    virtual void shellInit();
    virtual void userInterface(unsigned faceno);
};

#endif // DISPLAY_H
