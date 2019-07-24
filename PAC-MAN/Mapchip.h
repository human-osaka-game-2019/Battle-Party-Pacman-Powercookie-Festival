#ifndef MAPCHIP
#define MAPCHIP

#include<iostream>
#include<stdio.h>

#define MAP_SIZE_WIDTH (10)		// MAPの横幅(値はチップ数)
#define MAP_SIZE_HEIGHT (10)		// MAPの縦幅(値はチップ数)
#define MAPCHIP_WIDTH (32)		// マップチップの横幅
#define MAPCHIP_HEIGHT (32)		// マップチップの縦幅


class MapchipLoading {
public:
	int** mapchip(const char* filename, int Hrow, int Hcol, int** data);
	int textureprint(int** F, int s, int d);
};





class DrawMap {

public:

	void DrawMapChip();
	
	int tetureprint(int** f, int k, int d);

	int g_MapChipList[15][14] = { 0 };

};
	
	
	

#endif // !MAPCHIP