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

float right_pacman_x = 960.0f;
float right_pacman_y = 32.0f;
float left_pacman_x = 32.0f;
float left_pacman_y = 32.0f;
float pacman_tu = 0.0f;
int left_pacman_degree = 0;
int right_pacman_degree = 0;

float right_ghost_x = 960.0f;
float right_ghost_y = 32.0f;
float left_ghost_x = 96.0f;
float left_ghost_y = 32.0f;
float left_ghost_tu = 0.0f;
float right_ghost_tu = 0.0f;

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
	LoadTexture("PACMAN_yellow.png", PACMAN);
	LoadTexture("Ghost.png", GHOST);

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {

	flamecount++;

	map.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, 0.0f);

	map.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 960.f, 0.0f);



	Draw(left_ghost_x, left_ghost_y, 0xffffffff, left_ghost_tu, 0.0f, 32, 32, 0.25f, 0.5f, GHOST);

	//Draw(right_ghost_x, right_ghost_y, 0xffffffff, right_ghost_tu, 0.5f, 32, 32, 0.25f,0.5f, GHOST);

	Draw(left_pacman_x, left_pacman_y, 0xffffffff, pacman_tu, 0.0f, 32, 32, 0.25f, 1.0f, PACMAN, left_pacman_savekey);

	Draw(right_pacman_x, right_pacman_y, 0xffffffff, pacman_tu, 0.0f, 32, 32, 0.25f, 1.0f, PACMAN, right_pacman_savekey);

	if (flamecount % 6 == 0) {
		pacman_tu += 0.25f;

	}
	if (1.0f <= pacman_tu) {
		pacman_tu = 0.0f;
	}




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
	//左パックマンのkey入力
	if (dx.KeyState[DIK_UP] == dx.PRESS) {
		left_pacman_savekey = UP;
		left_row = -1;
		left_col = 0;
	}
	if (dx.KeyState[DIK_DOWN] == dx.PRESS) {
		left_pacman_savekey = DOWN;
		left_row = 1;
		left_col = 0;
	}
	if (dx.KeyState[DIK_LEFT] == dx.PRESS) {
		left_pacman_savekey = LEFT;
		left_row = 0;
		left_col = -1;
	}
	if (dx.KeyState[DIK_RIGHT] == dx.PRESS) {
		left_pacman_savekey = RIGHT;
		left_row = 0;
		left_col = 1;
	}

	//右パックマンのkey入力
	if (dx.KeyState[DIK_W] == dx.PRESS) {
		right_pacman_savekey = UP;
		right_row = -1;
		right_col = 0;
	}
	if (dx.KeyState[DIK_S] == dx.PRESS) {
		right_pacman_savekey = DOWN;
		right_row = 1;
		right_col = 0;
	}
	if (dx.KeyState[DIK_A] == dx.PRESS) {
		right_pacman_savekey = LEFT;
		right_row = 0;
		right_col = -1;
	}
	if (dx.KeyState[DIK_D] == dx.PRESS) {
		right_pacman_savekey = RIGHT;
		right_row = 0;
		right_col = 1;
	}

	int* array_left_map[31];
	int* array_right_map[31];

	for (int i = 0; i < 31; i++) {
		array_left_map[i] = map.left_map[i];
	}
	for (int i = 0; i < 31; i++) {
		array_right_map[i] = map.right_map[i];
	}


	CanMoveGhost(array_left_map);

	



	//右ステージのkey入力による当たり判定の方向
	//左ステージのkey入力による当たり判定の方向
	
	//左のパックマンの当たり判定
	JudgeCollision(&left_pacman_x, &left_pacman_y, 0.0f, 0.0f, left_row, left_col, DRAW_WIDTH, DRAW_HEIGHT, &left_key, &left_pacman_savekey, array_left_map);
	//右のパックマンの当たり判定
	JudgeCollision(&right_pacman_x, &right_pacman_y, 448.f + 160.0f, 0.0f, right_row, right_col, DRAW_WIDTH, DRAW_HEIGHT, &right_key, &right_pacman_savekey, array_right_map);
	//左のゴーストの当たり判定
	JudgeCollision(&left_ghost_x, &left_ghost_y, 0.0f, 0.0f, left_row, left_col, DRAW_WIDTH, DRAW_HEIGHT, &left_key, &left_ghost_savekey, array_left_map);
	
	
	//左画面の真ん中の逆から出てくる処理
	if ((14 == (int)(left_pacman_y / DRAW_HEIGHT)) && (27 == (int)(left_pacman_x / DRAW_WIDTH))) {
		left_pacman_x = 0.0f;
	}else if ((14 == (int)(left_pacman_y / DRAW_HEIGHT)) && (0 == (int)(left_pacman_x / DRAW_WIDTH))) {
		left_pacman_x = DRAW_WIDTH * 27;
	}

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
//当たり判定関数
void Game::JudgeCollision(float* x,float* y,float start_x,float start_y,int row_,int col_,float draw_width,float draw_height,KEY *key,KEY *savekey,int** map) {
	if (((int)*x % (int)draw_width) == 0 && ((int)*y % (int)draw_height == 0)) {
		int col = (*x - start_x) / draw_width;
		int row = (*y - start_y) / draw_height;
		if ( map[row + row_][col + col_] == 0 || map[row + row_][col + col_] == 35 || map[row + row_][col + col_] == 38 ) {
			*key = *savekey;
			switch (*key) {
			case LEFT:
				*x -= 32;
				break;
			case RIGHT:
				*x += 32;
				break;
			case UP:
				*y -= 32;
				break;
			case DOWN:
				*y += 32;
				break;
			case STOP:

				break;
			default:

				break;
			}
		}
	}
}

//ゴーストの移動できる方向の確認
void Game::CanMoveGhost(int** map) {
	int ro = 0;
	int co = 1;
	if (((int)left_ghost_x % (int)DRAW_WIDTH) == 0 && ((int)left_ghost_y % (int)DRAW_HEIGHT == 0)) {
		for (int i = 0; i < (4 * 28); i++) {
			//右の確認
			if (0 < co) {
				co++;
			}
			//左に移行
			if (co == 28) {
				co = -1;
			}
			//左の確認
			if (co < 0) {
				co--;
			}
			//下に移行
			if (co == -28) {
				co = 0;
				ro++;
			}
			//下の確認
			if (0 < ro) {
				ro++;
			}
			//上に移行
			if (ro == 28) {
				ro = -1;
			}
			//上の確認
			if (ro < 0) {
				ro = -1;
			}
			//if (map[(int)(left_ghost_x / DRAW_WIDTH) + ro][(int)(left_ghost_x / DRAW_WIDTH) + co] == map[(int)(left_pacman_x / DRAW_WIDTH)][(int)(left_pacman_x / DRAW_WIDTH)]){//0 || map[(int)(left_ghost_x / DRAW_WIDTH) + ro][(int)(left_ghost_x / DRAW_WIDTH) + co] == 35 || map[(int)(left_ghost_x / DRAW_WIDTH) + ro][(int)(left_ghost_x / DRAW_WIDTH) + co] == 38) {
			//}
			if ((int)((left_ghost_x / DRAW_WIDTH) + ro) == (int)((left_pacman_x / DRAW_WIDTH)) || (int)((left_ghost_y / DRAW_WIDTH) + co) == (int)((left_pacman_y / DRAW_WIDTH))) {
				left_ghost_x += 32;
			}

		}
	}


}