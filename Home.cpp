#include"Home.h"

Home::Home(){
	cout << "masuk" << endl;
}

Home::~Home(){
	
}

void Home::drawHome(){
	this->screenHome.drawScreen(1);
}