#ifndef GAME_H
#define GAME_H

#include "DirectX.h"
#include "Main.h"
#include "Mapchip.h"

#include <time.h>

#define MAP_SIZE_WIDTH (28)		// MAPの横幅(値はチップ数)
#define MAP_SIZE_HEIGHT (31)	// MAPの縦幅(値はチップ数)
#define MAPCHIP_WIDTH (32)		// マップチップの横幅
#define MAPCHIP_HEIGHT (32)		// マップチップの縦幅
#define TEXTURE_WIDTH (256)     // 読み込んだテクスチャの横幅
#define TEXTURE_HEIGHT (256)    // 読み込んだテクスチャの縦幅
#define DRAW_WIDTH (16)         // 描画する横幅
#define DRAW_HEIGHT (16)        // 描画する縦幅


class Game {
public:

	void Game_Scene();

	enum SCENE_PAHSE {
		LOAD,
		PROCESSING,
		RELEASES
	};

	Game::SCENE_PAHSE Phase = Game::LOAD;

	void Loading();
	void Process();
	void Release();

	
};
#endif