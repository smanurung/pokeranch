#include"Home.h"

#define HOME_HEIGHT 20
#define HOME_WIDTH 20

Home::Home(){
	//cout << "Masuk" << endl;
}

Home::~Home(){
	
}

void Home::drawHome(){
	this->screenHome.drawScreen(0);
}