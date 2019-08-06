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

