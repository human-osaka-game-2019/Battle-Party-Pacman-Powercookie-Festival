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
		break;
	}
}

//ゲームのテクスチャの読み込み
void Game::Loading() {

	Load();

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 2; i++)
	{
		cookie[i] =
		{
			0,
			0,
			0,
		};
	}
	fc_pacman = 0;
	countdown_tu = 0.0f;
	countdown_tv = 0.0f;
	fc_countdown = 0;


	pacman1p.Init(416.0f, 736.f);
	pacman2p.Init(416.0f + 960.f, 736.f);

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() 
{
	pacman1p.Update();
	pacman2p.Update();

	fc_pacman++;
	fc_countdown++;

	if (fc_countdown >= 365) {

		//パックマンのアニメーション
		for (int i = 0; i < 2; i++)
		{
			if (fc_pacman % 6 == 0) {
				pacman1p.tu += 0.25f;
				pacman2p.tu += 0.25f;
			}
			if (1.0f <= pacman1p.tu) {
				pacman1p.tu = 0.0f;
			}
			if (1.0f <= pacman2p.tu)
			{
				pacman2p.tu = 0.0f;
			}
		}



		////ゴーストのアニメーション
		//for (int i = 0; i < 2; i++)
		//{
		//	for (int j = 0; j < 8; j++)
		//	{
		//		ghost[i][j].tu += 64.0f / 512.0f;

		//		if (ghost[i][j].tu >= (64.0f * (2.0f + 2.0f * i)) / 512.0f)
		//		{
		//			ghost[i][j].tu = 0.0f + (64.0f * 2.0f * i);
		//		}
		//	}
		//}
		//

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






		//
		////パックマンの当たり判定
		//JudgeCollision(&pacman[LEFT_CHAR],0.0f, 0.0f,array_left_map);
		//JudgeCollision(&pacman[RIGHT_CHAR], 896.0f + 64.f, 0.0f, array_right_map);

		//
		////ゴーストが動けるかどうか

		//for (int j = 0; j < 8; j++) {
		//	CanMoveGhost(&ghost[LEFT_CHAR][j], 0.0f, 0.0f,array_left_map);
		//	CanMoveGhost(&ghost[RIGHT_CHAR][j], 0.0f + 960.f, 0.0f, array_right_map);
		//}


		////クッキーを食べる処理
		//Eat(array_left_map, pacman[LEFT_CHAR].x,pacman[LEFT_CHAR].y, &cookie[LEFT_CHAR].cookie, &cookie[LEFT_CHAR].powercookie);
		//Eat(array_right_map, pacman[RIGHT_CHAR].x, pacman[RIGHT_CHAR].y, &cookie[RIGHT_CHAR].cookie, &cookie[RIGHT_CHAR].powercookie);





		//クッキーを使える時間のカウント
		if (cookie[LEFT_CHAR].count != 0) {
			cookie[LEFT_CHAR].count--;
		}
		if (cookie[RIGHT_CHAR].count != 0) {
			cookie[RIGHT_CHAR].count--;
		}



		//左ステージの描画
		map.DrawMapchip( 0.0f, 0.0f, BLUE_MAPCHIP, array_left_map);
		map.DrawMapchip( 960.f, 0.0f, PINK_MAPCHIP, array_right_map);


		//パックマン描画
		Draw(pacman1p.x, pacman1p.y, 0xffffffff, pacman1p.tu, 0.0f, 32, 32, 0.25f, 0.5f, PACMAN, pacman1p.degree);
		Draw(pacman2p.x, pacman2p.y, 0xffffffff, pacman2p.tu, 0.5f, 32, 32, 0.25f, 0.5f, PACMAN, pacman2p.degree);

	
	}
}

//ゲームのテクスチャの解放
void Game::Release() 
{

	//テクスチャの開放
	for (int i = 0; i < TEX_MAX; i++) {
		if (dx.pTexture[i] != nullptr) {
			dx.pTexture[i]->Release();
			dx.pTexture[i] = nullptr;
		}
	}
	Phase = LOAD;
	//リザルトシーンへ
	scene = RESULT;
}

