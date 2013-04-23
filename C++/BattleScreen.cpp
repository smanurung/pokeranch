/* 
 * File:   BattleScreen.cpp
 * Author: haniferidaputra
 * 
 * Created on March 15, 2013, 12:01 AM
 */

#include "BattleScreen.h"

BattleScreen::BattleScreen() {
//Monster User
    for (int j=22; j<32; j++){
		for (int i=10; i<28; i++){
			matriks[j][i] = '.';
		}
	}
	for (int j=19; j<22; j++){
		for (int i=14; i<24; i++){
			matriks[j][i] = '_';
		}
	}
	matriks[20][16] = '0';
	matriks[20][21] = '0';
	for (int j=23; j<28; j++){
		for (int i=7; i<10; i++){
			matriks[j][i] = '|';
		}
	}
	for (int j=23; j<28; j++){
		for (int i=28; i<31; i++){
			matriks[j][i] = '|';
		}
	}
	
//Moster Musuh
	for (int j=3; j<13; j++){
		for (int i=41; i<59; i++){
			matriks[j][i] = '_';
		}
	}
	for (int j=0; j<3; j++){
		for (int i=45; i<55; i++){
			matriks[j][i] = '=';
		}
	}
	matriks[1][47] = '0';
	matriks[1][52] = '0';
	for (int j=4; j<9; j++){
		for (int i=38; i<41; i++){
			matriks[j][i] = '.';
		}
	}
	for (int j=4; j<9; j++){
		for (int i=59; i<62; i++){
			matriks[j][i] = '.';
		}
	}
}

BattleScreen::BattleScreen(const BattleScreen& BS) {
    xLength = BS.xLength;
    yLength = BS.yLength;
}

BattleScreen::~BattleScreen() {
	
}

BattleScreen& BattleScreen::operator=(const BattleScreen& BS) {
    xLength = BS.xLength;
    yLength = BS.yLength;
    return *this;
}

void BattleScreen::drawScreen(int i){
	cout<<"BATTLE COY!!!"<<endl;
    drawMatriks();
}