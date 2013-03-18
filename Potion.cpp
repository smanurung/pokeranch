//
//  Potion.cpp
//  
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#include "Potion.h"

Potion::Potion(int x, string s, int mp, int hp) {
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

void Potion::execute(Monster& m) {
    m.setCurrentHP(m.getCurrentHP() + hpTambah);
    m.setCurrentMP(m.getCurrentMP() + mpTambah);
}