#ifndef GAME_H
#define GAME_H

#include "DirectX.h"
#include "Main.h"
#include "Mapchip.h"

#include <time.h>

#define MAP_SIZE_WIDTH (28.f)		// MAPの横幅(値はチップ数)
#define MAP_SIZE_HEIGHT (31.f)	// MAPの縦幅(値はチップ数)
#define MAPCHIP_WIDTH (32.f)		// マップチップの横幅
#define MAPCHIP_HEIGHT (32.f)		// マップチップの縦幅
#define TEXTURE_WIDTH (256.f)     // 読み込んだテクスチャの横幅
#define TEXTURE_HEIGHT (256.f)    // 読み込んだテクスチャの縦幅
#define DRAW_WIDTH (32.f)         // 描画する横幅
#define DRAW_HEIGHT (32.f)        // 描画する縦幅


class Game {
public:

	void Game_Scene();

	enum SCENE_PAHSE {
		LOAD,
		PROCESSING,
		RELEASES
	};

	enum KEY {
		STOP = -1,
		RIGHT = 0,
		DOWN  = 90,
		LEFT  = 180,
		UP    = 270,
	};

	float right_pacman_x = 992.0f;
	float right_pacman_y = 32.0f;
	int right_pacman_degree = 0;
	KEY right_pacman_rotate = KEY::STOP;
	KEY right_pacman_key = KEY::STOP;
	KEY right_pacman_savekey = KEY::STOP;
	int right_pacman_row = 0;
	int right_pacman_col = 0;
	int right_pacman_life = 1;


	float left_pacman_x = 32.0f;
	float left_pacman_y = 32.0f;
	int left_pacman_degree = 0;
	KEY left_pacman_rotate = KEY::STOP;
	KEY left_pacman_key = KEY::STOP;
	KEY left_pacman_savekey = KEY::STOP;
	int left_pacman_row = 0;
	int left_pacman_col = 0;
	int left_pacman_life = 1;

	int flamecount = 0;
	float pacman_tu = 0.0f;
	float s = 0;

	float left_gauge_tu;
	float right_gauge_tu;





	float right_ghost_x_1 = 1056.0f;
	float right_ghost_y_1 = 32.0f;
	float left_ghost_x_1 = 640.0f;
	float left_ghost_y_1 = 32.0f;
	float left_ghost_tu_1 = 0.0f;
	float right_ghost_tu_1 = 0.0f;

	float right_ghost_x_2 = 1056.0f;
	float right_ghost_y_2 = 32.0f;
	float left_ghost_x_2 = 640.0f;
	float left_ghost_y_2 = 32.0f;
	float left_ghost_tu_2 = 0.0f;
	float right_ghost_tu_2 = 0.0f;

	float right_ghost_x_3 = 1056.0f;
	float right_ghost_y_3 = 32.0f;
	float left_ghost_x_3 = 640.0f;
	float left_ghost_y_3 = 32.0f;
	float left_ghost_tu_3 = 0.0f;
	float right_ghost_tu_3 = 0.0f;

	float right_ghost_x_4 = 1056.0f;
	float right_ghost_y_4 = 32.0f;
	float left_ghost_x_4 = 640.0f;
	float left_ghost_y_4 = 32.0f;
	float left_ghost_tu_4 = 0.0f;
	float right_ghost_tu_4 = 0.0f;



	

	


	int left_ghost_row_1 = 0;
	int left_ghost_col_1 = 0;
	int right_ghost_row_1 = 0;
	int right_ghost_col_1 = 0;
	float ghostmove_x_1 = 0;
	float ghostmove_y_1 = 0;
	KEY left_ghost_key_1 = KEY::STOP;
	KEY right_ghost_key_1 = KEY::STOP;
	KEY left_ghost_savekey_1 = KEY::STOP;
	KEY right_ghost_savekey_1 = KEY::STOP;
	KEY left_ghost_rotate_1 = KEY::STOP;
	KEY right_ghost_rotate_1 = KEY::STOP;
	int left_ghostpop_1 = 0;
	int right_ghostpop_1 = 0;

