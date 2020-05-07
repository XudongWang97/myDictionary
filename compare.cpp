#include<iostream>  
#include<string>  
#include "word.h"  
  
using namespace std;  
    
class Compare {  
public:
    bool operator()(Word a, Word b) {  
		return a.get_word() < b.get_word();  
	}
};


