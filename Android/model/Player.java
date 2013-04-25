package model;

import java.util.ArrayList;


public class Player {

	private String nama;
	private int uang;
	private ArrayList<Item> listItem;
	
	private int curX;
	private int curY;
	private int jumlahMenang;
	private int jumlahKalah;
	private int jumlahEscape;
	private int waktu;
	private String warnaPlayer;
	
	public Monster defaultMonster;
    public ArrayList<Monster> listMonster;
	
    public Player(){
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
    
    public Player(String a){
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
    
    /*------------------------------------------------------getter-------------------------------- */
    public String getNama(){
        return nama;
    }

    public int getUang(){
        return uang;
    }

    public int getCurX(){
        return curX;
    }

    public int getCurY(){
        return curY;
    }

    public int getJumlahMenang(){
        return jumlahMenang;
    }

    public int getJumlahKalah(){
        return jumlahKalah;
    }

    public int getJumlahEscape(){
        return jumlahEscape;
    }

    public int getWaktu(){
        return jumlahEscape;
    }

    public String getWarnaPlayer(){
        return warnaPlayer;
    }

    /*-------------------------------------------------setter-------------------------------------------------------- */
    public void setNama(String _n){
        nama = _n;
    }

    public void setUang(int _u){
        uang = _u;
    }

    public void addItem(Item _i){
        listItem.add(_i); 
    }

    public void addMonster(Monster _mon){
        listMonster.add(_mon);
    }

    public void setJumlahMenang(int _win){
        jumlahMenang = _win;
    }

    public void setJumlahKalah(int _lose){
        jumlahKalah = _lose;
    }

    public void setJumlahEscape(int _esc) {
        jumlahEscape = _esc;
    }

    public void setWaktu(int _time){
        waktu = _time;
    }

    public void setWarna(String _w){
        warnaPlayer = _w;
    }

    public void setCurX(int i){
            curX=i;
    }

    public void setCurY(int i){
            curY=i;
    }

    /*-------------------------------------------method utama--------------------------------------------------------------- */

    public void bet(int jmlBet, boolean isMenang){
        if (isMenang==true){
            uang=uang+jmlBet;
        }else{
            uang=uang-jmlBet;
        }
    }

//        void battle(String, NPC)
//        void battle(String, Monster);

    public void save(String s){
        //disimpan dg btk apa?
    }

    public void sleep(){
        //nunggu monster
    }


    public void sell(String item, int n){

            for (int ii=0; ii<n;ii++){
                for (int i=0; i< listItem.size(); i++){
                    if(listItem.get(i).getNama().equals(item)){
                            listItem.remove(i);
                            System.out.println(listItem.get(i).getNama()+" dijual");                            
                            uang=uang + listItem.get(i).getHarga();
                    }else if(i==(listItem.size()-1)){
                        System.out.println("item tidak tersedia");                            
                    }
                }//end for 2
            }//end for 1
        }

    public void buy(Item i){
        if(uang >= i.getHarga()){
            addToListItem(i);
            uang= uang - i.getHarga();
            System.out.println(i.getNama()+" dibeli");             
        }else{
            System.out.println("uang tidak cukup");
        }
    }


    public void teleport(int currentState, int toState, int xPosition, int yPosition, Kota s) {
        boolean allowTeleport = false;
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



    public void teleport(int &currentState, int toState, int &xPosition, int &yPosition, Screen &s) {
        boolean allowTeleport = false;
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

    public void teleport(int &currentState, int toState, int &xPosition, int &yPosition, Stadium &s) {
//        xPosition = curY;
//        yPosition = curX;
        cout << curX << ";" << curY << endl;
        cout << xPosition << ";" << yPosition << endl;
        boolean allowTeleport = false;
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

    public void teleport(int &currentState, int toState, int &xPosition, int &yPosition, Combinatorium &s) {
        boolean allowTeleport = false;
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

    public void teleport(int &currentState, int toState, int &xPosition, int &yPosition, Home &s) {
        boolean allowTeleport = false;
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

    public void teleport(int &currentState, int toState, int &xPosition, int &yPosition, Store &s) {
        boolean allowTeleport = false;
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

    public void teleport(int &currentState, int toState, int &xPosition, int &yPosition, BattleScreen &s) {
        boolean allowTeleport = false;
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

    public void move(String s, int i, Screen sc){
        if(s=="bawah"){
            if( (curX+i)>sc.getYLength()-1){
            curX=sc.getXLength()-1;
                System.out.println("mentok cuy");
            }else {
                curX= curX+i;
            }

        }else if(s=="atas"){
            if( (curX-i)<0){
            curX=0;
            System.out.println("mentok cuy");
            }else {
                curX= curX-i;
            }
        }else if(s=="kiri"){
            if( (curY-i)<0){
            curY=0;
            System.out.println("mentok cuy");
            }else {
                curY= curY-i;
            }
        }else if(s=="kanan"){
            if( (curY+i)>sc.getXLength()-1){
            curY=sc.getXLength()-1;
            System.out.println("mentok cuy");
            }else {
                curY= curY+i;
            }
        }
        System.out.println(curY+","+curX);        
    }  

    public void setMonster(String s){
        //set default pokemon untuk battle
//        defaultMonster=listMonster[s];
//        cout << "default monster = " << defaultMonster.getNama()<< endl;
    }

    public void dismiss(String s){
        //menghapus monster bernama s dari listMonster
        
    }

    public void escape(){
        jumlahEscape++;
    }

    public void change(String s){

    }

    public void addMoney(int i){
        uang=uang+i;
    }


    /*-------------------------------------------------------------------------------------method baru---------------------------------------------------------------------------------- */
    public void addMonster(Monster _m){
       listMonster.add(_m);
    }

    public void delMoney(int i){
        //mengurangi uang sebesar i
        uang = uang - i;
    }

    public void delItem(Item item){
        //menghapus item dari listItem
        for(int i=0; i< listItem.size();i++){
            if(listItem.get(i) ==item){
                listItem.remove(i);
            }//end if
        }//end for

    }



    /*--------------------------------------------------------------------------------------methodtambahan---------------------------------------------------------------------------------------*/

    public void printListItem(){
        System.out.println("");
        System.out.println("list item: ");        
        for(int i=0; i<listItem.size();i++){
            System.out.println(listItem.get(i).getNama());            
            System.out.println("harga : "+listItem.get(i).getHarga());            
        }
    }

    public void printListMonster(){
        System.out.println("");
        System.out.println("list monster: ");        
        for(int i=0; i<listMonster.size();i++){
            //System.out.println(listMonster.get(i).get());            
            //System.out.println("harga : "+listItem.get(i).getHarga());            
        }
    }

    public void addToListItem(Item item){
            listItem.add(item);     
    }

    public void addToListMonster(Monster monster){
            listMonster.add(monster);
    }

    public int isContainMonster(String _s){
//    	cout << _s;
//    	map<String,Monster>::iterator it = this->listMonster.find(_s);
//    	if (it == this->listMonster.end()){
//    		return 0;
//    	} else {
//    		return 1;
//    	}
    }

    public Monster getMonster(String _m) {
//    	if (isContainMonster(_m)) {
//    		return this->listMonster[_m];
//    	} else {
//    		return (*(Monster*)0);
//    	}
    }

}//end class