///ゴーストもできるように改善の余地あり
////パックマンの移動・当たり判定関数
//void Game::JudgeCollision(PACMAN* pacman,float start_x,float start_y,int** map) {
//	//マップぴったり
//	if (((int)pacman->x % (int)DRAW_WIDTH) == 0 && ((int)pacman->y % (int)DRAW_HEIGHT == 0)) {
//		int col = (pacman->x - start_x) / DRAW_WIDTH;
//		int row = (pacman->y - start_y) / DRAW_HEIGHT;
//		if ((row + pacman->forward_row) != -1 || (col + pacman->forward_col) != -1) {
//			if (map[row + pacman->forward_row][col + pacman->forward_col] == 0 || map[row + pacman->forward_row][col + pacman->forward_col] == 35 || map[row + pacman->forward_row][col + pacman->forward_col] == 38|| map[row + pacman->forward_row][col + pacman->forward_col] == 39|| map[row + pacman->forward_row][col + pacman->forward_col] == 40) {
//				pacman->move_key = pacman->next_movekey;
//				
//				switch (pacman->move_key) {
//				case RIGHT:
//					pacman->x += 2;
//					pacman->degree = 0;
//						break;
//				case DOWN:
//					pacman->y += 2;
//					pacman->degree = 90;
//					break;
//				case LEFT:
//					pacman->x -= 2;
//					pacman->degree = 180;
//					break;
//				case UP:
//					pacman->y -= 2;
//					pacman->degree = 270;
//					break;
//				case STOP:
//
//					break;
//				default:
//
//					break;
//
//				}
//			}
//		}
//	}//移動中
//	else {
//		switch (pacman->move_key) {
//		case RIGHT:
//			pacman->x += 2;
//			break;
//		case DOWN:
//			 pacman->y += 2;
//			break;
//		case LEFT:
//			pacman->x -= 2;
//			break;
//		case UP:
//			pacman->y -= 2;
//			break;
//		case STOP:
//
//			break;
//		default:
//
//			break;
//
//		}
//	}
//}

///上の関数にまとめたい

//ゴーストの移動できる方向の確認
//void Game::CanMoveGhost(GHOST* ghost,float start_x, float start_y, int** map) {
//
//	if (ghost->forward_row == 0 && ghost->forward_col == 0) {
//		ghost->next_movekey = (KEY)(rand() % 4);
//	}
//	if (((int)ghost->x % (int)DRAW_WIDTH) == 0 && ((int)ghost->y % (int)DRAW_HEIGHT == 0)) {
//
//		int col = (ghost->x - start_x) / DRAW_WIDTH;
//		int row = (ghost->y - start_y) / DRAW_HEIGHT;
//
//		if ((map[row + ghost->forward_row][col + ghost->forward_col] == 0) || (map[row + ghost->forward_row][row + ghost->forward_col] == 35) || (map[row + ghost->forward_row][col + ghost->forward_col] == 38) || (map[row + ghost->forward_row][col + ghost->forward_col] == 39) || (map[row + ghost->forward_row][col + ghost->forward_col] == 40)) {
//
//			int save = ghost->next_movekey;
//
//			for (int i = 0; i < 1000; i++) {
//				save = ghost->next_movekey;
//				if (save == ghost->move_key) {
//					continue;
//				}
//				break;
//			}
//
//			switch (save) {
//			case UP:
//				ghost->forward_row = -1;
//				ghost->forward_col = 0;
//				break;
//			case DOWN:
//				ghost->forward_row = 1;
//				ghost->forward_col = 0;
//				break;
//			case LEFT:
//				ghost->forward_row = 0;
//				ghost->forward_col = -1;
//				break;
//			case RIGHT:
//				ghost->forward_row = 0;
//				ghost->forward_col = 1;
//				break;
//			case STOP:
//				break;
//			default:
//
//				break;
//			}
//		}
//		if (map[row + ghost->forward_row][col + ghost->forward_col] != 0 && map[row + ghost->forward_row][col + ghost->forward_col] != 35 && map[row + ghost->forward_row][col + ghost->forward_col] != 38 && map[row + ghost->forward_row][col + ghost->forward_col] != 39 && map[row + ghost->forward_row][col + ghost->forward_col] != 40) {
//			ghost->next_movekey = (KEY)(rand() % 4);
//		}
//	}
//	
//	if (((int)ghost->x % (int)DRAW_WIDTH) == 0 && ((int)ghost->y % (int)DRAW_HEIGHT == 0)) {
//
//		int col = (ghost->x - start_x) / DRAW_WIDTH;
//		int row = (ghost->y - start_y) / DRAW_HEIGHT;
//
//		if ((row + ghost->forward_row) != -1 && (col + ghost->forward_col) != -1) {
//
//			if (map[row + ghost->forward_row][col + ghost->forward_col] == 0 || map[row + ghost->forward_row][col + ghost->forward_col] == 35 || map[row + ghost->forward_row][col + ghost->forward_col] == 38 || map[row + ghost->forward_row][col + ghost->forward_col] == 39 || map[row + ghost->forward_row][col + ghost->forward_col] == 40) {
//
//				ghost->move_key = ghost->next_movekey;
//
//				switch (ghost->move_key) {
//				case UP:
//					ghost->y -= 2;
//					break;
//				case DOWN:
//					ghost->y += 2;
//					break;
//				case RIGHT:
//					ghost->x += 2;
//					break;
//				case LEFT:
//					ghost->x -= 2;
//					break;
//				case STOP:
//					break;
//				default:
//					break;
//				}
//			}
//			
//		}
//	}
//	else {
//
//		switch (ghost->move_key) {
//		case UP:
//			ghost->y -= 2;
//			break;
//		case DOWN:
//			ghost->y += 2;
//			break;
//		case RIGHT:
//			ghost->x += 2;
//			break;
//		case LEFT:
//			ghost->x -= 2;
//			break;
//		default:
//			break;
//		}
//	}
//
//	
//}

