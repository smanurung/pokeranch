#include"Home.h"

#define HOME_HEIGHT 20
#define HOME_WIDTH 20

Home::Home(){
	cout << "masuk" << endl;
	
	Screen _s(HOME_WIDTH,HOME_HEIGHT);
	/*_s.drawScreen(1);*/
	screenHome = _s;
	
	char subs;
	for (int i=0; i<4; i++){
		switch (i) {
			
			case 0 : {
				subs = 'E';
				break;
			}
			
			case 1 : {
				subs = 'M';
				break;
			}
			
			case 2 : {
				subs = 'O';
				break;
			}
			
			case 3 : {
				subs = 'H';
				break;
			}
		}
		
		//_s.matriks[HOME_WIDTH-i,i] = subs;
		screenHome.setMatriks(0,HOME_WIDTH-i-1,subs);
	}
}

Home::~Home(){
	
}

void Home::drawHome(){
	this->screenHome.drawScreen(1);
}