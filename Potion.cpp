//
//  Potion.cpp
//  
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#include "Potion.h"

Potion::Potion(int x, string s, int mp, int hp) : Item(100,"potion") { //ini kok x sama s ngga ada gunanya?
    mpTambah = mp;
    hpTambah = hp;
}

Potion::Potion(int _mp, int _hp) : Item(100,"potion"){
	this->mpTambah = _mp;
	this->hpTambah = _hp;
}

Potion::Potion(const Potion& p) {
    mpTambah = p.mpTambah;
    hpTambah = p.hpTambah;
	
	harga = p.harga;
	itemName = p.itemName;
}

Potion::~Potion() {
    
}

Potion& Potion::operator=(const Potion& p) {
    mpTambah = p.mpTambah;
    hpTambah = p.hpTambah;
	
	harga = p.harga;
	itemName = p.itemName;
    
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