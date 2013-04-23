//
//  MonsterEgg.cpp
//  
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#include "MonsterEgg.h"

MonsterEgg::MonsterEgg(int x, string s, Monster& m) : Item(1000,"monsterEgg") {
    /*if(m != NULL)
        isiEgg = m;
    else
        cout << "Telur kosong" << endl;*/
}

MonsterEgg::MonsterEgg(Monster& _megg) : Item(1000,"monsterEgg"){
	this->isiEgg = _megg;
}

MonsterEgg::MonsterEgg(const MonsterEgg& me) {
    isiEgg = me.isiEgg;
	
	harga = me.harga;
	itemName = me.itemName;
}

MonsterEgg::~MonsterEgg() {
    
}

MonsterEgg& MonsterEgg::operator=(const MonsterEgg& me) {
    isiEgg = me.isiEgg;
    
	harga = me.harga;
	itemName = me.itemName;
	
    return *this;
}

void MonsterEgg::execute(Player& p) {
    p.addMonster(isiEgg);
}