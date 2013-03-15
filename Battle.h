/*
	author Sonny Theo Tumbur
*/

#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include "NPC.h"
#include "Player.h"
#include "Monster.h"
#include "BattleScreen.h"

class Battle {
	public :
		Battle(string, Player, Monster, NPC);
		Battle(const Battle&);
		~Battle();
		
	private :
		Player pemain;
		Monster monsterLuar;
		NPC NPCBattle;
		BattleScreen btlScreen;
};

#endif