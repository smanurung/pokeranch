/* 
 * File:   AreaLuar.h
 * Author: haniferidaputra
 *
 * Created on March 14, 2013, 11:12 PM
 */

#ifndef AREALUAR_H
#define	AREALUAR_H

#include "Screen.h"
#include "Point.h"

class AreaLuar {
public:
    AreaLuar();
    AreaLuar(int,int);
    AreaLuar(const AreaLuar& orig);
    ~AreaLuar();

    void drawScreen();
    int isSteppable(Point);
    void implementRandom();

private:
    Point monsterPositionList[];
    Point unsteppableList[];
};

#endif	/* AREALUAR_H */

