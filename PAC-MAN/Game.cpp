#include "Game.h"

MapchipLoading Mp;
DrawMap map;

Game::SCENE_PAHSE Phase = Game::LOAD;

float a_pink_ghost_tu = 0.0f;
float b_pink_ghost_tu = (64.0f * 2.0f) / 512.0f;
float c_pink_ghost_tu = (64.0f * 4.0f) / 512.0f;
float d_pink_ghost_tu = (64.0f * 6.0f) / 512.0f;
float a_blue_ghost_tu = 0.0f;
float b_blue_ghost_tu = (64.0f * 2.0f) / 512.0f;
float c_blue_ghost_tu = (64.0f * 4.0f) / 512.0f;
float d_blue_ghost_tu = (64.0f * 6.0f) / 512.0f;
float blue_ghost_tv = 64.0f / 512.0f;

float right_pacman_x = 800.0f;
float right_pacman_y = 16.0f;
float left_pacman_x = 16.0f;
float left_pacman_y = 16.0f;

int flamecount = 0;

float s = 0;

//ゲームのフェーズの移動
void Game::Game_Scene() {

	switch (Phase) {
	case LOAD:
		Loading();
		break;
	case PROCESSING:
		Process();
		break;
	case RELEASES:
		Release();
		Phase = LOAD;
		break;
	}
}

//ゲームのテクスチャの読み込み
void Game::Loading() {

	LoadTexture("map_test.png", TEST_MAPCHIP);
	LoadTexture("Pacman.png", PACMAN);
	LoadTexture("Ghost.png", GHOST);

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {

	flamecount++;

	map.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, 0.0f);

	map.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 448.f + 160.0f, 0.0f);

	Draw(left_pacman_x,left_pacman_y,0xffffffff,0.0f,0.0f,16,16,1.0f,1.0f,PACMAN);

	Draw(right_pacman_x, right_pacman_y, 0xffffffff, 0.0f, 0.0f, 16, 16, 1.0f, 1.0f, PACMAN);
		








	




	////ピンクゴースト
	//Draw(0, 200, 0xffffffff, a_pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//Draw(0, 300, 0xffffffff, b_pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//Draw(100, 200, 0xffffffff, c_pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//Draw(100, 300, 0xffffffff, d_pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	////ブルーゴースト
	//Draw(200, 200, 0xffffffff, a_blue_ghost_tu, blue_ghost_tv, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//Draw(200, 300, 0xffffffff, b_blue_ghost_tu, blue_ghost_tv, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//Draw(300, 200, 0xffffffff, c_blue_ghost_tu, blue_ghost_tv, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//Draw(300, 300, 0xffffffff, d_blue_ghost_tu, blue_ghost_tv, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);

	////ピンクゴーストアニメーション
	//a_pink_ghost_tu += 64.0f / 512.0f;
	//b_pink_ghost_tu += 64.0f / 512.0f;
	//c_pink_ghost_tu += 64.0f / 512.0f;
	//d_pink_ghost_tu += 64.0f / 512.0f;
	//if (a_pink_ghost_tu >= (64.0f * 2.0f) / 512.0f)
	//{
	//	a_pink_ghost_tu = 0.0f;
	//}
	//if (b_pink_ghost_tu >= (64.0f * 4.0f) / 512.0f)
	//{
	//	b_pink_ghost_tu = (64.0f * 2.0f) / 512.0f;
	//}
	//if (c_pink_ghost_tu >= (64.0f * 6.0f) / 512.0f)
	//{
	//	c_pink_ghost_tu = (64.0f * 4.0f) / 512.0f;
	//}
	//if (d_pink_ghost_tu >= (64.0f * 8.0f) / 512.0f)
	//{
	//	d_pink_ghost_tu = (64.0f * 6.0f) / 512.0f;
	//}
	////ブルーゴーストアニメーション
	//a_blue_ghost_tu += 64.0f / 512.0f;
	//b_blue_ghost_tu += 64.0f / 512.0f;
	//c_blue_ghost_tu += 64.0f / 512.0f;
	//d_blue_ghost_tu += 64.0f / 512.0f;
	//if (a_blue_ghost_tu >= (64.0f * 2.0f) / 512.0f)
	//{
	//	a_blue_ghost_tu = 0;
	//}
	//if (b_blue_ghost_tu >= (64.0f * 4.0f) / 512.0f)
	//{
	//	b_blue_ghost_tu = (64.0f * 2.0f) / 512.0f;
	//}
	//if (c_blue_ghost_tu >= (64.0f * 6.0f) / 512.0f)
	//{
	//	c_blue_ghost_tu = (64.0f * 4.0f) / 512.0f;
	//}
	//if (d_blue_ghost_tu >= (64.0f * 8.0f) / 512.0f)
	//{
	//	d_blue_ghost_tu = (64.0f * 6.0f) / 512.0f;
	//}




	


