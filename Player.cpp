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

    /*-------------------------------------------------------------------------------------------getter---------------------------------------------------------------------------------------- */
    string Player::getNama(){
        return nama;
    }

    int Player::getUang(){
        return uang;
    }

    int Player::getCurX(){
        return curX;
    }

    int Player::getCurY(){
        return curY;
    }

    int Player::getJumlahMenang(){
        return jumlahMenang;
    }

    int Player::getJumlahKalah(){
        return jumlahKalah;
    }

    int Player::getJumlahEscape(){
        return jumlahEscape;
    }

    int Player::getWaktu(){
        return jumlahEscape;
    }

    string Player::getWarnaPlayer(){
        return warnaPlayer;
    }


/*----------------------------------------------------------------------------------method utama------------------------------------------------------------------------------- */

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

    void Player::sell(Item item){
        for (int i=0; i< listItem.size(); i++){
            if(listItem.at(i)==item){
                    listItem.erase(listItem.begin()+i);
                    cout << item.getItemName() << " dijual"<< endl;
                    uang=uang + item.getHarga();
            }else if(i==(listItem.size()-1)){
                    cout << "item tidak tersedia" << endl;
            }
        }//end for
    }

    void Player::buy(Item i){
        if(uang >= i.getHarga()){
            addToListItem(i);
            uang= uang - i.getHarga();
            cout << i.getItemName() << " dibeli" << endl;
        }else{
            cout << "uang tidak cukup" << endl;
        }
    }

    void Player::teleport(){

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


/*-------------------------------------------------------------------------------------method baru---------------------------------------------------------------------------------- */
    void addMonster(Monster&);





/*--------------------------------------------------------------------------------------method tambahan---------------------------------------------------------------------------------------*/

void Player::printListItem(){
    cout << endl;
    for(int i=0; i<listItem.size();i++){
        Item &a = listItem.at(i);                                   //masih ngga pasti benar
        cout << a.getItemName()<<endl;
    }//end for
}

void Player::printListMonster(){
    cout << endl;
    typedef map<string,Monster>::const_iterator mapIter;
    for(mapIter iter = listMonster.begin(); iter != listMonster.end(); iter++){
        cout << iter->first << endl;
    }//end for
}

void Player::addToListItem(Item item){
        listItem.push_back(item);
}

void Player::addToListMonster(string namaMonster, Monster monster){
        listMonster.insert(make_pair(namaMonster, monster));
}
