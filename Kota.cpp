/*
 * File:   Kota.cpp
 * Author: haniferidaputra
 *
 * Created on March 15, 2013, 7:18 AM
 */

#include "Kota.h"

Kota::Kota() {

}

Kota::Kota(int x, int y){
// x dan y harus diisi dengan curX dan curY player
    xPlayer=x;
    yPlayer=y;
    matriks[xPlayer][yPlayer]='0';
    xHome = xHomeBound;
    yHome = yHomeBound;
    for (int j=xHomeBound-2; j<xHomeBound+3; j++){
		for (int i=yHomeBound; i<yHomeBound+5; i++){
			matriks[j][i] = '.';
		}
	}
    matriks[xHome][yHome]='H';
    xStadium = xStadiumBound;
    yStadium = yStadiumBound;
    for (int j=xStadiumBound-5; j<xStadiumBound+1; j++){
		for (int i=yStadiumBound-5; i<yStadiumBound+10; i++){
			matriks[j][i] = '_';
		}
	}
    matriks[xStadium][yStadium]='S';
    xCmb = xCombinatoriumBound;
    yCmb = yCombinatoriumBound;
    for (int j=xCombinatoriumBound-4; j<xCombinatoriumBound+1; j++){
		for (int i=yCombinatoriumBound-5; i<yCombinatoriumBound+5; i++){
			matriks[j][i] = '-';
		}
	}
    matriks[xCmb][yCmb]='C';
    xStore = xStoreBound;
    yStore = yStoreBound;
    for (int j=xStoreBound-5; j<xStoreBound+4; j++){
		for (int i=yStoreBound-4; i<yStoreBound+1; i++){
			matriks[j][i] = '|';
		}
	}
    matriks[xStore][yStore]='T';
    matriks[xLuarBound][yLuarBound]='L';
    for (int j=27; j<29; j++){
		for (int i=20; i<65; i++){
			matriks[j][i] = '*';
		}
	}
	
}

Kota::Kota(const Kota& K) {
    xLength = K.xLength;
    yLength = K.yLength;
}

Kota::~Kota() {

}

void Kota::setXPlayer(int i){
    xPlayer=i;
}
void Kota::setYPlayer(int i){
    yPlayer=i;
}

void Kota::setPosisiPlayer(int x,int y){
    matriks[xPlayer][yPlayer]=' ';
    setXPlayer(x);
    setYPlayer(y);
    matriks[x][y]='0';
}

Kota& Kota::operator =(const Kota& K){
    xLength = K.xLength;
    yLength = K.yLength;
    return *this;
}

void Kota::drawScreen(int i){
    drawMatriks(); //misalkan aja angka satu
}

int Kota::isSteppable(){

}
