//
//  Item.cpp
//
//
//  Created by Muhammad Sohibul Maromi on 3/15/13.
//
//

#include "Item.h"

Item::Item(int x, string s) {
    harga = x;
    itemName = s;
}

Item::Item(const Item& i) {
    harga = i.harga;
    itemName = i.itemName;
}

Item::~Item() {

}

Item& Item::operator=(const Item& i) {
    harga = i.harga;
    itemName = i.itemName;

    return *this;
}

bool Item::operator==(Item& i){
    return (getItemName()==i.getItemName());
}

string Item::getItemName(){
    return itemName;
}

int Item::getHarga(){
    return harga;
}

void Item::execute() {

}
