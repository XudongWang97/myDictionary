#ifndef DICFRAME_H
#define DICFRAME_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include "word.h"
#include "database.h"
#include "display.h"
#include "iofile.h"

class DicFrame{
    unsigned mode;
    Database database;
    Display display;
    IOfile iofile;
public:
    DicFrame();
    virtual void run();
};

#endif // DICFRAME_H
