//
//  StatusIncrease.h
//  
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#ifndef ____StatusIncrease__
#define ____StatusIncrease__

#include "Item.h"
#include "Monster.h"

class StatusIncrease:public Item {
public:
    StatusIncrease(int = 0, string = "noname", int = 0, int = 0);
	StatusIncrease(int,int);
    StatusIncrease(const StatusIncrease&);
    ~StatusIncrease();
    StatusIncrease& operator=(const StatusIncrease&);
    
    void execute(Monster&);
    
private:
    int mpMaxAddition;
    int hpMaxAddition;
};

#endif /* defined(____StatusIncrease__) */
