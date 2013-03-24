/*
 * File:   Screen.h
 * Author: haniferidaputra
 *
 * Created on March 14, 2013, 11:12 PM
 */

#ifndef SCREEN_H
#define	SCREEN_H
#include <string>
#include <iostream>
using namespace std;

static int xHomeBound = 10;
static int yHomeBound = 10;
static int xLuarBound = 0;
static int yLuarBound = 10;
static int xStoreBound = 70;
static int yStoreBound = 10;
static int xStadiumBound = 70;
static int yStadiumBound = 70;
static int xBattlescreenBound = 10;
static int yBattlescreenBound = 70;
static int xCombinatoriumBound = 50;
static int yCombinatoriumBound = 50;

class Screen {
public:
    Screen();
    Screen(int,int);
    Screen(const Screen&);
    ~Screen();

    void drawMatriks();
    virtual void drawScreen(int);
	
	//SETTER
	void setMatriks(int,int,char); // X, Y, char pengganti

    int getXLength();
    int getYLength();        
	
protected:
    int xLength;
    int yLength;
    char ** matriks;
	void drawMatriksHome();
	void drawMatriksStore();
	void drawMatriksCombinatorium();
	void drawMatriksStadium();
};

#endif	/* SCREEN_H */