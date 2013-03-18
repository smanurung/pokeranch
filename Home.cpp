#include"Home.h"

#define HOME_HEIGHT 20
#define HOME_WIDTH 20

Home::Home(){
	Screen _s(HOME_WIDTH,HOME_HEIGHT);
	/*_s.drawScreen(1);*/
	screenHome = _s;
	
	char subs;
	for (int i=0; i<4; i++){
		switch (i) {
			case 0 : subs = 'E';
			case 1 : subs = 'M';
			case 2 : subs = 'O';
			case 3 : subs = 'H';
		}
			
		_s.matriks[HOMEWIDTH-i,i] = subs;
	}
}

Home::~Home(){
	
}

void Home::drawHome(){
	this->screenHome.drawScreen(1);
}