	int left_ghost_row_2 = 0;
	int left_ghost_col_2 = 0;
	int right_ghost_row_2 = 0;
	int right_ghost_col_2 = 0;
	float ghostmove_x_2 = 0;
	float ghostmove_y_2 = 0;
	KEY left_ghost_key_2 = KEY::STOP;
	KEY right_ghost_key_2 = KEY::STOP;
	KEY left_ghost_savekey_2 = KEY::STOP;
	KEY right_ghost_savekey_2 = KEY::STOP;
	KEY left_ghost_rotate_2 = KEY::STOP;
	KEY right_ghost_rotate_2 = KEY::STOP;
	int left_ghostpop_2 = 0;
	int right_ghostpop_2 = 0;

	int left_ghost_row_3 = 0;
	int left_ghost_col_3 = 0;
	int right_ghost_row_3 = 0;
	int right_ghost_col_3 = 0;
	float ghostmove_x_3 = 0;
	float ghostmove_y_3 = 0;
	KEY left_ghost_key_3 = KEY::STOP;
	KEY right_ghost_key_3 = KEY::STOP;
	KEY left_ghost_savekey_3 = KEY::STOP;
	KEY right_ghost_savekey_3 = KEY::STOP;
	KEY left_ghost_rotate_3 = KEY::STOP;
	KEY right_ghost_rotate_3 = KEY::STOP;
	int left_ghostpop_3 = 0;
	int right_ghostpop_3 = 0;

	int left_ghost_row_4 = 0;
	int left_ghost_col_4 = 0;
	int right_ghost_row_4 = 0;
	int right_ghost_col_4 = 0;
	float ghostmove_x_4 = 0;
	float ghostmove_y_4 = 0;
	KEY left_ghost_key_4 = KEY::STOP;
	KEY right_ghost_key_4 = KEY::STOP;
	KEY left_ghost_savekey_4 = KEY::STOP;
	KEY right_ghost_savekey_4 = KEY::STOP;
	KEY left_ghost_rotate_4 = KEY::STOP;
	KEY right_ghost_rotate_4 = KEY::STOP;
	int left_ghostpop_4 = 0;
	int right_ghostpop_4 = 0;




	int left_ghost_move_1 = 3;
	int right_ghost_move_1 = 3;

	int left_ghost_move_2 = 3;
	int right_ghost_move_2 = 3;

	int left_ghost_move_3 = 3;
	int right_ghost_move_3 = 3;

	int left_ghost_move_4 = 3;
	int right_ghost_move_4 = 3;




	int left_cookie = 0;
	int left_powercookie = 0;

	int right_cookie = 0;
	int right_powercookie = 0;

	int right_cookie_count = 0;
	int left_cookie_count = 0;

	
	


	Game::SCENE_PAHSE Phase = Game::LOAD;

	void Loading();
	void Process();
	void Release();

	//当たり判定
	void JudgeCollision(float* x, float* y, float start_x, float start_y, int row_, int col_, float draw_width, float draw_height, KEY* key, KEY* savekey,KEY* rotate_key, int** map);
	//ゴーストが動けるかどうか
	void CanMoveGhost(float* x, float* y, float start_x, float start_y, int row_, int col_, float draw_width, float draw_height, KEY* key, KEY* savekey,KEY* rotate_key ,int** map);
	//パックマンが死ぬ処理
	void Die(float player_x, float player_y, float player_width, float player_height, float enemy_x, float enemy_y, float enemy_width, float enemy_hieght, int pacman_life);

	void Kill(float player_x, float player_y, float player_width, float player_height, float* enemy_x, float* enemy_y, float enemy_width, float enemy_hieght, float start_x, int* enemy_pop);

	void Eat(int** map, float ghost_x, float ghost_y,int* cookie, int* power_cookie);

	void Pop(float enemy_x, float* enemy_y, int* enemy_pop);
};
#endif