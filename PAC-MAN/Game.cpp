#include "Game.h"
#include <random>
#include <iostream>

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

	LoadTexture("map_test.png", TEST_MAPCHIP);
	LoadTexture("pacman.png", PACMAN);
	LoadTexture("Ghost.png", GHOST);
	LoadTexture("GameBack.png", GAME_BACK);
	LoadTexture("gauge.png",GAUGE);

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {


	flamecount++;

	//左ステージの描画
	map.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, 0.0f);

	//右ステージの描画
	map.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 960.f, 0.0f);

	//左のゴーストの描画
	Draw(left_ghost_x, left_ghost_y, 0xffffffff, left_ghost_tu, 0.0f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);

	//右のゴーストの描画
	Draw(right_ghost_x, right_ghost_y, 0xffffffff, right_ghost_tu, 0.2f, 32, 32, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);

	//左のパックマンの描画
	Draw(left_pacman_x, left_pacman_y, 0xffffffff, pacman_tu, 0.0f, 32, 32, 0.25f, 0.5f, PACMAN, left_pacman_rotate);

	//右のパックマンの描画
	Draw(right_pacman_x, right_pacman_y, 0xffffffff, pacman_tu, 0.0f, 32, 32, 0.25f, 0.5f, PACMAN, right_pacman_rotate);
	
	///アニメーション関数ですべてのキャラクターのアニメーショできるようにする
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


	
	////8:1 width:height
	//Draw(100, 0, 0xffffffff, left_gauge_tu, 0.0f, 400, 50, 0.05f, 0.5f,GAUGE);
	//Draw(100, 100, 0xffffffff, right_gauge_tu, 0.507f, 400, 50, 0.05f, 0.493f,GAUGE);
	
	////お邪魔ブルーゴースト
	//Draw(400, 200, 0xffffffff, left_disturbed_ghost_tu, disturbed_ghost_tv, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	////お邪魔ピンクゴースト
	//Draw(600, 200, 0xffffffff, left_disturbed_ghost_tu, disturbed_ghost_tv, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	////いじけブルーゴースト														  
	//Draw(800, 200, 0xffffffff, mess_ghost_tu, mess_ghost_tv, 16, 16, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	////いじけピンクゴースト
	//Draw(800, 300, 0xffffffff, mess_ghost_tu, mess_ghost_tv, 16, 16, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	////いじけお邪魔ブルーゴースト
	//Draw(900, 200, 0xffffffff, mess_disturbed_ghost_tu, mess_ghost_tv, 16, 16, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	////いじけお邪魔ピンクゴースト
	//Draw(900, 300, 0xffffffff, mess_disturbed_ghost_tu, mess_ghost_tv, 16, 16, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);



	//if (dx.KeyState[DIK_Y] == dx.PRESS) {
	//	
	//}
	//else if (dx.KeyState[DIK_H] == dx.PRESS) {
	//	
	//}
	//else if (dx.KeyState[DIK_G] == dx.PRESS) {
	//	
	//}
	//else if (dx.KeyState[DIK_J] == dx.PRESS) {
	//	
	//}




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

	std::mt19937 rand{ std::random_device{}() };

	std::uniform_int_distribution<int> a(0, 3);
	
	if ((map.left_map[(int)(left_ghost_y / DRAW_WIDTH) + left_ghost_row][(int)(left_ghost_x / DRAW_WIDTH) + left_ghost_col] != 0) && (map.left_map[(int)(left_ghost_y / DRAW_WIDTH) + left_ghost_row][(int)(left_ghost_x / DRAW_WIDTH) + left_ghost_col] != 35) && (map.left_map[(int)(left_ghost_y / DRAW_WIDTH) + left_ghost_row][(int)(left_ghost_x / DRAW_WIDTH) + left_ghost_col] != 38)) {
		int save = left_ghost_move;
		for (int i = 0; i < 1000; i++) {
			left_ghost_move = a(rand);
			if (save == left_ghost_move) {
				continue;
			}
			break;
		}
	}
	
	

	switch (left_ghost_move) {
	case 0:
		left_ghost_savekey = UP;
		left_ghost_row = -1;
		left_ghost_col = 0;
		break;
	case 1:
		left_ghost_savekey = DOWN;
		left_ghost_row = 1;
		left_ghost_col = 0;
		break;
	case 2:
		left_ghost_savekey = RIGHT;
		left_ghost_row = 0;
		left_ghost_col = 1;
		break;
	case 3:
		left_ghost_savekey = LEFT;
		left_ghost_row = 0;
		left_ghost_col = -1;
		break;
	default:

		break;
	}

	/*int right_ghost_move = a(rand);
	switch (right_ghost_move) {
	case 0:
		right_ghost_savekey = UP;
		right_ghost_row = -1;
		right_ghost_col = 0;
		break;
	case 1:
		right_ghost_savekey = DOWN;
		right_ghost_row = 1;
		right_ghost_col = 0;
		break;
	case 2:
		right_ghost_savekey = RIGHT;
		right_ghost_row = 0;
		right_ghost_col = 1;
		break;
	case 3:
		right_ghost_savekey = LEFT;
		right_ghost_row = 0;
		right_ghost_col = -1;
		break;
	default:

		break;
	}*/



	///下の二ついらないかも
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
	JudgeCollision(&right_pacman_x, &right_pacman_y, 448.f + 160.0f, 0.0f, right_pacman_row, right_pacman_col, DRAW_WIDTH, DRAW_HEIGHT, &right_pacman_key, &right_pacman_savekey,&right_pacman_rotate, array_right_map);
	//左のゴーストの当たり判定
	CanMoveGhost(&left_ghost_x, &left_ghost_y, 0.0f, 0.0f, left_ghost_row, left_ghost_col, DRAW_WIDTH, DRAW_HEIGHT, &left_ghost_key, &left_ghost_savekey, &left_ghost_rotate, array_left_map);
	//右のゴーストの当たり判定
	CanMoveGhost(&right_ghost_x, &right_ghost_y, 0.0f, 0.0f, right_ghost_row, right_ghost_col, DRAW_WIDTH, DRAW_HEIGHT, &right_ghost_key, &right_ghost_savekey, &right_ghost_rotate, array_right_map);

	//パックマンの残機が減り死ぬ関数
	Die(left_pacman_x, left_pacman_y, DRAW_WIDTH, DRAW_HEIGHT,left_ghost_x,left_ghost_y, DRAW_WIDTH, DRAW_HEIGHT);
	//パックマンの残機が減り死ぬ関数
	Die(right_pacman_x, right_pacman_y, DRAW_WIDTH, DRAW_HEIGHT, right_ghost_x, right_ghost_y, DRAW_WIDTH, DRAW_HEIGHT);


	//左画面の真ん中の逆から出てくる処理
	if ((14 == (int)(left_pacman_y / DRAW_HEIGHT)) && (27 == (int)(left_pacman_x / DRAW_WIDTH))) {
		left_pacman_x = 0.0f;
	}else if ((14 == (int)(left_pacman_y / DRAW_HEIGHT)) && (0 == (int)(left_pacman_x / DRAW_WIDTH))) {
		left_pacman_x = DRAW_WIDTH * 27;
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
		*rotate_key = *savekey;
		if ((row + row) != -1 && (col + col_) != -1) {
			
			if (map[row + row_][col + col_] == 0 || map[row + row_][col + col_] == 35 || map[row + row_][col + col_] == 38) {
				switch (*key) {
				case UP:
					*y -= 1;
					break;
				case DOWN:
					*y += 1;
					break;
				case RIGHT:
					*x += 1;
					break;
				case LEFT:
					*x -= 1;
					break;
				default:

					break;
				}
			}
		}
	}
	else {
		*key = *savekey;
		switch (*key) {
		case UP:
			*y -= 1;
			break;
		case DOWN:
			*y += 1;
			break;
		case RIGHT:
			*x += 1;
			break;
		case LEFT:
			*x -= 1;
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

void Game::Die(float player_x,float player_y,float player_width,float player_height,float enemy_x,float enemy_y,float enemy_width,float enemy_hieght) {
	if ((player_x + player_width) > enemy_x && player_x < (enemy_x + enemy_width) && player_y < (enemy_y + enemy_hieght) && (player_y + player_height) > enemy_y) {
		pacman_life--;
	}
	if (pacman_life == 0) {
		Phase = RELEASES;
		pacman_life = 3;
	}
}