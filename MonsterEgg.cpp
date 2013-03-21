//
//  MonsterEgg.cpp
//  
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#include "MonsterEgg.h"

MonsterEgg::MonsterEgg(int x, string s, Monster& m) {
    if(m != NULL)
        isiEgg = m;
    else
        cout << "Telur kosong" << endl;
}

MonsterEgg::MonsterEgg(const MonsterEgg& me) {
    isiEgg = me.isiEgg;
}

MonsterEgg::~MonsterEgg() {
    
}

MonsterEgg& MonsterEgg::operator=(const MonsterEgg& me) {
    isiEgg = me.isiEgg;
    
    return *this;
}

void MonsterEgg::execute(Player& p) {
    p.addMonster(isiEgg);
}