/* 
 * File:   AreaLuar.cpp
 * Author: haniferidaputra
 * 
 * Created on March 14, 2013, 11:12 PM
 */

#include "AreaLuar.h"

AreaLuar::AreaLuar() {
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

AreaLuar::AreaLuar(int x, int y){
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

void AreaLuar::drawScreen(int s){
    switch (s){
        case 0:
            cout << "AREA LUAR" << endl;
            for(int i=0; i<yLength; i++){
                for(int j=0; j<xLength; j++){
                    cout << matriks[i][j] ;
                }
                cout<< endl;
            }//end for
        break;
    }
}

int AreaLuar::isSteppable(Point P){

}

void AreaLuar::implementRandom(){
    
}