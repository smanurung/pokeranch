/* 
 * File:   Kota.cpp
 * Author: haniferidaputra
 * 
 * Created on March 15, 2013, 7:18 AM
 */

#include "Kota.h"

Kota::Kota() {
    xLength = 30;
    yLength = 30;
}

Kota::Kota(int x, int y){
    xLength = x;
    yLength = y;
}

Kota::Kota(const Kota& K) {
    xLength = K.xLength;
    yLength = K.yLength;
}

Kota::~Kota() {

}

Kota& Kota::operator =(const Kota& K){
    xLength = K.xLength;
    yLength = K.yLength;
    return *this;
}

void Kota::drawScreen(){

}

int Kota::isSteppable(){
    
}