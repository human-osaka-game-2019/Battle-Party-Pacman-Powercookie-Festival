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

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {


	flamecount++;
	
	///アニメーション関数ですべてのキャラクターのアニメーショできるようにする
	//パックマンのアニメーション
	if (flamecount % 6 == 0) {
		pacman_tu += 0.25f;
	}
	if (1.0f <= pacman_tu) {
		pacman_tu = 0.0f;
	}





	left_ghost_tu_1 += 64.0f / 512.0f;
	right_ghost_tu_1 += 64.0f / 512.0f;
	if (left_ghost_tu_1 >= (64.0f * 2.0f) / 512.0f)
	{
		left_ghost_tu_1 = 0;
	}

	if (right_ghost_tu_1 >= (64.0f * 4.0f) / 512.0f)
	{
		right_ghost_tu_1 = (64.0f * 2.0f) / 512.0f;
	}


	

	///key入力の関数化
	//左パックマンのkey入力
	if (dx.KeyState[DIK_UP] == dx.PRESS) {
		left_pacman_savekey = UP;
		//左ステージのkey入力による当たり判定の方向
		left_pacman_row = -1;
		left_pacman_col = 0;
	}else if (dx.KeyState[DIK_DOWN] == dx.PRESS) {
		left_pacman_savekey = DOWN;
		//左ステージのkey入力による当たり判定の方向
		left_pacman_row = 1;
		left_pacman_col = 0;
	}else if (dx.KeyState[DIK_LEFT] == dx.PRESS) {
		left_pacman_savekey = LEFT;
		//左ステージのkey入力による当たり判定の方向
		left_pacman_row = 0;
		left_pacman_col = -1;
	}else if (dx.KeyState[DIK_RIGHT] == dx.PRESS) {
		left_pacman_savekey = RIGHT;
		//左ステージのkey入力による当たり判定の方向
		left_pacman_row = 0;
		left_pacman_col = 1;
	}

	//右パックマンのkey入力
	if (dx.KeyState[DIK_W] == dx.PRESS) {
		right_pacman_savekey = UP;
		//右ステージのkey入力による当たり判定の方向
		right_pacman_row = -1;
		right_pacman_col = 0;
	}else if (dx.KeyState[DIK_S] == dx.PRESS) {
		right_pacman_savekey = DOWN;
		//右ステージのkey入力による当たり判定の方向
		right_pacman_row = 1;
		right_pacman_col = 0;
	}else if (dx.KeyState[DIK_A] == dx.PRESS) {
		right_pacman_savekey = LEFT;
		//右ステージのkey入力による当たり判定の方向
		right_pacman_row = 0;
		right_pacman_col = -1;
	}else if (dx.KeyState[DIK_D] == dx.PRESS) {
		right_pacman_savekey = RIGHT;
		//右ステージのkey入力による当たり判定の方向
		right_pacman_row = 0;
		right_pacman_col = 1;
	}

	//std::mt19937 rand{ std::random_device{}() };
	//std::uniform_int_distribution<int> a(0, 3);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if ((int)(left_ghost_y_1) % (int)(DRAW_HEIGHT) == 0 && (int)(left_ghost_x_1) % (int)(DRAW_WIDTH)) {
		if ((map.left_map[(int)(left_ghost_y_1 / DRAW_HEIGHT) + left_ghost_row_1][(int)(left_ghost_x_1 / DRAW_WIDTH) + left_ghost_col_1] != 0) && (map.left_map[(int)(left_ghost_y_1 / DRAW_HEIGHT) + left_ghost_row_1][(int)(left_ghost_x_1 / DRAW_WIDTH) + left_ghost_col_1] != 35) && (map.left_map[(int)(left_ghost_y_1 / DRAW_HEIGHT) + left_ghost_row_1][(int)(left_ghost_x_1 / DRAW_WIDTH) + left_ghost_col_1] != 38)) {
			int save = left_ghost_move_1;
			for (int i = 0; i < 1000; i++) {
				srand((unsigned int)time(NULL));
				left_ghost_move_1 = rand() % 4;//a(rand);
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
		left_ghost_col_1= 1;
		break;
	case 3:
		left_ghost_savekey_1 = LEFT;
		left_ghost_row_1 = 0;
		left_ghost_col_1 = -1;
		break;
	default:

		break;
	}
	if ((int)(left_ghost_y_1) % (int)(DRAW_HEIGHT) == 0 && (int)(left_ghost_x_1) % (int)(DRAW_WIDTH)) {
		if ((map.left_map[(int)(left_ghost_y_2 / DRAW_HEIGHT) + left_ghost_row_2][(int)(left_ghost_x_2 / DRAW_WIDTH) + left_ghost_col_2] != 0) && (map.left_map[(int)(left_ghost_y_2 / DRAW_HEIGHT) + left_ghost_row_2][(int)(left_ghost_x_2 / DRAW_WIDTH) + left_ghost_col_2] != 35) && (map.left_map[(int)(left_ghost_y_2 / DRAW_HEIGHT) + left_ghost_row_2][(int)(left_ghost_x_2 / DRAW_WIDTH) + left_ghost_col_2] != 38)) {
			int save = left_ghost_move_2;
			for (int i = 0; i < 1000; i++) {
				srand((unsigned int)time(NULL));
				left_ghost_move_2 = rand() % 4;//a(rand);
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
				srand((unsigned int)time(NULL));
				left_ghost_move_3 = rand() % 4;//a(rand);
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
				srand((unsigned int)time(NULL));
				left_ghost_move_4 = rand() % 4;//a(rand);
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if ((int)(right_ghost_y_1) % (int)(DRAW_HEIGHT) == 0 && (int)(right_ghost_x_1) % (int)(DRAW_WIDTH)) {
		if ((map.right_map[(int)(right_ghost_y_1 / DRAW_HEIGHT) + right_ghost_row_1][(int)(right_ghost_x_1 / DRAW_WIDTH) + right_ghost_col_1] != 0) && (map.right_map[(int)(right_ghost_y_1 / DRAW_HEIGHT) + right_ghost_row_1][(int)(right_ghost_x_1 / DRAW_WIDTH) + right_ghost_col_1] != 35) && (map.right_map[(int)(right_ghost_y_1 / DRAW_HEIGHT) + right_ghost_row_1][(int)(right_ghost_x_1 / DRAW_WIDTH) + right_ghost_col_1] != 38)) {
			int save = right_ghost_move_1;
			for (int i = 0; i < 1000; i++) {
				srand((unsigned int)time(NULL));
				right_ghost_move_1 = rand() % 4;//a(rand);
				if (save == right_ghost_move_1) {
					continue;
				}
				break;
			}
		}
	}

	switch (right_ghost_move_1) {
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
				srand((unsigned int)time(NULL));
				right_ghost_move_2 = rand() % 4;//a(rand);
				if (save == right_ghost_move_2) {
					continue;
				}
				break;
			}
		}
	}

	switch (right_ghost_move_2) {
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
				srand((unsigned int)time(NULL));
				right_ghost_move_3 = rand() % 4;//a(rand);
				if (save == right_ghost_move_3) {
					continue;
				}
				break;
			}
		}
	}

	switch (right_ghost_move_1) {
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
				srand((unsigned int)time(NULL));
				right_ghost_move_4 = rand() % 4;//a(rand);
				if (save == right_ghost_move_4) {
					continue;
				}
				break;
			}
		}
	}

	switch (right_ghost_move_4) {
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
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//左画面の真ん中の逆から出てくる処理
	if ((14 == (int)(left_pacman_y / DRAW_HEIGHT)) && (0 == (int)(left_pacman_x / DRAW_WIDTH))) {
		left_pacman_x = DRAW_WIDTH * 27;
	}else if ((14 == (int)(left_pacman_y / DRAW_HEIGHT)) && (27 == (int)(left_pacman_x / DRAW_WIDTH))) {
		left_pacman_x = 0.0f;
	}
	 







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








	//左のパックマンの当たり判定
	JudgeCollision(&left_pacman_x, &left_pacman_y, 0.0f, 0.0f, left_pacman_row, left_pacman_col, DRAW_WIDTH, DRAW_HEIGHT, &left_pacman_key, &left_pacman_savekey,&left_pacman_rotate, array_left_map);
	//右のパックマンの当たり判定
	JudgeCollision(&right_pacman_x, &right_pacman_y, 896.0f + 64.f, 0.0f, right_pacman_row, right_pacman_col, DRAW_WIDTH, DRAW_HEIGHT, &right_pacman_key, &right_pacman_savekey,&right_pacman_rotate, array_right_map);
	
	
	
	
	
	
	
	
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	//左のゴーストの当たり判定
	CanMoveGhost(&left_ghost_x_1, &left_ghost_y_1, 0.0f, 0.0f, left_ghost_row_1, left_ghost_col_1, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_1, &left_ghost_savekey_1, &left_ghost_rotate_1, array_left_map);
	//右のゴーストの当たり判定
	CanMoveGhost(&right_ghost_x_1, &right_ghost_y_1, 0.0f, 0.0f, right_ghost_row_1, right_ghost_col_1, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_1, &right_ghost_savekey_1, &right_ghost_rotate_1, array_right_map);

	//左のゴーストの当たり判定
	CanMoveGhost(&left_ghost_x_2, &left_ghost_y_2, 0.0f, 0.0f, left_ghost_row_2, left_ghost_col_2, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_2, &left_ghost_savekey_2, &left_ghost_rotate_2, array_left_map);
	//右のゴーストの当たり判定
	CanMoveGhost(&right_ghost_x_2, &right_ghost_y_2, 0.0f, 0.0f, right_ghost_row_2, right_ghost_col_2, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_2, &right_ghost_savekey_2, &right_ghost_rotate_2, array_right_map);

	//左のゴーストの当たり判定
	CanMoveGhost(&left_ghost_x_3, &left_ghost_y_3, 0.0f, 0.0f, left_ghost_row_3, left_ghost_col_3, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_3, &left_ghost_savekey_3, &left_ghost_rotate_3, array_left_map);
	//右のゴーストの当たり判定
	CanMoveGhost(&right_ghost_x_3, &right_ghost_y_3, 0.0f, 0.0f, right_ghost_row_3, right_ghost_col_3, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_3, &right_ghost_savekey_3, &right_ghost_rotate_3, array_right_map);

	//左のゴーストの当たり判定
	CanMoveGhost(&left_ghost_x_4, &left_ghost_y_4, 0.0f, 0.0f, left_ghost_row_4, left_ghost_col_4, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key_4, &left_ghost_savekey_4, &left_ghost_rotate_4, array_left_map);
	//右のゴーストの当たり判定
	CanMoveGhost(&right_ghost_x_4, &right_ghost_y_4, 0.0f, 0.0f, right_ghost_row_4, right_ghost_col_4, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key_4, &right_ghost_savekey_4, &right_ghost_rotate_4, array_right_map);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	Eat(array_left_map, left_pacman_x, left_pacman_y,&left_cookie,&left_powercookie);

	Eat(array_right_map, right_pacman_x - 960.f, right_pacman_y,&right_cookie,&right_powercookie);
	






	if (left_powercookie == 1 && dx.KeyState[DIK_Q] == dx.PRESS) {
		left_cookie_count = 60*8;
		left_powercookie = 0;
	}
	
	if (right_powercookie == 1 && dx.KeyState[DIK_W] == dx.PRESS) {
		right_cookie_count = 60*8;
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
		Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_1, &left_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT,0.0f,&left_ghostpop_1);
		
		Draw(left_ghost_x_1, left_ghost_y_1, 0xffffffff, left_ghost_tu_1, 0.625f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	else if(left_cookie_count == 0) {
		
		Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_1, left_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
		//左のゴーストの描画
		Draw(left_ghost_x_1, left_ghost_y_1, 0xffffffff, left_ghost_tu_1, 0.f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	if (right_cookie_count > 0) {
		Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_1, &right_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT,960.f, &right_ghostpop_1);
		//右のゴーストの描画
		Draw(right_ghost_x_1, right_ghost_y_1, 0xffffffff, right_ghost_tu_1, 0.625f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	else if (right_cookie_count == 0) {
		
		Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_1, right_ghost_y_1, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
		//右のゴーストの描画
		Draw(right_ghost_x_1, right_ghost_y_1, 0xffffffff, right_ghost_tu_1, 0.125f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}


	if (left_cookie_count > 0) {
		Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_2, &left_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT,0.0f,&left_ghostpop_2);

		Draw(left_ghost_x_2, left_ghost_y_2, 0xffffffff, left_ghost_tu_2, 0.125f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	else if (left_cookie_count == 0) {

		Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_2, left_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
		//左のゴーストの描画
		Draw(left_ghost_x_2, left_ghost_y_1, 0xffffffff, left_ghost_tu_2, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	if (right_cookie_count > 0) {
		Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_2, &right_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT,960.f, &right_ghostpop_2);
		//右のゴーストの描画
		Draw(right_ghost_x_2, right_ghost_y_2, 0xffffffff, right_ghost_tu_2, 0.625f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	else if (right_cookie_count == 0) {

		Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_2, right_ghost_y_2, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
		//右のゴーストの描画
		Draw(right_ghost_x_2, right_ghost_y_2, 0xffffffff, right_ghost_tu_2, 0.125f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}


	if (left_cookie_count > 0) {
		Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_3, &left_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT,0.0f, &left_ghostpop_3);

		Draw(left_ghost_x_3, left_ghost_y_3, 0xffffffff, left_ghost_tu_3, 0.125f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	else if (left_cookie_count == 0) {

		Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_3, left_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
		//左のゴーストの描画
		Draw(left_ghost_x_3, left_ghost_y_3, 0xffffffff, left_ghost_tu_3, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	if (right_cookie_count > 0) {
		Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_3, &right_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT,960.f, &right_ghostpop_3);
		//右のゴーストの描画
		Draw(right_ghost_x_3, right_ghost_y_3, 0xffffffff, right_ghost_tu_3, 0.625f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	else if (right_cookie_count == 0) {

		Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_3, right_ghost_y_3, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
		//右のゴーストの描画
		Draw(right_ghost_x_3, right_ghost_y_3, 0xffffffff, right_ghost_tu_3, 0.125f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}



	if (left_cookie_count > 0) {
		Kill(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_x_4, &left_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT,0.0f, &left_ghostpop_4);

		Draw(left_ghost_x_4, left_ghost_y_4, 0xffffffff, left_ghost_tu_4, 0.125f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	else if (left_cookie_count == 0) {

		Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, left_ghost_x_4, left_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT, left_pacman_life);
		//左のゴーストの描画
		Draw(left_ghost_x_4, left_ghost_y_4, 0xffffffff, left_ghost_tu_4, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	if (right_cookie_count > 0) {
		Kill(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_x_4, &right_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT,960.f,&right_ghostpop_4);
		//右のゴーストの描画
		Draw(right_ghost_x_4, right_ghost_y_4, 0xffffffff, right_ghost_tu_4, 0.625f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}
	else if (right_cookie_count == 0) {

		Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x_4, right_ghost_y_4, DRAW_WIDTH, DRAW_HEIGHT, right_pacman_life);
		//右のゴーストの描画
		Draw(right_ghost_x_4, right_ghost_y_4, 0xffffffff, right_ghost_tu_4, 0.125f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Pop(left_ghost_x_1,&left_ghost_y_1,&left_ghostpop_1);

	Pop(left_ghost_x_2, &left_ghost_y_2, &left_ghostpop_2);

	Pop(left_ghost_x_3, &left_ghost_y_3, &left_ghostpop_3);

	Pop(left_ghost_x_4, &left_ghost_y_4, &left_ghostpop_4);

	Pop(right_ghost_x_1, &right_ghost_y_1, &right_ghostpop_1);

	Pop(right_ghost_x_2, &right_ghost_y_2, &right_ghostpop_2);

	Pop(right_ghost_x_3, &right_ghost_y_3, &right_ghostpop_3);

	Pop(right_ghost_x_4, &right_ghost_y_4, &right_ghostpop_4);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	
	//左のパックマンの描画
	Draw(left_pacman_x, left_pacman_y, 0xffffffff, pacman_tu, 0.0f, 32, 32, 0.25f, 0.5f, PACMAN, left_pacman_rotate);

	//右のパックマンの描画
	Draw(right_pacman_x, right_pacman_y, 0xffffffff, pacman_tu, 0.5f, 32, 32, 0.25f, 0.5f, PACMAN, right_pacman_rotate);






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
			if (map[row + row_][col + col_] == 0 || map[row + row_][col + col_] == 35 || map[row + row_][col + col_] == 38) {
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
void Game::CanMoveGhost(float* x, float* y, float start_x, float start_y, int row_, int col_, float draw_width, float draw_height, KEY* key, KEY* savekey,KEY* rotate_key, int** map) {
	if (((int)* x % (int)draw_width) == 0 && ((int)* y % (int)draw_height == 0)) {
		int col = (*x - start_x) / draw_width;
		int row = (*y - start_y) / draw_height;
		if ((row + row) != -1 && (col + col_) != -1) {
			if (map[row + row_][col + col_] == 0 || map[row + row_][col + col_] == 35 || map[row + row_][col + col_] == 38) {
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
	}
}

void Game::Eat(int** map,float ghost_x,float ghost_y,int* cookie,int* power_cookie) {
	if (map[(int)(ghost_y / DRAW_HEIGHT)][(int)(ghost_x / DRAW_WIDTH)] == 35)
	{
		map[(int)(ghost_y / DRAW_HEIGHT)][(int)(ghost_x / DRAW_WIDTH)] = 0;
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
		map[(int)(ghost_y / DRAW_HEIGHT)][(int)(ghost_x / DRAW_WIDTH)] = 0;
		*power_cookie = 1;
	}

	
}

void Game::Pop(float enemy_x,float* enemy_y,int* enemy_pop) {
	
	if (*enemy_pop >= 0) {
		*enemy_pop -= 1;
	}
	if (*enemy_pop == 0) {
		
		*enemy_y -= 64.0f;
	
	}

};


void Game::Kill(float player_x, float player_y, float player_width, float player_height, float* enemy_x, float* enemy_y, float enemy_width, float enemy_hieght,float start_x,int* enemy_pop) {
	

	if ((player_x + player_width) > *enemy_x && player_x < (*enemy_x + enemy_width) && player_y < (*enemy_y + enemy_hieght) && (player_y + player_height) > *enemy_y) {
		*enemy_x  = 448 + start_x;
		*enemy_y = 416;
		*enemy_pop = 2*60 ;
	}
}