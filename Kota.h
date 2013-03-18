/*
 * File:   Kota.h
 * Author: haniferidaputra
 *
 * Created on March 15, 2013, 7:18 AM
 */

#ifndef KOTA_H
#define	KOTA_H

#include <map>
#include "Screen.h"
#include "Point.h"
#include <string>

class Kota:public Screen {
public:
    Kota();
    Kota(int,int);
    Kota(const Kota&);
    ~Kota();
    Kota& operator=(const Kota&);

    void setXPlayer(int);
    void setYPlayer(int);

    void setPosisiPlayer(int,int);

    void drawScreen(int); //override dari kelas Screen
    int isSteppable();

private:
    map<string,Point> elmtPosition;
    int xPlayer;
    int yPlayer;
};

#endif	/* KOTA_H */

