/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

/**
 *
 * @author msmaromi
 */
public class MonsterEgg extends Item {
  private Monster isiEgg;
  
  public MonsterEgg(int harga, String nama, Monster egg) {
    super(harga, nama);
    isiEgg = egg;
  }
  
  public MonsterEgg(MonsterEgg me) {
    super(me);
    isiEgg = me.isiEgg;
  }
  
  public Monster getIsiEgg() {
    return isiEgg;
  }
  
  public void setIsiEgg(Monster egg) {
    isiEgg = egg;
  }
  
  public void execute(Player p) {
    //p.addMonster(isiEgg);
  }
}
