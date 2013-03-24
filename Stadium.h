#ifndef STADIUM_H
#define STADIUM_H

#include "Point.h"
#include "Screen.h"
#include <iostream>

using namespace std;

class Stadium{

private:
    Screen screenStadium;
	int bet;
//	NPC lawan[];

public:
	//ctor
    Stadium();
	
	//dtor
    ~Stadium();
	
	//function member
	void drawStadium();
};//end class

#endif // STADIUM_H_INCLUDED