/* 
 * File:   Screen.h
 * Author: haniferidaputra
 *
 * Created on March 14, 2013, 11:12 PM
 */

#ifndef SCREEN_H
#define	SCREEN_H

class Screen {
public:
    Screen();
    Screen(int,int);
    Screen(const Screen&);
    ~Screen();

    virtual void drawScreen();

private:
    int xLength;
    int yLength;
    int matriks[][];
};

#endif	/* SCREEN_H */

