/* 
 * File:   AreaLuar.h
 * Author: haniferidaputra
 *
 * Created on March 14, 2013, 11:12 PM
 */

#ifndef AREALUAR_H
#define	AREALUAR_H

#include "Screen.h"
#include "point.h"

class AreaLuar:public Screen {
public:
    AreaLuar();
    AreaLuar(int,int);
    AreaLuar(const AreaLuar&);
    ~AreaLuar();
    AreaLuar& operator=(const AreaLuar&);

    void setXPlayer(int);
    void setYPlayer(int);

    void setPosisiPlayer(int,int);

    void drawScreen(int); //override dari kelas Screen
    int isSteppable();

private:
    int xPlayer;
    int yPlayer;
    int xM1; //Monster 1
    int yM1;
    int xM2; //Monster 2
    int yM2;
    int xM3; //Monster 3
    int yM3;
    int xM4; //Monster 4
    int yM4;
    int xM5; //Monster 5
    int yM5;
    int xM6; //Monster 6
    int yM6;
    int xM7; //Monster 7
    int yM7;
    int xM8; //Monster 8
    int yM8;
    int xM9; //Monster 8
    int yM9;
    int xM10; //Monster 10
    int yM10;
};

#endif	/* AREALUAR_H */

