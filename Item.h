//
//  Item.h
//
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#ifndef ____Item__
#define ____Item__

#include <string>
#include <iostream>
using namespace std;

class Item {
public:
    Item(int = 0, string = "noname");
    Item(const Item&);
    ~Item();
    Item& operator=(const Item&);

    bool operator==(Item&);                              //ditambah JO
    string getItemName();                                   //ditambah JO
    int getHarga();                                                //ditambah JO

    void execute();

private:
    int harga;
    string itemName;
};

#endif /* defined(____Item__) */
