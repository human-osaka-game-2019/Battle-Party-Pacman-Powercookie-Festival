#include <iostream>
#include <string>
#include <fstream>
#include "Mapchip.h"
#include "Main.h"

int** MapchipLoading::mapchip(const char* filename, int Hrow, int Hcol, int** data) {

	using namespace std;
	ifstream stream(filename);
	string line;
	const string delim = ",";

	int row = 0;
	int col;
	while (getline(stream, line)) {
		col = 0;
		// delimを区切り文字として切り分け、intに変換してdata[][]に格納する
		for (string::size_type spos, epos = 0;
			(spos = line.find_first_not_of(delim, epos)) != string::npos;) {
			string token = line.substr(spos, (epos = line.find_first_of(delim, spos)) - spos);
			data[row][col++] = stoi(token);
		}
		++row;
	}

	//                   ↓15が行数、１４が列の数
	for (row = 0; row < Hrow; ++row) {
		for (col = 0; col < Hcol; ++col) {
			cout << data[row][col] << " ";
		}
		cout << endl;
	}

	return data;
}

int MapchipLoading::textureprint(int** F, int s, int d)
{
	for (int i = 0; i < s; i++) {
		
		for (int j = 0; j < d; j++)
		{
			
		}
	}

	return 0;
}






//
//
//
////640
//void DrawMap::DrawMapChip()
//{
//	for (int i = 0; i < MAP_SIZE_HEIGHT; i++)
//	{
//		for (int j = 0; j < MAP_SIZE_WIDTH; j++)
//		{
//			int chip_id = a[i][j];
//			if (chip_id == 0)
//			{
//				continue;
//			}
//
//			// テクスチャのサイズとマップチップのサイズから横と縦のチップ数を割り出す
//			// (int)g_TextureList[TextureId::MapChip].m_Width       テクスチャのwidth
//			//(int)g_TextureList[TextureId::MapChip].m_Height       テクスチャのheight
//			//MAPCHIP_WIDTH                                         マップチップの１つのwidth大きさ
//			//MAPCHIP_HEIGHT                                        マップチップの１つのheight大きさ
//			int width_num = TEXTURE_WIDTH / MAPCHIP_WIDTH;
//			int height_num = TEXTURE_HEIGHT / MAPCHIP_HEIGHT;
//
//			////表示したい一つのtextureの大きさ
//			//float y = (float)(TEXTURE_CHIP_WIDTH / MAPCHIP_WIDTH);
//			//float u = (float)(TEXTURE_CHIP_HEIGHT / MAPCHIP_HEIGHT);
//
//			// chip_idからチップのテクスチャ座標を割り出す
//			// チップの描画
//			//chip_pos_x                                            左上のtuの位置
//			//chip_pos_y                                            左上のtvの位置
//			//MAPCHIP_WIDTH                                         一マスのwidth大きさ
//			//MAPCHIP_HEIGHT                                        一マスのheight大きさ
//			float chip_pos_x = (float)(chip_id % width_num) * MAPCHIP_WIDTH;
//			float chip_pos_y = (float)(chip_id / height_num) * MAPCHIP_HEIGHT;
//
//			DrawMap::tetureprint(MAPCHIP_WIDTH * j, MAPCHIP_HEIGHT * i,MAPCHIP_WIDTH,MAPCHIP_HEIGHT,chip_pos_x / TEXTURE_WIDTH,chip_pos_y / TEXTURE_HEIGHT, MAPCHIP_WIDTH / TEXTURE_WIDTH, MAPCHIP_HEIGHT / TEXTURE_HEIGHT);
//		}
//	}
//}
//
////マップチップ描画
//int DrawMap::tetureprint(int drawpos_x,int drawpos_y,int mapcip_width,int mapchip_height,float chip_pos_x,float chip_pos_y,float width_num,float height_num) {
//	
//			Draw( drawpos_x, drawpos_y,0xffffffff,chip_pos_x,chip_pos_y,mapcip_width,mapchip_height,width_num,height_num,TEST_MAPCHIP);
//		
//	return 0;
//}
//
//
//






void DrawMap::DrawMapChip(int map_size_width,int map_size_height,float texture_width,float texture_height,float mapchip_width,float mapchip_height,float draw_width,float draw_height,float draw_pos_x,float draw_pos_y, int texture,int** map)
{
	for (int i = 0; i < map_size_height; i++)
	{
		for (int j = 0; j < map_size_width; j++)
		{
			int chip_id = map[i][j];
			if (chip_id == 0)
			{
				continue;
			}

			// テクスチャのサイズとマップチップのサイズから横と縦のチップ数を割り出す
			// (int)g_TextureList[TextureId::MapChip].m_Width       テクスチャのwidth
			//(int)g_TextureList[TextureId::MapChip].m_Height       テクスチャのheight
			//MAPCHIP_WIDTH                                         マップチップの１つのwidth大きさ
			//MAPCHIP_HEIGHT                                        マップチップの１つのheight大きさ
			int width_num = texture_width / mapchip_width;
			int height_num = texture_height / mapchip_height;

			// chip_idからチップのテクスチャ座標を割り出す
			// チップの描画
			//chip_pos_x                                            左上のtuの位置
			//chip_pos_y                                            左上のtvの位置
			//MAPCHIP_WIDTH                                         一マスのwidth大きさ
			//MAPCHIP_HEIGHT                                        一マスのheight大きさ
			float chip_pos_x = (float)(chip_id % width_num) * mapchip_width;
			float chip_pos_y = (float)(chip_id / height_num) * mapchip_height;

			DrawMap::textureprint(draw_pos_x + draw_width * j, draw_pos_y + draw_height * i, draw_width, draw_height, chip_pos_x / texture_width, chip_pos_y / texture_height, mapchip_width / texture_width, mapchip_height / texture_height,texture);
		}
	}
}

//マップチップ描画
void DrawMap::textureprint(int drawpos_x, int drawpos_y, int mapcip_width, int mapchip_height, float chip_pos_x, float chip_pos_y, float width_num, float height_num,int texture) {

	Draw(drawpos_x, drawpos_y, 0xffffffff, chip_pos_x, chip_pos_y, mapcip_width, mapchip_height, width_num, height_num, texture,0);

}


void DrawMap::InitMap()
{
	int init_left_map[31][28] =
	{ 5,	2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	25,	26,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,	 2,	 6,
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
	   2,   2,	 2,	 2,	 2,	16,	35,	24,	23,  0,	 3,	 0,  0,	 0,	 0,	 0,  0,	 1,	 0,	24,	23,	35,	14,	 2,  2,	 2,	 2,	 2,
	   0,	0,	 0,	 0,	 0,	 0,	35,	 0,	 0,  0,	 3,	 0,  0,	 0,  0,  0,  0,	 1,	 0,	 0,	 0,	35,	 0,	 0,  0,	 0,	 0,	 0,
	   4,   4,	 4,	 4,	 4,	15,	35,	21,	22,  0,	 3,	 0,	 0,  0,  0,  0,  0,  1,	 0,	21,	22,	35,	13,	 4,  4,	 4,	 4,	 4,
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




	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			left_map[j][i] = init_left_map[j][i];
		}
	}

	int init_right_map[31][28] =
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

	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			right_map[j][i] = init_right_map[j][i];
		}
	}

}


