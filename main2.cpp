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

using namespace std;

void parseFile(Player& _p){
	//cout << "parse" << endl;
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
				//item potion telah berhasil ditambahkan ke listitem player
				//cout << tokens[0] << " " << tokens[1] << "berhasil aman" << endl;

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

int main() {
    //char input[500];
    //char command[100];
    //char argument[4][100];

	string input;
	string command;
	vector<string> argument;
    int state = 0;

    Player p1;
	parseFile(p1);

    Kota k(p1.getCurX(),p1.getCurY());

	cout << "---POKERANCH---" << endl;

    while (command != "exit") {
		cout << "command :";
        cin >> input;

		//////////////////
		istringstream iss(input);
		vector<string> strInput;
		copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string> >(strInput));

		for (int j=0; j<strInput.size(); j++){
			cout << "he" << strInput[j] << "halo" << endl;
		}

		command = strInput[0];
		for (int i = 1; i<strInput.size(); i++){
			argument.push_back(strInput[i]);
		}
		///////////////////

        int i = 0;
        //memasukkan command
        /*while (input[i]!='\0' && input[i]!=' ') {
            command[i] = input[i];
            i++;
        }
        command[i] = '\0';
        i++;

        int arg_start = 0;
        while (input[i]!='\0' && input[i]!=' ') {
            argument[0][arg_start] = input[i];
            //cout << input[i] << endl;
            //cout << argument[0][i] << endl;
            i++;
            arg_start++;
        }

        argument[0][arg_start] = '\0';
        i++;

        cout << argument[0] << endl;

        arg_start = 0;
        while (input[i]!='\0' && input[i]!=' ') {
            argument[1][i] = input[i];
            i++;
            arg_start++;
        }
        argument[1][arg_start] = '\0';*/

        if(command == "new") {
            //new game
        }
        else if(command == "load") {
            if(argument[0] == "") {
                cout << "argumen kurang" << endl;
            }
            //load game
        }
        else if(command == "sleep") {
            //sleep
        }
        else if(command == "save") {
            //save
        }
        else if(command == "sleep") {
            //sleep
        }


/*----------------------------------------------------------------------------------------------------------------------teleport----------------------------------------------------------------------------------------------------------------------*/
        else if(command == "teleport"){
            if(argument[0] == "") {
                cout << "argumen kurang" << endl;
            }
            //teleport
            //assign state
            if(argument[0] == "kota") {				 //toState  1
                p1.teleport(state, 1, p1.getCurX(), p1.getCurY(), k);
            }//end if kota

			else if((argument[0], "luar")==0) {                      //toState  2
                p1.teleport(state, 2, p1.getCurX(), p1.getCurY(), k);/////////////////////////////////////////////////////////////////////////////////////////

            }//end if luar


            else if((argument[0], "store")==0) {                  //toState  3
                if(state==1){
                    state = 3;

                    //////////////////////////////////////////////////draw store
                }else{
                    cout << "tempat tidak dapat diakses"<<endl;
                }

            }
            else if((argument[0], "stadium")==0) {            //toState  4
                if(state==1){
                    state = 4;

                    //////////////////////////////////////////////////draw stadium
                }else{
                    cout << "tempat tidak dapat diakses"<<endl;
                }

            } else {
                cout << "tidak ada tempat tersebut" << endl;
            }
        }


/*----------------------------------------------------------------------------------------------------------------------sell----------------------------------------------------------------------------------------------------------------------*/
        else if(command == "sell") {
            if(argument[0] == "") {
                cout << "argumen kurang" << endl;
            }else
            if(argument[1] == "") {
                cout << "argumen kurang" << endl;
             }
            else{
                //p1.sell(argument[0],atoi(argument[1]));
            }

            //sell
        }
        else if(command == "buy") {
            if(argument[0] == "") {
                cout << "argumen kurang" << endl;
                break;
            }
            if(argument[1] == "") {
                cout << "argumen kurang" << endl;
                break;
            }
            //buy
        }
        else if(command == "combine") {
            if(argument[0] == "") {
                cout << "argumen kurang" << endl;
                break;
            }
            if(argument[1] == "") {
                cout << "argumen kurang" << endl;
                break;
            }
            //combine
        }
        else if(command == "battle") {
            if(argument[0] == "") {
                cout << "argumen kurang" << endl;
            }
            //battle
        }
        else if(command == "move") {
            if(argument[0] == "") {
                cout << "argumen kurang" << endl;
                break;
            }
            if(argument[1] == "") {
                cout << "argumen kurang" << endl;
                break;
            }
            //move
            int step = atoi(argument[1].c_str());
            p1.move(argument[0],step,k);
            k.setPosisiPlayer(p1.getCurX(), p1.getCurY());
            k.drawScreen(1);

        }
        else if(command == "list-monster") {
            //list-monster
        }
        else if(command == "list-item") {
            //list-item
        }
        else if(command == "status") {
            //status
        }
        else if(command == "set") {
            if(argument[0] == "") {
                cout << "argumen kurang" << endl;
            }
            //set
        }
        else if(command == "dismiss") {
            if(argument[0] == "") {
                cout << "argumen kurang" << endl;
            }
            //dismiss
        }
        else if(command == "help") {
            //help
        }
        else if(command == "exit") {
            //
        }
        else { //command kosong
            cout << "command tidak ada" << endl;
        }

    }//end main

    return 0;
}
