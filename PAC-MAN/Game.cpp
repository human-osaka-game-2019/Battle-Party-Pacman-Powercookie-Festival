#include "Game.h"
//#include <random>
//#include <iostream>
#include <stdlib.h>
#include <time.h>

MapchipLoading Mp;
DrawMap map;

Game::SCENE_PAHSE Phase = Game::LOAD;


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

	LoadTexture("pacman_stage_blue.png", BLUE_MAPCHIP);
	LoadTexture("pacman_stage_pink.png", PINK_MAPCHIP);
	LoadTexture("pacman.png", PACMAN);
	LoadTexture("Ghost.png", GHOST);
	LoadTexture("GameBack.png", GAME_BACK);
	LoadTexture("gauge.png",GAUGE);
	LoadTexture("blue.png",COUNTDOWN_BLUE);
	LoadTexture("pink.png",COUNTDOWN_PINK);
	srand((unsigned int)time(NULL));


	right_pacman_x = 416.0f + 960.f;
	right_pacman_y = 736.0f;
	right_pacman_degree = 0;
	right_pacman_rotate = KEY::STOP;
	right_pacman_key = KEY::STOP;
	right_pacman_savekey = KEY::STOP;
	right_pacman_row = 0;
	right_pacman_col = 0;
	right_pacman_life = 1;


	left_pacman_x = 416.0f;
	left_pacman_y = 736.0f;
	left_pacman_degree = 0;
	left_pacman_rotate = KEY::STOP;
	left_pacman_key = KEY::STOP;
	left_pacman_savekey = KEY::STOP;
	left_pacman_row = 0;
	left_pacman_col = 0;
	left_pacman_life = 1;

	flamecount = 0;
	pacman_tu = 0.0f;
	s = 0;

	left_gauge_tu = 0.f;
	right_gauge_tu = 0.f;


	left_ghost_tu = 0.0f;
	right_ghost_tu = 0.0f;


	right_ghost_x_1 = 416.0f + 960.f;
	right_ghost_y_1 = 352.0f;
	left_ghost_x_1 = 416.0f;
	left_ghost_y_1 = 352.0f;


	right_ghost_x_2 = 448.0f + 960.f;
	right_ghost_y_2 = 352.0f;
	left_ghost_x_2 = 448.0f;
	left_ghost_y_2 = 352.0f;


	right_ghost_x_3 = 384.0f + 960.f;
	right_ghost_y_3 = 352.0f;
	left_ghost_x_3 = 384.0f;
	left_ghost_y_3 = 352.0f;

	right_ghost_x_4 = 352.0f + 960.f;
	right_ghost_y_4 = 352.0f;
	left_ghost_x_4 = 352.0f;
	left_ghost_y_4 = 352.0f;

	right_ghost_x_5 = 416.0f + 960.f;
	right_ghost_y_5 = 352.0f;
	left_ghost_x_5 = 416.0f;
	left_ghost_y_5 = 352.0f;


	right_ghost_x_6 = 448.0f + 960.f;
	right_ghost_y_6 = 352.0f;
	left_ghost_x_6 = 448.0f;
	left_ghost_y_6 = 352.0f;

	right_ghost_x_7 = 384.0f + 960.f;
	right_ghost_y_7 = 352.0f;
	left_ghost_x_7 = 384.0f;
	left_ghost_y_7 = 352.0f;

	right_ghost_x_8 = 352.0f + 960.f;
	right_ghost_y_8 = 352.0f;
	left_ghost_x_8 = 352.0f;
	left_ghost_y_8 = 352.0f;







	left_ghost_row_1 = 0;
	left_ghost_col_1 = 0;
	right_ghost_row_1 = 0;
	right_ghost_col_1 = 0;
	ghostmove_x_1 = 0;
	ghostmove_y_1 = 0;
	left_ghost_key_1 = KEY::STOP;
	right_ghost_key_1 = KEY::STOP;
	left_ghost_savekey_1 = KEY::STOP;
	right_ghost_savekey_1 = KEY::STOP;
	left_ghost_rotate_1 = KEY::STOP;
	right_ghost_rotate_1 = KEY::STOP;
	left_ghostpop_1 = 0;
	right_ghostpop_1 = 0;

	left_ghost_row_2 = 0;
	left_ghost_col_2 = 0;
	right_ghost_row_2 = 0;
	right_ghost_col_2 = 0;
	ghostmove_x_2 = 0;
	ghostmove_y_2 = 0;
	left_ghost_key_2 = KEY::STOP;
	right_ghost_key_2 = KEY::STOP;
	left_ghost_savekey_2 = KEY::STOP;
	right_ghost_savekey_2 = KEY::STOP;
	left_ghost_rotate_2 = KEY::STOP;
	right_ghost_rotate_2 = KEY::STOP;
	left_ghostpop_2 = 0;
	right_ghostpop_2 = 0;

	left_ghost_row_3 = 0;
	left_ghost_col_3 = 0;
	right_ghost_row_3 = 0;
	right_ghost_col_3 = 0;
	ghostmove_x_3 = 0;
	ghostmove_y_3 = 0;
	left_ghost_key_3 = KEY::STOP;
	right_ghost_key_3 = KEY::STOP;
	left_ghost_savekey_3 = KEY::STOP;
	right_ghost_savekey_3 = KEY::STOP;
	left_ghost_rotate_3 = KEY::STOP;
	right_ghost_rotate_3 = KEY::STOP;
	left_ghostpop_3 = 0;
	right_ghostpop_3 = 0;

	left_ghost_row_4 = 0;
	left_ghost_col_4 = 0;
	right_ghost_row_4 = 0;
	right_ghost_col_4 = 0;
	ghostmove_x_4 = 0;
	ghostmove_y_4 = 0;
	left_ghost_key_4 = KEY::STOP;
	right_ghost_key_4 = KEY::STOP;
	left_ghost_savekey_4 = KEY::STOP;
	right_ghost_savekey_4 = KEY::STOP;
	left_ghost_rotate_4 = KEY::STOP;
	right_ghost_rotate_4 = KEY::STOP;
	left_ghostpop_4 = 0;
	right_ghostpop_4 = 0;


	left_ghost_row_5 = 0;
	left_ghost_col_5 = 0;
	right_ghost_row_5 = 0;
	right_ghost_col_5 = 0;
	ghostmove_x_5 = 0;
	ghostmove_y_5 = 0;
	left_ghost_key_5 = KEY::STOP;
	right_ghost_key_5 = KEY::STOP;
	left_ghost_savekey_5 = KEY::STOP;
	right_ghost_savekey_5 = KEY::STOP;
	left_ghost_rotate_5 = KEY::STOP;
	right_ghost_rotate_5 = KEY::STOP;
	left_ghostpop_5 = 0;
	right_ghostpop_5 = 0;

	left_ghost_row_6 = 0;
	left_ghost_col_6 = 0;
	right_ghost_row_6 = 0;
	right_ghost_col_6 = 0;
	ghostmove_x_6 = 0;
	ghostmove_y_6 = 0;
	left_ghost_key_6 = KEY::STOP;
	right_ghost_key_6 = KEY::STOP;
	left_ghost_savekey_6 = KEY::STOP;
	right_ghost_savekey_6 = KEY::STOP;
	left_ghost_rotate_6 = KEY::STOP;
	right_ghost_rotate_6 = KEY::STOP;
	left_ghostpop_6 = 0;
	right_ghostpop_6 = 0;

	left_ghost_row_7 = 0;
	left_ghost_col_7 = 0;
	right_ghost_row_7 = 0;
	right_ghost_col_7 = 0;
	ghostmove_x_7 = 0;
	ghostmove_y_7 = 0;
	left_ghost_key_7 = KEY::STOP;
	right_ghost_key_7 = KEY::STOP;
	left_ghost_savekey_7 = KEY::STOP;
	right_ghost_savekey_7 = KEY::STOP;
	left_ghost_rotate_7 = KEY::STOP;
	right_ghost_rotate_7 = KEY::STOP;
	left_ghostpop_7 = 0;
	right_ghostpop_7 = 0;

	left_ghost_row_8 = 0;
	left_ghost_col_8 = 0;
	right_ghost_row_8 = 0;
	right_ghost_col_8 = 0;
	ghostmove_x_8 = 0;
	ghostmove_y_8 = 0;
	left_ghost_key_8 = KEY::STOP;
	right_ghost_key_8 = KEY::STOP;
	left_ghost_savekey_8 = KEY::STOP;
	right_ghost_savekey_8 = KEY::STOP;
	left_ghost_rotate_8 = KEY::STOP;
	right_ghost_rotate_8 = KEY::STOP;
	left_ghostpop_8 = 0;
	right_ghostpop_8 = 0;


	left_ghost_move_1 = 3;
	right_ghost_move_1 = 3;

	left_ghost_move_2 = 3;
	right_ghost_move_2 = 3;

	left_ghost_move_3 = 3;
	right_ghost_move_3 = 3;

	left_ghost_move_4 = 3;
	right_ghost_move_4 = 3;

	left_ghost_move_5 = 0;
	right_ghost_move_5 = 0;

	left_ghost_move_6 = 1;
	right_ghost_move_6 = 1;

	left_ghost_move_7 = 2;
	right_ghost_move_7 = 2;

	left_ghost_move_8 = 3;
	right_ghost_move_8 = 3;


	left_cookie = 0;
	left_powercookie = 0;

	right_cookie = 0;
	right_powercookie = 0;

	right_cookie_count = 0;
	left_cookie_count = 0;


	left_cookie = 0;
	left_powercookie = 0;

	right_cookie = 0;
	right_powercookie = 0;

	right_cookie_count = 0;
	left_cookie_count = 0;
	


	countdown_tu = 0.0f;
	countdown_tv = 0.0f;
	flamecount_a = 0;
	flamecount_b = 0;




	int init_left_map[31][28] =
	{  5,	2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	25,	26,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,	 2,	 6,
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
			map.left_map[j][i] = init_left_map[j][i];
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
			map.right_map[j][i] = init_right_map[j][i];
		}
	}

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {


	flamecount++;
	flamecount_a++;
	///アニメーション関数ですべてのキャラクターのアニメーショできるようにする
	

	if (flamecount_a >= 365) {


		//パックマンのアニメーション
		if (flamecount % 6 == 0) {
			pacman_tu += 0.25f;
		}
		if (1.0f <= pacman_tu) {
			pacman_tu = 0.0f;
		}





		left_ghost_tu += 64.0f / 512.0f;
		right_ghost_tu += 64.0f / 512.0f;
		if (left_ghost_tu >= (64.0f * 2.0f) / 512.0f)
		{
			left_ghost_tu = 0;
		}

		if (right_ghost_tu >= (64.0f * 4.0f) / 512.0f)
		{
			right_ghost_tu = (64.0f * 2.0f) / 512.0f;
		}






		///key入力の関数化
		//左パックマンのkey入力
		if (dx.KeyState[DIK_W] == dx.PRESS) {
			left_pacman_savekey = UP;
			//左ステージのkey入力による当たり判定の方向
			left_pacman_row = -1;
			left_pacman_col = 0;
		}
		else if (dx.KeyState[DIK_S] == dx.PRESS) {
			left_pacman_savekey = DOWN;
			//左ステージのkey入力による当たり判定の方向
			left_pacman_row = 1;
			left_pacman_col = 0;
		}
		else if (dx.KeyState[DIK_A] == dx.PRESS) {
			left_pacman_savekey = LEFT;
			//左ステージのkey入力による当たり判定の方向
			left_pacman_row = 0;
			left_pacman_col = -1;
		}
		else if (dx.KeyState[DIK_D] == dx.PRESS) {
			left_pacman_savekey = RIGHT;
			//左ステージのkey入力による当たり判定の方向
			left_pacman_row = 0;
			left_pacman_col = 1;
		}

		//右パックマンのkey入力
		if (dx.KeyState[DIK_UP] == dx.PRESS) {
			right_pacman_savekey = UP;
			//右ステージのkey入力による当たり判定の方向
			right_pacman_row = -1;
			right_pacman_col = 0;
		}
		else if (dx.KeyState[DIK_DOWN] == dx.PRESS) {
			right_pacman_savekey = DOWN;
			//右ステージのkey入力による当たり判定の方向
			right_pacman_row = 1;
			right_pacman_col = 0;
		}
		else if (dx.KeyState[DIK_LEFT] == dx.PRESS) {
			right_pacman_savekey = LEFT;
			//右ステージのkey入力による当たり判定の方向
			right_pacman_row = 0;
			right_pacman_col = -1;
		}
		else if (dx.KeyState[DIK_RIGHT] == dx.PRESS) {
			right_pacman_savekey = RIGHT;
			//右ステージのkey入力による当たり判定の方向
			right_pacman_row = 0;
			right_pacman_col = 1;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if ((int)(left_ghost_y_1) % (int)(DRAW_HEIGHT) == 0 && (int)(left_ghost_x_1) % (int)(DRAW_WIDTH)) {
			if ((map.left_map[(int)(left_ghost_y_1 / DRAW_HEIGHT) + left_ghost_row_1][(int)(left_ghost_x_1 / DRAW_WIDTH) + left_ghost_col_1] != 0) && (map.left_map[(int)(left_ghost_y_1 / DRAW_HEIGHT) + left_ghost_row_1][(int)(left_ghost_x_1 / DRAW_WIDTH) + left_ghost_col_1] != 35) && (map.left_map[(int)(left_ghost_y_1 / DRAW_HEIGHT) + left_ghost_row_1][(int)(left_ghost_x_1 / DRAW_WIDTH) + left_ghost_col_1] != 38)) {
				int save = left_ghost_move_1;
				for (int i = 0; i < 1000; i++) {
					//left_ghost_move_1 = rand() % 4;
					if (save == left_ghost_move_1) {
						continue;
					}
					break;
				}
			}
		}
		switch (left_ghost_move_1) {
		case 0:
			left_ghost_savekey_1 = UP;
			left_ghost_row_1 = -1;
			left_ghost_col_1 = 0;
			break;
		case 1:
			left_ghost_savekey_1 = DOWN;
			left_ghost_row_1 = 1;
			left_ghost_col_1 = 0;
			break;
		case 2:
			left_ghost_savekey_1 = RIGHT;
			left_ghost_row_1 = 0;
			left_ghost_col_1 = 1;
			break;
		case 3:
			left_ghost_savekey_1 = LEFT;
			left_ghost_row_1 = 0;
			left_ghost_col_1 = -1;
			break;
		default:

			break;
		}
		if ((int)(left_ghost_y_2) % (int)(DRAW_HEIGHT) == 0 && (int)(left_ghost_x_2) % (int)(DRAW_WIDTH)) {
			if ((map.left_map[(int)(left_ghost_y_2 / DRAW_HEIGHT) + left_ghost_row_2][(int)(left_ghost_x_2 / DRAW_WIDTH) + left_ghost_col_2] != 0) && (map.left_map[(int)(left_ghost_y_2 / DRAW_HEIGHT) + left_ghost_row_2][(int)(left_ghost_x_2 / DRAW_WIDTH) + left_ghost_col_2] != 35) && (map.left_map[(int)(left_ghost_y_2 / DRAW_HEIGHT) + left_ghost_row_2][(int)(left_ghost_x_2 / DRAW_WIDTH) + left_ghost_col_2] != 38)) {
				int save = left_ghost_move_2;
				for (int i = 0; i < 1000; i++) {
					//left_ghost_move_2 = rand() % 4;
					if (save == left_ghost_move_2) {
						continue;
					}
					break;
				}
			}
		}
		switch (left_ghost_move_2) {
		case 0:
			left_ghost_savekey_2 = UP;
			left_ghost_row_2 = -1;
			left_ghost_col_2 = 0;
			break;
		case 1:
			left_ghost_savekey_2 = DOWN;
			left_ghost_row_2 = 1;
			left_ghost_col_2 = 0;
			break;
		case 2:
			left_ghost_savekey_2 = RIGHT;
			left_ghost_row_2 = 0;
			left_ghost_col_2 = 1;
			break;
		case 3:
			left_ghost_savekey_2 = LEFT;
			left_ghost_row_2 = 0;
			left_ghost_col_2 = -1;
			break;
		default:

			break;
		}
		if ((int)(left_ghost_y_3) % (int)(DRAW_HEIGHT) == 0 && (int)(left_ghost_x_3) % (int)(DRAW_WIDTH)) {
			if ((map.left_map[(int)(left_ghost_y_3 / DRAW_HEIGHT) + left_ghost_row_3][(int)(left_ghost_x_3 / DRAW_WIDTH) + left_ghost_col_3] != 0) && (map.left_map[(int)(left_ghost_y_3 / DRAW_HEIGHT) + left_ghost_row_3][(int)(left_ghost_x_3 / DRAW_WIDTH) + left_ghost_col_3] != 35) && (map.left_map[(int)(left_ghost_y_3 / DRAW_HEIGHT) + left_ghost_row_3][(int)(left_ghost_x_3 / DRAW_WIDTH) + left_ghost_col_3] != 38)) {
				int save = left_ghost_move_3;
				for (int i = 0; i < 1000; i++) {
					//left_ghost_move_3 = rand() % 4;
					if (save == left_ghost_move_3) {
						continue;
					}
					break;
				}
			}
		}
		switch (left_ghost_move_3) {
		case 0:
			left_ghost_savekey_3 = UP;
			left_ghost_row_3 = -1;
			left_ghost_col_3 = 0;
			break;
		case 1:
			left_ghost_savekey_3 = DOWN;
			left_ghost_row_3 = 1;
			left_ghost_col_3 = 0;
			break;
		case 2:
			left_ghost_savekey_3 = RIGHT;
			left_ghost_row_3 = 0;
			left_ghost_col_3 = 1;
			break;
		case 3:
			left_ghost_savekey_3 = LEFT;
			left_ghost_row_3 = 0;
			left_ghost_col_3 = -1;
			break;
		default:

			break;
		}
		if ((int)(left_ghost_y_4) % (int)(DRAW_HEIGHT) == 0 && (int)(left_ghost_x_4) % (int)(DRAW_WIDTH)) {
			if ((map.left_map[(int)(left_ghost_y_4 / DRAW_HEIGHT) + left_ghost_row_4][(int)(left_ghost_x_4 / DRAW_WIDTH) + left_ghost_col_4] != 0) && (map.left_map[(int)(left_ghost_y_4 / DRAW_HEIGHT) + left_ghost_row_4][(int)(left_ghost_x_4 / DRAW_WIDTH) + left_ghost_col_4] != 35) && (map.left_map[(int)(left_ghost_y_4 / DRAW_HEIGHT) + left_ghost_row_4][(int)(left_ghost_x_4 / DRAW_WIDTH) + left_ghost_col_4] != 38)) {
				int save = left_ghost_move_4;
				for (int i = 0; i < 1000; i++) {
					//left_ghost_move_4 = rand() % 4;
					if (save == left_ghost_move_4) {
						continue;
					}
					break;
				}
			}
		}
		switch (left_ghost_move_4) {
		case 0:
			left_ghost_savekey_4 = UP;
			left_ghost_row_4 = -1;
			left_ghost_col_4 = 0;
			break;
		case 1:
			left_ghost_savekey_4 = DOWN;
			left_ghost_row_4 = 1;
			left_ghost_col_4 = 0;
			break;
		case 2:
			left_ghost_savekey_4 = RIGHT;
			left_ghost_row_4 = 0;
			left_ghost_col_4 = 1;
			break;
		case 3:
			left_ghost_savekey_4 = LEFT;
			left_ghost_row_4 = 0;
			left_ghost_col_4 = -1;
			break;
		default:

			break;
		}

		if ((int)(left_ghost_y_5) % (int)(DRAW_HEIGHT) == 0 && (int)(left_ghost_x_5) % (int)(DRAW_WIDTH)) {
			if ((map.left_map[(int)(left_ghost_y_5 / DRAW_HEIGHT) + left_ghost_row_5][(int)(left_ghost_x_5 / DRAW_WIDTH) + left_ghost_col_5] != 0) && (map.left_map[(int)(left_ghost_y_5 / DRAW_HEIGHT) + left_ghost_row_5][(int)(left_ghost_x_5 / DRAW_WIDTH) + left_ghost_col_5] != 35) && (map.left_map[(int)(left_ghost_y_5 / DRAW_HEIGHT) + left_ghost_row_5][(int)(left_ghost_x_5 / DRAW_WIDTH) + left_ghost_col_5] != 38)) {
				int save = left_ghost_move_5;
				for (int i = 0; i < 1000; i++) {
					//right_ghost_move_1 = rand() % 4;
					if (save == left_ghost_move_5) {
						continue;
					}
					break;
				}
			}
		}

		switch (left_ghost_move_8) {
		case 0:
			left_ghost_savekey_5 = UP;
			left_ghost_row_5 = -1;
			left_ghost_col_5 = 0;
			break;
		case 1:
			left_ghost_savekey_5 = DOWN;
			left_ghost_row_5 = 1;
			left_ghost_col_5 = 0;
			break;
		case 2:
			left_ghost_savekey_5 = RIGHT;
			left_ghost_row_5 = 0;
			left_ghost_col_5 = 1;
			break;
		case 3:
			left_ghost_savekey_5 = LEFT;
			left_ghost_row_5 = 0;
			left_ghost_col_5 = -1;
			break;
		default:

			break;
		}
		if ((int)(left_ghost_y_6) % (int)(DRAW_HEIGHT) == 0 && (int)(left_ghost_x_2) % (int)(DRAW_WIDTH)) {
			if ((map.left_map[(int)(left_ghost_y_6 / DRAW_HEIGHT) + left_ghost_row_6][(int)(left_ghost_x_6 / DRAW_WIDTH) + left_ghost_col_6] != 0) && (map.left_map[(int)(left_ghost_y_6 / DRAW_HEIGHT) + left_ghost_row_6][(int)(left_ghost_x_6 / DRAW_WIDTH) + left_ghost_col_6] != 35) && (map.left_map[(int)(left_ghost_y_6 / DRAW_HEIGHT) + left_ghost_row_6][(int)(left_ghost_x_6 / DRAW_WIDTH) + left_ghost_col_6] != 38)) {
				int save = left_ghost_move_6;
				for (int i = 0; i < 1000; i++) {
					//right_ghost_move_2 = rand() % 4;
					if (save == left_ghost_move_6) {
						continue;
					}
					break;
				}
			}
		}

		switch (left_ghost_move_5) {
		case 0:
			left_ghost_savekey_6 = UP;
			left_ghost_row_6 = -1;
			left_ghost_col_6 = 0;
			break;
		case 1:
			left_ghost_savekey_6 = DOWN;
			left_ghost_row_6 = 1;
			left_ghost_col_6 = 0;
			break;
		case 2:
			left_ghost_savekey_6 = RIGHT;
			left_ghost_row_6 = 0;
			left_ghost_col_6 = 1;
			break;
		case 3:
			left_ghost_savekey_6 = LEFT;
			left_ghost_row_6 = 0;
			left_ghost_col_6 = -1;
			break;
		default:

			break;
		}
		if ((int)(left_ghost_y_7) % (int)(DRAW_HEIGHT) == 0 && (int)(left_ghost_x_7) % (int)(DRAW_WIDTH)) {
			if ((map.left_map[(int)(left_ghost_y_7 / DRAW_HEIGHT) + left_ghost_row_7][(int)(left_ghost_x_7 / DRAW_WIDTH) + left_ghost_col_7 != 0]) && (map.left_map[(int)(left_ghost_y_7 / DRAW_HEIGHT) + left_ghost_row_7][(int)(left_ghost_x_7 / DRAW_WIDTH) + left_ghost_col_7] != 35) && (map.left_map[(int)(left_ghost_y_7 / DRAW_HEIGHT) + left_ghost_row_7][(int)(left_ghost_x_7 / DRAW_WIDTH) + left_ghost_col_7] != 38)) {
				int save = left_ghost_move_7;
				for (int i = 0; i < 1000; i++) {
					//right_ghost_move_3 = rand() % 4;
					if (save == left_ghost_move_7) {
						continue;
					}
					break;
				}
			}
		}

		switch (left_ghost_move_6) {
		case 0:
			left_ghost_savekey_7 = UP;
			left_ghost_row_7 = -1;
			left_ghost_col_7 = 0;
			break;
		case 1:
			left_ghost_savekey_7 = DOWN;
			left_ghost_row_7 = 1;
			left_ghost_col_7 = 0;
			break;
		case 2:
			left_ghost_savekey_7 = RIGHT;
			left_ghost_row_7 = 0;
			left_ghost_col_7 = 1;
			break;
		case 3:
			left_ghost_savekey_7 = LEFT;
			left_ghost_row_7 = 0;
			left_ghost_col_7 = -1;
			break;
		default:

			break;
		}
		if ((int)(left_ghost_y_8) % (int)(DRAW_HEIGHT) == 0 && (int)(left_ghost_x_8) % (int)(DRAW_WIDTH)) {
			if ((map.left_map[(int)(left_ghost_y_8 / DRAW_HEIGHT) + left_ghost_row_8][(int)(left_ghost_x_8 / DRAW_WIDTH) + left_ghost_col_8] != 0) && (map.left_map[(int)(left_ghost_y_8 / DRAW_HEIGHT) + left_ghost_row_4][(int)(left_ghost_x_8 / DRAW_WIDTH) + left_ghost_col_8] != 35) && (map.left_map[(int)(left_ghost_y_8 / DRAW_HEIGHT) + left_ghost_row_8][(int)(left_ghost_x_8 / DRAW_WIDTH) + left_ghost_col_8] != 38)) {
				int save = left_ghost_move_4;
				for (int i = 0; i < 1000; i++) {
					//left_ghost_move_8 = rand() % 4;
					if (save == left_ghost_move_8) {
						continue;
					}
					break;
				}
			}
		}

		switch (left_ghost_move_5) {
		case 0:
			left_ghost_savekey_8 = UP;
			left_ghost_row_8 = -1;
			left_ghost_col_8 = 0;
			break;
		case 1:
			left_ghost_savekey_8 = DOWN;
			left_ghost_row_8 = 1;
			left_ghost_col_8 = 0;
			break;
		case 2:
			left_ghost_savekey_8 = RIGHT;
			left_ghost_row_8 = 0;
			left_ghost_col_8 = 1;
			break;
		case 3:
			left_ghost_savekey_8 = LEFT;
			left_ghost_row_8 = 0;
			left_ghost_col_8 = -1;
			break;
		default:

			break;
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if ((int)(right_ghost_y_1) % (int)(DRAW_HEIGHT) == 0 && (int)(right_ghost_x_1) % (int)(DRAW_WIDTH)) {
			if ((map.right_map[(int)(right_ghost_y_1 / DRAW_HEIGHT) + right_ghost_row_1][(int)(right_ghost_x_1 / DRAW_WIDTH) + right_ghost_col_1] != 0) && (map.right_map[(int)(right_ghost_y_1 / DRAW_HEIGHT) + right_ghost_row_1][(int)(right_ghost_x_1 / DRAW_WIDTH) + right_ghost_col_1] != 35) && (map.right_map[(int)(right_ghost_y_1 / DRAW_HEIGHT) + right_ghost_row_1][(int)(right_ghost_x_1 / DRAW_WIDTH) + right_ghost_col_1] != 38)) {
				int save = right_ghost_move_1;
				for (int i = 0; i < 1000; i++) {
					//right_ghost_move_1 = rand() % 4;
					if (save == right_ghost_move_1) {
						continue;
					}
					break;
				}
			}
		}

		switch (right_ghost_move_4) {
		case 0:
			right_ghost_savekey_1 = UP;
			right_ghost_row_1 = -1;
			right_ghost_col_1 = 0;
			break;
		case 1:
			right_ghost_savekey_1 = DOWN;
			right_ghost_row_1 = 1;
			right_ghost_col_1 = 0;
			break;
		case 2:
			right_ghost_savekey_1 = RIGHT;
			right_ghost_row_1 = 0;
			right_ghost_col_1 = 1;
			break;
		case 3:
			right_ghost_savekey_1 = LEFT;
			right_ghost_row_1 = 0;
			right_ghost_col_1 = -1;
			break;
		default:

			break;
		}
		if ((int)(right_ghost_y_2) % (int)(DRAW_HEIGHT) == 0 && (int)(right_ghost_x_2) % (int)(DRAW_WIDTH)) {
			if ((map.right_map[(int)(left_ghost_y_2 / DRAW_HEIGHT) + right_ghost_row_2][(int)(right_ghost_x_2 / DRAW_WIDTH) + right_ghost_col_2] != 0) && (map.right_map[(int)(right_ghost_y_2 / DRAW_HEIGHT) + right_ghost_row_2][(int)(right_ghost_x_2 / DRAW_WIDTH) + right_ghost_col_2] != 35) && (map.right_map[(int)(right_ghost_y_2 / DRAW_HEIGHT) + right_ghost_row_2][(int)(right_ghost_x_2 / DRAW_WIDTH) + right_ghost_col_2] != 38)) {
				int save = right_ghost_move_2;
				for (int i = 0; i < 1000; i++) {
					//right_ghost_move_2 = rand() % 4;
					if (save == right_ghost_move_2) {
						continue;
					}
					break;
				}
			}
		}

		switch (right_ghost_move_3) {
		case 0:
			right_ghost_savekey_2 = UP;
			right_ghost_row_2 = -1;
			right_ghost_col_2 = 0;
			break;
		case 1:
			right_ghost_savekey_2 = DOWN;
			right_ghost_row_2 = 1;
			right_ghost_col_2 = 0;
			break;
		case 2:
			right_ghost_savekey_2 = RIGHT;
			right_ghost_row_2 = 0;
			right_ghost_col_2 = 1;
			break;
		case 3:
			right_ghost_savekey_2 = LEFT;
			right_ghost_row_2 = 0;
			right_ghost_col_2 = -1;
			break;
		default:

			break;
		}
		if ((int)(right_ghost_y_3) % (int)(DRAW_HEIGHT) == 0 && (int)(right_ghost_x_3) % (int)(DRAW_WIDTH)) {
			if ((map.right_map[(int)(left_ghost_y_3 / DRAW_HEIGHT) + right_ghost_row_3][(int)(right_ghost_x_3 / DRAW_WIDTH) + right_ghost_col_3] != 0) && (map.right_map[(int)(right_ghost_y_3 / DRAW_HEIGHT) + right_ghost_row_3][(int)(right_ghost_x_3 / DRAW_WIDTH) + right_ghost_col_3] != 35) && (map.right_map[(int)(right_ghost_y_3 / DRAW_HEIGHT) + right_ghost_row_3][(int)(right_ghost_x_3 / DRAW_WIDTH) + right_ghost_col_3] != 38)) {
				int save = right_ghost_move_3;
				for (int i = 0; i < 1000; i++) {
					//right_ghost_move_3 = rand() % 4;
					if (save == right_ghost_move_3) {
						continue;
					}
					break;
				}
			}
		}

		switch (right_ghost_move_2) {
		case 0:
			right_ghost_savekey_3 = UP;
			right_ghost_row_3 = -1;
			right_ghost_col_3 = 0;
			break;
		case 1:
			right_ghost_savekey_3 = DOWN;
			right_ghost_row_3 = 1;
			right_ghost_col_3 = 0;
			break;
		case 2:
			right_ghost_savekey_3 = RIGHT;
			right_ghost_row_3 = 0;
			right_ghost_col_3 = 1;
			break;
		case 3:
			right_ghost_savekey_3 = LEFT;
			right_ghost_row_3 = 0;
			right_ghost_col_3 = -1;
			break;
		default:

			break;
		}
		if ((int)(right_ghost_y_4) % (int)(DRAW_HEIGHT) == 0 && (int)(right_ghost_x_4) % (int)(DRAW_WIDTH)) {
			if ((map.right_map[(int)(left_ghost_y_4 / DRAW_HEIGHT) + right_ghost_row_4][(int)(right_ghost_x_4 / DRAW_WIDTH) + right_ghost_col_4] != 0) && (map.right_map[(int)(right_ghost_y_4 / DRAW_HEIGHT) + right_ghost_row_4][(int)(right_ghost_x_4 / DRAW_WIDTH) + right_ghost_col_4] != 35) && (map.right_map[(int)(right_ghost_y_4 / DRAW_HEIGHT) + right_ghost_row_4][(int)(right_ghost_x_4 / DRAW_WIDTH) + right_ghost_col_4] != 38)) {
				int save = right_ghost_move_4;
				for (int i = 0; i < 1000; i++) {
					right_ghost_move_4 = rand() % 4;
					if (save == right_ghost_move_4) {
						continue;
					}
					break;
				}
			}
		}

		switch (right_ghost_move_1) {
		case 0:
			right_ghost_savekey_4 = UP;
			right_ghost_row_4 = -1;
			right_ghost_col_4 = 0;
			break;
		case 1:
			right_ghost_savekey_4 = DOWN;
			right_ghost_row_4 = 1;
			right_ghost_col_4 = 0;
			break;
		case 2:
			right_ghost_savekey_4 = RIGHT;
			right_ghost_row_4 = 0;
			right_ghost_col_4 = 1;
			break;
		case 3:
			right_ghost_savekey_4 = LEFT;
			right_ghost_row_4 = 0;
			right_ghost_col_4 = -1;
			break;
		default:

			break;
		}
		if ((int)(right_ghost_y_5) % (int)(DRAW_HEIGHT) == 0 && (int)(right_ghost_x_5) % (int)(DRAW_WIDTH)) {
			if ((map.right_map[(int)(right_ghost_y_5 / DRAW_HEIGHT) + right_ghost_row_5][(int)(right_ghost_x_5 / DRAW_WIDTH) + right_ghost_col_5] != 0) && (map.right_map[(int)(right_ghost_y_5 / DRAW_HEIGHT) + right_ghost_row_5][(int)(right_ghost_x_5 / DRAW_WIDTH) + right_ghost_col_5] != 35) && (map.right_map[(int)(right_ghost_y_5 / DRAW_HEIGHT) + right_ghost_row_5][(int)(right_ghost_x_5 / DRAW_WIDTH) + right_ghost_col_5] != 38)) {
				int save = right_ghost_move_5;
				for (int i = 0; i < 1000; i++) {
					//left_ghost_move_1 = rand() % 4;
					if (save == right_ghost_move_5) {
						continue;
					}
					break;
				}
			}
		}
		switch (left_ghost_move_5) {
		case 0:
			right_ghost_savekey_5 = UP;
			right_ghost_row_5 = -1;
			right_ghost_col_5 = 0;
			break;
		case 1:
			right_ghost_savekey_5 = DOWN;
			right_ghost_row_5 = 1;
			right_ghost_col_5 = 0;
			break;
		case 2:
			right_ghost_savekey_5 = RIGHT;
			right_ghost_row_5 = 0;
			right_ghost_col_5 = 1;
			break;
		case 3:
			right_ghost_savekey_5 = LEFT;
			right_ghost_row_5 = 0;
			right_ghost_col_5 = -1;
			break;
		default:

			break;
		}
		if ((int)(right_ghost_y_6) % (int)(DRAW_HEIGHT) == 0 && (int)(right_ghost_x_6) % (int)(DRAW_WIDTH)) {
			if ((map.right_map[(int)(right_ghost_y_6 / DRAW_HEIGHT) + right_ghost_row_6][(int)(right_ghost_x_6 / DRAW_WIDTH) + right_ghost_col_6] != 0) && (map.right_map[(int)(right_ghost_y_6 / DRAW_HEIGHT) + right_ghost_row_6][(int)(right_ghost_x_6 / DRAW_WIDTH) + right_ghost_col_6] != 35) && (map.right_map[(int)(right_ghost_y_6 / DRAW_HEIGHT) + right_ghost_row_6][(int)(right_ghost_x_6 / DRAW_WIDTH) + right_ghost_col_6] != 38)) {
				int save = right_ghost_move_6;
				for (int i = 0; i < 1000; i++) {
					//left_ghost_move_2 = rand() % 4;
					if (save == right_ghost_move_6) {
						continue;
					}
					break;
				}
			}
		}
		switch (right_ghost_move_6) {
		case 0:
			right_ghost_savekey_6 = UP;
			right_ghost_row_6 = -1;
			right_ghost_col_6 = 0;
			break;
		case 1:
			right_ghost_savekey_6 = DOWN;
			right_ghost_row_6 = 1;
			right_ghost_col_6 = 0;
			break;
		case 2:
			right_ghost_savekey_6 = RIGHT;
			right_ghost_row_6 = 0;
			right_ghost_col_6 = 1;
			break;
		case 3:
			right_ghost_savekey_6 = LEFT;
			right_ghost_row_6 = 0;
			right_ghost_col_6 = -1;
			break;
		default:

			break;
		}
		if ((int)(right_ghost_y_7) % (int)(DRAW_HEIGHT) == 0 && (int)(right_ghost_x_7) % (int)(DRAW_WIDTH)) {
			if ((map.right_map[(int)(right_ghost_y_7 / DRAW_HEIGHT) + right_ghost_row_7][(int)(right_ghost_x_7 / DRAW_WIDTH) + right_ghost_col_7] != 0) && (map.right_map[(int)(right_ghost_y_7 / DRAW_HEIGHT) + right_ghost_row_7][(int)(right_ghost_x_7 / DRAW_WIDTH) + right_ghost_col_7] != 35) && (map.right_map[(int)(right_ghost_y_7 / DRAW_HEIGHT) + right_ghost_row_7][(int)(right_ghost_x_7 / DRAW_WIDTH) + right_ghost_col_7] != 38)) {
				int save = right_ghost_move_7;
				for (int i = 0; i < 1000; i++) {
					//left_ghost_move_3 = rand() % 4;
					if (save == right_ghost_move_7) {
						continue;
					}
					break;
				}
			}
		}
		switch (right_ghost_move_7) {
		case 0:
			right_ghost_savekey_7 = UP;
			right_ghost_row_7 = -1;
			right_ghost_col_7 = 0;
			break;
		case 1:
			right_ghost_savekey_7 = DOWN;
			right_ghost_row_7 = 1;
			right_ghost_col_7 = 0;
			break;
		case 2:
			right_ghost_savekey_7 = RIGHT;
			right_ghost_row_7 = 0;
			right_ghost_col_7 = 1;
			break;
		case 3:
			right_ghost_savekey_7 = LEFT;
			right_ghost_row_7 = 0;
			right_ghost_col_7 = -1;
			break;
		default:

			break;
		}
		if ((int)(right_ghost_y_8) % (int)(DRAW_HEIGHT) == 0 && (int)(right_ghost_x_8) % (int)(DRAW_WIDTH)) {
			if ((map.right_map[(int)(right_ghost_y_8 / DRAW_HEIGHT) + right_ghost_row_8][(int)(right_ghost_x_8 / DRAW_WIDTH) + right_ghost_col_8] != 0) && (map.right_map[(int)(right_ghost_y_8 / DRAW_HEIGHT) + right_ghost_row_8][(int)(right_ghost_x_8 / DRAW_WIDTH) + right_ghost_col_8] != 35) && (map.right_map[(int)(right_ghost_y_8 / DRAW_HEIGHT) + right_ghost_row_8][(int)(right_ghost_x_8 / DRAW_WIDTH) + right_ghost_col_8] != 38)) {
				int save = right_ghost_move_8;
				for (int i = 0; i < 1000; i++) {
					//left_ghost_move_4 = rand() % 4;
					if (save == right_ghost_move_8) {
						continue;
					}
					break;
				}
			}
		}
		switch (right_ghost_move_8) {
		case 0:
			right_ghost_savekey_8 = UP;
			right_ghost_row_8 = -1;
			right_ghost_col_8 = 0;
			break;
		case 1:
			right_ghost_savekey_8 = DOWN;
			right_ghost_row_8 = 1;
			right_ghost_col_8 = 0;
			break;
		case 2:
			right_ghost_savekey_8 = RIGHT;
			right_ghost_row_8 = 0;
			right_ghost_col_8 = 1;
			break;
		case 3:
			right_ghost_savekey_8 = LEFT;
			right_ghost_row_8 = 0;
			right_ghost_col_8 = -1;
			break;
		default:

			break;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		////左画面の真ん中の逆から出てくる処理
		//if ((14 == (int)(left_pacman_y / DRAW_HEIGHT)) && (0 == (int)(left_pacman_x / DRAW_WIDTH))) {
		//	left_pacman_x = DRAW_WIDTH * 27;
		//}else if ((14 == (int)(left_pacman_y / DRAW_HEIGHT)) && (27 == (int)(left_pacman_x / DRAW_WIDTH))) {
		//	left_pacman_x = 0.0f;
		//}








		//マップの二十配列を渡すための変数
		int* array_left_map[31];
		int* array_right_map[31];
		//上の変数にマップのアドレスを入れる
		for (int i = 0; i < 31; i++) {
			array_left_map[i] = map.left_map[i];
		}
		for (int i = 0; i < 31; i++) {
			array_right_map[i] = map.right_map[i];
		}





		for (int i = 0; i < 100; i++)
		{
			if (eating_cookie[i][eating_cookie_Num] != 0)
			{
				repop_cookie_count[i]++;
				//if (repop_cookie_count[i] % 120 == 0 && eating_cookie[i][eating_cookie_Num] != 0)
				//{

				Repop(array_left_map, i);

				//}
			}
		}

		for (int j = 0; j < 4; j++)
		{
			if (eating_power_cookie[j][eating_cookie_Num] != 0)
			{
				repop_power_cookie_count[j]++;
				//if (repop_power_cookie_count[j] == 1800 && eating_power_cookie[j][eating_cookie_Num]!=0)
				//{

				Repop(array_left_map, j);
				//}
			}
		}


		for (int i = 0; i < 100; i++)
		{
			if (eating_cookie[i][eating_cookie_Num] != 0)
			{
				repop_cookie_count[i]++;
				//if (repop_cookie_count[i] % 120 == 0 && eating_cookie[i][eating_cookie_Num] != 0)
				//{

				Repop(array_right_map, i);

				//}
			}
		}

		for (int j = 0; j < 4; j++)
		{
			if (eating_power_cookie[j][eating_cookie_Num] != 0)

			{
				repop_power_cookie_count[j]++;
				//if (repop_power_cookie_count[j] == 1800 && eating_power_cookie[j][eating_cookie_Num]!=0)
				//{

				Repop(array_right_map, j);
				//}
			}
		}



		//左のパックマンの当たり判定
		JudgeCollision(&left_pacman_x, &left_pacman_y, 0.0f, 0.0f, left_pacman_row, left_pacman_col, DRAW_WIDTH, DRAW_HEIGHT, &left_pacman_key, &left_pacman_savekey, &left_pacman_rotate, array_left_map);
		//右のパックマンの当たり判定
		JudgeCollision(&right_pacman_x, &right_pacman_y, 896.0f + 64.f, 0.0f, right_pacman_row, right_pacman_col, DRAW_WIDTH, DRAW_HEIGHT, &right_pacman_key, &right_pacman_savekey, &right_pacman_rotate, array_right_map);









		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		//左のゴーストの当たり判定
		CanMoveGhost(&left_ghost_x_1, &left_ghost_y_1, 0.0f, 0.0f, left_ghost_row_1, left_ghost_col_1, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_1, &left_ghost_savekey_1, &left_ghost_rotate_1, &left_ghost_move_1, array_left_map);
		//右のゴーストの当たり判定
		CanMoveGhost(&right_ghost_x_1, &right_ghost_y_1, 960.0f, 0.0f, right_ghost_row_1, right_ghost_col_1, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_1, &right_ghost_savekey_1, &right_ghost_rotate_1, &right_ghost_move_1, array_right_map);

		//左のゴーストの当たり判定
		CanMoveGhost(&left_ghost_x_2, &left_ghost_y_2, 0.0f, 0.0f, left_ghost_row_2, left_ghost_col_2, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_2, &left_ghost_savekey_2, &left_ghost_rotate_2, &left_ghost_move_2, array_left_map);
		//右のゴーストの当たり判定
		CanMoveGhost(&right_ghost_x_2, &right_ghost_y_2, 960.0f, 0.0f, right_ghost_row_2, right_ghost_col_2, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_2, &right_ghost_savekey_2, &right_ghost_rotate_2, &right_ghost_move_2, array_right_map);

		//左のゴーストの当たり判定
		CanMoveGhost(&left_ghost_x_3, &left_ghost_y_3, 0.0f, 0.0f, left_ghost_row_3, left_ghost_col_3, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_3, &left_ghost_savekey_3, &left_ghost_rotate_3, &left_ghost_move_3, array_left_map);
		//右のゴーストの当たり判定
		CanMoveGhost(&right_ghost_x_3, &right_ghost_y_3, 960.0f, 0.0f, right_ghost_row_3, right_ghost_col_3, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_3, &right_ghost_savekey_3, &right_ghost_rotate_3, &right_ghost_move_3, array_right_map);

		//左のゴーストの当たり判定
		CanMoveGhost(&left_ghost_x_4, &left_ghost_y_4, 0.0f, 0.0f, left_ghost_row_4, left_ghost_col_4, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_4, &left_ghost_savekey_4, &left_ghost_rotate_4, &left_ghost_move_4, array_left_map);
		//右のゴーストの当たり判定
		CanMoveGhost(&right_ghost_x_4, &right_ghost_y_4, 960.0f, 0.0f, right_ghost_row_4, right_ghost_col_4, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_4, &right_ghost_savekey_4, &right_ghost_rotate_4, &right_ghost_move_4, array_right_map);

		//左のゴーストの当たり判定
		CanMoveGhost(&left_ghost_x_5, &left_ghost_y_5, 0.0f, 0.0f, left_ghost_row_5, left_ghost_col_5, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_5, &left_ghost_savekey_5, &left_ghost_rotate_5, &left_ghost_move_5, array_left_map);
		//右のゴーストの当たり判定
		CanMoveGhost(&right_ghost_x_5, &right_ghost_y_5, 960.0f, 0.0f, right_ghost_row_5, right_ghost_col_5, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_5, &right_ghost_savekey_5, &right_ghost_rotate_5, &right_ghost_move_5, array_right_map);

		//左のゴーストの当たり判定
		CanMoveGhost(&left_ghost_x_6, &left_ghost_y_6, 0.0f, 0.0f, left_ghost_row_6, left_ghost_col_6, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_6, &left_ghost_savekey_6, &left_ghost_rotate_6, &left_ghost_move_6, array_left_map);
		//右のゴーストの当たり判定
		CanMoveGhost(&right_ghost_x_6, &right_ghost_y_6, 960.0f, 0.0f, right_ghost_row_6, right_ghost_col_6, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_6, &right_ghost_savekey_6, &right_ghost_rotate_6, &right_ghost_move_6, array_right_map);

		//左のゴーストの当たり判定
		CanMoveGhost(&left_ghost_x_7, &left_ghost_y_7, 0.0f, 0.0f, left_ghost_row_7, left_ghost_col_7, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_7, &left_ghost_savekey_7, &left_ghost_rotate_7, &left_ghost_move_7, array_left_map);
		//右のゴーストの当たり判定
		CanMoveGhost(&right_ghost_x_7, &right_ghost_y_7, 960.0f, 0.0f, right_ghost_row_7, right_ghost_col_7, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_7, &right_ghost_savekey_7, &right_ghost_rotate_7, &right_ghost_move_7, array_right_map);

		//左のゴーストの当たり判定
		CanMoveGhost(&left_ghost_x_8, &left_ghost_y_8, 0.0f, 0.0f, left_ghost_row_8, left_ghost_col_8, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_8, &left_ghost_savekey_8, &left_ghost_rotate_8, &left_ghost_move_8, array_left_map);
		//右のゴーストの当たり判定
		CanMoveGhost(&right_ghost_x_8, &right_ghost_y_8, 960.0f, 0.0f, right_ghost_row_8, right_ghost_col_8, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_8, &right_ghost_savekey_8, &right_ghost_rotate_8, &right_ghost_move_8, array_right_map);




		////左のゴーストの当たり判定
		//CanMoveGhost(&left_ghost_x_1, &left_ghost_y_1, 0.0f, 0.0f, left_ghost_row_1, left_ghost_col_1, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_1, &left_ghost_savekey_1, &left_ghost_rotate_1, &left_ghost_move_1, array_right_map);
		////右のゴーストの当たり判定
		//CanMoveGhost(&right_ghost_x_1, &right_ghost_y_1, 960.0f, 0.0f, right_ghost_row_1, right_ghost_col_1, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_1, &right_ghost_savekey_1, &right_ghost_rotate_1, &right_ghost_move_1, array_left_map);

		////左のゴーストの当たり判定
		//CanMoveGhost(&left_ghost_x_2, &left_ghost_y_2, 0.0f, 0.0f, left_ghost_row_2, left_ghost_col_2, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_2, &left_ghost_savekey_2, &left_ghost_rotate_2, &left_ghost_move_2, array_right_map);
		////右のゴーストの当たり判定
		//CanMoveGhost(&right_ghost_x_2, &right_ghost_y_2, 960.0f, 0.0f, right_ghost_row_2, right_ghost_col_2, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_2, &right_ghost_savekey_2, &right_ghost_rotate_2, &right_ghost_move_2, array_left_map);

		////左のゴーストの当たり判定
		//CanMoveGhost(&left_ghost_x_3, &left_ghost_y_3, 0.0f, 0.0f, left_ghost_row_3, left_ghost_col_3, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_3, &left_ghost_savekey_3, &left_ghost_rotate_3, &left_ghost_move_3, array_right_map);
		////右のゴーストの当たり判定
		//CanMoveGhost(&right_ghost_x_3, &right_ghost_y_3, 960.0f, 0.0f, right_ghost_row_3, right_ghost_col_3, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_3, &right_ghost_savekey_3, &right_ghost_rotate_3, &right_ghost_move_3, array_left_map);

		////左のゴーストの当たり判定
		//CanMoveGhost(&left_ghost_x_4, &left_ghost_y_4, 0.0f, 0.0f, left_ghost_row_4, left_ghost_col_4, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_4, &left_ghost_savekey_4, &left_ghost_rotate_4, &left_ghost_move_4, array_right_map);
		////右のゴーストの当たり判定
		//CanMoveGhost(&right_ghost_x_4, &right_ghost_y_4, 960.0f, 0.0f, right_ghost_row_4, right_ghost_col_4, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_4, &right_ghost_savekey_4, &right_ghost_rotate_4, &right_ghost_move_4, array_left_map);

		////左のゴーストの当たり判定
		//CanMoveGhost(&left_ghost_x_5, &left_ghost_y_5, 0.0f, 0.0f, left_ghost_row_5, left_ghost_col_5, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_5, &left_ghost_savekey_5, &left_ghost_rotate_5, &left_ghost_move_5, array_right_map);
		////右のゴーストの当たり判定
		//CanMoveGhost(&right_ghost_x_5, &right_ghost_y_5, 960.0f, 0.0f, right_ghost_row_5, right_ghost_col_5, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_5, &right_ghost_savekey_5, &right_ghost_rotate_5, &right_ghost_move_5, array_left_map);

		////左のゴーストの当たり判定
		//CanMoveGhost(&left_ghost_x_6, &left_ghost_y_6, 0.0f, 0.0f, left_ghost_row_6, left_ghost_col_6, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_6, &left_ghost_savekey_6, &left_ghost_rotate_6, &left_ghost_move_6, array_right_map);
		////右のゴーストの当たり判定
		//CanMoveGhost(&right_ghost_x_6, &right_ghost_y_6, 960.0f, 0.0f, right_ghost_row_6, right_ghost_col_6, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_6, &right_ghost_savekey_6, &right_ghost_rotate_6, &right_ghost_move_6, array_left_map);

		////左のゴーストの当たり判定
		//CanMoveGhost(&left_ghost_x_7, &left_ghost_y_7, 0.0f, 0.0f, left_ghost_row_7, left_ghost_col_7, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_7, &left_ghost_savekey_7, &left_ghost_rotate_7, &left_ghost_move_7, array_right_map);
		////右のゴーストの当たり判定
		//CanMoveGhost(&right_ghost_x_7, &right_ghost_y_7, 960.0f, 0.0f, right_ghost_row_7, right_ghost_col_7, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_7, &right_ghost_savekey_7, &right_ghost_rotate_7, &right_ghost_move_7, array_left_map);

		////左のゴーストの当たり判定
		//CanMoveGhost(&left_ghost_x_8, &left_ghost_y_8, 0.0f, 0.0f, left_ghost_row_8, left_ghost_col_8, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_8, &left_ghost_savekey_8, &left_ghost_rotate_8, &left_ghost_move_8, array_right_map);
		////右のゴーストの当たり判定
		//CanMoveGhost(&right_ghost_x_8, &right_ghost_y_8, 960.0f, 0.0f, right_ghost_row_8, right_ghost_col_8, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_8, &right_ghost_savekey_8, &right_ghost_rotate_8, &right_ghost_move_8, array_left_map);

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		Eat(array_left_map, left_pacman_x, left_pacman_y, &left_cookie, &left_powercookie);

		Eat(array_right_map, right_pacman_x - 960.f, right_pacman_y, &right_cookie, &right_powercookie);







		if (left_powercookie == 1 && dx.KeyState[DIK_E] == dx.PRESS) {
			left_cookie_count = 60 * 8;
			left_powercookie = 0;
		}

		if (right_powercookie == 1 && dx.KeyState[DIK_END] == dx.PRESS) {
			right_cookie_count = 60 * 8;
			right_powercookie = 0;
		}

		if (left_cookie_count != 0) {
			left_cookie_count--;
		}
		if (right_cookie_count != 0) {
			right_cookie_count--;
		}




		//左ステージの描画
		map.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, 0.0f, BLUE_MAPCHIP, array_left_map);

		//右ステージの描画
		map.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 960.f, 0.0f, PINK_MAPCHIP, array_right_map);












		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (left_cookie_count > 0) {
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_1, &left_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, &left_ghostpop_1);
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_1, &left_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, &left_ghostpop_1);


			Draw(left_ghost_x_1, left_ghost_y_1, 0xffffffff, left_ghost_tu, 64.0f * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (left_cookie_count == 0) {
			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_1, left_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);

			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_1, left_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
			//左のゴーストの描画
			Draw(left_ghost_x_1, left_ghost_y_1, 0xffffffff, left_ghost_tu, 64.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		if (right_cookie_count > 0) {
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_1, &right_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, 960.f, &right_ghostpop_1);
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_1, &right_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, 960.f, &right_ghostpop_1);
			//右のゴーストの描画
			Draw(right_ghost_x_1, right_ghost_y_1, 0xffffffff, right_ghost_tu, 64 * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (right_cookie_count == 0) {
			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_1, right_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);

			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_1, right_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
			//右のゴーストの描画
			Draw(right_ghost_x_1, right_ghost_y_1, 0xffffffff, right_ghost_tu, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}


		if (left_cookie_count > 0) {
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_2, &left_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, &left_ghostpop_2);
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_2, &left_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, &left_ghostpop_2);

			Draw(left_ghost_x_2, left_ghost_y_2, 0xffffffff, left_ghost_tu, 64.0f * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (left_cookie_count == 0) {
			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_2, left_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);

			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_2, left_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
			//左のゴーストの描画
			Draw(left_ghost_x_2, left_ghost_y_2, 0xffffffff, left_ghost_tu, 64.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		if (right_cookie_count > 0) {
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_2, &right_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT, 960.f, &right_ghostpop_2);
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_2, &right_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT, 960.f, &right_ghostpop_2);

			//右のゴーストの描画
			Draw(right_ghost_x_2, right_ghost_y_2, 0xffffffff, right_ghost_tu, 64 * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (right_cookie_count == 0) {
			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_2, right_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);

			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_2, right_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
			//右のゴーストの描画
			Draw(right_ghost_x_2, right_ghost_y_2, 0xffffffff, right_ghost_tu, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}


		if (left_cookie_count > 0) {
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_3, &left_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, &left_ghostpop_3);
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_3, &left_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, &left_ghostpop_3);

			Draw(left_ghost_x_3, left_ghost_y_3, 0xffffffff, left_ghost_tu, 64.0f * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (left_cookie_count == 0) {
			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_3, left_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);

			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_3, left_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
			//左のゴーストの描画
			Draw(left_ghost_x_3, left_ghost_y_3, 0xffffffff, left_ghost_tu, 64.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		if (right_cookie_count > 0) {
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_3, &right_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT, 960.f, &right_ghostpop_3);
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_3, &right_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT, 960.f, &right_ghostpop_3);

			//右のゴーストの描画
			Draw(right_ghost_x_3, right_ghost_y_3, 0xffffffff, right_ghost_tu, 64 * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (right_cookie_count == 0) {
			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_3, right_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);

			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_3, right_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
			//右のゴーストの描画
			Draw(right_ghost_x_3, right_ghost_y_3, 0xffffffff, right_ghost_tu, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}



		if (left_cookie_count > 0) {
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_4, &left_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT, 960.0f, &left_ghostpop_4);
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_4, &left_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT, 960.0f, &left_ghostpop_4);

			Draw(left_ghost_x_4, left_ghost_y_4, 0xffffffff, left_ghost_tu, 64.0f * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (left_cookie_count == 0) {
			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_4, left_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);

			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_4, left_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
			//左のゴーストの描画
			Draw(left_ghost_x_4, left_ghost_y_4, 0xffffffff, left_ghost_tu, 64.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		if (right_cookie_count > 0) {
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_4, &right_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT, 0.f, &right_ghostpop_4);
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_4, &right_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT, 0.f, &right_ghostpop_4);

			//右のゴーストの描画
			Draw(right_ghost_x_4, right_ghost_y_4, 0xffffffff, right_ghost_tu, 64 * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (right_cookie_count == 0) {
			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_4, right_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);

			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_4, right_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
			//右のゴーストの描画
			Draw(right_ghost_x_4, right_ghost_y_4, 0xffffffff, right_ghost_tu, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}


		if (left_cookie_count > 0) {
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_5, &left_ghost_y_5, DRAW_WIDTH, DRAW_HEIGHT, 960.0f, &left_ghostpop_5);
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_5, &left_ghost_y_5, DRAW_WIDTH, DRAW_HEIGHT, 960.0f, &left_ghostpop_5);

			Draw(left_ghost_x_5, left_ghost_y_5, 0xffffffff, left_ghost_tu, 64.0f * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (left_cookie_count == 0) {
			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_5, left_ghost_y_5, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);

			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_5, left_ghost_y_5, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
			//左のゴーストの描画
			Draw(left_ghost_x_5, left_ghost_y_5, 0xffffffff, left_ghost_tu, 64.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		if (right_cookie_count > 0) {
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_5, &right_ghost_y_5, DRAW_WIDTH, DRAW_HEIGHT, 0.f, &right_ghostpop_5);
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_5, &right_ghost_y_5, DRAW_WIDTH, DRAW_HEIGHT, 0.f, &right_ghostpop_5);

			//右のゴーストの描画
			Draw(right_ghost_x_5, right_ghost_y_5, 0xffffffff, right_ghost_tu, 64 * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (right_cookie_count == 0) {
			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_1, right_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);

			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_1, right_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
			//右のゴーストの描画
			Draw(right_ghost_x_1, right_ghost_y_1, 0xffffffff, right_ghost_tu, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}


		if (left_cookie_count > 0) {
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_6, &left_ghost_y_6, DRAW_WIDTH, DRAW_HEIGHT, 960.0f, &left_ghostpop_6);
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_6, &left_ghost_y_6, DRAW_WIDTH, DRAW_HEIGHT, 960.0f, &left_ghostpop_6);

			Draw(left_ghost_x_6, left_ghost_y_6, 0xffffffff, left_ghost_tu, 64.0f * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (left_cookie_count == 0) {
			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_6, left_ghost_y_6, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);

			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_6, left_ghost_y_6, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
			//左のゴーストの描画
			Draw(left_ghost_x_6, left_ghost_y_6, 0xffffffff, left_ghost_tu, 64.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		if (right_cookie_count > 0) {
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_6, &right_ghost_y_6, DRAW_WIDTH, DRAW_HEIGHT, 0.f, &right_ghostpop_6);
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_6, &right_ghost_y_6, DRAW_WIDTH, DRAW_HEIGHT, 0.f, &right_ghostpop_6);

			//右のゴーストの描画
			Draw(right_ghost_x_6, right_ghost_y_6, 0xffffffff, right_ghost_tu, 64 * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (right_cookie_count == 0) {
			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_6, right_ghost_y_6, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);

			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_6, right_ghost_y_6, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
			//右のゴーストの描画
			Draw(right_ghost_x_6, right_ghost_y_6, 0xffffffff, right_ghost_tu, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}


		if (left_cookie_count > 0) {
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_7, &left_ghost_y_7, DRAW_WIDTH, DRAW_HEIGHT, 960.0f, &left_ghostpop_7);
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_7, &left_ghost_y_7, DRAW_WIDTH, DRAW_HEIGHT, 960.0f, &left_ghostpop_7);

			Draw(left_ghost_x_7, left_ghost_y_7, 0xffffffff, left_ghost_tu, 64.0f * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (left_cookie_count == 0) {
			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_7, left_ghost_y_7, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);

			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_7, left_ghost_y_7, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
			//左のゴーストの描画
			Draw(left_ghost_x_7, left_ghost_y_7, 0xffffffff, left_ghost_tu, 64.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		if (right_cookie_count > 0) {
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_7, &right_ghost_y_7, DRAW_WIDTH, DRAW_HEIGHT, 0.f, &right_ghostpop_7);
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_7, &right_ghost_y_7, DRAW_WIDTH, DRAW_HEIGHT, 0.f, &right_ghostpop_7);

			//右のゴーストの描画
			Draw(right_ghost_x_7, right_ghost_y_7, 0xffffffff, right_ghost_tu, 64 * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (right_cookie_count == 0) {
			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_7, right_ghost_y_7, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);

			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_7, right_ghost_y_7, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
			//右のゴーストの描画
			Draw(right_ghost_x_7, right_ghost_y_7, 0xffffffff, right_ghost_tu, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}



		if (left_cookie_count > 0) {
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_8, &left_ghost_y_8, DRAW_WIDTH, DRAW_HEIGHT, 960.0f, &left_ghostpop_8);
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_8, &left_ghost_y_8, DRAW_WIDTH, DRAW_HEIGHT, 960.0f, &left_ghostpop_8);

			Draw(left_ghost_x_8, left_ghost_y_8, 0xffffffff, left_ghost_tu, 64.0f * 4.0f / 512.0f
				, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (left_cookie_count == 0) {
			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_8, left_ghost_y_8, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);

			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_8, left_ghost_y_8, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
			//左のゴーストの描画
			Draw(left_ghost_x_8, left_ghost_y_8, 0xffffffff, left_ghost_tu, 64.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		if (right_cookie_count > 0) {
			Left_Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_8, &right_ghost_y_8, DRAW_WIDTH, DRAW_HEIGHT, 0.f, &right_ghostpop_8);
			Right_Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_8, &right_ghost_y_8, DRAW_WIDTH, DRAW_HEIGHT, 0.f, &right_ghostpop_8);

			//右のゴーストの描画
			Draw(right_ghost_x_8, right_ghost_y_8, 0xffffffff, right_ghost_tu, 64 * 4.0f / 512.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		else if (right_cookie_count == 0) {
			Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_8, right_ghost_y_8, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);

			Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_8, right_ghost_y_8, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
			//右のゴーストの描画
			Draw(right_ghost_x_8, right_ghost_y_8, 0xffffffff, right_ghost_tu, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		Pop(left_ghost_x_1, &left_ghost_y_1, &left_ghostpop_1);

		Pop(left_ghost_x_2, &left_ghost_y_2, &left_ghostpop_2);

		Pop(left_ghost_x_3, &left_ghost_y_3, &left_ghostpop_3);

		Pop(left_ghost_x_4, &left_ghost_y_4, &left_ghostpop_4);

		Pop(right_ghost_x_1, &right_ghost_y_1, &right_ghostpop_1);

		Pop(right_ghost_x_2, &right_ghost_y_2, &right_ghostpop_2);

		Pop(right_ghost_x_3, &right_ghost_y_3, &right_ghostpop_3);

		Pop(right_ghost_x_4, &right_ghost_y_4, &right_ghostpop_4);

		Pop(left_ghost_x_5, &left_ghost_y_5, &left_ghostpop_5);

		Pop(left_ghost_x_6, &left_ghost_y_6, &left_ghostpop_6);

		Pop(left_ghost_x_7, &left_ghost_y_7, &left_ghostpop_7);

		Pop(left_ghost_x_8, &left_ghost_y_4, &left_ghostpop_8);

		Pop(right_ghost_x_5, &right_ghost_y_5, &right_ghostpop_5);

		Pop(right_ghost_x_6, &right_ghost_y_6, &right_ghostpop_6);

		Pop(right_ghost_x_7, &right_ghost_y_7, &right_ghostpop_7);

		Pop(right_ghost_x_8, &right_ghost_y_8, &right_ghostpop_8);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		//左のパックマンの描画
		Draw(left_pacman_x, left_pacman_y, 0xffffffff, pacman_tu, 0.0f, 32, 32, 0.25f, 0.5f, PACMAN, left_pacman_rotate);

		//右のパックマンの描画
		Draw(right_pacman_x, right_pacman_y, 0xffffffff, pacman_tu, 0.5f, 32, 32, 0.25f, 0.5f, PACMAN, right_pacman_rotate);






		RECT rect_1;//表示したい範囲

	 /* 表示範囲の指定 */
		rect_1.left = 0;
		rect_1.top = 1000;
		rect_1.right = 1500;
		rect_1.bottom = 1200;






		RECT rect_2;//表示したい範囲

	 /* 表示範囲の指定 */
		rect_2.left = 960;
		rect_2.top = 1000;
		rect_2.right = 1500 + 960;
		rect_2.bottom = 1200;





		/* 文字列の表示 */
		sprintf_s(buf, 256, "今、パワークッキーが%dコ、残り%d秒",left_powercookie,left_cookie_count/60 );
		dx.pFont->DrawText(NULL, buf, -1, &rect_1, DT_LEFT | DT_NOCLIP, D3DCOLOR_ARGB(255, 255, 255, 255));

		sprintf_s(buf, 256, "今、パワークッキーが%dコ、残り%d秒",right_powercookie, right_cookie_count / 60);
		dx.pFont->DrawText(NULL, buf, -1, &rect_2, DT_LEFT | DT_NOCLIP, D3DCOLOR_ARGB(255, 255, 255, 255));

	/*	Draw(0, 600, 0xffffff, left_gauge_tu, 0.0f, 800, 200, 1 / 20, 1 / 2, GAUGE);

		Draw(960, 600, 0xffffff, right_gauge_tu, 0.5f, 800, 200, 1 / 20, 1 / 2, GAUGE);
*/





	}
	else {













	

	
		if (countdown_tv < 1.0f)
		{
			Draw(130, 170, 0xffffffff, countdown_tu, countdown_tv, 700, 700, 0.5f, 0.25f, COUNTDOWN_BLUE);
			Draw(1090, 170, 0xffffffff, countdown_tu, countdown_tv, 700, 700, 0.5f, 0.25f, COUNTDOWN_PINK);
		}

		if (flamecount_a == 10)
		{
			countdown_tu += 0.5f;

		}
		if (flamecount_a == 80)
		{
			countdown_tu = 0.0f;
			countdown_tv += 0.25f;

		}
		if (flamecount_a == 90)
		{
			countdown_tu = 0.5f;

		}
		if (flamecount_a == 160)
		{
			countdown_tu = 0.0f;
			countdown_tv += 0.25f;

		}
		if (flamecount_a == 170)
		{
			countdown_tu = 0.5f;

		}
		if (flamecount_a == 240)
		{
			countdown_tu = 0.0f;
			countdown_tv += 0.25f;

		}
		if (flamecount_a == 250)
		{
			countdown_tu = 0.5f;

		}
		if (flamecount_a == 360)
		{
			countdown_tu = 0.0f;
			countdown_tv += 0.25f;
		}
		if (flamecount_a >= 360) {
			flamecount_a = 365;
		}
	}
	//リリースのフェーズへ
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

///ゴーストもできるように改善の余地あり
//パックマンの当たり判定関数
void Game::JudgeCollision(float* x,float* y,float start_x,float start_y,int row_,int col_,float draw_width,float draw_height,KEY *key,KEY *savekey,KEY* rotate_key,int** map) {
	if (((int)*x % (int)draw_width) == 0 && ((int)*y % (int)draw_height == 0)) {
		*rotate_key = *savekey;
		int col = (*x - start_x) / draw_width;
		int row = (*y - start_y) / draw_height;
		if ((row + row) != -1 || (col + col_) != -1) {
			if (map[row + row_][col + col_] == 0 || map[row + row_][col + col_] == 35 || map[row + row_][col + col_] == 38|| map[row + row_][col + col_] == 39|| map[row + row_][col + col_] == 40) {
				*key = *savekey;
				
				switch (*key) {
				case RIGHT:
					*x += 2;
						break;
				case DOWN:
					*y += 2;
					break;
				case LEFT:
					*x -= 2;
					break;
				case UP:
					*y -= 2;
					break;
				case STOP:

					break;
				default:

					break;

				}
			}
		}
	}
	else {
		switch (*key) {
		case RIGHT:
			*x += 2;
			break;
		case DOWN:
			*y += 2;
			break;
		case LEFT:
			*x -= 2;
			break;
		case UP:
			*y -= 2;
			break;
		case STOP:

			break;
		default:

			break;

		}
	}
}

///上の関数にまとめたい
//パックマン探す関数
//ゴーストの移動できる方向の確認
void Game::CanMoveGhost(float* x, float* y, float start_x, float start_y, int row_, int col_, float draw_width, float draw_height, KEY* key, KEY* savekey, KEY* rotate_key,int* ghost_move, int** map) {
	if (((int)* x % (int)draw_width) == 0 && ((int)* y % (int)draw_height == 0)) {
		int col = (*x - start_x) / draw_width;
		int row = (*y - start_y) / draw_height;
		if ((row + row_) != -1 && (col + col_) != -1) {
			if (map[row + row_][col + col_] == 0 || map[row + row_][col + col_] == 35 || map[row + row_][col + col_] == 38 || map[row + row_][col + col_] == 39 || map[row + row_][col + col_] == 40) {
				*key = *savekey;
				*rotate_key = *savekey;
				switch (*key) {
				case UP:
					*y -= 2;
					break;
				case DOWN:
					*y += 2;
					break;
				case RIGHT:
					*x += 2;
					break;
				case LEFT:
					*x -= 2;
					break;
				default:
					break;
				}
			}
			else if (map[row + row_][col + col_] != 0 && map[row + row_][col + col_] != 35 && map[row + row_][col + col_] != 38 || map[row + row_][col + col_] == 39 || map[row + row_][col + col_] == 40) {
				*ghost_move = rand() % 4;
			}
		}
	}
	else {
		switch (*key) {
		case UP:
			*y -= 2;
			break;
		case DOWN:
			*y += 2;
			break;
		case RIGHT:
			*x += 2;
			break;
		case LEFT:
			*x -= 2;
			break;
		default:
			break;
		}
	}
}

//void Game::LookForPacman(int** map) {
//
//	int ro = 0;
//	int co = 1;
//	if (((int)left_ghost_x % (int)DRAW_WIDTH) == 0 && ((int)left_ghost_y % (int)DRAW_HEIGHT == 0)) {
//		for (int i = 0; i < (4 * 28); i++) {
//			//右の確認
//			if (0 < co) {
//				co++;
//			}
//			//左に移行
//			if (co == 28) {
//				co = -1;
//			}
//			//左の確認
//			if (co < 0) {
//				co--;
//			}
//			//下に移行
//			if (co == -28) {
//				co = 0;
//				ro++;
//			}
//			//下の確認
//			if (0 < ro) {
//				ro++;
//			}
//			//上に移行
//			if (ro == 28) {
//				ro = -1;
//			}
//			//上の確認
//			if (ro < 0) {
//				ro--;
//			}
//		}
//			//if (map[(int)(left_ghost_x / DRAW_WIDTH) + ro][(int)(left_ghost_x / DRAW_WIDTH) + co] == map[(int)(left_pacman_x / DRAW_WIDTH)][(int)(left_pacman_x / DRAW_WIDTH)]) {//0 || map[(int)(left_ghost_x / DRAW_WIDTH) + ro][(int)(left_ghost_x / DRAW_WIDTH) + co] == 35 || map[(int)(left_ghost_x / DRAW_WIDTH) + ro][(int)(left_ghost_x / DRAW_WIDTH) + co] == 38) {
//			if ((int)((left_ghost_x / DRAW_WIDTH) + ro) == (int)((left_pacman_x / DRAW_WIDTH)) && (int)((left_ghost_y / DRAW_WIDTH) + co) == (int)((left_pacman_y / DRAW_WIDTH))){
//				//switch (ro && co)
//				if (ro >= 1 && co == 0) {
//					ghostmove_x = 32;
//					ghostmove_y = 0;
//				}
//				else if (ro <= -1 && co == 0) {
//					ghostmove_x = -32;
//					ghostmove_y = 0;
//				}
//				else if (ro == 0 && co >= 1) {
//					ghostmove_x = 0;
//					ghostmove_y = 32;
//				}
//				else if (ro == 0 && co <= -1) {
//					ghostmove_x = 0;
//					ghostmove_y = -32;
//				}
//				else if (ro == 0 && co == 0) {
//					ghostmove_x = 0;
//					ghostmove_y = 0;
//				}
//
//			}
//			//}
//		
//		left_ghost_x += ghostmove_x;
//		left_ghost_y += ghostmove_y;
//	}
//}

void Game::Die(float player_x,float player_y,float player_width,float player_height,float enemy_x,float enemy_y,float enemy_width,float enemy_hieght,int pacman_life) {
	if ((player_x + player_width) > enemy_x && player_x < (enemy_x + enemy_width) && player_y < (enemy_y + enemy_hieght) && (player_y + player_height) > enemy_y) {
		pacman_life--;
	}
	if (pacman_life == 0) {
		Phase = RELEASES;
		
		pacman_life = 1;

		if (player_x == left_pacman_x) {
			dx.win = 2;
		}
		if (player_x == right_pacman_x) {
			dx.win = 1;
		}
	}
}

void Game::Eat(int** map, float ghost_x, float ghost_y, int* cookie, int* power_cookie) {
	if (map[(int)(ghost_y / DRAW_HEIGHT)][(int)(ghost_x / DRAW_WIDTH)] == 35)
	{
		map[(int)(ghost_y / DRAW_HEIGHT)][(int)(ghost_x / DRAW_WIDTH)] = 39;
		repop_cookie_count[eating_cookie_Val] = 1;
		eating_cookie[eating_cookie_Val][eating_cookie_Num] = ghost_y / DRAW_HEIGHT;
		eating_cookie[eating_cookie_Val++][eating_cookie_Num + 1] = ghost_x / DRAW_WIDTH;
		if (eating_cookie_Val == 100)
		{
			eating_cookie_Val = 0;
		}
		if (*power_cookie == 0) {
			*cookie += 1;
		}
		if (*cookie == 80) {
			*cookie = 0;
			*power_cookie = 1;
		}
	}
	if (map[(int)(ghost_y / DRAW_HEIGHT)][(int)(ghost_x / DRAW_WIDTH)] == 38)
	{
		map[(int)(ghost_y / DRAW_HEIGHT)][(int)(ghost_x / DRAW_WIDTH)] = 40;
		repop_power_cookie_count[eating_power_cookie_Val] = 1;
		eating_power_cookie[eating_power_cookie_Val][eating_power_cookie_Num] = ghost_y / DRAW_HEIGHT;
		eating_power_cookie[eating_power_cookie_Val++][eating_power_cookie_Num + 1] = ghost_x / DRAW_WIDTH;
		*power_cookie = 1;
	}


}

void Game::Repop(int** map, int cookie) {

	if (*repop_cookie_count == 60 * 7) {

		if (map[eating_cookie[cookie][eating_cookie_Num]][eating_cookie[cookie][eating_power_cookie_Num + 1]] == 39)
		{
			map[eating_cookie[cookie][eating_cookie_Num]][eating_cookie[cookie][eating_power_cookie_Num + 1]] = 35;
			*repop_cookie_count = 0;
		}
	}
	if (*repop_power_cookie_count == (60 * 15)) {
		if (map[eating_power_cookie[cookie][eating_power_cookie_Num]][eating_power_cookie[cookie][eating_power_cookie_Num + 1]] == 40)
		{

			map[eating_power_cookie[cookie][eating_power_cookie_Num]][eating_power_cookie[cookie][eating_power_cookie_Num + 1]] = 38;

			*repop_power_cookie_count = 0;
		}
	}

}


void Game::Pop(float enemy_x,float* enemy_y,int* enemy_pop) {
	


	if (*enemy_pop >= 0) {
		*enemy_pop -= 1;
	}
	if (*enemy_pop == 0) {
		
		*enemy_y += 64.0f;
	
	}

};


void Game::Right_Kill(float player_x, float player_y, float player_width, float player_height, float* enemy_x, float* enemy_y, float enemy_width, float enemy_hieght, float start_x, int* enemy_pop) {
	
	int nextpop = rand() % 4;
	if ((player_x + player_width) > * enemy_x && player_x < (*enemy_x + enemy_width) && player_y < (*enemy_y + enemy_hieght) && (player_y + player_height) > * enemy_y) {
		switch (nextpop) {
		case 0:
				*enemy_x = 32 * 3 + start_x;
				*enemy_y = 32 * 3;
				
		case 1:
			*enemy_x = 32 * 9 + start_x;
			*enemy_y = 32 * 3;
			break;
		case 2:
			*enemy_x = 32 * 18 + start_x;
			*enemy_y = 32 * 3;
			break;
		case 3:
			*enemy_x = 32 * 24 + start_x;
			*enemy_y = 32 * 3;
			break;
		}
		*enemy_pop = 2 * 60;
	}
	
}

void Game::Left_Kill(float player_x, float player_y, float player_width, float player_height, float* enemy_x, float* enemy_y, float enemy_width, float enemy_hieght, float start_x, int* enemy_pop) {
	
	int nextpop = rand() % 4;
	if ((player_x + player_width) > * enemy_x && player_x < (*enemy_x + enemy_width) && player_y < (*enemy_y + enemy_hieght) && (player_y + player_height) > * enemy_y) {
		switch (nextpop) {
		case 0:
			*enemy_x = 32 * 3;
			*enemy_y = 32 * 3;

		case 1:
			*enemy_x = 32 * 9;
			*enemy_y = 32 * 3;
			break;
		case 2:
			*enemy_x = 32 * 18;
			*enemy_y = 32 * 3;
			break;
		case 3:
			*enemy_x = 32 * 24;
			*enemy_y = 32 * 3;
			break;
		}
		*enemy_pop = 2 * 60;
	}
}