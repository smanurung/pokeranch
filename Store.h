#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

#include <iostream>
using namespace std;

class Store{

private:
    int itemAvaliable[10];      // sementara int
//    Screen screenStore;

public:
    Store();
    Store(int[]);
    ~Store();

    void showAvailableItem();
    void printAvailableItem();


}; //end class

#endif // STORE_H_INCLUDED
