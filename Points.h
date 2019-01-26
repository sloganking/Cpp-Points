#if !defined POINTS_H_
#define POINTS_H_
#include "Point.h"

struct Points{
	Point** pointArray;
	int size;
};		//end of struct

Points* createPoints (const char* filename);
void displayPoints (Points* p);
void destroyPoints (Points* p);

#endif