//パックマン見つける処理

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

//
//void Game::InputKey(PACMAN* pacman,COOKIE* cookie) {
//
//
//	if (dx.KeyState[DIK_W] == dx.PRESS) {
//		pacman[LEFT_CHAR].next_movekey = UP;
//		//左ステージのkey入力による当たり判定の方向
//		pacman[LEFT_CHAR].forward_row = -1;
//		pacman[LEFT_CHAR].forward_col = 0;
//	}
//	else if (dx.KeyState[DIK_S] == dx.PRESS) {
//		pacman[LEFT_CHAR].next_movekey = DOWN;
//		//左ステージのkey入力による当たり判定の方向
//		pacman[LEFT_CHAR].forward_row = 1;
//		pacman[LEFT_CHAR].forward_col= 0;
//	}
//	else if (dx.KeyState[DIK_A] == dx.PRESS) {
//		pacman[LEFT_CHAR].next_movekey = LEFT;
//		//左ステージのkey入力による当たり判定の方向
//		pacman[LEFT_CHAR].forward_row = 0;
//		pacman[LEFT_CHAR].forward_col = -1;
//	}
//	else if (dx.KeyState[DIK_D] == dx.PRESS) {
//		pacman[LEFT_CHAR].next_movekey = RIGHT;
//		//左ステージのkey入力による当たり判定の方向
//		pacman[LEFT_CHAR].forward_row = 0;
//		pacman[LEFT_CHAR].forward_col = 1;
//	}
//
//	//右パックマンのkey入力
//	if (dx.KeyState[DIK_UP] == dx.PRESS) {
//		pacman[RIGHT_CHAR].next_movekey = UP;
//		//右ステージのkey入力による当たり判定の方向
//		pacman[RIGHT_CHAR].forward_row = -1;
//		pacman[RIGHT_CHAR].forward_col = 0;
//	}
//	else if (dx.KeyState[DIK_DOWN] == dx.PRESS) {
//		pacman[RIGHT_CHAR].next_movekey = DOWN;
//		//右ステージのkey入力による当たり判定の方向
//		pacman[RIGHT_CHAR].forward_row = 1;
//		pacman[RIGHT_CHAR].forward_col = 0;
//	}
//	else if (dx.KeyState[DIK_LEFT] == dx.PRESS) {
//		pacman[RIGHT_CHAR].next_movekey = LEFT;
//		//右ステージのkey入力による当たり判定の方向
//		pacman[RIGHT_CHAR].forward_row = 0;
//		pacman[RIGHT_CHAR].forward_col = -1;
//	}
//	else if (dx.KeyState[DIK_RIGHT] == dx.PRESS) {
//		pacman[RIGHT_CHAR].next_movekey = RIGHT;
//		//右ステージのkey入力による当たり判定の方向
//		pacman[RIGHT_CHAR].forward_row = 0;
//		pacman[RIGHT_CHAR].forward_col = 1;
//	}
//
//	//左のパワークッキー
//	if (cookie[LEFT_CHAR].powercookie == 1 && dx.KeyState[DIK_E] == dx.PRESS) {
//		cookie[LEFT_CHAR].count = 60 * 8;
//		cookie[LEFT_CHAR].powercookie = 0;
//	}
//	//右のパワークッキー
//	if (cookie[RIGHT_CHAR].powercookie == 1 && dx.KeyState[DIK_END] == dx.PRESS) {
//		cookie[RIGHT_CHAR].count = 60 * 8;
//		cookie[RIGHT_CHAR].powercookie = 0;
//	}
//	
//	
//
//	//リリースのフェーズへ
//	if (dx.KeyState[DIK_RETURN] == dx.PRESS) {
//		Phase = RELEASES;
//	}
//
//}