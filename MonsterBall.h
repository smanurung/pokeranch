//
//  MonsterBall.h
//  
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#ifndef ____MonsterBall__
#define ____MonsterBall__

#include "Item.h"
#include "Monster.h"
#include "Player.h"

class MonsterBall:public Item {
public:
    MonsterBall(int = 0, string = "noname");
    MonsterBall(const MonsterBall&);
    ~MonsterBall();
    MonsterBall& operator=(const MonsterBall&);
    
    void execute(Player&, Monster&);
};

#endif /* defined(____MonsterBall__) */
