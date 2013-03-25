//file : SkillMonster.cpp

#include "SkillMonster.h"
#include <iostream>

using namespace std;

SkillMonster::SkillMonster(){
    NamaSkill = "xxxx";
    ElmSkill = "xxxx";
    Damage = 0;
    Efek = "xxxx";
    HPCost = 0;
    MPCost = 0;
}

SkillMonster::SkillMonster(string ns, string es, int dmg, string ef, int hc, int mc){
    NamaSkill = ns;
    ElmSkill = es;
    Damage = dmg;
    Efek = ef;
    HPCost = hc;
    MPCost = mc;
}

SkillMonster::SkillMonster(const SkillMonster& SM){
    NamaSkill = SM.NamaSkill;
    ElmSkill = SM.ElmSkill;
    Damage = SM.Damage;
    Efek = SM.Efek;
    HPCost = SM.HPCost;
    MPCost = SM.MPCost;
}

SkillMonster& SkillMonster::operator=(const SkillMonster& SM){
    NamaSkill = SM.NamaSkill;
    ElmSkill = SM.ElmSkill;
    Damage = SM.Damage;
    Efek = SM.Efek;
    HPCost = SM.HPCost;
    MPCost = SM.MPCost;
    return *this;
}

SkillMonster::~SkillMonster(){

}

string SkillMonster::getNamaSkill(){
    return NamaSkill;
}

void SkillMonster::setNamaSkill(string ns){
    NamaSkill = ns;
}

string SkillMonster::getElmSkill(){
    return ElmSkill;
}

void SkillMonster::setElmSkill(string es){
    ElmSkill = es;
}

int SkillMonster::getDamage(){
    return Damage;
}

void SkillMonster::setDamage(int dmg){
    Damage = dmg;
}

string SkillMonster::getEfek(){
    return Efek;
}

void SkillMonster::setEfek(string ef){
    Efek = ef;
}

int SkillMonster::getHPCost(){
    return HPCost;
}

void SkillMonster::setHPCost(int hc){
    HPCost = hc;
}

int SkillMonster::getMPCost(){
    return MPCost;
}

void SkillMonster::setMPCost(int mc){
    MPCost = mc;
}

void SkillMonster::CastSkill(Monster M){
    int currhp = M.getCurrentHP();
    if (ElmSkill == M.getElm()){
       M.setCurrentHP(currhp - (Damage/2));
    } else if (ElmSkill == "Fire" && M.getElm() == "Water"){
        M.setCurrentHP(currhp - (Damage/2));
    } else if (ElmSkill == "Fire" && M.getElm() == "Earth"){
        M.setCurrentHP(currhp - (Damage*3/2));
    } else if (ElmSkill == "Water" && M.getElm() == "Wind"){
        M.setCurrentHP(currhp - (Damage/2));
    } else if (ElmSkill == "Water" && M.getElm() == "Fire"){
        M.setCurrentHP(currhp - (Damage*3/2));
    } else if (ElmSkill == "Wind" && M.getElm() == "Earth"){
        M.setCurrentHP(currhp - (Damage/2));
    } else if (ElmSkill == "Wind" && M.getElm() == "Water"){
        M.setCurrentHP(currhp - (Damage*3/2));
    } else if (ElmSkill == "Earth" && M.getElm() == "Fire"){
        M.setCurrentHP(currhp - (Damage/2));
    } else if (ElmSkill == "Earth" && M.getElm() == "Wind"){
        M.setCurrentHP(currhp - (Damage*3/2));
    } else {
        M.setCurrentHP(currhp - Damage);
    }
    M.setStatus(Efek);
}

void SkillMonster::ShowSkillStatus(){
    cout << "Nama Skill : " << NamaSkill << endl;
    cout << "Element Skill : " << ElmSkill << endl;
    cout << "Damage : " << Damage << endl;
    cout << "Efek : " << Efek << endl;
    cout << "HPCost : " << HPCost << endl;
    cout << "MPCost : " << MPCost << endl;
    cout << "-----------------------------" << endl;
}
