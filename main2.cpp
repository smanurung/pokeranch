#include "Player.h"
#include "Store.h"
#include "Screen.h"
#include "Item.h"
#include "Potion.h"
#include "StatusIncrease.h"
#include "MonsterEgg.h"
#include "Kota.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <ctime>


#include "AreaLuar.h"
#include "BattleScreen.h"
#include "Combinatorium.h"
#include "Home.h"
#include "Kota.h"
#include "Stadium.h"

using namespace std;


void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void parseFile(Player& _p){
	fstream f;
	f.open("example.txt", ios::in | ios::out);
	string _s;
	vector<string> isiFile;
	if (f.is_open()) {
		cout << ">>file berhasil dibuka" << endl;
		while (f.good()){ //kondisi file ready
			getline(f,_s);
			isiFile.push_back(_s);
		}

		int idx = 1;
		//nama
		_p.setNama(isiFile[idx++]);

		//uang
		int _uang = atoi(isiFile[idx++].c_str());
		_p.setUang(_uang);

		//player item
		const string END_ITEM = "enditem";
		const string END_MONSTER = "endmonster";
		while (isiFile[idx].compare(END_ITEM)){
			if (!isiFile[idx].compare("potion")) {
				idx += 1;

				istringstream iss(isiFile[idx]);
				vector<string> tokens;
				copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(tokens));
				int mp = atoi(tokens[0].c_str());
				int hp = atoi(tokens[1].c_str());
				Potion _pot(mp,hp);
				_p.addItem(_pot);

				idx += 1;
			} else if (!isiFile[idx].compare("statusincrease")) {
				idx += 1;

				istringstream iss(isiFile[idx]);
				vector<string> tokens;
				copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(tokens));
				int mpp = atoi(tokens[0].c_str());
				int hpp = atoi(tokens[1].c_str());
				StatusIncrease _statInc(mpp,hpp);
				_p.addItem(_statInc);
				//item status increase telah berhasil ditambahkan ke listitem player

				idx += 1;
			} else if (!isiFile[idx].compare("monsteregg")) {
				idx += 1;

				istringstream iss(isiFile[idx]);
				vector<string> tokens;
				copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(tokens));

				/*for (int i=0; i<tokens.size(); i++){
					cout << "halah : " << tokens[i] << endl;
				}*/

				Monster _m(tokens[0],atoi(tokens[1].c_str()),atoi(tokens[2].c_str()),tokens[3],tokens[4],atoi(tokens[5].c_str()),atoi(tokens[6].c_str()),atoi(tokens[7].c_str()),atoi(tokens[8].c_str()),atoi(tokens[9].c_str()),tokens[10],atoi(tokens[11].c_str()),tokens[12]);
				MonsterEgg _megg(_m);

				_p.addItem(_megg);

				idx += 1;
			} else {
				idx += 2;
			}
		}

		//player monster
		idx += 1;
		while (isiFile[idx].compare(END_MONSTER)) {
			if (!isiFile[idx].compare("monster")) {
				//cout << isiFile[idx] << endl;
				idx += 1;

				istringstream iss(isiFile[idx]);
				vector<string> tokens;
				copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(tokens));

				Monster _m(tokens[0],atoi(tokens[1].c_str()),atoi(tokens[2].c_str()),tokens[3],tokens[4],atoi(tokens[5].c_str()),atoi(tokens[6].c_str()),atoi(tokens[7].c_str()),atoi(tokens[8].c_str()),atoi(tokens[9].c_str()),tokens[10],atoi(tokens[11].c_str()),tokens[12]);

				_p.addMonster(_m.getNama(),_m);

				idx += 1;
			} else {
				idx += 2;
			}
		}

		//cout << isiFile[idx] << endl;
		idx += 1;
		//jumlah menang
		_p.setJumlahMenang(atoi(isiFile[idx++].c_str()));
		_p.setJumlahKalah(atoi(isiFile[idx++].c_str()));
		_p.setJumlahEscape(atoi(isiFile[idx++].c_str()));
		_p.setWaktu(atoi(isiFile[idx++].c_str()));
		_p.setWarna(isiFile[idx++]);

	} else {
		cout << ">>Warning!! File tidak bisa dibuka" << endl;
	}

	f.close();
}


