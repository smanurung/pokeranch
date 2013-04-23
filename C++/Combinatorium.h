#ifndef COMBINATORIUM_H
#define COMBINATORIUM_H

#include "Point.h"
#include "Screen.h"
#include <iostream>

using namespace std;

class Combinatorium{

private:
    Screen screenCmb;
//    Monster combinedMonster;

public:
	//ctor
    Combinatorium();
	
	//dtor
    ~Combinatorium();
	
	//function member
	void drawCombinatorium();
};//end class

#endif // COMBINATORIUM_H_INCLUDED