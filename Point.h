#if !defined POINT_H_
#define POINT_H_

struct Point{
	double x;
	double y;
	double z;
};		//end of struct

Point* createPoint (double x, double y, double z);
void displayPoint (Point* p);
void destroyPoint (Point* p);

#endif