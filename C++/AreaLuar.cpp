/*
 * File:   AreaLuar.cpp
 * Author: haniferidaputra
 *
 * Created on March 14, 2013, 11:12 PM
 */

#include "AreaLuar.h"

AreaLuar::AreaLuar() {

}

AreaLuar::AreaLuar(int x, int y){
    // x dan y harus diisi dengan curX dan curY player
    xPlayer=x;
    yPlayer=y;
    matriks[xPlayer][yPlayer]='0';
    xM1=10;
    yM1=30;
    matriks[xM1][yM1]='M';
    xM2=15;
    yM2=10;
    matriks[xM2][yM2]='M';
    xM3=12;
    yM3=3;
    matriks[xM3][yM3]='M';
    xM4=17;
    yM4=15;
    matriks[xM4][yM4]='M';
    xM5=25;
    yM5=45;
    matriks[xM5][yM5]='M';
    xM6=30;
    yM6=60;
    matriks[xM6][yM6]='M';
    xM7=23;
    yM7=42;
    matriks[xM7][yM7]='M';
    xM8=22;
    yM8=17;
    matriks[xM8][yM8]='M';
    xM9=28;
    yM9=5;
    matriks[xM9][yM9]='M';
    xM10=5;
    yM10=65;
    matriks[xM10][yM10]='M';
    for (int j=0; j<2; j++){
		for (int i=0; i<2; i++){
			matriks[j][i] = '+';
		}
	}
    matriks[1][1] = 'K';
    for (int j=2; j<5; j++){
		for (int i=18; i<63; i++){
			matriks[j][i] = '*';
		}
	}
	for (int j=27; j<29; j++){
		for (int i=20; i<65; i++){
			matriks[j][i] = '*';
		}
	}
	for (int j=9; j<21; j++){
		for (int i=50; i<67; i++){
			matriks[j][i] = '*';
		}
	}
	for (int j=7; j<17; j++){
		for (int i=25; i<30; i++){
			matriks[j][i] = '*';
		}
	}
	for (int j=18; j<21; j++){
		for (int i=5; i<12; i++){
			matriks[j][i] = '*';
		}
	}

}

AreaLuar::AreaLuar(const AreaLuar& AL) {
    xLength = AL.xLength;
    yLength = AL.yLength;
}

AreaLuar::~AreaLuar() {

}

void AreaLuar::setXPlayer(int i){
    xPlayer=i;
}
void AreaLuar::setYPlayer(int i){
    yPlayer=i;
}

void AreaLuar::setPosisiPlayer(int x,int y){
    matriks[xPlayer][yPlayer]=' ';
    setXPlayer(x);
    setYPlayer(y);
    matriks[x][y]='0';
}

AreaLuar& AreaLuar::operator =(const AreaLuar& AL){
    xLength = AL.xLength;
    yLength = AL.yLength;
    return *this;
}

void AreaLuar::drawScreen(int i){
	cout<<"AREA LUAR POKERANCH"<<endl;
    drawMatriks(); //misalkan aja angka satu
}

int AreaLuar::isSteppable(int y, int x){ //return 1 apabila dapat diinjak
	return matriks[x][y] == ' ' || matriks[x][y] == 'K' || matriks[x][y] == 'M';
}
