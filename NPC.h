/*
	author Sonny Theo Tumbur
*/

#ifndef NPC_H
#define NPC_H

#include <string>
#include "Monster.h"

using namespace std;

class NPC{
	public :
		//ctor
		NPC();
		NPC(string, string); //nama dan warna NPC; monster NPC diacak
		
		//cctor
		NPC(const NPC&);
		
		//operator=
		NPC& operator=(const NPC&);
		
		//dtor
		~NPC();
		
		//function member
		void talk();
		int getRandom();
	
	private :
		string nama;
		Monster * monsterNPC;
		int jmlMonster;
		string warnaNPC;
};

#endif
