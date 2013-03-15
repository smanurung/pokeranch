/* 
 * File:   AreaLuar.cpp
 * Author: haniferidaputra
 * 
 * Created on March 14, 2013, 11:12 PM
 */

#include "AreaLuar.h"

AreaLuar::AreaLuar() {
    xLength = 30;
    yLength = 30;
}

AreaLuar::AreaLuar(int x, int y){
    xLength = x;
    yLength = y;
}

AreaLuar::AreaLuar(const AreaLuar& AL) {
    xLength = AL.xLength;
    yLength = AL.yLength;
}

AreaLuar::~AreaLuar() {

}

AreaLuar& AreaLuar::operator =(const AreaLuar& AL){
    xLength = AL.xLength;
    yLength = AL.yLength;
    return *this;
}

void AreaLuar::drawScreen(){
    
}

int AreaLuar::isSteppable(Point P){

}

void AreaLuar::implementRandom(){
    
}