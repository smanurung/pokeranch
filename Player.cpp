#include "Player.h"

    Player::Player(){
        nama="pemain";
        uang = 1000;
        curX=0;
        curY=0;
        jumlahMenang=0;
        jumlahKalah=0;
        jumlahEscape=0;
        waktu=0; //detik
        warnaPlayer="putih";
    }

    Player::Player(string a){
        nama="a";
        uang = 1000;
        curX=0;
        curY=0;
        jumlahMenang=0;
        jumlahKalah=0;
        jumlahEscape=0;
        waktu=0;
        warnaPlayer="putih";
    }

    Player::~Player(){}

    void Player::bet(int jmlBet, bool isMenang){
        if (isMenang==true){
            uang=uang+jmlBet;
        }else{
            uang=uang-jmlBet;
        }
    }

//    void Player::battle(string, NPC)
//    void Player::battle(string, Monster);

    void Player::save(string){
        //disimpan dg btk apa?
    }

    void Player::sleep(){
        //nunggu monster
    }

    void Player::sell(string s, int i){

    }

    void Player::buy(string, int){

    }

    void Player::teleport(string){

    }

    void Player::move(string, int){

    }

    void Player::showMonsterList(){

    }

    void Player::showItemList(){

    }

    void Player::setMonster(string){

    }

    void Player::dismiss(string){

    }

    void Player::escape(){
////////////////////////////// belum selesai

        jumlahEscape++;
    }

    void Player::change(string){

    }

    void Player::addMoney(int i){
        uang=uang+i;
    }


/*--------------------method tambahan---------------------*/

void Player::printListItem(){
    typedef map<string,int>::const_iterator mapIter;
    for(mapIter iter = listItem.begin(); iter != listItem.end(); iter++){
        cout << iter->first << ",";
        cout << iter->second << endl;
    }//end for
}

void Player::printListMonster(){
    typedef map<string,int>::const_iterator mapIter;
    for(mapIter iter = listMonster.begin(); iter != listMonster.end(); iter++){
        cout << iter->first << ",";
        cout << iter->second << endl;
    }//end for
}

void Player::addToListItem(string namaItem, int item){
        listItem.insert(make_pair(namaItem, item));
}

void Player::addToListMonster(string namaMonster, int monster){
        listMonster.insert(make_pair(namaMonster, monster));
}
