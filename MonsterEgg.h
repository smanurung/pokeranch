//
//  MonsterEgg.h
//  
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#ifndef ____MonsterEgg__
#define ____MonsterEgg__

#include "Item.h"
#include "Monster.h"
#include "Player.h"

class MonsterEgg:public Item {
public:
    MonsterEgg(int = 0, string = "noname", Monster& = NULL);
    MonsterEgg(const MonsterEgg&);
    ~MonsterEgg();
    MonsterEgg& operator=(const MonsterEgg&);
    
    void execute(Player&);
    
private:
    Monster isiEgg;
};

#endif /* defined(____MonsterEgg__) */
