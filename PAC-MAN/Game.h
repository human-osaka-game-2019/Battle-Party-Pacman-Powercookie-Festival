﻿#ifndef GAME_H
#define GAME_H

#include "DirectX.h"
#include "Main.h"
#include "Mapchip.h"

#include <time.h>


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