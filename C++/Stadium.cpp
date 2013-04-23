#include"Stadium.h"

Stadium::Stadium(){
	cout << "Masuk" << endl;
}

Stadium::~Stadium(){
	
}

void Stadium::drawStadium(){
	this->screenStadium.drawScreen(4);
}