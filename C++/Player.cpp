#include "Player.h"
#include <iostream>
#include <map>

using namespace std;

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

/*-------------------------------------------------------------------------------------------setter---------------------------------------------------------------------------------------- */
void Player::setNama(string _n){
    this->nama = _n;
}

void Player::setUang(int _u){
    this->uang = _u;
}

void Player::addItem(Item& _i){
    this->listItem.push_back(_i);
}

void Player::addMonster(string _nama, Monster& _mon){
    this->listMonster.insert(pair<string,Monster>(_nama,_mon));
}

void Player::setJumlahMenang(int _win){
    this->jumlahMenang = _win;
}

void Player::setJumlahKalah(int _lose){
    this->jumlahKalah = _lose;
}

void Player::setJumlahEscape(int _esc) {
    this->jumlahEscape = _esc;
}

void Player::setWaktu(int _time){
    this->waktu = _time;
}

void Player::setWarna(string _w){
    this->warnaPlayer = _w;
}

	void Player::setCurX(int i){
        curX=i;
    }

    void Player::setCurY(int i){
        curY=i;
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


    void Player::sell(string item, int n){

        for (int ii=0; ii<n;ii++){
            for (int i=0; i< listItem.size(); i++){
                if(listItem[i].getItemName()==item){
                        listItem.erase(listItem.begin()+i);
                        cout << listItem[i].getItemName() << " dijual"<< endl;
                        uang=uang + listItem[i].getHarga();
                }else if(i==(listItem.size()-1)){
                        cout << "item tidak tersedia" << endl;
                }
            }//end for 2
        }//end for 1
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


void Player::teleport(int &currentState, int toState, int &xPosition, int &yPosition, Kota &s) {
    bool allowTeleport = false;
    if (currentState==1) { //kota
        if (toState==0) {
            if (xPosition==xHomeBound && yPosition==yHomeBound) {
                allowTeleport = true;
            }
        } else if (toState==2) {
            if (xPosition==xLuarBound && yPosition==yLuarBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==3) {
            if (xPosition==xStoreBound && yPosition==yStoreBound) {
                allowTeleport = true;
            }
        } else if (toState==4) {
            if (xPosition==xStadiumBound && yPosition==yStadiumBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==5) {
            if (xPosition==xBattlescreenBound && yPosition==yBattlescreenBound) {
                allowTeleport = true;
            }
        } else if (toState==6) {
            if (xPosition==xCombinatoriumBound && yPosition==yCombinatoriumBound) {
                allowTeleport = true;
            }
        }
    } else {
        if (toState==1) {
            if (currentState==0) {
                allowTeleport = true;
                xPosition = xHomeBound;
                yPosition = yHomeBound;
            } else if (currentState==2) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xLuarBound;
                    yPosition = yLuarBound;
                }
            } else if (currentState==3) {
                allowTeleport = true;
                xPosition = xStoreBound;
                yPosition = yStoreBound;
            } else if (currentState==4) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xStadiumBound;
                    yPosition = yStadiumBound;
                }
            } else if (currentState==5) {
                allowTeleport = true;
                xPosition = xBattlescreenBound;
                yPosition = yBattlescreenBound;
            } else if (currentState==6) {
                allowTeleport = true;
                xPosition = xCombinatoriumBound;
                yPosition = yCombinatoriumBound;
            }
        }
    }
    if (allowTeleport) {

        currentState = toState;
        setCurX(xPosition);
        setCurY(yPosition);
        cout << curY << "," << curX << endl;

        s.setPosisiPlayer(xPosition,yPosition);
        s.drawScreen(currentState);
    } else {
        cout << "Tidak bisa teleport" << endl;
    }
}



void Player::teleport(int &currentState, int toState, int &xPosition, int &yPosition, Screen &s) {
    bool allowTeleport = false;
    if (currentState==1) { //kota
        if (toState==0) {
            if (xPosition==xHomeBound && yPosition==yHomeBound) {
                allowTeleport = true;
            }
        } else if (toState==2) {
            if (xPosition==xLuarBound && yPosition==yLuarBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==3) {
            if (xPosition==xStoreBound && yPosition==yStoreBound) {
                allowTeleport = true;
            }
        } else if (toState==4) {
            if (xPosition==xStadiumBound && yPosition==yStadiumBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==5) {
            if (xPosition==xBattlescreenBound && yPosition==yBattlescreenBound) {
                allowTeleport = true;
            }
        } else if (toState==6) {
            if (xPosition==xCombinatoriumBound && yPosition==yCombinatoriumBound) {
                allowTeleport = true;
            }
        }
    } else {
        if (toState==1) {
            if (currentState==0) {
                allowTeleport = true;
                xPosition = xHomeBound;
                yPosition = yHomeBound;
            } else if (currentState==2) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xLuarBound;
                    yPosition = yLuarBound;
                }
            } else if (currentState==3) {
                allowTeleport = true;
                xPosition = xStoreBound;
                yPosition = yStoreBound;
            } else if (currentState==4) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xStadiumBound;
                    yPosition = yStadiumBound;
                }
            } else if (currentState==5) {
                allowTeleport = true;
                xPosition = xBattlescreenBound;
                yPosition = yBattlescreenBound;
            } else if (currentState==6) {
                allowTeleport = true;
                xPosition = xCombinatoriumBound;
                yPosition = yCombinatoriumBound;
            }
        }
    }
    if (allowTeleport) {

        currentState = toState;
        setCurX(xPosition);
        setCurY(yPosition);
        cout << curY << "," << curX << endl;
        s.drawScreen(currentState);
    } else {
        cout << "Tidak bisa teleport" << endl;
    }
}

