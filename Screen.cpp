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

void Screen::drawScreen(int s){
    //menggambar screen dengan masukan integer tempat

    switch (s){
        case 1:                     //store
                drawMatriks();

        break;

        case 2:                 //home
                drawMatriks();
        break;

    }//end switch
}

