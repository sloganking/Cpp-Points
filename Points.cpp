/*
Sean Logan King
*/

#include <iostream>		//pre processor directive, inputs library commands
#include <time.h> 		//time
#include <stdlib.h>		//srand, rand
#include <iomanip>		//setprecision()
#include <fstream>		//files
#include "Point.h"	//functions for this program
#include "Points.h"
using namespace std;

Points* createPoints (const char* filename){
	
	ifstream inputFile;
	inputFile.open(filename, ios::in);		//opens file		.c_str()
	
	int amount;	//for file for loop
	inputFile >> amount;	//grabs amount
	
	Points* ps = new Points;		//create points  (with appropriate size)
	Point** arrayOfPoints = new Point*[amount];
	ps-> pointArray = arrayOfPoints;
	ps->size = amount;
	for(int i = 0; i < amount; i++){
		cout << "i: " << i << endl;
		double x, y, z;
		inputFile >> x;
		inputFile >> y;
		inputFile >> z;
		cout << x << "," << y << "," << z << endl;
		
		ps->pointArray[i] = createPoint(x,y,z);
	}//end of for
	inputFile.close();
	
	return ps;
}//end of function createPoints

void displayPoints (Points* p){
	cout << "Points..." << endl;
	for(int i = 0; i < p->size; i++){
		displayPoint(p->pointArray[i]);
	}//end of for
	cout << "Done displaying points" << endl;
}//end of function DisplayPoints

void destroyPoints (Points* p){
	for(int i = 0; i < p->size; i++){
		destroyPoint (p->pointArray[i]);
	}//end of for
	delete p;
	cout << "Points deleted...";
}//end of function destroyPoints