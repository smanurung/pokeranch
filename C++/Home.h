#ifndef HOME_H
#define HOME_H

#include "Point.h"
#include "Screen.h"
#include <iostream>

using namespace std;

class Home{

private:
    Screen screenHome;
	Point playerPosition;

public:
	//ctor
    Home();
	
	//dtor
    ~Home();
	
	//function member
	void drawHome();
};//end class

#endif // HOME_H_INCLUDED