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
    matriks[xPlayer][yPlayer]='.';
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
    drawMatriks();
}

int Kota::isSteppable(){

}
