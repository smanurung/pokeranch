#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "Potion.h"
#include "Monster.h"
#include "Item.h"

using namespace std;

class Player{
private:

    string nama;
    int uang;
    vector<Item> listItem;
    map<string,Monster > listMonster;
    int curX;
    int curY;
    int jumlahMenang;
    int jumlahKalah;
    int jumlahEscape;
    int waktu;
    string warnaPlayer;

public:

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

    /*-----------------method utama-------------- */
    void bet(int, bool);                //parameter nambah bool
//    void battle(string, NPC);
//    void battle(string, Monster);
    void save(string);
    void sleep();
    void sell(Item);
    void buy(Item);
    void teleport();                        //parameter string dihapus
    void move(string, int);
    void showMonsterList();
    void showItemList();
    void setMonster(string);
    void dismiss(string);
    void escape();
    void change(string);
    void addMoney(int);

    /*-----------------method baru-------------- */
    void addMonster(Monster&);




    /*-----------------method tambahan-------------- */
    void printListItem();
    void printListMonster();
    void addToListItem(Item);
    void addToListMonster(string, Monster);


};//end class

#endif // PLAYER_H_INCLUDED
