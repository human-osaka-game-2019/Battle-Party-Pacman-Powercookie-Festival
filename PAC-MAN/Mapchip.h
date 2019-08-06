﻿#ifndef MAPCHIP
#define MAPCHIP

#include<iostream>
#include<stdio.h>



class MapchipLoading {
public:
	int** mapchip(const char* filename, int Hrow, int Hcol, int** data);
	int textureprint(int** F, int s, int d);
};


struct mapp {
	int num;
	int tex;
};


class DrawMap {

public:

	void DrawMapChip(int map_size_width, int map_size_height, float texture_width, float texture_height, float mapchip_width, float mapchip_height, float draw_width, float draw_height, float draw_pos_x, float draw_pos_y, int texture);
	
	void textureprint(int drawpos_x,int drawpos_y, int mapcip_width, int mapchip_height, float chip_pos_x, float chip_pos_y,float width_num,float height_num, int texture);

 int left_map[31][28] = 
{  5,   2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	25,	26,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,	 2,	 6,
   1,  35,	35,	35,	35,	35,	35,	35,	35, 35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	 3,
   1,  35,	17,  4,	 4,	18,	35,	17,	 4,  4,	 4,	18,	35,	11,	 9,	35,	17,	 4,	 4,	 4,	18,	35,	17,	 4,	 4,	18,	35,	 3,
   1,  38,	 3,	 0,	 0,	 1,	35,	 3,	 0,  0,	 0,	 1,	35,	11,	 9,	35,	 3,	 0,	 0,	 0,	 1,	35,	 3,	 0,	 0,	 1,	38,	 3,
   1,  35,	20,	36,	36,	19,	35,	20,	36, 36,	36,	19,	35,	24,	23,	35,	20,	36,	36,	36,	19,	35,	20,	36,	36,	19,	35,	 3,
   1,  35,	35,	35,	35,	35,	35,	35,	35, 35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	 3,
   1,  35,	21,	12,	12,	22,	35,	21,	22, 35,	21,	12,	12,	12,	12,	12,	12,	22,	35,	21,	22,	35,	21,	12,	12,	22,	35,	 3,
   1,  35,	24,	10,	10,	23,	35,	11,	 9, 35,	24,	10,	10,	31,	32,	10,	10,	23,	35,	11,	 9,	35,	24,	10,	10,	23,	35,	 3,
   1,  35,	35,	35,	35,	35,	35,	11,	 9, 35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	35,	35,	 3,
   8,   4,	 4,	 4,	 4,	15,	35,	11,	33, 12,	12,	22,	 0,	11,	 9,	 0,	21,	12,	12,	34,	 9,	35,	13,	 4,  4,	 4,	 4,	 7,
   0,   0,	 0,	 0,	 0,	 1,	35,	11,	32, 10,	10,	23,	 0,	24,	23,	 0,	24,	10,	10,	31,	 9,	35,	3,	 0,  0,  0,  0,  0,
   0,   0,	 0,	 0,	 0,	 1,	35,	11,	 9,  0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	11,	 9,	35,	3,	 0,  0,  0,  0,  0,
   0,   0,	 0,	 0,	 0,	 1,	35,	11,	 9,  0,	17,	 4,	 4,	37,	37,	 4,	 4,	18,	 0,	11,	 9,	35,	3,	 0,  0,  0,  0,  0,
   2,   2,	 2,	 2,	 2,	16,	35,	24,	23,  0,	 3,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	24,	23,	35,	14,	 2,  2,	 2,	 2,	 2,
   0,   0,	 0,	 0,	 0,	 0,	35,	 0,	 0,  0,	 3,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	35,	 0,	 0,  0,	 0,	 0,	 0,
   4,   4,	 4,	 4,	 4,	15,	35,	21,	22,  0,	 3,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	21,	22,	35,	13,	 4,  4,	 4,	 4,	 4,
   0,   0,	 0,	 0,	 0,	 1,	35,	11,	 9,  0,	20,	 2,	 2,	 2,	 2,	 2,	 2,	19,	 0,	11,	 9,	35,	3,	 0,  0,  0,  0,  0,
   0,   0,	 0,	 0,	 0,	 1,	35,	11,	 9,  0,	 0,	 0,	 0,  0,	 0,	 0,	 0,	 0,	 0,	11,	 9,	35,	3,	 0,  0,  0,  0,  0,
   0,   0,	 0,	 0,	 0,	 1,	35,	11,	 9,  0,	21,	12,	12,	12,	12,	12,	12,	22,	 0,	11,	 9,	35,	3,	 0,  0,  0,  0,  0,
   5,   2,	 2,	 2,	 2,	16,	35,	24,	23,  0,	24,	10,	10,	31,	32,	10,	10,	23,	 0,	24,	23,	35,	14,	 2,  2,	 2,	 2,	 6,
   1,  35,	35, 35,	35,	35,	35,	35,	35, 35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	 3,
   1,  35,	21, 12,	12,	22,	35,	21,	12, 12,	12,	22,	35,	11,	 9,	35,	21,	12,	12,	12,	22,	35,	21,	12,	12,	22,	35,	 3,
   1,  35,	24, 10,	31,	 9,	35,	24,	10, 10,	10,	23,	35,	24,	23,	35,	24,	10,	10,	10,	23,	35,	11,	32,	10,	23,	35,	 3,
   1,  38,	35, 35,	11,	 9,	35,	35,	35, 35,	35,	35,	35,	 0,	 0,	35,	35,	35,	35,	35,	35,	35,	11,	 9,	35,	35,	38,	 3,
  29,  12,	22, 35,	11,	 9,	35,	21,	22, 35,	21,	12,	12,	12,	12,	12,	12,	22,	35,	21,	22,	35,	11,	 9,	35,	21,	12,	27,
  30,  10,	23, 35,	24,	23,	35,	11,	 9, 35,	24,	10,	10,	31,	32,	10,	10,	23,	35,	11,	 9,	35,	24,	23,	35,	24,	10,	28,
   1,  35,	35, 35,	35,	35,	35,	11,	 9, 35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	35,	35,	 3,
   1,  35,	21, 12,	12,	12,	12,	34,	33, 12,	12,	22,	35,	11,	 9,	35,	21,	12,	12,	34,	33,	12,	12,	12,	12,	22,	35,	 3,
   1,  35,	24, 10,	10,	10,	10,	10,	10, 10,	10,	23,	35,	24,	23,	35,	24,	10,	10,	10,	10,	10,	10,	10,	10,	23,	35,	 3,
   1,  35,	35, 35,	35,	35,	35,	35,	35, 35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	 3,
   8,   4,	 4,	 4,  4,	 4,	 4,	 4,	 4,  4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 7, };
  							  