void Player::teleport(int &currentState, int toState, int &xPosition, int &yPosition, Stadium &s) {
//    xPosition = curY;
//    yPosition = curX;
    cout << curX << ";" << curY << endl;
    cout << xPosition << ";" << yPosition << endl;
    bool allowTeleport = false;
    if (currentState==1) { //kota
        if (toState==0) {
            if (xPosition==xHomeBound && yPosition==yHomeBound) {
                allowTeleport = true;
            }
        } else if (toState==2) {
            if (xPosition==xLuarBound && yPosition==yLuarBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==3) {
            if (xPosition==xStoreBound && yPosition==yStoreBound) {
                allowTeleport = true;
            }
        } else if (toState==4) {
            cout << "masuk if stadium" << endl;
            if (xPosition==xStadiumBound && yPosition==yStadiumBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==5) {
            if (xPosition==xBattlescreenBound && yPosition==yBattlescreenBound) {
                allowTeleport = true;
            }
        } else if (toState==6) {
            if (xPosition==xCombinatoriumBound && yPosition==yCombinatoriumBound) {
                allowTeleport = true;
            }
        }
    } else {
        if (toState==1) {
            if (currentState==0) {
                allowTeleport = true;
                xPosition = xHomeBound;
                yPosition = yHomeBound;
            } else if (currentState==2) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xLuarBound;
                    yPosition = yLuarBound;
                }
            } else if (currentState==3) {
                allowTeleport = true;
                xPosition = xStoreBound;
                yPosition = yStoreBound;
            } else if (currentState==4) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xStadiumBound;
                    yPosition = yStadiumBound;
                }
            } else if (currentState==5) {
                allowTeleport = true;
                xPosition = xBattlescreenBound;
                yPosition = yBattlescreenBound;
            } else if (currentState==6) {
                allowTeleport = true;
                xPosition = xCombinatoriumBound;
                yPosition = yCombinatoriumBound;
            }
        }
    }

    if (allowTeleport) {
        currentState = toState;
        setCurX(xPosition);
        setCurY(yPosition);
        s.drawStadium();
    } else {
        cout << "Tidak bisa teleport" << endl;
    }
}

void Player::teleport(int &currentState, int toState, int &xPosition, int &yPosition, Combinatorium &s) {
    bool allowTeleport = false;
    if (currentState==1) { //kota
        if (toState==0) {
            if (xPosition==xHomeBound && yPosition==yHomeBound) {
                allowTeleport = true;
            }
        } else if (toState==2) {
            if (xPosition==xLuarBound && yPosition==yLuarBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==3) {
            if (xPosition==xStoreBound && yPosition==yStoreBound) {
                allowTeleport = true;
            }
        } else if (toState==4) {
            if (xPosition==xStadiumBound && yPosition==yStadiumBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==5) {
            if (xPosition==xBattlescreenBound && yPosition==yBattlescreenBound) {
                allowTeleport = true;
            }
        } else if (toState==6) {
            if (xPosition==xCombinatoriumBound && yPosition==yCombinatoriumBound) {
                allowTeleport = true;
            }
        }
    } else {
        if (toState==1) {
            if (currentState==0) {
                allowTeleport = true;
                xPosition = xHomeBound;
                yPosition = yHomeBound;
            } else if (currentState==2) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xLuarBound;
                    yPosition = yLuarBound;
                }
            } else if (currentState==3) {
                allowTeleport = true;
                xPosition = xStoreBound;
                yPosition = yStoreBound;
            } else if (currentState==4) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xStadiumBound;
                    yPosition = yStadiumBound;
                }
            } else if (currentState==5) {
                allowTeleport = true;
                xPosition = xBattlescreenBound;
                yPosition = yBattlescreenBound;
            } else if (currentState==6) {
                allowTeleport = true;
                xPosition = xCombinatoriumBound;
                yPosition = yCombinatoriumBound;
            }
        }
    }

    if (allowTeleport) {
        currentState = toState;
        setCurX(xPosition);
        setCurY(yPosition);
        s.drawCombinatorium();
    } else {
        cout << "Tidak bisa teleport" << endl;
    }
}

