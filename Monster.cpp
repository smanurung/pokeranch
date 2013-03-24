//file : Monster.cpp

#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(string nm){
    Nama = nm;
    Level = 0;
    Exp = 0;
    Species = "xxxx";
    Elm = "xxxx";
    HP = 0;
    MP = 0;
    Speed = 0;
    BonusUang = 0;
    BonusExp = 0;
    CurrentHP = 0;
    CurrentMP = 0;
    Status = "xxxx";
    Umur = 0;
    WarnaMonster = "xxxx";
}

Monster::Monster(string nm, int lvl, int ex, string sp, string el, int _hp, int _mp, int spd, int bu, int be, string st, int um, string wm){
    Nama = nm;
    Level = lvl;
    Exp = ex;
    Species = sp;
    Elm = el;
    HP = HP;
    MP = MP;
    Speed = spd;
    BonusUang = bu;
    BonusExp = be;
    CurrentHP = _hp;
    CurrentMP = _mp;
    Status = st;
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
    Speed = M.Speed;
    BonusUang = M.BonusUang;
    BonusExp = M.BonusExp;
    CurrentHP = M.CurrentHP;
    CurrentMP = M.CurrentMP;
    Status = M.Status;
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
    Speed = M.Speed;
    BonusUang = M.BonusUang;
    BonusExp = M.BonusExp;
    CurrentHP = M.CurrentHP;
    CurrentMP = M.CurrentMP;
    Status = M.Status;
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

int Monster::getSpeed(){
    return Speed;
}

void Monster::setSpeed(int spd){
    Speed = spd;
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

int Monster::getCurrentMP(){
    return CurrentMP;
}

void Monster::setCurrentMP(int cm){
    CurrentMP = cm;
}

string Monster::getStatus(){
    return Status;
}

void Monster::setStatus(string st){
    Status = st;
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

//fungsi combine monster
//menghasilkan monster baru
Monster Monster::Combine(Monster M){
    Monster M3(M.getNama());
    M3 = M;
    return M3;
}

//fungsi menambah exp monster player
void Monster::addExperience(Monster M){
    Exp += M.getBonusExp();
}

//fungsi naik level
//ketika naik level, hp dan mp penuh kembali
void Monster::addLevel(){
    if (Exp > 200) {Level++;Exp=0;
        if (Elm == "Api"){
            HP += Level*4;
            MP += Level*2;
            Speed += 2;
            BonusUang += 20;
            BonusExp += 5;
            CurrentHP = HP;
            CurrentMP = MP;
        }
        else if (Elm == "Air"){
            HP += Level*2;
            MP += Level*6;
            Speed += 3;
            BonusUang += 20;
            BonusExp += 5;
            CurrentHP = HP;
            CurrentMP = MP;
        }
        else if (Elm == "Angin"){
            HP += Level*3;
            MP += Level*4;
            Speed += 4;
            BonusUang += 20;
            BonusExp += 5;
            CurrentHP = HP;
            CurrentMP = MP;
        }
        else if (Elm == "Tanah"){
            HP += Level*6;
            MP += Level*3;
            Speed += 1;
            BonusUang += 20;
            BonusExp += 5;
            CurrentHP = HP;
            CurrentMP = MP;
        }
        }
    }

//fungsi mengecek monster sekarat
//sekarat apabila hp kurang dari 10%
int Monster::isSekarat(){
    int boo = 0;
    if (this->getCurrentHP() < (this->getHP()/10)) {
        boo = 1;
        return boo;
    }
    else return boo;
}

void Monster::StatusEfek(){
    int damageefek;
    if (Status == "Burning"){
        damageefek = HP/10;
        CurrentHP -= damageefek;
    } else if (Status == "Frozen"){
        damageefek = HP/20;
        CurrentHP -= damageefek;
    }
}

//fungsi mengubah spesies
void Monster::changeSpecies(){
    if ((Level >= 6) && (Elm == "Api") && (Species == "Yi")) {
            this->setSpecies("Er");
        } else if ((Level >= 11) && (Elm == "Api") && (Species == "Er")){
            this->setSpecies("San");
        } else if ((Level >= 16) && (Elm == "Api") && (Species == "San")){
            this->setSpecies("Shi");
        } else if ((Level >= 21) && (Elm == "Api") && (Species == "Shi")){
            this->setSpecies("Wu");
        } else if ((Level >= 26) && (Elm == "Api") &&(Species == "Wu")){
            this->setSpecies("Liu");
        }
     else if ((Level >= 6) && (Elm == "Air") && (Species == "One")){
            this->setSpecies("Two");
        } else if ((Level >= 11) && (Elm == "Air") && (Species == "Two")){
            this->setSpecies("Three");
        } else if ((Level >= 16) && (Elm == "Air") && (Species == "Three")){
            this->setSpecies("Four");
        } else if ((Level >= 21) && (Elm == "Air") && (Species == "Four")){
            this->setSpecies("Five");
        } else if ((Level >= 26) && (Elm == "Air") && (Species == "Five")){
            this->setSpecies("Six");
        }
     else if ((Level >= 6) && (Elm == "Angin") && (Species == "Uno")){
            this->setSpecies("Dos");
        } else if ((Level >= 11) && (Elm == "Angin") && (Species == "Dos")){
            this->setSpecies("Tres");
        } else if ((Level >= 16) && (Elm == "Angin") && (Species == "Tres")){
            this->setSpecies("Cuatro");
        } else if ((Level >= 21) && (Elm == "Angin") && (Species == "Cuatro")){
            this->setSpecies("Cinco");
        } else if ((Level >= 26) && (Elm == "Angin") && (Species == "Cinco")){
            this->setSpecies("Seis");
        }
     else if ((Level >= 6) && (Elm == "Tanah") && (Species == "Un")){
            this->setSpecies("Deux");
        } else if ((Level >= 11) && (Elm == "Tanah") && (Species == "Deux")){
            this->setSpecies("Trois");
        } else if ((Level >= 16) && (Elm == "Tanah") && (Species == "Trois")){
            this->setSpecies("Quatre");
        } else if ((Level >= 21) && (Elm == "Tanah") && (Species == "Quatre")){
            this->setSpecies("Cinq");
        } else if ((Level >= 26) && (Elm == "Tanah") && (Species == "Cinq")){
            this->setSpecies("Six");
        }
}

void Monster::ShowStatus(){
    cout << "Nama : " << Nama << endl;
    cout << "Level : " << Level << endl;
    cout << "Experience : " << Exp << endl;
    cout << "Spesies : " << Species << endl;
    cout << "Element : " << Elm << endl;
    cout << "HP : " << HP << endl;
    cout << "MP : " << MP << endl;
    cout << "Speed : " << Speed << endl;
    cout << "Bonus Uang : " << BonusUang << endl;
    cout << "Bonus Exp : " << BonusExp << endl;
    cout << "Current HP : " << CurrentHP << endl;
    cout << "Current MP : " << CurrentMP << endl;
    cout << "Umur : " << Umur << endl;
}


