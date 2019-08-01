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
#define DRAW_WIDTH (16.f)         // 描画する横幅
#define DRAW_HEIGHT (16.f)        // 描画する縦幅


class Game {
public:

	void Game_Scene();

	enum SCENE_PAHSE {
		LOAD,
		PROCESSING,
		RELEASES
	};

	enum KEY {
		LEFT = 180,
		RIGHT = 0,
		UP = 270,
		DOWN = 90,
		STOP,
	};


	KEY left_key = KEY::STOP;
	KEY right_key = KEY::STOP;
	KEY left_savekey = KEY::STOP;
	KEY right_savekey = KEY::STOP;
	int left_row = 0;
	int left_col = 0;
	int right_row = 0;
	int right_col = 0;

	Game::SCENE_PAHSE Phase = Game::LOAD;

	void Loading();
	void Process();
	void Release();

	
	//当たり判定
	void JudgeCollision(float* x, float* y, float start_x, float start_y, int row_, int col_, float draw_width, float draw_height, KEY* key, KEY* savekey, int** map);
	

};
#endif