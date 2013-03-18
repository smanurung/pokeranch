/*
 * File:   Screen.cpp
 * Author: haniferidaputra
 *
 * Created on March 14, 2013, 11:12 PM
 */

#include "Screen.h"

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

void Screen::drawMatriks(){
                for(int i=0; i<yLength; i++){
                    for(int j=0; j<xLength; j++){
                        cout << matriks[i][j] ;
                    }
                    cout<< endl;
                }//end for
}

void Screen::drawScreen(int s){
    //menggambar screen

    switch (s){
        case 1:                     //store
                drawMatriks();

        break;

        case 2:                 //home
                drawMatriks();
        break;

    }//end switch
}

void Screen::setMatriks(int _x, int _y, char _c){
	this->matriks[_x][_y] = _c;
}