void Player::teleport(int &currentState, int toState, int &xPosition, int &yPosition, Home &s) {
    bool allowTeleport = false;
    if (currentState==1) { //kota
        if (toState==0) {
            if (xPosition==xHomeBound && yPosition==yHomeBound) {
                allowTeleport = true;
            }
        } else if (toState==2) {
            if (xPosition==xLuarBound && yPosition==yLuarBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==3) {
            if (xPosition==xStoreBound && yPosition==yStoreBound) {
                allowTeleport = true;
            }
        } else if (toState==4) {
            if (xPosition==xStadiumBound && yPosition==yStadiumBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==5) {
            if (xPosition==xBattlescreenBound && yPosition==yBattlescreenBound) {
                allowTeleport = true;
            }
        } else if (toState==6) {
            if (xPosition==xCombinatoriumBound && yPosition==yCombinatoriumBound) {
                allowTeleport = true;
            }
        }
    } else {
        if (toState==1) {
            if (currentState==0) {
                allowTeleport = true;
                xPosition = xHomeBound;
                yPosition = yHomeBound;
            } else if (currentState==2) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xLuarBound;
                    yPosition = yLuarBound;
                }
            } else if (currentState==3) {
                allowTeleport = true;
                xPosition = xStoreBound;
                yPosition = yStoreBound;
            } else if (currentState==4) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xStadiumBound;
                    yPosition = yStadiumBound;
                }
            } else if (currentState==5) {
                allowTeleport = true;
                xPosition = xBattlescreenBound;
                yPosition = yBattlescreenBound;
            } else if (currentState==6) {
                allowTeleport = true;
                xPosition = xCombinatoriumBound;
                yPosition = yCombinatoriumBound;
            }
        }
    }

    if (allowTeleport) {
        currentState = toState;
        setCurX(xPosition);
        setCurY(yPosition);
        s.drawHome();
    } else {
        cout << "Tidak bisa teleport" << endl;
    }
}

void Player::teleport(int &currentState, int toState, int &xPosition, int &yPosition, Store &s) {
    bool allowTeleport = false;
    if (currentState==1) { //kota
        if (toState==0) {
            if (xPosition==xHomeBound && yPosition==yHomeBound) {
                allowTeleport = true;
            }
        } else if (toState==2) {
            if (xPosition==xLuarBound && yPosition==yLuarBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==3) {
            if (xPosition==xStoreBound && yPosition==yStoreBound) {
                allowTeleport = true;
            }
        } else if (toState==4) {
            if (xPosition==xStadiumBound && yPosition==yStadiumBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==5) {
            if (xPosition==xBattlescreenBound && yPosition==yBattlescreenBound) {
                allowTeleport = true;
            }
        } else if (toState==6) {
            if (xPosition==xCombinatoriumBound && yPosition==yCombinatoriumBound) {
                allowTeleport = true;
            }
        }
    } else {
        if (toState==1) {
            if (currentState==0) {
                allowTeleport = true;
                xPosition = xHomeBound;
                yPosition = yHomeBound;
            } else if (currentState==2) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xLuarBound;
                    yPosition = yLuarBound;
                }
            } else if (currentState==3) {
                allowTeleport = true;
                xPosition = xStoreBound;
                yPosition = yStoreBound;
            } else if (currentState==4) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xStadiumBound;
                    yPosition = yStadiumBound;
                }
            } else if (currentState==5) {
                allowTeleport = true;
                xPosition = xBattlescreenBound;
                yPosition = yBattlescreenBound;
            } else if (currentState==6) {
                allowTeleport = true;
                xPosition = xCombinatoriumBound;
                yPosition = yCombinatoriumBound;
            }
        }
    }

    if (allowTeleport) {
        currentState = toState;
        setCurX(xPosition);
        setCurY(yPosition);
        s.drawStore();
    } else {
        cout << "Tidak bisa teleport" << endl;
    }
}

