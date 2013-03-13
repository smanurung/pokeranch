/*
	author Sonny Theo Tumbur
*/

#include <iostream>
#include "NPC.h"

using namespace std;

NPC::NPC(){ //default ctor
	
}

NPC::NPC(const NPC& _npc){
	this->nama = _npc.nama;
	this->warnaNPC = _npc.warnaNPC;
//	this->MonsterNPC[] = _npc.MonsterNPC[]; //tidak bitwise copy karena bukan pointer
}

NPC::~NPC(){
	cout << "dtor NPC" << endl;
}

void NPC::talk() {
	cout << "Hello Player" << endl;
}
