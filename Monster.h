//file : Monster.h

#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using std::string;

class Monster{
    public :
        Monster();
        Monster(string,int,int,string,string,int,int,int,int,int,int,int,int,int,string);
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
        int getBonusUang();
        void setBonusUang(int);
        int getBonusExp();
        void setBonusExp(int);
        int getCurrentHP();
        void setCurrentHP(int);
        int getMaxHP();
        void setMaxHP(int);
        int getCurrentMP();
        void setCurrentMP(int);
        int getMaxMP();
        void setMaxMP(int);
        int getUmur();
        void setUmur(int);
        string getWarnaMonster();
        void setWarnaMonster(string);

        Monster Combine(Monster);
        void addExperience(Monster);

        private :
        string Nama;
        int Level;
        int Exp;
        string Species;
        string Elm;
        int HP;
        int MP;
        int BonusUang;
        int BonusExp;
        int CurrentHP;
        int MaxHP;
        int CurrentMP;
        int MaxMP;
        int Umur;
        string WarnaMonster;
};
#endif
