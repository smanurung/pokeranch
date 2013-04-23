//
//  StatusIncrease.cpp
//  
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#include "StatusIncrease.h"

StatusIncrease::StatusIncrease(int x, string s, int mp, int hp) : Item(100,"statusincrease") {
    mpMaxAddition = mp;
    hpMaxAddition = hp;
}

StatusIncrease::StatusIncrease(int mpp,int hpp) : Item(100,"statusincrease"){
	this->mpMaxAddition = mpp;
	this->hpMaxAddition = hpp;
}

StatusIncrease::StatusIncrease(const StatusIncrease& s) {
    mpMaxAddition = s.mpMaxAddition;
    hpMaxAddition = s.hpMaxAddition;
	
	harga = s.harga;
	itemName = s.itemName;
}

StatusIncrease::~StatusIncrease() {
    
}

StatusIncrease& StatusIncrease::operator=(const StatusIncrease& s) {
    mpMaxAddition = s.mpMaxAddition;
    hpMaxAddition = s.hpMaxAddition;
	
	harga = s.harga;
	itemName = s.itemName;
    
    return *this;
}

void StatusIncrease::execute(Monster& m) {
    m.setHP(m.getHP() + mpMaxAddition);
    m.setMP(m.getMP() + hpMaxAddition);
}
