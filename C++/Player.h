#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "Potion.h"
#include "Monster.h"
#include "Item.h"
#include "Kota.h"
#include "Screen.h"
#include "AreaLuar.h"
#include "BattleScreen.h"
#include "Combinatorium.h"
#include "Home.h"
#include "Kota.h"
#include "Stadium.h"
#include "Store.h"

using namespace std;

class Player{
private:

    string nama;
    int uang;
    vector<Item> listItem;

    int curX;
    int curY;
    int jumlahMenang;
    int jumlahKalah;
    int jumlahEscape;
    int waktu;
    string warnaPlayer;

public:

    Monster defaultMonster;
    map<string,Monster> listMonster;

    Player();
    Player(string nama);
    ~Player();

    /*-----------------getter-------------- */
    string getNama();
    int getUang();
    int getCurX();
    int getCurY();
    int getJumlahMenang();
    int getJumlahKalah();
    int getJumlahEscape();
    int getWaktu();
    string getWarnaPlayer();
	Monster getMonster(string);

	/*-----------------setter-------------- */
	void setNama(string);
	void setUang(int);
	void addItem(Item&);
	void addMonster(Monster&);
	void setJumlahMenang(int);
	void setJumlahKalah(int);
	void setJumlahEscape(int);
	void setWaktu(int);
	void setWarna(string);
	void setCurX(int);
    void setCurY(int);

    /*-----------------method utama-------------- */
    void bet(int, bool);                //parameter nambah bool
//    void battle(string, NPC);
//    void battle(string, Monster);
    void save(string);
    void sleep();
    void sell(string,int);
    void buy(Item);
    void teleport(int&,int,int&,int&, Screen&);
    void teleport(int&,int,int&,int&, Stadium&);
    void teleport(int&,int,int&,int&, Combinatorium&);
    void teleport(int&,int,int&,int&, Home&);
    void teleport(int&,int,int&,int&, Store&);
    void teleport(int&,int,int&,int&, BattleScreen&);
    void teleport(int &currentState, int toState, int &xPosition, int &yPosition, Kota &s);
    void move(string, int, Screen);
    void showMonsterList();
    void showItemList();
    void setMonster(string);
    void dismiss(string);
    void escape();
    void change(string);
    void addMoney(int);

    /*-----------------method baru-------------- */
    void addMonster(string,Monster&);
    void delMoney(int);
    void delItem(Item);


    /*-----------------method tambahan-------------- */
    void printListItem();
    void printListMonster();
    void addToListItem(Item);
    void addToListMonster(string, Monster);
	int isContainMonster(string);

};//end class

#endif // PLAYER_H_INCLUDED
