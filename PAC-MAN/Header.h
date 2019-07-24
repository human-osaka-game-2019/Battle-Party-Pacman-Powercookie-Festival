#ifndef MAPCHIP
#define MAPCHIP

#include<iostream>
#include<stdio.h>

struct MAPC {

	int Mapchipsnumber;

};

class APNUMBER {
public:

	int num;

};
class MapchipLoading {
public:
	int** mapchip(const char* filename, int Hrow, int Hcol, int** data);
	int textureprint(int** F, int s, int d);
};


#endif // !MAPCHIP