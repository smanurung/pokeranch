/*
	author Sonny Theo Tumbur
*/

#ifndef BATTLE_H
#define BATTLE_H

#include "NPC.h"
#include "Player.h"
#include "Monster.h"
#include "BattleScreen.h"

class Battle {
	private :
		Player pemain;
		Monster MonsterLuar;
		NPC NPCBattle;
		BattleScreen btlScreen;
};

#endif