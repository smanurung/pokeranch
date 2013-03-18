#include "Player.h"
#include "Store.h"
#include "Screen.h"
#include "Item.h"
#include "Potion.h"
#include "Kota.h"s


int main() {

    char input[500];
    char command[100];
    char argument[4][100];
    int state = 0;
    
    while (strcmp(command, "exit")!=0) {        
        cin >> input;
        int i = 0;
        //memasukkan command
        while (input[i]!='\0' && input[i]!=' ') {
            command[i] = input[i];
            i++;
        }
        command[i] = '\0';
        
        while (input[i]!='\0' && input[i]!=' ') {
            argument[0][i] = input[i];
            i++;
        }
        argument[0][i] = '\0';
        
        while (input[i]!='\0' && input[i]!=' ') {
            argument[1][i] = input[i];
            i++;
        }
        argument[1][i] = '\0';
        
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
                state = 1;
            } else if(strcmp(argument[0], "luar")==0) {
                state = 2;
            } else if(strcmp(argument[0], "store")==0) {
                state = 3;
            } else if(strcmp(argument[0], "stadium")==0) {
                state = 4;
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
                                
        switch (state) {
            case 1:
                //kota
                break;
            case 2:
                //luar
                break;
            case 3:
                //store
                break;
            case 4:
                //stadium
                break;
            case 5:
                //battle screen
            case 6:
                //combinatorium
                
            default:
                //home
                break;
        }

    }
    
    
    
    return 0;
}
