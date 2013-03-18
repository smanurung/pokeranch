/*
 * File:   Screen.cpp
 * Author: haniferidaputra
 *
 * Created on March 14, 2013, 11:12 PM
 */

#include "Screen.h"

#define STORE_HEIGHT 70
#define STORE_WIDTH 10

Screen::Screen() {
    xLength = 50;
    yLength = 20;

    matriks = new char * [yLength];
    for(int i=0; i<yLength; i++){
        matriks[i]= new char[xLength];
    }

    for(int i=0; i<yLength; i++){
        for(int j=0; j<xLength; j++){
            matriks[i][j] = '.';
        }
    }
}

Screen::Screen(int x, int y){
    xLength = x;
    yLength = y;

    matriks = new char * [yLength];
    for(int i=0; i<yLength; i++){
        matriks[i]= new char[xLength];
    }

    for(int i=0; i<yLength; i++){
        for(int j=0; j<xLength; j++){
            matriks[i][j] = '.';
        }
    }

}

Screen::Screen(const Screen& S) {
    xLength = S.xLength;
    yLength = S.yLength;
}

Screen::~Screen() {

}

int Screen::getXLength(){
    return xLength;
}

int Screen::getYLength(){
    return yLength;
}


void Screen::drawMatriks(){
                for(int i=0; i<yLength; i++){
                    for(int j=0; j<xLength; j++){
                        cout << matriks[i][j] ;
                    }
                    cout<< endl;
                }//end for
                cout<< endl;
                cout<< endl;
}

void Screen::drawMatriksStore(){
	Screen _s(STORE_HEIGHT, STORE_WIDTH);
	
	char subs;
	for (int i=0; i<5; i++){
		switch (i) {
			
			case 0 : {
				subs = 'E';
				break;
			}
			
			case 1 : {
				subs = 'R';
				break;
			}
			
			case 2 : {
				subs = 'O';
				break;
			}
			
			case 3 : {
				subs = 'T';
				break;
			}
			
			case 4 : {
				subs = 'S';
				break;
			}
		}
		
		//_s.matriks[HOME_WIDTH-i,i] = subs;
		_s.setMatriks(0,STORE_HEIGHT-i-1,subs);
	}
	
    for(int i=0; i<_s.yLength; i++){
        for(int j=0; j<_s.xLength; j++){
            cout << _s.matriks[i][j] ;
        }
        cout<< endl;
    }//end for
    cout<< endl;
    cout<< endl;
}

void Screen::drawScreen(int s){
    //menggambar screen dengan masukan integer tempat

    switch (s){
        case 1:                 //store
			drawMatriks();
			break;
			
        case 2:                 //home
			drawMatriksStore();
			break;
    }
}

void Screen::setMatriks(int _x, int _y, char _c){
	this->matriks[_x][_y] = _c;
}