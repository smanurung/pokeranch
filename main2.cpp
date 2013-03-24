#include "Player.h"
#include "Store.h"
#include "Screen.h"
#include "Item.h"
#include "Potion.h"
#include "Kota.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>

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
		/*while (isiFile[idx].compare(END_ITEM)){
			if (!isiFile[idx].compare("potion")) {
				idx += 1;
				string potAttr = isiFile[idx];
				
				//Potion _pot();
			}
		}*/
		
	} else {
		cout << ">>Warning!! File tidak bisa dibuka" << endl;
	}
	
	f.close();
}

int main() {
    char input[500];
    char command[100];
    char argument[4][100];
    int state = 0;

    Player p1;
	parseFile(p1);
	
	cout << p1.getNama() << endl;
	cout << p1.getUang() << endl;
	
    Kota k(p1.getCurX(),p1.getCurY());
	
	cout << "---POKERANCH---" << endl;

    while (strcmp(command, "exit")!=0) {
		cout << "command :";
        gets(input);
        //cout << input << endl;
        //cin >> input;
        int i = 0;
        //memasukkan command
        while (input[i]!='\0' && input[i]!=' ') {
            command[i] = input[i];
            i++;
        }
        command[i] = '\0';
        //argument[0][i] = '\0';
//        cout << command << endl;
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
        argument[1][arg_start] = '\0';

        if(strcmp(command, "new")==0) {
            //new game
        } else if(strcmp(command, "load")==0) {
            if(strcmp(argument[0], "")==0) {
                cout << "argumen kurang" << endl;
            }
            //load game
        } else if(strcmp(command, "sleep")==0) {
            //sleep
        } else if(strcmp(command, "save")==0) {
            //save
        } else if(strcmp(command, "sleep")==0) {
            //sleep
        } else if(strcmp(command, "teleport")==0) {
            if(strcmp(argument[0], "")==0) {
                cout << "argumen kurang" << endl;
            }
            //teleport
            //assign state
            if(strcmp(argument[0], "kota")==0) {
                state = p1.teleport(state,0,0);
                if(state==1){
                    k.drawScreen(1);
                }else{
                    cout << "gagal"<<endl;
                }

            } else if(strcmp(argument[0], "luar")==0) {
                state = p1.teleport(state,0,0);
                if(state==2){


                    //////////////////////////////////////////////////draw luar
                }else{
                    cout << "tempat tidak dapat diakses"<<endl;
                }

            } else if(strcmp(argument[0], "store")==0) {
                if(state==1){
                    state = 3;

                    //////////////////////////////////////////////////draw store
                }else{
                    cout << "tempat tidak dapat diakses"<<endl;
                }

            } else if(strcmp(argument[0], "stadium")==0) {
                if(state==1){
                    state = 4;

                    //////////////////////////////////////////////////draw stadium
                }else{
                    cout << "tempat tidak dapat diakses"<<endl;
                }

            } else {
                cout << "tidak ada tempat tersebut" << endl;
            }
        } else if(strcmp(command, "sell")==0) {
            if(strcmp(argument[0], "")==0) {
                cout << "argumen kurang" << endl;
                break;
            }
            if(strcmp(argument[1], "")==0) {
                cout << "argumen kurang" << endl;
                break;
            }
            //sell
        } else if(strcmp(command, "buy")==0) {
            if(strcmp(argument[0], "")==0) {
                cout << "argumen kurang" << endl;
                break;
            }
            if(strcmp(argument[1], "")==0) {
                cout << "argumen kurang" << endl;
                break;
            }
            //buy
        } else if(strcmp(command, "combine")==0) {
            if(strcmp(argument[0], "")==0) {
                cout << "argumen kurang" << endl;
                break;
            }
            if(strcmp(argument[1], "")==0) {
                cout << "argumen kurang" << endl;
                break;
            }
            //combine
        } else if(strcmp(command, "battle")==0) {
            if(strcmp(argument[0], "")==0) {
                cout << "argumen kurang" << endl;
            }
            //battle
        } else if(strcmp(command, "move")==0) {
            if(strcmp(argument[0], "")==0) {
                cout << "argumen kurang" << endl;
                break;
            }
            if(strcmp(argument[1], "")==0) {
                cout << "argumen kurang" << endl;
                break;
            }
            //move
            int step = atoi(argument[1]);
            p1.move(argument[0],step,k);
            k.setPosisiPlayer(p1.getCurX(), p1.getCurY());
            k.drawScreen(1);

        } else if(strcmp(command, "list-monster")==0) {
            //list-monster
        } else if(strcmp(command, "list-item")==0) {
            //list-item
        } else if(strcmp(command, "status")==0) {
            //status
        } else if(strcmp(command, "set")==0) {
            if(strcmp(argument[0], "")==0) {
                cout << "argumen kurang" << endl;
            }
            //set
        } else if(strcmp(command, "dismiss")==0) {
            if(strcmp(argument[0], "")==0) {
                cout << "argumen kurang" << endl;
            }
            //dismiss
        } else if(strcmp(command, "help")==0) {
            //help
        } else if(strcmp(command, "exit")==0) {
            //
        } else {
            cout << "command tidak ada" << endl;
        }



    }//end main



    return 0;
}