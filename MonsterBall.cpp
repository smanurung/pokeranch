//
//  MonsterBall.cpp
//  
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#include "MonsterBall.h"

MonsterBall::MonsterBall(int x, string s) {
    
}

MonsterBall::MonsterBall(const MonsterBall& mb) {
    
}

MonsterBall::~MonsterBall() {
    
}

MonsterBall& MonsterBall::operator=(const MonsterBall& mb) {
    
}

void MonsterBall::execute(Player& p, Monster& m) {
    if(m.isSekarat())
        p.addMonster(m);
    else
        cout << "Tidak bisa ditangkap" << endl;
}