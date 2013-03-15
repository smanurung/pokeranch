//file : Monster.cpp

#include "Monster.h"
#include <iostream>
//#include <string>

using namespace std;
//using std::string;

Monster::Monster(){
    Nama = "xxxx";
    Level = 0;
    Exp = 0;
    Species = "xxxx";
    Elm = "xxxx";
    HP = 0;
    MP = 0;
    BonusUang = 0;
    BonusExp = 0;
    CurrentHP = 0;
    MaxHP = 0;
    CurrentMP = 0;
    MaxMP = 0;
    Umur = 0;
    WarnaMonster = "xxxx";
}

Monster::Monster(string nm, int lvl, int ex, string sp, string el, int _hp, int _mp, int bu, int be, int ch, int mh, int cm, int mm, int um, string wm){
    Nama = nm;
    Level = lvl;
    Exp = ex;
    Species = sp;
    Elm = el;
    HP = _hp;
    MP = _mp;
    BonusUang = bu;
    BonusExp = be;
    CurrentHP = ch;
    MaxHP = mh;
    CurrentMP = cm;
    MaxMP = mm;
    Umur = um;
    WarnaMonster = wm;
}

Monster::Monster(const Monster& M){
    Nama = M.Nama;
    Level = M.Level;
    Exp = M.Exp;
    Species = M.Species;
    Elm = M.Elm;
    HP = M.HP;
    MP = M.MP;
    BonusUang = M.BonusUang;
    BonusExp = M.BonusExp;
    CurrentHP = M.CurrentHP;
    MaxHP = M.MaxHP;
    CurrentMP = M.CurrentMP;
    MaxMP = M.MaxMP;
    Umur = M.Umur;
    WarnaMonster = M.WarnaMonster;
}

Monster& Monster::operator=(const Monster& M){
    Nama = M.Nama;
    Level = M.Level;
    Exp = M.Exp;
    Species = M.Species;
    Elm = M.Elm;
    HP = M.HP;
    MP = M.MP;
    BonusUang = M.BonusUang;
    BonusExp = M.BonusExp;
    CurrentHP = M.CurrentHP;
    MaxHP = M.MaxHP;
    CurrentMP = M.CurrentMP;
    MaxMP = M.MaxMP;
    Umur = M.Umur;
    WarnaMonster = M.WarnaMonster;
    return *this;
}

Monster::~Monster(){

}

string Monster::getNama(){
    return Nama;
}

void Monster::setNama(string nm){
    Nama = nm;
}

int Monster::getLevel(){
    return Level;
}

void Monster::setLevel(int lvl){
    Level = lvl;
}

int Monster::getExp(){
    return Exp;
}

void Monster::setExp(int ex){
    Exp = ex;
}

string Monster::getSpecies(){
    return Species;
}

void Monster::setSpecies(string sp){
    Species = sp;
}

string Monster::getElm(){
    return Elm;
}

void Monster::setElm(string el){
    Elm = el;
}

int Monster::getHP(){
    return HP;
}

void Monster::setHP(int _hp){
    HP = _hp;
}

int Monster::getMP(){
    return MP;
}

void Monster::setMP(int _mp){
    MP = _mp;
}

int Monster::getBonusUang(){
    return BonusUang;
}

void Monster::setBonusUang(int bu){
    BonusUang = bu;
}

int Monster::getBonusExp(){
    return BonusExp;
}

void Monster::setBonusExp(int be){
    BonusExp = be;
}

int Monster::getCurrentHP(){
    return CurrentHP;
}

void Monster::setCurrentHP(int ch){
    CurrentHP = ch;
}

int Monster::getMaxHP(){
    return MaxHP;
}

void Monster::setMaxHP(int mh){
    MaxHP = mh;
}

int Monster::getCurrentMP(){
    return CurrentMP;
}

void Monster::setCurrentMP(int cm){
    CurrentMP = cm;
}

int Monster::getMaxMP(){
    return MaxMP;
}

void Monster::setMaxMP(int mm){
    MaxMP = mm;
}

int Monster::getUmur(){
    return Umur;
}

void Monster::setUmur(int um){
    Umur = um;
}

string Monster::getWarnaMonster(){
    return WarnaMonster;
}

void Monster::setWarnaMonster(string wm){
    WarnaMonster = wm;
}

Monster Monster::Combine(Monster M){
    Monster M3;
    M3 = M;
    return M3;
}

void Monster::addExperience(Monster M){
    Exp += M.getBonusExp();
}
