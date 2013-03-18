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
    void drawScreen(int);

    int getXLength();
    int getYLength();
	
protected:
    int xLength;
    int yLength;
    char ** matriks;
};

#endif	/* SCREEN_H */