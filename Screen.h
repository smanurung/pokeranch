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

static int xHomeBound = 5;
static int yHomeBound = 5;
static int xLuarBound = 0;
static int yLuarBound = 5;
static int xStoreBound = 30;
static int yStoreBound = 5;
static int xStadiumBound = 30;
static int yStadiumBound = 30;
static int xBattlescreenBound = 5;
static int yBattlescreenBound = 30;
static int xCombinatoriumBound = 20;
static int yCombinatoriumBound = 20;

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