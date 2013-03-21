//File : SkillMonster.h

#ifndef SKILLMONSTER_H
#define SKILLMONSTER_H

class Monster;

#include <string>
#include "Monster.h"

using namespace std;

class SkillMonster{
    public :
    SkillMonster();
    SkillMonster(string,string,int,string,int,int);
    SkillMonster(const SkillMonster&);
    SkillMonster& operator=(const SkillMonster&);
    ~SkillMonster();

    string getNamaSkill();
    void setNamaSkill(string);
    string getElmSkill();
    void setElmSkill(string);
    int getDamage();
    void setDamage(int);
    string getEfek();
    void setEfek(string);
    int getHPCost();
    void setHPCost(int);
    int getMPCost();
    void setMPCost(int);

    void CastSkill(Monster*);
    void ShowSkillStatus();

    private :
    string NamaSkill;
    string ElmSkill;
    int Damage;
    string Efek;
    int HPCost;
    int MPCost;
};
#endif
