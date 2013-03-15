/*
	author Sonny Theo Tumbur
*/

#include <iostream>
#include "NPC.h"
/*#include "Monster.h"*/
#include <cstdlib>
#include <ctime>

#define ARRAY_SIZE(array) sizeof(array)/sizeof(string);	 //untuk menghitung panjang array of string
#define JUMLAH_MONSTER_MAX 5 //jumlah monster maksimal tiap NPC

using namespace std;

NPC::NPC(){ //default ctor
	this->nama = "defaultNPC";
	this->warnaNPC = "merah"; //warna default NPC
	
	this->jmlMonster = getRandom();
	this->monsterNPC = new Monster[this->jmlMonster]; //menciptakan array
	for (int i=0; i<this->jmlMonster; i++) {
		//isi assign dengan monster tertentu
	}
}

NPC::NPC(string _nama, string _warna) {
	this->nama = _nama;
	this->warnaNPC = _warna;
	
	this->jmlMonster = getRandom();
	this->monsterNPC = new Monster[this->jmlMonster]; //menciptakan array
	for (int i=0; i<this->jmlMonster; i++) {
		//isi assign dengan monster tertentu
	}
}

//cctor
NPC::NPC(const NPC& _npc){
	this->nama = _npc.nama;
	this->warnaNPC = _npc.warnaNPC;
	this->jmlMonster = _npc.jmlMonster;
/*	this->MonsterNPC[] = _npc.MonsterNPC[]; //tidak bitwise copy karena bukan pointer*/
	
	for (int i=0; i<this->jmlMonster; i++) { //melakukan copy NPC
		this->monsterNPC[i] = _npc.monsterNPC[i];
	}
}

//dtor
NPC::~NPC(){
	cout << "dtor NPC" << endl;
}

void NPC::talk() {
	cout << "Hello Player, I am NPC" << endl;
}

int NPC::getRandom() { //menghasilkan integer random antara 1-4
	srand(time(NULL));
	return (rand()%4 + 1);
}