#ifdef R_H
#define R_H
	if (dx.KeyState[DIK_K] == dx.PRESS) {
		s += 0.25f;
		if (s == 1.0f) {
			s = 0.0f;
		}
	}

	Draw(210, 0, 0xffffffff, s, 0.0f, 200, 200, 0.25f, 0.5f, PACMAN);
	Draw(210, 210, 0xffffffff, s, 0.5f, 200, 200, 0.25f, 0.5f, PACMAN);

#endif

	if (dx.KeyState[DIK_UP] == dx.PRESS) {
		left_savekey = UP;
	}
	if (dx.KeyState[DIK_DOWN] == dx.PRESS) {
		left_savekey = DOWN;
	}
	if (dx.KeyState[DIK_LEFT] == dx.PRESS) {
		left_savekey = LEFT;
	}
	if (dx.KeyState[DIK_RIGHT] == dx.PRESS) {		
		left_savekey = RIGHT;
	}
	
	if (dx.KeyState[DIK_W] == dx.PRESS) {
		right_savekey = UP;
	}
	if (dx.KeyState[DIK_S] == dx.PRESS) {
		right_savekey = DOWN;
	}
	if (dx.KeyState[DIK_A] == dx.PRESS) {
		right_savekey = LEFT;
	}
	if (dx.KeyState[DIK_D] == dx.PRESS) {
		right_savekey = RIGHT;
	}

	int* array_left_map[31];
	int* array_right_map[31];

	for (int i = 0; i < 31;i++) {
		array_left_map[i] = map.left_map[i];

	}

	for (int i = 0; i < 31; i++) {
		array_right_map[i] = map.right_map[i];

	}

	switch (right_savekey) {
	case LEFT:
		right_row = 0;
		right_col = -1;
		break;
	case RIGHT:
		right_row = 0;
		right_col = 1;
		break;
	case UP:
		right_row = -1;
		right_col = 0;
		break;
	case DOWN:
		right_row = 1;
		right_col = 0;
		break;
	case STOP:

		break;
	default:

		break;
	}

	switch (left_savekey) {
	case LEFT:
		left_row = 0;
		left_col = -1;
		break;
	case RIGHT:
		left_row = 0;
		left_col = 1;
		break;
	case UP:
		left_row = -1;
		left_col = 0;
		break;
	case DOWN:
		left_row = 1;
		left_col = 0;
		break;
	case STOP:

		break;
	default:

		break;
	}


	JudgeCollision(&left_pacman_x, &left_pacman_y,0.0f,0.0f,left_row,left_col, DRAW_WIDTH, DRAW_HEIGHT,  &left_key, &left_savekey, array_left_map);
	
	JudgeCollision(&right_pacman_x, &right_pacman_y, 448.f + 160.0f,0.0f, right_row, right_col, DRAW_WIDTH, DRAW_HEIGHT, &right_key, &right_savekey, array_right_map);


	

	if (dx.KeyState[DIK_RETURN] == dx.PRESS) {
		Phase = RELEASES;
}
	}

//ゲームのテクスチャの解放
void Game::Release() {

	//テクスチャの開放
	for (int i = 0; i < TEX_MAX; i++) {
		if (dx.pTexture[i] != nullptr) {
			dx.pTexture[i]->Release();
			dx.pTexture[i] = nullptr;
		}
	}
	//リザルトシーンへ
	scene = RESULT;
}

void Game::JudgeCollision(float* x,float* y,float start_x,float start_y,int row_,int col_,float draw_width,float draw_height,KEY *key,KEY *savekey,int** map) {
	if (((int)*x % (int)draw_width) == 0 && ((int)*y % (int)draw_height == 0)) {
		int col = (*x - start_x) / draw_width;
		int row = (*y - start_y) / draw_height;
		if ( map[row + row_][col + col_] == 0 || map[row + row_][col + col_] == 35 || map[row + row_][col + col_] == 38 ) {
			*key = *savekey;
			switch (*key) {
			case LEFT:
				*x -= 16;
				break;
			case RIGHT:
				*x += 16;
				break;
			case UP:
				*y -= 16;
				break;
			case DOWN:
				*y += 16;
				break;
			case STOP:

				break;
			default:

				break;
			}
		
		}
	}
}

