//
//  MonsterEgg.cpp
//  
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#include "MonsterEgg.h"

MonsterEgg::MonsterEgg(int x, string s, Monster& m) :Item(1000,"monsteregg") {
}

MonsterEgg::MonsterEgg(Monster& _megg) :Item(1000,"monsteregg") {
	this->isiEgg = _megg;
}

MonsterEgg::MonsterEgg(const MonsterEgg& me){
    isiEgg = me.isiEgg;
	this->harga = me.harga;
	this->itemName = me.itemName;
}

MonsterEgg::~MonsterEgg(){
    
}

MonsterEgg& MonsterEgg::operator=(const MonsterEgg& me) {
    isiEgg = me.isiEgg;
    this->itemName = me.itemName;
	this->harga = me.harga;
	
    return *this;
}

void MonsterEgg::execute(Player& p) {
    p.addMonster(isiEgg);
}