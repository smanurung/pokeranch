//
//  Potion.h
//
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#ifndef ____Potion__
#define ____Potion__

#include "Item.h"
#include "Monster.h"

class Potion:public Item {
public:
    Potion(int = 0, string = "noname", int = 0, int = 0);
	Potion(int,int);
    Potion(const Potion&);
    ~Potion();
    Potion& operator=(const Potion&);

    void execute(Monster&);

	void setMP(int);
	int getHP();
	void setHP(int);
	int getMP();

private:
    int mpTambah;
    int hpTambah;
};

#endif /* defined(____Potion__) */