void Player::teleport(int &currentState, int toState, int &xPosition, int &yPosition, BattleScreen &s) {
    bool allowTeleport = false;
    if (currentState==1) { //kota
        if (toState==0) {
            if (xPosition==xHomeBound && yPosition==yHomeBound) {
                allowTeleport = true;
            }
        } else if (toState==2) {
            if (xPosition==xLuarBound && yPosition==yLuarBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==3) {
            if (xPosition==xStoreBound && yPosition==yStoreBound) {
                allowTeleport = true;
            }
        } else if (toState==4) {
            if (xPosition==xStadiumBound && yPosition==yStadiumBound) {
                allowTeleport = true;
                xPosition = 1;
                yPosition = 1;
            }
        } else if (toState==5) {
            if (xPosition==xBattlescreenBound && yPosition==yBattlescreenBound) {
                allowTeleport = true;
            }
        } else if (toState==6) {
            if (xPosition==xCombinatoriumBound && yPosition==yCombinatoriumBound) {
                allowTeleport = true;
            }
        }
    } else {
        if (toState==1) {
            if (currentState==0) {
                allowTeleport = true;
                xPosition = xHomeBound;
                yPosition = yHomeBound;
            } else if (currentState==2) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xLuarBound;
                    yPosition = yLuarBound;
                }
            } else if (currentState==3) {
                allowTeleport = true;
                xPosition = xStoreBound;
                yPosition = yStoreBound;
            } else if (currentState==4) {
                if (xPosition==1 && yPosition==1) {
                    allowTeleport = true;
                    xPosition = xStadiumBound;
                    yPosition = yStadiumBound;
                }
            } else if (currentState==5) {
                allowTeleport = true;
                xPosition = xBattlescreenBound;
                yPosition = yBattlescreenBound;
            } else if (currentState==6) {
                allowTeleport = true;
                xPosition = xCombinatoriumBound;
                yPosition = yCombinatoriumBound;
            }
        }
    }

    if (allowTeleport) {
        currentState = toState;
        setCurX(xPosition);
        setCurY(yPosition);
        s.drawScreen(currentState);
    } else {
        cout << "Tidak bisa teleport" << endl;
    }
}

void Player::move(string s, int i, Screen sc){
    if(s=="bawah"){
        if( (curX+i)>sc.getYLength()-1){
        curX=sc.getXLength()-1;
        cout << "mentok cuy"<<endl;
        }else {
            curX= curX+i;
        }

    }else if(s=="atas"){
        if( (curX-i)<0){
        curX=0;
        cout << "mentok cuy"<<endl;
        }else {
            curX= curX-i;
        }
    }else if(s=="kiri"){
        if( (curY-i)<0){
        curY=0;
        cout << "mentok cuy"<<endl;
        }else {
            curY= curY-i;
        }
    }else if(s=="kanan"){
        if( (curY+i)>sc.getXLength()-1){
        curY=sc.getXLength()-1;
        cout << "mentok cuy"<<endl;
        }else {
            curY= curY+i;
        }
    }
    cout << curY << "," << curX << endl;
}

void Player::showMonsterList(){

}

void Player::showItemList(){

}

void Player::setMonster(string s){
    //set default pokemon untuk battle
    defaultMonster=listMonster[s];
    cout << "default monster = " << defaultMonster.getNama()<< endl;
}

void Player::dismiss(string s){
    //menghapus monster bernama s dari listMonster
    listMonster.erase(s);
}

void Player::escape(){
    jumlahEscape++;
}

void Player::change(string s){

}

void Player::addMoney(int i){
    uang=uang+i;
}


/*-------------------------------------------------------------------------------------method baru---------------------------------------------------------------------------------- */
void Player::addMonster(Monster& _m){
    this->listMonster[_m.getNama()] = _m;
}

void Player::delMoney(int i){
    //mengurangi uang sebesar i
    uang = uang - i;
}

void Player::delItem(Item item){
    //menghapus item dari listItem
    for(int i=0; i< listItem.size();i++){
        if(listItem.at(i)==item){
            listItem.erase(listItem.begin() + i);
        }//end if
    }//end for

}



/*--------------------------------------------------------------------------------------methodtambahan---------------------------------------------------------------------------------------*/

void Player::printListItem(){
	cout << this->listItem[0].getItemName() << endl;

    cout << endl;
    cout << "list item: "<<endl;
    for(int i=0; i<listItem.size();i++){
        cout << ">" << listItem[i].getItemName() << endl;
		cout << ">> harga : " << listItem[i].getHarga() << endl;
    }
}

void Player::printListMonster(){
    cout << endl;
    cout << "list monster: "<<endl;
    typedef map<string,Monster>::const_iterator mapIter;
    for(mapIter iter = listMonster.begin(); iter != listMonster.end(); iter++){
        cout << ">" << iter->first << endl;
    }//end for
}

void Player::addToListItem(Item item){
        listItem.push_back(item);               //push item ke akhir vector listItem
}

void Player::addToListMonster(string namaMonster, Monster monster){
        listMonster.insert(make_pair(namaMonster, monster));
}

int Player::isContainMonster(string _s){
	cout << _s;
	map<string,Monster>::iterator it = this->listMonster.find(_s);
	if (it == this->listMonster.end()){
		return 0;
	} else {
		return 1;
	}
}

Monster Player::getMonster(string _m) {
	if (isContainMonster(_m)) {
		return this->listMonster[_m];
	} else {
		return (*(Monster*)0);
	}
}
