//file : Monster.h

#ifndef MONSTER_H
#define MONSTER_H

class SkillMonster;

#include <string>
#include <vector>
#include "SkillMonster.h"

using namespace std;

class Monster{
    public :
        Monster();
        Monster(string,int,int,string,string,int,int,int,int,int,int,int,string,int,string);
        Monster(const Monster&);
        Monster& operator=(const Monster&);
        ~Monster();

        string getNama();
        void setNama(string);
        int getLevel();
        void setLevel(int);
        int getExp();
        void setExp(int);
        string getSpecies();
        void setSpecies(string);
        string getElm();
        void setElm(string);
        int getHP();
        void setHP(int);
        int getMP();
        void setMP(int);
        int getSpeed();
        void setSpeed(int);
        int getBonusUang();
        void setBonusUang(int);
        int getBonusExp();
        void setBonusExp(int);
        int getCurrentHP();
        void setCurrentHP(int);
        int getCurrentMP();
        void setCurrentMP(int);
        string getStatus();
        void setStatus(string);
        int getUmur();
        void setUmur(int);
        string getWarnaMonster();
        void setWarnaMonster(string);

        Monster Combine(Monster);
        void addExperience(Monster);
        void addLevel();
        int isSekarat();
        void StatusEfek();
        void changeSpecies();
        void ShowStatus();

     private :
        string Nama;
        int Level;
        int Exp;
        string Species;
        string Elm;
        int HP;
        int MP;
        int Speed;
        int BonusUang;
        int BonusExp;
        int CurrentHP;
        int CurrentMP;
        string Status;
        int Umur;
        string WarnaMonster;
        vector<SkillMonster*> Skill;
};
#endif
