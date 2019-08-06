#ifndef GAME_H
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

	const float gauge_width = 50.0f;
	const float gauge_height = 50.0f;

	int a[15][14];
	int* b[15];

	float powercookie_tu = 0.25f;

	float pink_PACMAN_tu = 0.0f;
	float pink_PACMAN_tv = 0.0f;

	float pink_gauge_tu = 0.0f;
	float blue_gauge_tu = 0.0f;

	float pink_ghost_tu ;
	float left_pink_ghost_tu = 0.0f;
	float right_pink_ghost_tu = (64.0f * 2.0f) / 512.0f;
	float up_pink_ghost_tu = (64.0f * 4.0f) / 512.0f;
	float down_pink_ghost_tu = (64.0f * 6.0f) / 512.0f;


	float left_blue_ghost_tu = 0.0f;
	float right_blue_ghost_tu = (64.0f * 2.0f) / 512.0f;
	float up_blue_ghost_tu = (64.0f * 4.0f) / 512.0f;
	float down_blue_ghost_tu = (64.0f * 6.0f) / 512.0f;

	float blue_ghost_tv = 64.0f / 512.0f;

	float left_disturbed_blue_ghost_tu = 0.0f;
	float right_disturbed_blue_ghost_tu = (64.0f * 2.0f) / 512.0f;
	float up_disturbed_blue_ghost_tu = (64.0f * 4.0f) / 512.0f;
	float down_disturbed_blue_ghost_tu = (64.0f * 6.0f) / 512.0f;

	float disturbed_blue_ghost_tv = (64.0f * 3.0f) / 512.0f;

	float left_disturbed_pink_ghost_tu = 0.0f;
	float right_disturbed_pink_ghost_tu = (64.0f * 2.0f) / 512.0f;
	float up_disturbed_pink_ghost_tu = (64.0f * 4.0f) / 512.0f;
	float down_disturbed_pink_ghost_tu = (64.0f * 6.0f) / 512.0f;

	float disturbed_pink_ghost_tv = (64.0f * 2.0f) / 512.0f;

	float mess_blue_ghost_tu = 0.0f;
	float mess_pink_ghost_tu = (64.0f * 2.0f) / 512.0f;
	float mess_disturbed_blue_ghost_tu = (64.0f * 4.0f) / 512.0f;
	float mess_disturbed_pink_ghost_tu = (64.0f * 6.0f) / 512.0f;
	float mess_ghost_tv = (64.0f * 4.0f) / 512.0f;

	int gauge = 800;


};

#endif