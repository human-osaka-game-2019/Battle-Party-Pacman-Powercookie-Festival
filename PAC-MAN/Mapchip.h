#ifndef MAPCHIP
#define MAPCHIP

#include<iostream>
#include<stdio.h>

#define MAP_SIZE_WIDTH (10)		// MAPの横幅(値はチップ数)
#define MAP_SIZE_HEIGHT (5)		// MAPの縦幅(値はチップ数)
#define MAPCHIP_WIDTH (64)		// マップチップの横幅
#define MAPCHIP_HEIGHT (64)		// マップチップの縦幅


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
class DrawMap {

	void DrawMapChip();
	int g_MapChipList[30][30] = {0};

};
	
	
	

#endif // !MAPCHIP