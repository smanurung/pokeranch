/* 
 * File:   BattleScreen.cpp
 * Author: haniferidaputra
 * 
 * Created on March 15, 2013, 12:01 AM
 */

#include "BattleScreen.h"

BattleScreen::BattleScreen() {
    matriks[12][5]='P';
    matriks[37][15]='M';
}

BattleScreen::BattleScreen(int xp, int yp, int xm, int ym){
    xPlayer = xp;
    yPlayer = yp;
    xMonster = xm;
    yMonster = ym;

    matriks[xPlayer][yPlayer]='P';
    matriks[xMonster][yMonster]='M';
}

BattleScreen::BattleScreen(const BattleScreen& BS) {
    xPlayer = BS.xPlayer;
    yPlayer = BS.yPlayer;
    xMonster = BS.xMonster;
    yMonster = BS.yMonster;

    matriks[xPlayer][yPlayer]='P';
    matriks[xMonster][yMonster]='M';
}

BattleScreen::~BattleScreen() {

}

BattleScreen& BattleScreen::operator=(const BattleScreen& BS) {
    xPlayer = BS.xPlayer;
    yPlayer = BS.yPlayer;
    xMonster = BS.xMonster;
    yMonster = BS.yMonster;

    matriks[xPlayer][yPlayer]='P';
    matriks[xMonster][yMonster]='M';

    return *this;
}

void BattleScreen::drawScreen(){
    drawMatriks();
}