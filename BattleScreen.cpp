/* 
 * File:   BattleScreen.cpp
 * Author: haniferidaputra
 * 
 * Created on March 15, 2013, 12:01 AM
 */

#include "BattleScreen.h"

BattleScreen::BattleScreen() {
    xPlayer = xLength/4;
    yPlayer = yLength/4;
    xMonster = xPlayer+(xLength/2);
    yMonster = yPlayer+(yLength/2);

    S = Screen();

    matriks[xPlayer][yPlayer]='P';
    matriks[xMonster][yMonster]='M';
}

BattleScreen::BattleScreen(int xp, int yp, int xm, int ym){
    xPlayer = xp;
    yPlayer = yp;
    xMonster = xm;
    yMonster = ym;

    S = Screen();

    matriks[xp][yp]='P';
    matriks[xm][xp]='M';
}

BattleScreen::BattleScreen(const BattleScreen& BS) {
    xPlayer = BS.xPlayer;
    yPlayer = BS.yPlayer;
    xMonster = BS.xMonster;
    yMonster = BS.yMonster;

    S = BS.S;

    matriks[BS.xPlayer][BS.yPlayer]='P';
    matriks[BS.xMonster][BS.yMonster]='M';
}

BattleScreen::~BattleScreen() {

}

BattleScreen& BattleScreen::operator=(const BattleScreen& BS) {
    xPlayer = BS.xPlayer;
    yPlayer = BS.yPlayer;
    xMonster = BS.xMonster;
    yMonster = BS.yMonster;

    S = BS.S;

    matriks[BS.xPlayer][BS.yPlayer]='P';
    matriks[BS.xMonster][BS.yMonster]='M';

    return *this;
}

void BattleScreen::drawScreen(int s){
    switch(s){
        case 1:
                drawMatriks();
        break;
    }
}