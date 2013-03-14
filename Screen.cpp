/* 
 * File:   Screen.cpp
 * Author: haniferidaputra
 * 
 * Created on March 14, 2013, 10:08 PM
 */

#include "Screen.h"

Screen::Screen() {
    xLength = 10;
    yLength = 10;
}

Screen::Screen(int x, int y){
    xLength = x;
    yLength = y;
}

Screen::Screen(const Screen& S) {
    xLength = S.xLength;
    yLength = S.yLength;
}

Screen::~Screen() {

}

void Screen::drawScreen(){
    
}

