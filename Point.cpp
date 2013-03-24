/* 
 * File:   Point.cpp
 * Author: haniferidaputra
 * 
 * Created on March 14, 2013, 11:40 PM
 */

#include "point.h"


//constructor
Point :: Point(){}

Point :: Point(int Ta, int Tb){
    x = Ta;
    y = Tb;
}

Point :: ~Point(){
    //cout << "dtor.." << endl;
}

int Point :: getX(){
    return x;
}

int Point :: getY(){
    return y;
}

void Point :: setX(int a){
    x = a;
}

void Point :: setY(int b){
    y = b;
}

int Point::LT (Point P1, Point P2){
// true (bukan 0) jika P1< P2 : absis dan ordinat lebih kecil
// Perhatikan Current_Object tidak dipakai!
	return (P1.getX() < P2.getX()) && (P1.getY() < P2.getY());
}
int Point::operator< (Point P1){
// true jika P1< Current_Object : absis dan ordinat lebih kecil
// Perhatikan Current_Object dipakai!
	return( (P1.getX() < x) && (P1.getY() < y));
}
// Predikat lain
int Point::IsOrigin (){
	return (x == 0 && y == 0);
}
/* method */
void Point::mirror (){
	x = -x;
	y = -y;
}
Point Point::Mirrorof (){
	int tmpx = -x;
	int tmpy = -y;
	return (Point (tmpx, tmpy));
}
void Point::PrintObj (){
	cout << "P=(" << x << "," << y << ")" << endl;
}
