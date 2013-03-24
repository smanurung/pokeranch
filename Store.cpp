#include "Store.h"

Store::Store(){
    for(int j=0; j<10;j++){
            itemAvaliable[j]=0;
    }
}

Store::Store(int* i){

    for(int j=0; j<10;j++){
        itemAvaliable[j]=i[j];
    }

}

Store::~Store(){
	
}

void Store::printAvailableItem(){
    for(int j=0; j<10;j++){
        cout<< itemAvaliable[j]<<endl;
    }
}

void Store::drawStore(){
	this->screenStore.drawScreen(3);
}