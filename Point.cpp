/*
Sean Logan King
*/

#include <iostream>		//pre processor directive, inputs library commands
#include <time.h> 		//time
#include <stdlib.h>		//srand, rand
#include <iomanip>		//setprecision()
#include <fstream>		//files
#include "Point.h"	//functions for this program
using namespace std;

Point* createPoint(double x1,double y1,double z1){
	Point* p = new Point;		//declares point in heap memory
	p->x = x1;
	p->y = y1;
	p->z = z1;
	
	return p;
}//end of function createPoint

void displayPoint (Point* p){
	cout << "(" << p->x << ", " << p->y << ", " << p->z << ")" << endl;
}//end of function

void destroyPoint (Point* p){
	delete p;
}//end of function