/* 
 * File:   Point.h
 * Author: haniferidaputra
 *
 * Created on March 14, 2013, 11:40 PM
 */

#ifndef POINT_H
#define	POINT_H
#include <iostream>

using namespace std;
class Point {
    public:
//Konstruktor
        Point();
        Point(int Ta, int Tb);
//Destruktor
        ~Point();
//method get dan set
        int getX();
        int getY();
        void setX(int a);
        void setY(int b);
// Relasional
	int LT (Point P1, Point P2);
// true (bukan 0) jika P1< P2 : absis dan ordinat lebih kecil
// Perhatikan Current_Object tidak dipakai!
	int operator<(Point P1);
// true jika P1< Current_Object : absis dan ordinat lebih kecil
// Perhatikan Current_Object dipakai!
// Predikat lain
	int IsOrigin ();
// mengirim true (1) jika Current_Object =(0,0); false(0)jika bukan Origin
// method
	void mirror ();
	Point Mirrorof ();
	void PrintObj ();

    private:
        int x;
        int y;
};




#endif	/* POINT_H */

