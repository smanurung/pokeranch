/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import view.BattleScreen;

/**
 *
 * @author Sonny Theo Thumbur
 */
public class Battle {
    private Player pemain;
    private Monster monsterLuar;
    private NPC NPCBattle;
    private BattleScreen btlScreen;
    
    public Battle(Player _p, Monster _m, NPC _npc, BattleScreen _b) {
        pemain = _p;
        monsterLuar = _m;
        NPCBattle = _npc;
        btlScreen = _b;
    }
    
    public Player getPlayer() {
        return pemain;
    }
    
    public Monster getMonsterLawan() {
        return monsterLuar;
    }
    
    public NPC getNPCLawan() {
        return NPCBattle;
    }
    
    public BattleScreen getScreen() {
        return btlScreen;
    }
}
