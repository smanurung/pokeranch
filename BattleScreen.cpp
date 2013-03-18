/* 
 * File:   BattleScreen.cpp
 * Author: haniferidaputra
 * 
 * Created on March 15, 2013, 12:01 AM
 */

#include "BattleScreen.h"

BattleScreen::BattleScreen() {
    xLength = 50;
    yLength = 20;
}

BattleScreen::BattleScreen(int x, int y){
    xLength = x;
    yLength = y;
}

BattleScreen::BattleScreen(const BattleScreen& BS) {
    xLength = BS.xLength;
    yLength = BS.yLength;
}

BattleScreen::~BattleScreen() {

}

BattleScreen& BattleScreen::operator =(const BattleScreen& BS) {
    xLength = BS.xLength;
    yLength = BS.yLength;
    return *this;
}

void BattleScreen::drawScreen(){
    
}