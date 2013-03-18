/* 
 * File:   BattleScreen.h
 * Author: haniferidaputra
 *
 * Created on March 15, 2013, 12:01 AM
 */

#ifndef BATTLESCREEN_H
#define	BATTLESCREEN_H

#include "Screen.h"
#include "Point.h"

class BattleScreen:public Screen {
public:
    BattleScreen();
    BattleScreen(int,int);
    BattleScreen(const BattleScreen&);
    ~BattleScreen();
    BattleScreen& operator=(const BattleScreen&);

    void drawScreen();

private:
    Point position;
};

#endif	/* BATTLESCREEN_H */

