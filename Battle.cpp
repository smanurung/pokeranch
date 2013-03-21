/*
	author Sonny Theo Tumbur
*/
/*
#include "Battle.h"
#include <string>
#include <cstring>

#define DEFAULT_LENGTH 30
#define DEFAULT_WIDTH 30

//ctor
Battle::Battle(string lokasi, Player _p, Monster _m, NPC _n){ //lokasi berisi "kota" atau "arealuar"
	this->pemain = _p;
	if (lokasi == "kota") {
		this->monsterLuar = _m;
		this->NPCBattle = _n;
		this->btlScreen = BattleScreen(DEFAULT_LENGTH, DEFAULT_WIDTH);
	} else if (lokasi == "arealuar") {
		this->monsterLuar = _m;
		this->NPCBattle = _n;
		this->btlScreen = BattleScreen(DEFAULT_LENGTH, DEFAULT_WIDTH);
	} else cout << "Mode Battle tidak berlaku di tempat yang Anda maksud" << endl;
}

//cctor
Battle::Battle(const Battle& _b){
	this->pemain = _b.pemain;
	this->monsterLuar = _b.monsterLuar;
	this->NPCBattle = _b.NPCBattle;
	this->btlScreen = _b.btlScreen;
}

//dtor
Battle::~Battle(){
	cout << "dtor kelas Battle" << endl;
}

//operator=
Battle& Battle::operator=(const Battle& _b){
	this->pemain = _b.pemain;
	this->monsterLuar = _b.monsterLuar;
	this->NPCBattle = _b.NPCBattle;
	this->btlScreen = _b.btlScreen;
}*/