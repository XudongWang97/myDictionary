#ifndef IOFILE_H
#define IOFILE_H

#include<fstream>
#include<string>
#include "database.h"

class IOfile{
    Database database;
public:
    IOfile();
    virtual void initDatabase(Database& db);
    //virtual void initFout(string s);
    virtual void readTextthenShow(string s);
    virtual void initializeFromLog();
    virtual void writeLog();
};

#endif // IOFILE_H
