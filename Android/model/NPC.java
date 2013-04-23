/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.util.ArrayList;

/**
 *
 * @author Sonny Theo Thumbur
 */
public class NPC {
    private String nama; //identitas unik
    private ArrayList<Monster> monsterNPC;
    private String warnaNPC;
    
    public String getName() {
        return nama;
    }
    
    public ArrayList<Monster> getMonsterList() {
        return monsterNPC;
    }
    
    public Monster getFirstMonster() {
        return monsterNPC.get(0);
    }
    
    public String getWarna() {
        return warnaNPC;
    }
    
    public void talk() {
        //diletakan pada screen
    }
}
