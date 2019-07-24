#include "Game.h"

Game::SCENE_PAHSE Phase = Game::LOAD;

float pink_PACMAN_tu = 0.0f;
float pink_PACMAN_tv = 0.0f;

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

	D3DXCreateTextureFromFile(dx.pD3Device,_T("Pink_PACMAN.png"),&dx.pTexture[BLUE_PACMAN]);
	D3DXCreateTextureFromFile(dx.pD3Device, _T("Blue_PACMAN.png"), &dx.pTexture[PINK_PACMAN]);

	D3DXCreateTextureFromFile(dx.pD3Device, _T("Pink_Ghost.png"), &dx.pTexture[PINK_GHOST]);
	D3DXCreateTextureFromFile(dx.pD3Device, _T("Blue_Ghost.png"), &dx.pTexture[BLUE_GHOST]);

	D3DXCreateTextureFromFile(dx.pD3Device, _T("Pink_Gauge.png"), &dx.pTexture[PINK_GAUGE]);
	D3DXCreateTextureFromFile(dx.pD3Device, _T("Blue_Gauge.png"), &dx.pTexture[BLUE_GAUGE]);

	D3DXCreateTextureFromFile(dx.pD3Device, _T("Mess_Width_Ghost.png"), &dx.pTexture[MESS_WIDTH_GHOST]);

	D3DXCreateTextureFromFile(dx.pD3Device, _T("GameBack.png"), &dx.pTexture[BLUE_PACMAN]);

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {



	for (int i = 0; i < 15;i++) 
	{
		b[i] = a[i];
	}

	int** c = Mp.mapchip("Test_CSV.csv",15,14,b);




































	flamecount++;

	if (flamecount == 6) {
		flamecount = 0;
		pink_PACMAN_tu += 0.25;
		if (pink_PACMAN_tu == 1.0f) {
			pink_PACMAN_tu = 0.0f;
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

	Draw(400, 400, 0xffffffff, s, 0.0f, 200, 200, 0.25f, 1.0f, BLUE_PACMAN);

#endif

	Draw(0, 0, 0xffffffff, pink_PACMAN_tu, pink_PACMAN_tv, 200, 200, 0.25f, 1.0f, BLUE_PACMAN);
	Draw(0,200,0xffffffff,pink_PACMAN_tu,pink_PACMAN_tv,200,200,0.25f,1.0f,PINK_PACMAN);

	Draw(200, 0, 0xffffffff,pink_gauge_tu,0.0f, 400, 200, 0.05f, 1.0f, PINK_GAUGE);
	Draw(200,200, 0xffffffff,blue_gauge_tu,0.0f, 400, 200, 0.05f, 1.0f, BLUE_GAUGE);
	
	Draw(0, 400, 0xffffffff, 0.0f, 0.0f, 200, 200, 0.125f, 1.0f, PINK_GHOST);
	Draw(200, 400, 0xffffffff, 0.0f, 0.0f, 200, 200, 0.125f, 1.0f, BLUE_GHOST);

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
