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
	float left_pacman_x = 32.0f;
	float left_pacman_y = 32.0f;
	float pacman_tu = 0.0f;
	int left_pacman_degree = 0;
	int right_pacman_degree = 0;

	float right_ghost_x = 1056.0f;
	float right_ghost_y = 32.0f;
	float left_ghost_x = 640.0f;
	float left_ghost_y = 32.0f;
	float left_ghost_tu = 0.0f;
	float right_ghost_tu = 0.0f;

	int flamecount = 0;

	float s = 0;

	float left_gauge_tu;
	float right_gauge_tu;


	KEY left_pacman_key = KEY::STOP;
	KEY right_pacman_key = KEY::STOP;
	KEY left_pacman_savekey = KEY::STOP;
	KEY right_pacman_savekey = KEY::STOP;
	KEY left_ghost_key = KEY::STOP;
	KEY right_ghost_key = KEY::STOP;
	KEY left_ghost_savekey = KEY::STOP;
	KEY right_ghost_savekey = KEY::STOP;

	int left_pacman_row = 0;
	int left_pacman_col = 0;
	int right_pacman_row = 0;
	int right_pacman_col = 0;
	int left_ghost_row = 0;
	int left_ghost_col = 0;
	int right_ghost_row = 0;
	int right_ghost_col = 0;
	float ghostmove_x = 0;
	float ghostmove_y = 0;

	KEY left_pacman_rotate = KEY::STOP;
	KEY right_pacman_rotate = KEY::STOP;
	KEY left_ghost_rotate = KEY::STOP;
	KEY right_ghost_rotate = KEY::STOP;

	int left_ghost_move = 3;
	int pacman_life = 3;

	Game::SCENE_PAHSE Phase = Game::LOAD;

	void Loading();
	void Process();
	void Release();

	
	//当たり判定
	void JudgeCollision(float* x, float* y, float start_x, float start_y, int row_, int col_, float draw_width, float draw_height, KEY* key, KEY* savekey,KEY* rotate_key, int** map);
	//ゴーストが動けるかどうか
	void CanMoveGhost(float* x, float* y, float start_x, float start_y, int row_, int col_, float draw_width, float draw_height, KEY* key, KEY* savekey,KEY* rotate_key ,int** map);
	//パックマンが死ぬ処理
	void Die(float player_x, float player_y, float player_width, float player_height, float enemy_x, float enemy_y, float enemy_width, float enemy_hieght);
};
#endif