void DatabaseMonster(vector<Monster>& listMonster){
    ifstream f;
    f.open("Monster.pr");
    while(!f.eof()){
        Monster M;
        string a;
        string b;
        int d;
        getline(f,a);
        istringstream c(a);
        c >> b;
        M.setNama(b);
        c >> b;
        d = atoi(b.c_str());
        M.setLevel(d);
        c >> b;
        d = atoi (b.c_str());
        M.setExp(d);
        c >> b;
        M.setSpecies(b);
        c >> b;
        M.setElm(b);
        c >> b;
        d = atoi(b.c_str());
        M.setHP(d);
        M.setCurrentHP(d);
        c >> b;
        d = atoi (b.c_str());
        M.setMP(d);
        M.setCurrentMP(d);
        c >> b;
        d = atoi (b.c_str());
        M.setSpeed(d);
        c >> b;
        d = atoi (b.c_str());
        M.setBonusUang(d);
        c >> b;
        d = atoi (b.c_str());
        M.setBonusExp(d);
        c >> b;
        M.setStatus(b);
        c >> b;
        d = atoi (b.c_str());
        M.setUmur(d);
        c >> b;
        M.setWarnaMonster(b);
        listMonster.push_back(M);
    }
    f.close();
}


/*-------------------------------------------------------------------main----------------------------------------------------------------*/
int main() {
	string input;
	string command;
	vector<string> argument;
    int state = 0;

    Player p1;
    int posisiXPlayer=p1.getCurX();
    int posisiYPlayer=p1.getCurY();

    vector<Monster> DataMonster;

	parseFile(p1);

    Kota kota(p1.getCurX(),p1.getCurY());
    AreaLuar areaLuar(1,1);

    BattleScreen battleScreen;
    Combinatorium combinatorium;
    Home home;
    Stadium stadium;
    Store store;

	cout << "---POKERANCH---" << endl;

    DatabaseMonster(DataMonster);

    p1.setMonster("johannes");
    Monster firstMonster=p1.defaultMonster;
/*-----------------------------------------------------------------------------------------------------------------------*/

    while (command != "exit") {
		cout << "command :";
        getline(cin,input);

		argument.clear();

		//splitting input
		istringstream iss(input);
		vector<string> strInput;
		copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(strInput));

		command = strInput[0];
		for (int i = 1; i<strInput.size(); i++){
			argument.push_back(strInput[i]);
		}

        int i = 0;
        //memasukkan command
        if(command == "new") {
            //new game
			cout << "\n --New Game Mode--\n" << endl;
        }
        else if(command == "load") {
            if(argument.size() == 0) {
                cout << "argumen kurang" << endl;
            } else {
				cout << "load file berhasil" << endl;
			}
        }
        else if(command == "sleep") {
            //sleep
			cout << "\nPlayer is sleeping ... \n" << endl;

			//merevitalisasi seluruh monster


			sleep(5000);
			cout << "\nPlayer sudah bangun kembali ^^\n" << endl;
        }
        else if(command == "save") {
            //save
        }
/*----------------------------------------------------------------------------------------------------------------------teleport----------------------------------------------------------------------------------------------------------------------*/
        else if(command == "teleport"){
            if(argument.size() == 0) {
                cout << "argumen kurang" << endl;
                //cout<<argument[0];
			}else
				//teleport
				//assign state
				if(argument[0] == "home") {				 //toState  0
					p1.teleport(state, 0, posisiXPlayer, posisiYPlayer, home);
				}//end if home

				else if(argument[0] == "kota") {				 //toState  1
					p1.teleport(state, 1, posisiXPlayer, posisiYPlayer, kota);
				}//end if kota

				else if(argument[0]== "luar") {                      //toState  2
//				    posisiXPlayer=xLuarBound;
//				    posisiYPlayer=yLuarBound;
					p1.teleport(state, 2, posisiXPlayer, posisiYPlayer, areaLuar);
					while(state==2){
						cout << "command : ";
						getline(cin,input);

						argument.clear();

						//splitting input
						istringstream iss(input);
						vector<string> strInput;
						copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(strInput));

						command = strInput[0];
						for (int i = 1; i<strInput.size(); i++){
							argument.push_back(strInput[i]);
						}

						int i = 0;

						if(command == "move"){
							if(argument.size() <2) {
								cout << "argumen kurang" << endl;
							}
							//move
							int step = atoi(argument[1].c_str());
							p1.move(argument[0],step,areaLuar);
							posisiXPlayer = p1.getCurX();
							posisiYPlayer = p1.getCurY();
							areaLuar.setPosisiPlayer(p1.getCurX(), p1.getCurY());
							areaLuar.drawScreen(1);
						}//end move
						else if(command == "teleport"){
							if(argument.size() == 0) {
								cout << "argumen kurang" << endl;
							}
							if(argument[0] == "kota") {				 //toState  1
								p1.teleport(state, 1, posisiXPlayer, posisiYPlayer, kota);
							}//end if kota
						}//end teleport
						/* ------------------------------------------------------------------battle-------------------------------------------------*/
                        else if (command == "battle"){
                            if (argument.size() != 1){
                                cout << "argumen seharusnya battle <bet>" << endl;
                            } else if (argument.size() == 1) {
                                int d = atoi(argument[1].c_str());
                //                firstMonster.ShowStatus();
                                //firstMonster.ShowBattleStatus();
                                Monster MEnemy = DataMonster[rand() %7];
                                //cout << "Monster Musuh : " << endl;
                                //MEnemy.ShowBattleStatus();
                                while((firstMonster.getCurrentHP() > 0) && (MEnemy.getCurrentHP() > 0)){
                                    firstMonster.setCurrentHP(firstMonster.getCurrentHP()-5);
                                    firstMonster.StatusEfek();
                                    MEnemy.StatusEfek();

                                    battleScreen.drawScreen(1);

                                    firstMonster.addSkill();
                                    MEnemy.addSkill();

                                    cout << "Monster Player : " << endl;
                                    firstMonster.ShowBattleStatus();
                                    firstMonster.ShowListSkill();

                                    cout << "Monster Musuh : " << endl;
                                    MEnemy.ShowBattleStatus();

                                    cout << "command : ";
                                    getline(cin,input);

                                    argument.clear();

                                    //splitting input
                                    istringstream iss(input);
                                    vector<string> strInput;
                                    copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(strInput));

                                    command = strInput[0];
                                    for (int i = 1; i<strInput.size(); i++){
                                        argument.push_back(strInput[i]);
                                    }

                                    int i = 0;

                                    if(command == "skill"){
                                        if (argument.size() == 1){
                                            int a = 0;
                                            while(firstMonster.ListSkill[a].getNamaSkill() != argument[0]){
                                                a++;
                                            }
                                            MEnemy.setCurrentHP(MEnemy.getCurrentHP() - firstMonster.ListSkill[a].getDamage());
                                            MEnemy.setStatus(firstMonster.ListSkill[a].getEfek());
                                            firstMonster.setCurrentMP(firstMonster.getCurrentMP()-5);
                                        } else {
                                            cout << "argumen seharusnya skill <nama-skill>" << endl;
                                        }
                                    } else if(command == "item"){
                                        if (argument.size() == 1){
                                            if(argument[0] == "Potion"){
                                                firstMonster.setCurrentHP(firstMonster.getCurrentHP() + 20);
                                            }
                                        } else {
                                            cout << "Argumen seharusnya item <nama-item>" << endl;
                                        }
                                    } else if(command == "change"){
                                        if((argument.size() == 1) && (p1.isContainMonster(argument[0]))){
//                                            Monster M = DataMonster[rand() %7];
//                                            M.setNama(argument[0]);
//                                            firstMonster = M;
                                            p1.setMonster(argument[0]);
                                            firstMonster=p1.defaultMonster;
                                        }
                                        else{
                                            cout << endl<<"argumen kurang atau monster tidak dimiliki"<<endl;
                                        }
                                    }else if(command == "escape"){
                                        cout<<"kabur"<<endl;
                                        p1.escape();
                                        break;
                                    }
                                }
                                if (firstMonster.getCurrentHP() <= 0){
                                    cout << "Maaf anda kalah" << endl;
                                }
                                else if (MEnemy.getCurrentHP() <=0){
                                    cout << "Monster mendapatkan " << MEnemy.getBonusExp() << " experience" << endl;
                                    firstMonster.addExperience(MEnemy);
                                    p1.setUang(p1.getUang() + MEnemy.getBonusUang());
                                    firstMonster.changeSpecies();
                                    cout << "Selamat anda menang pertempuran" << endl;
                                    cout << "Anda mendapatkan uang : " << MEnemy.getBonusUang() << endl;
                                }
                            }//end argumentsize==1
                    }//end battle
                    /* ------------------------------------------------------------------end battle-------------------------------------------------*/
					}//end while

				}//end if luar

				else if(argument[0] == "store") {                  //toState  3
	//				    posisiXPlayer=xStoreBound;
	//				    posisiYPlayer=yStoreBound;
					p1.teleport(state, 3, posisiXPlayer, posisiYPlayer, store);
					while(state==3){
						cout << "command : ";
						getline(cin,input);

						argument.clear();

						//splitting input
						istringstream iss(input);
						vector<string> strInput;
						copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(strInput));

						command = strInput[0];
						for (int i = 1; i<strInput.size(); i++){
							argument.push_back(strInput[i]);
						}

						int i = 0;

						if(command == "sell") {
                            if(argument.size() < 2) {
                                cout << "argumen kurang" << endl;
                             }
                            else{
                                p1.sell(argument[0],atoi(argument[1].c_str()));
                            }
						//sell
						}
						else if(command == "buy") {
							if(argument.size() < 2) {
								cout << "argumen kurang" << endl;
							}
							//buy
						}
						else if(command == "teleport") {
							if(argument.size() < 1) {
								cout << "argumen kurang" << endl;
							}
							else{
                                p1.teleport(state, 1, posisiXPlayer, posisiYPlayer, kota);
							}
						}

					}//end while

				}//end if store
				else if(argument[0] == "stadium") {            //toState  4
	                p1.teleport(state, 4, posisiXPlayer, posisiYPlayer, stadium);

                    while(state==4){
						cout << "command : ";
						getline(cin,input);

						argument.clear();

						//splitting input
						istringstream iss(input);
						vector<string> strInput;
						copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(strInput));

						command = strInput[0];
						for (int i = 1; i<strInput.size(); i++){
							argument.push_back(strInput[i]);
						}

						int i = 0;

						if(command == "teleport") {
							if(argument.size() < 1) {
								cout << "argumen kurang" << endl;
							}
							else{
                                p1.teleport(state, 1, posisiXPlayer, posisiYPlayer, kota);
							}
						}
                        /* ------------------------------------------------------------------battle-------------------------------------------------*/
                        else if (command == "battle"){
                            if (argument.size() != 1){
                                cout << "argumen seharusnya battle <bet>" << endl;
                            } else if (argument.size() == 1) {
                                int d = atoi(argument[1].c_str());
                //                firstMonster.ShowStatus();
                                //firstMonster.ShowBattleStatus();
                                Monster MEnemy = DataMonster[rand() %7];
                                //cout << "Monster Musuh : " << endl;
                                //MEnemy.ShowBattleStatus();
                                while((firstMonster.getCurrentHP() > 0) && (MEnemy.getCurrentHP() > 0)){
                                    firstMonster.setCurrentHP(firstMonster.getCurrentHP()-5);
                                    firstMonster.StatusEfek();
                                    MEnemy.StatusEfek();

                                    battleScreen.drawScreen(1);

                                    firstMonster.addSkill();
                                    MEnemy.addSkill();

                                    cout << "Monster Player : " << endl;
                                    firstMonster.ShowBattleStatus();
                                    firstMonster.ShowListSkill();

                                    cout << "Monster Musuh : " << endl;
                                    MEnemy.ShowBattleStatus();

                                    cout << "command : ";
                                    getline(cin,input);

                                    argument.clear();

                                    //splitting input
                                    istringstream iss(input);
                                    vector<string> strInput;
                                    copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(strInput));

                                    command = strInput[0];
                                    for (int i = 1; i<strInput.size(); i++){
                                        argument.push_back(strInput[i]);
                                    }

                                    int i = 0;

                                    if(command == "skill"){
                                        if (argument.size() == 1){
                                            int a = 0;
                                            while(firstMonster.ListSkill[a].getNamaSkill() != argument[0]){
                                                a++;
                                            }
                                            MEnemy.setCurrentHP(MEnemy.getCurrentHP() - firstMonster.ListSkill[a].getDamage());
                                            MEnemy.setStatus(firstMonster.ListSkill[a].getEfek());
                                            firstMonster.setCurrentMP(firstMonster.getCurrentMP()-5);
                                        } else {
                                            cout << "argumen seharusnya skill <nama-skill>" << endl;
                                        }
                                    } else if(command == "item"){
                                        if (argument.size() == 1){
                                            if(argument[0] == "Potion"){
                                                firstMonster.setCurrentHP(firstMonster.getCurrentHP() + 20);
                                            }
                                        } else {
                                            cout << "Argumen seharusnya item <nama-item>" << endl;
                                        }
                                    } else if(command == "change"){
                                        if((argument.size() == 1) && (p1.isContainMonster(argument[0]))){
//                                            Monster M = DataMonster[rand() %7];
//                                            M.setNama(argument[0]);
//                                            firstMonster = M;
                                            p1.setMonster(argument[0]);
                                            firstMonster=p1.defaultMonster;
                                        }
                                        else{
                                            cout << endl<<"argumen kurang atau monster tidak dimiliki"<<endl;
                                        }
                                    }else if(command == "escape"){
                                        cout<<"kabur"<<endl;
                                        p1.escape();
                                        break;
                                    }
                                }
                                if (firstMonster.getCurrentHP() <= 0){
                                    cout << "Maaf anda kalah" << endl;
                                }
                                else if (MEnemy.getCurrentHP() <=0){
                                    cout << "Monster mendapatkan " << MEnemy.getBonusExp() << " experience" << endl;
                                    firstMonster.addExperience(MEnemy);
                                    p1.setUang(p1.getUang() + MEnemy.getBonusUang());
                                    firstMonster.changeSpecies();
                                    cout << "Selamat anda menang pertempuran" << endl;
                                    cout << "Anda mendapatkan uang : " << MEnemy.getBonusUang() << endl;
                                }
                            }//end argumentsize==1
                        }//end battle
                    /* ------------------------------------------------------------------end battle-------------------------------------------------*/

					}//end while
				}//end stadium


				else if(argument[0] == "combinatorium") {                  //toState  6
//						posisiXPlayer=xCombinatoriumBound;
//						posisiYPlayer=yCombinatoriumBound;
					p1.teleport(state, 6, posisiXPlayer, posisiYPlayer, combinatorium);
                    while(state==6){
						cout << "command : ";
						getline(cin,input);

						argument.clear();

						//splitting input
						istringstream iss(input);
						vector<string> strInput;
						copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(strInput));

						command = strInput[0];
						for (int i = 1; i<strInput.size(); i++){
							argument.push_back(strInput[i]);
						}

						int i = 0;

						if(command == "teleport") {
							if(argument.size() < 1) {
								cout << "argumen kurang" << endl;
							}
							else{
                                p1.teleport(state, 1, posisiXPlayer, posisiYPlayer, kota);
							}
						}
                        else if(command == "combine") {
                                    if(argument.size() < 2) {
                                        cout << "argumen kurang" << endl;
                                    } else if (state != 6) {
                                        cout << "\nWARNING. Player tidak bisa melakukan combine!\n" << endl;
                                    } else {
                                        string _monStr2 = argument[0];
                                        string _monStr1 = argument[1];
                                        if (p1.isContainMonster(_monStr1) && p1.isContainMonster(_monStr2)) {
                                            Monster _m1 = p1.getMonster(_monStr1).Combine(p1.getMonster(_monStr2));
                                            p1.addMonster(_m1);
                                            p1.dismiss(_monStr1);
                                            p1.dismiss(_monStr2);
                                            cout << "\nSELAMAT. Combine berhasil dilakukan\n" << endl;
                                        } else {
                                            cout << "\nWARNING. Monster tidak dimiliki player\n" << endl;
                                        }
                                    }
                        }
                    }//end while
				}//end combinatorium
				else {
					cout << "tidak ada tempat tersebut" << endl;
				}

			}//end if teleport


        else if((command == "move") && (state==1)) {
            if(argument.size() <2) {
                cout << "argumen kurang" << endl;
            }
            //move
            int step = atoi(argument[1].c_str());
            p1.move(argument[0],step,kota);
            posisiXPlayer = p1.getCurX();
            posisiYPlayer = p1.getCurY();
            kota.setPosisiPlayer(p1.getCurX(), p1.getCurY());
            kota.drawScreen(1);
        }//end move

        else if(command == "list-monster") {
            //list-monster
			p1.printListMonster();
        }
        else if(command == "list-item") {
            //list-item
			p1.printListItem();
        } else if(command == "item"){
            if (argument.size() < 1){
                cout << "Argumen kurang" << endl;
            } else if ((argument.size() == 1) && (argument[0] == "MonsterEgg")){
                p1.addMonster(DataMonster[rand() %7]);
            } else if ((argument.size() == 2) && (argument[0] == "MonsterEgg")){
                Monster M = DataMonster[rand() %7];
                M.setNama(argument[1]);
                p1.addMonster(M);
            }
        }
        else if(command == "status") {
            //status
			cout << "\n--Status Player\n" << endl;
			cout << "Nama : " << p1.getNama() << endl;
			cout << "Uang : " << p1.getUang() << endl;
			//cout << "Position : " << p1.getCurX() << ", " << p1.getCurY << endl;
			cout << "Jumlah menang :" << p1.getJumlahMenang() << endl;
			cout << "Jumlah kalah : " << p1.getJumlahKalah() << endl;
			cout << "Jumlah escape : " << p1.getJumlahEscape() << endl;
			cout << "Waktu : " << p1.getWaktu() << endl;
			cout << "Warna : " << p1.getWarnaPlayer() << endl;
        }
        else if(command == "set") {
            if(argument.size() == 0) {
                cout << "argumen kurang" << endl;
            }else{
                p1.setMonster(argument[0]);
                firstMonster=p1.defaultMonster;
            }

        }//end set
        else if(command == "dismiss") {
            if(argument.size() == 0) {
                cout << "argumen kurang" << endl;
            } else {
				//menghapus monster yang ada
				if (p1.isContainMonster(argument[0])) {
					p1.dismiss(argument[0]);
					cout << "\nMonster " << argument[0] << " telah berhasil dilepaskan ke area luar\n" << endl;
				} else {
					cout << "\nWARNING. Monster tidak terdapat pada player\n" << endl;
				}
			}
        }
        else if(command == "help") {
            cout << "\n\n|****************HELP****************|" << endl;
			cout << "---" << "teleport <nama-tempat>" << endl;
			cout << "berpindah ke tempat yang dituju" << endl;
			cout << "---" << "move <arah> [jumlah-langkah]" << endl;
			cout << "menggerakan player" << endl;
			cout << "---" << "list-monster" << endl;
			cout << "menampilkan seluruh monster yang dimiliki" << endl;
			cout << "---" << "list-item" << endl;
			cout << "menampilkan seluruh item yang dimiliki" << endl;
			cout << "---" << "Status" << endl;
			cout << "menampilkan status player" << endl;
			cout << "---" << "set <nama_monster>" << endl;
			cout << "membuat monster terkait untuk digunakan oleh player" << endl;
			cout << "---" << "dismiss <nama_monster>" << endl;
			cout << "melepaskan monster terkait ke alam liar\n\n*" << endl;
        }
        else if(command == "exit") {
            cout << "\nSelamat Jalan ^^^" << endl;
        }
        else { //command kosong
            cout << "\nWARNING!! Command tidak ada\n" << endl;
        }

    }//end main

    return 0;
}
