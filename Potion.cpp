//
//  Potion.cpp
//  
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#include "Potion.h"

Potion::Potion(int x, string s, int mp, int hp) { //ini kok x sama s ngga ada gunanya?
    mpTambah = mp;
    hpTambah = hp;
}

Potion::Potion(const Potion& p) {
    mpTambah = p.mpTambah;
    hpTambah = p.hpTambah;
}

Potion::~Potion() {
    
}

Potion& Potion::operator=(const Potion& p) {
    mpTambah = p.mpTambah;
    hpTambah = p.hpTambah;
    
    return *this;
}

void Potion::setMP(int _mp){
	this->mpTambah = _mp;
}

void Potion::setHP(int _hp){
	this->hpTambah = _hp;
}

void Potion::execute(Monster& m) {
    m.setCurrentHP(m.getCurrentHP() + hpTambah);
    m.setCurrentMP(m.getCurrentMP() + mpTambah);
}