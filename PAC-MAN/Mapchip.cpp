#include <iostream>
#include <string>
#include <fstream>
#include "Mapchip.h"
#include "Main.h"

//int** MapchipLoading::mapchip(const char* filename, int Hrow, int Hcol, int** data) {
//
//	using namespace std;
//	ifstream stream(filename);
//	string line;
//	const string delim = ",";
//
//	int row = 0;
//	int col;
//	while (getline(stream, line)) {
//		col = 0;
//		// delimを区切り文字として切り分け、intに変換してdata[][]に格納する
//		for (string::size_type spos, epos = 0;
//			(spos = line.find_first_not_of(delim, epos)) != string::npos;) {
//			string token = line.substr(spos, (epos = line.find_first_of(delim, spos)) - spos);
//			data[row][col++] = stoi(token);
//		}
//		++row;
//	}
//
//	//                   ↓15が行数、１４が列の数
//	for (row = 0; row < Hrow; ++row) {
//		for (col = 0; col < Hcol; ++col) {
//			cout << data[row][col] << " ";
//		}
//		cout << endl;
//	}
//
//	return data;
//}
//
//int MapchipLoading::textureprint(int** F, int s, int d)
//{
//	for (int i = 0; i < s; i++) {
//		
//		for (int j = 0; j < d; j++)
//		{
//			
//		}
//	}
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//void DrawMap::DrawMapChip()
//{
//	for (int i = 0; i < MAP_SIZE_HEIGHT; i++)
//	{
//		for (int j = 0; j < MAP_SIZE_WIDTH; j++)
//		{
//			int chip_id = g_MapChipList[i][j];
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
//			int width_num = 320 / MAPCHIP_WIDTH;
//			int height_num = 320 / MAPCHIP_HEIGHT;
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
//		}
//	}
//}
//
////マップチップ描画
//int DrawMap::tetureprint(int** f, int k, int d) {
//	for (int i = 0; i < k; i++) {
//		for (int j = 0; j < d; j++) {
//			//描画
//			Draw(0, 0,0xffffffff,0.0f,0.0f,200,200,1.0f,1.0f, g_MapChipList[i][j]);
//		}
//	}
//	return 0;
//}
//
