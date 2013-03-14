#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <map>
#include <iostream>

using namespace std;

class Player{
private:

    string nama;
    int uang;
    map<string, int> listItem;            //sementara pake int
    map<string, int> listMonster;        //sementara pake int
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
    void bet(int, bool);                //parameter nambah bool
//    void battle(string, NPC);
//    void battle(string, Monster);
    void save(string);
    void sleep();
    void sell(string, int);
    void buy(string, int);
    void teleport(string);
    void move(string, int);
    void showMonsterList();
    void showItemList();
    void setMonster(string);
    void dismiss(string);
    void escape();
    void change(string);
    void addMoney(int);


/*-----------------method tambahan-------------- */
    void printListItem();
    void printListMonster();
    void addToListItem(string, int);           //sementara string & int
    void addToListMonster(string, int);           //sementara string & int




};//end class

#endif // PLAYER_H_INCLUDED