	int right_map[31][28] =
	{ 5,   2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	25,	26,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,	 2,	 6,
	   1,  35,	35,	35,	35,	35,	35,	35,	35, 35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	 3,
	   1,  35,	17,  4,	 4,	18,	35,	17,	 4,  4,	 4,	18,	35,	11,	 9,	35,	17,	 4,	 4,	 4,	18,	35,	17,	 4,	 4,	18,	35,	 3,
	   1,  38,	 3,	 0,	 0,	 1,	35,	 3,	 0,  0,	 0,	 1,	35,	11,	 9,	35,	 3,	 0,	 0,	 0,	 1,	35,	 3,	 0,	 0,	 1,	38,	 3,
	   1,  35,	20,	36,	36,	19,	35,	20,	36, 36,	36,	19,	35,	24,	23,	35,	20,	36,	36,	36,	19,	35,	20,	36,	36,	19,	35,	 3,
	   1,  35,	35,	35,	35,	35,	35,	35,	35, 35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	 3,
	   1,  35,	21,	12,	12,	22,	35,	21,	22, 35,	21,	12,	12,	12,	12,	12,	12,	22,	35,	21,	22,	35,	21,	12,	12,	22,	35,	 3,
	   1,  35,	24,	10,	10,	23,	35,	11,	 9, 35,	24,	10,	10,	31,	32,	10,	10,	23,	35,	11,	 9,	35,	24,	10,	10,	23,	35,	 3,
	   1,  35,	35,	35,	35,	35,	35,	11,	 9, 35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	35,	35,	 3,
	   8,   4,	 4,	 4,	 4,	15,	35,	11,	33, 12,	12,	22,	 0,	11,	 9,	 0,	21,	12,	12,	34,	 9,	35,	13,	 4,  4,	 4,	 4,	 7,
	   0,   0,	 0,	 0,	 0,	 9,	35,	11,	32, 10,	10,	23,	 0,	24,	23,	 0,	24,	10,	10,	31,	 9,	35,	11,	 0,  0,  0,  0,  0,
	   0,   0,	 0,	 0,	 0,	 9,	35,	11,	 9,  0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	11,	 9,	35,	11,	 0,  0,  0,  0,  0,
	   0,   0,	 0,	 0,	 0,	 9,	35,	11,	 9,  0,	17,	 4,	 4,	37,	37,	 4,	 4,	18,	 0,	11,	 9,	35,	11,	 0,  0,  0,  0,  0,
	   2,   2,	 2,	 2,	 2,	16,	35,	24,	23,  0,	 3,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	24,	23,	35,	14,	 2,  2,	 2,	 2,	 2,
	   0,   0,	 0,	 0,	 0,	 0,	35,	 0,	 0,  0,	 3,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	35,	 0,	 0,  0,	 0,	 0,	 0,
	   4,   4,	 4,	 4,	 4,	15,	35,	21,	22,  0,	 3,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	21,	22,	35,	13,	 4,  4,	 4,	 4,	 4,
	   0,   0,	 0,	 0,	 0,	 9,	35,	11,	 9,  0,	20,	 2,	 2,	 2,	 2,	 2,	 2,	19,	 0,	11,	 9,	35,	11,	 0,  0,  0,  0,  0,
	   0,   0,	 0,	 0,	 0,	 9,	35,	11,	 9,  0,	 0,	 0,	 0,  0,	 0,	 0,	 0,	 0,	 0,	11,	 9,	35,	11,	 0,  0,  0,  0,  0,
	   0,   0,	 0,	 0,	 0,	 9,	35,	11,	 9,  0,	21,	12,	12,	12,	12,	12,	12,	22,	 0,	11,	 9,	35,	11,	 0,  0,  0,  0,  0,
	   5,   2,	 2,	 2,	 2,	16,	35,	24,	23,  0,	24,	10,	10,	31,	32,	10,	10,	23,	 0,	24,	23,	35,	14,	 2,  2,	 2,	 2,	 6,
	   1,  35,	35, 35,	35,	35,	35,	35,	35, 35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	 3,
	   1,  35,	21, 12,	12,	22,	35,	21,	12, 12,	12,	22,	35,	11,	 9,	35,	21,	12,	12,	12,	22,	35,	21,	12,	12,	22,	35,	 3,
	   1,  35,	24, 10,	31,	 9,	35,	24,	10, 10,	10,	23,	35,	24,	23,	35,	24,	10,	10,	10,	23,	35,	11,	32,	10,	23,	35,	 3,
	   1,  38,	35, 35,	11,	 9,	35,	35,	35, 35,	35,	35,	35,	 0,	 0,	35,	35,	35,	35,	35,	35,	35,	11,	 9,	35,	35,	38,	 3,
	  29,  12,	22, 35,	11,	 9,	35,	21,	22, 35,	21,	12,	12,	12,	12,	12,	12,	22,	35,	21,	22,	35,	11,	 9,	35,	21,	12,	27,
	  30,  10,	23, 35,	24,	23,	35,	11,	 9, 35,	24,	10,	10,	31,	32,	10,	10,	23,	35,	11,	 9,	35,	24,	23,	35,	24,	10,	28,
	   1,  35,	35, 35,	35,	35,	35,	11,	 9, 35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	11,	 9,	35,	35,	35,	35,	35,	35,	 3,
	   1,  35,	21, 12,	12,	12,	12,	34,	33, 12,	12,	22,	35,	11,	 9,	35,	21,	12,	12,	34,	33,	12,	12,	12,	12,	22,	35,	 3,
	   1,  35,	24, 10,	10,	10,	10,	10,	10, 10,	10,	23,	35,	24,	23,	35,	24,	10,	10,	10,	10,	10,	10,	10,	10,	23,	35,	 3,
	   1,  35,	35, 35,	35,	35,	35,	35,	35, 35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	35,	 3,
	   8,   4,	 4,	 4,  4,	 4,	 4,	 4,	 4,  4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 4,	 7, };
};
	

	
	

#endif // !MAPCHIP