/*
 * File:   Screen.cpp
 * Author: haniferidaputra
 *
 * Created on March 14, 2013, 11:12 PM
 */

#include "Screen.h"

#include <iostream>
#include <fstream>
#include <string>
#include <fstream> 
#include <sstream> 

#define HOME_HEIGHT 20
#define HOME_WIDTH 20

#define STORE_HEIGHT 10
#define STORE_WIDTH 70

#define COMBINATORIUM_HEIGHT 20
#define COMBINATORIUM_WIDTH 40

using namespace std;

char bred[] = { 0x1b, '[', '1', ';', '4', '1', 'm', 0 };
char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
char byellow[] = { 0x1b, '[', '1', ';', '4', '3', 'm', 0 };
char yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
char bmagenta[] = { 0x1b, '[', '1', ';', '4', '5', 'm', 0 };
char magenta[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
char bcyan[] = { 0x1b, '[', '1', ';', '4', '6', 'm', 0 };
char cyan[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
char bgreen[] = { 0x1b, '[', '1', ';', '4', '2', 'm', 0 };
char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
char bblack[] = { 0x1b, '[', '1', ';', '4', '0', 'm', 0 };
char black[] = { 0x1b, '[', '1', ';', '3', '0', 'm', 0 };
char white[] = { 0x1b, '[', '0', ';', '3', '7', 'm', 0 };
char bgray[] = { 0x1b, '[', '1', ';', '4', '7', 'm', 0 };
char bnormal[] = { 0x1b, '[', '0', ';', '4', '9', 'm', 0 };
char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

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
                        if (matriks[i][j] == '.'){ //unsteppable place
            				cout <<bgray<< matriks[i][j]<<normal<<bnormal ;
            			} else if (matriks[i][j] == '0'){ //orang/user
            				cout <<bgreen<< matriks[i][j]<<normal<<bnormal ;
            			} else { //Lain-lain bisa ditambah
            				cout <<byellow<<red<< matriks[i][j]<<normal<<bnormal ;
            			}
                    }
                    cout<< endl;
                }//end for
                cout<< endl;
                cout<< endl;
}

void Screen::drawMatriksHome(){
	Screen _s(HOME_WIDTH,HOME_HEIGHT);
	
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
		_s.setMatriks(0,HOME_WIDTH-i-1,subs);
	}
	
	for(int i=0; i<_s.yLength; i++){
        for(int j=0; j<_s.xLength; j++){
        	if (_s.matriks[i][j] == '.'){ //unsteppable place
            	cout <<bcyan<< _s.matriks[i][j]<<normal<<bnormal ;
            } else if (matriks[i][j] == '0'){ //orang/user
            	cout <<bgreen<< matriks[i][j]<<normal<<bnormal ;
            } else {
            	cout <<byellow<<red<< _s.matriks[i][j]<<normal<<bnormal ;
            }
        }
        cout<< endl;
    }//end for
    cout<< endl;
    cout<< endl;
}

void Screen::drawMatriksStore(){
	Screen _s(STORE_WIDTH, STORE_HEIGHT);
	
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
		_s.setMatriks(0,STORE_WIDTH-i-1,subs);
	}
	
    for(int i=0; i<_s.yLength; i++){
        for(int j=0; j<_s.xLength; j++){
        	if (_s.matriks[i][j] == '.'){ //unsteppable place
            	cout <<bgray<< _s.matriks[i][j]<<normal<<bnormal ;
            } else if (matriks[i][j] == '0'){ //orang/user
            	cout <<bgreen<< matriks[i][j]<<normal<<bnormal ;
            } else {
            	cout <<byellow<<red<< _s.matriks[i][j]<<normal<<bnormal ;
            }
        }
        cout<< endl;
    }//end for
    cout<< endl;
    cout<< endl;
}

void Screen::drawMatriksCombinatorium(){
	Screen _s(COMBINATORIUM_WIDTH, COMBINATORIUM_HEIGHT);
	
	char subs;
	for (int i=0; i<13; i++){
		switch (i) {
			
			case 0 : {
				subs = 'M';
				break;
			}
			
			case 1 : {
				subs = 'U';
				break;
			}
			
			case 2 : {
				subs = 'I';
				break;
			}
			
			case 3 : {
				subs = 'R';
				break;
			}
			
			case 4 : {
				subs = 'O';
				break;
			}
			
			case 5 : {
				subs = 'T';
				break;
			}
			
			case 6 : {
				subs = 'A';
				break;
			}
			
			case 7 : {
				subs = 'N';
				break;
			}
			
			case 8 : {
				subs = 'I';
				break;
			}
			
			case 9 : {
				subs = 'B';
				break;
			}
			
			case 10 : {
				subs = 'M';
				break;
			}
			
			case 11 : {
				subs = 'O';
				break;
			}
			
			case 12 : {
				subs = 'C';
				break;
			}
		}
		
		//_s.matriks[HOME_WIDTH-i,i] = subs;
		_s.setMatriks(0,COMBINATORIUM_WIDTH-i-1,subs);
	}
	
    for(int i=0; i<_s.yLength; i++){
        for(int j=0; j<_s.xLength; j++){
        	if (_s.matriks[i][j] == '.'){ //unsteppable place
            	cout <<bmagenta<< _s.matriks[i][j]<<normal<<bnormal ;
            } else if (matriks[i][j] == '0'){ //orang/user
            	cout <<bgreen<< matriks[i][j]<<normal<<bnormal ;
            } else {
            	cout <<byellow<<red<< _s.matriks[i][j]<<normal<<bnormal ;
            }
        }
        cout<< endl;
    }//end for
    cout<< endl;
    cout<< endl;
}

void Screen::drawScreen(int s){
    //menggambar screen dengan masukan integer tempat

    switch (s){
        case 1:                 //Home
			drawMatriksHome();
			break;
			
        case 2:                 //Store
			drawMatriksStore();
			break;
		case 3:					//Combinatorium
			drawMatriksCombinatorium();
			break;
    }
}

void Screen::setMatriks(int _x, int _y, char _c){
	this->matriks[_x][_y] = _c;
}