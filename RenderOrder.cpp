/*
Sean Logan King
*/

#include <iostream>		//pre processor directive, inputs library commands
#include <time.h> 		//time
#include <stdlib.h>		//srand, rand
#include <iomanip>		//setprecision()
#include <fstream>		//files
#include <cmath>
#include "Point.h"	//functions for this program
#include "Points.h"
using namespace std;

float distanceFromRefPoint (Point* p, Point* refPoint){
	float x1,y1,z1, distance;
	
	x1 = refPoint->x - p->x;
	y1 = refPoint->y - p->y;
	z1 = refPoint->z - p->z;
	
	distance = pow(x1,2) + pow(y1,2);
	distance = sqrt(distance);
	distance = pow(distance,2) + pow(z1,2);
	distance = sqrt(distance);
	if(distance < 0){
		distance *= -1;
	}//end of if
	return distance;
}//end of function

void sortPointsByDistance (Points* p, Point* refPoint){
	int max;
	Point* temp;
	for(int i = 0; i < p->size; i++){
		max = i;
		for(int i2 = i + 1; i2 < p->size; i2++){
			if(distanceFromRefPoint(p->pointArray[i2],refPoint) > distanceFromRefPoint(p->pointArray[max],refPoint)){
				max = i2;
			}//end of if
		}//end of for
		temp = p->pointArray[max];
		p->pointArray[max] = p->pointArray[i];
		p->pointArray[i] = temp;
	}//end of for
}//end of function

int main(){
	ifstream inputFile;
	string fileName;
	do{
		cout << "Please enter the name of your data file : ";
		cin >> fileName;
		cout << "Attempting to open: " << fileName << endl;
		inputFile.open(fileName.c_str(), ios::in);		//opens file
		if(!inputFile){
			cout << "The designated file does not exist" << endl;//Your program should test for the existence of the supplied point file and warn if it does not exist before asking again.
		}else{
			cout << "File " << fileName << " was found and opened" << endl;
		}//end of else
		inputFile.close();
	}while(!inputFile);
	const char* filename = fileName.c_str();
	Points* testPoints = createPoints(filename);		//creates all points from file
	
	double x,y,z;
	cout << "Enter a refrence point..." << endl;
	cout << "Enter X:";
	cin >> x;
	cout << "Enter Y:";
	cin >> y;
	cout << "Enter Z:";
	cin >> z;
	Point* rp = createPoint(x,y,z);
	cout << "Refrence point: " <<endl;
	displayPoint(rp);
	cout << "Created..." << endl;
	
	
	cout << "Printing points unsorted by refrence point";
	displayPoints(testPoints);
	sortPointsByDistance(testPoints, rp);
	cout << "Printing points sorted by refrence point";
	displayPoints(testPoints);
	delete rp;
	destroyPoints(testPoints);
	return 0;
}//end of main