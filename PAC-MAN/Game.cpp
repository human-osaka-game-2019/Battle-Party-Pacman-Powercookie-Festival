#include "Game.h"
#include "Mapchip.h"

Game::SCENE_PAHSE Phase = Game::LOAD;
//
//MapchipLoading Mp;
//DrawMap map;

float pink_PACMAN_tu = 0.0f;
float blue_PACMAN_tu = 0.0f;

float pink_gauge_tu = 0.0f;
float blue_gauge_tu = 0.0f;

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

	//LoadTexture("Pink_PACMAN.png",BLUE_PACMAN);
	//LoadTexture("Blue_PACMAN.png",PINK_PACMAN);
	
	LoadTexture("PACMAN.png", PACMAN);

	LoadTexture("Pink_Ghost.png",PINK_GHOST);
	LoadTexture("Blue_Ghost.png",BLUE_GHOST);
	
	LoadTexture("Gauge.png",PINK_GAUGE);
	LoadTexture("Gauge.png",BLUE_GAUGE);
	
	LoadTexture("Mess_Width_Ghost.png",MESS_WIDTH_GHOST);
	
	LoadTexture("GameBack.png", BLUE_PACMAN);

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {



	flamecount++;

	if (flamecount == 6) {
		flamecount = 0;
		pink_PACMAN_tu += 0.25;
		blue_PACMAN_tu += 0.25;
		if (pink_PACMAN_tu == 1.0f) {
			pink_PACMAN_tu = 0.0f;
			blue_PACMAN_tu = 0.0f;
		}
		pink_gauge_tu += 0.05f;
		blue_gauge_tu += 0.05f;
	 }


#ifndef R_H
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

	/*Draw(0, 0, 0xffffffff, pink_PACMAN_tu, pink_PACMAN_tv, 200, 200, 0.25f, 1.0f, BLUE_PACMAN);
	Draw(0,200,0xffffffff,pink_PACMAN_tu,pink_PACMAN_tv,200,200,0.25f,1.0f,PINK_PACMAN);*/

	Draw(0, 0, 0xffffffff, pink_PACMAN_tu, 0.0f, 200, 200, 0.25f, 0.5f, PACMAN);
	Draw(0, 210, 0xffffffff, blue_PACMAN_tu, 0.0f + 0.503f, 200, 200, 0.25f, 0.5f, PACMAN);

	//8:1 width:height
	Draw(0, 420, 0xffffffff,pink_gauge_tu,0.0f,400, 50, 0.05f, 0.5f, PINK_GAUGE);
	Draw(0,480, 0xffffffff,blue_gauge_tu,0.507f, 400, 50, 0.05f, 0.5f, BLUE_GAUGE);
	
	Draw(420, 0, 0xffffffff, 0.0f, 0.0f, 200, 200, 0.125f, 1.0f, PINK_GHOST);
	Draw(420, 210, 0xffffffff, 0.0f, 0.0f, 200, 200, 0.125f, 1.0f, BLUE_GHOST);

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
