#include "Game.h"
#include "Mapchip.h"

Game::SCENE_PAHSE Phase = Game::LOAD;
//
//MapchipLoading Mp;
//DrawMap map;

bool is_get = true;

int flamecount = 0;
int flamecount_a = 0;

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

	LoadTexture("Pink_PACMAN.png",BLUE_PACMAN);
	
	LoadTexture("Blue_PACMAN.png",PINK_PACMAN);
	
	LoadTexture("Ghost.png",GHOST);
	
	LoadTexture("Gauge.png",PINK_GAUGE);
	LoadTexture("Gauge.png",BLUE_GAUGE);

	
	LoadTexture("GameBack.png", GAME_BACK);

	LoadTexture("powercookie.png", POWER_COOKIE);
	LoadTexture("powercookie_gauge.png", POWER_COOKIE_GAUGE);

	LoadTexture("cookie.png", COOKIE);

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {



	for (int i = 0; i < 15;i++) 
	{
		b[i] = a[i];
	}

	/*int** c = Mp.mapchip("Test_CSV.csv",15,14,b);



	map.DrawMapChip();

	map.tetureprint(c, 15, 14);*/































	flamecount++;
	flamecount_a++;
	

#ifndef R_H
#define R_H
	if (dx.KeyState[DIK_K] == dx.PRESS) {
		s += 0.25f;
		if (s >= 1.0f) {
			s = 0.0f;
		}
	}

	Draw(600, 100, 0xffffffff, s, 0.0f, 16, 16, 0.25f, 1.0f, BLUE_PACMAN);

#endif

	Draw(0, 0, 0xffffffff, pink_PACMAN_tu, pink_PACMAN_tv, 16, 16, 0.25f, 1.0f, BLUE_PACMAN);
	Draw(0,100,0xffffffff,pink_PACMAN_tu,pink_PACMAN_tv,16,16,0.25f,1.0f,PINK_PACMAN);

	//8:1 width:height
	Draw(100, 0, 0xffffffff,pink_gauge_tu,0.0f,400, 50, 0.05f, 0.5f, PINK_GAUGE);
	Draw(100,100, 0xffffffff,blue_gauge_tu,0.507f, 400, 50, 0.05f, 0.493f, BLUE_GAUGE);
	
	//ピンクゴースト
	//Draw(0, 200, 0xffffffff, left_pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(0, 300, 0xffffffff, right_pink_ghost_tu, 0.0f, 100, 100, 64.0f/512.0f, 64.0f/512.0f, GHOST);
	Draw(100, 200, 0xffffffff, up_pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(100, 300, 0xffffffff, down_pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//ブルーゴースト
	Draw(200, 200, 0xffffffff, left_blue_ghost_tu, blue_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(200, 300, 0xffffffff, right_blue_ghost_tu, blue_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(300, 200, 0xffffffff, up_blue_ghost_tu, blue_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(300, 300, 0xffffffff, down_blue_ghost_tu, blue_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//お邪魔ブルーゴースト
	Draw(400, 200, 0xffffffff, left_disturbed_blue_ghost_tu, disturbed_blue_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(400, 300, 0xffffffff, right_disturbed_blue_ghost_tu, disturbed_blue_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(500, 200, 0xffffffff, up_disturbed_blue_ghost_tu, disturbed_blue_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(500, 300, 0xffffffff, down_disturbed_blue_ghost_tu, disturbed_blue_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//お邪魔ピンクゴースト
	Draw(600, 200, 0xffffffff, left_disturbed_pink_ghost_tu, disturbed_pink_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(600, 300, 0xffffffff, right_disturbed_pink_ghost_tu, disturbed_pink_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(700, 200, 0xffffffff, up_disturbed_pink_ghost_tu, disturbed_pink_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(700, 300, 0xffffffff, down_disturbed_pink_ghost_tu, disturbed_pink_ghost_tv, 100,100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
    //いじけブルーゴースト														  
	Draw(800, 200, 0xffffffff, mess_blue_ghost_tu, mess_ghost_tv, 16, 16, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//いじけピンクゴースト
	Draw(800, 300, 0xffffffff, mess_pink_ghost_tu, mess_ghost_tv, 16, 16, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//いじけお邪魔ブルーゴースト
	Draw(900, 200, 0xffffffff, mess_disturbed_blue_ghost_tu, mess_ghost_tv, 16, 16, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//いじけお邪魔ピンクゴースト
	Draw(900, 300, 0xffffffff, mess_disturbed_pink_ghost_tu, mess_ghost_tv, 16, 16, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//どっと
	Draw(1000, 100, 0xffffffff, 0.0f, 0.0f, 16, 16, 1.0f, 1.0f, COOKIE);

	
	if (dx.KeyState[DIK_LEFT] == dx.PRESS)
	{
		pink_ghost_tu = left_pink_ghost_tu;
	}
	if (dx.KeyState[DIK_RIGHT] == dx.PRESS)
	{
		pink_ghost_tu = right_pink_ghost_tu;
	}
	if (dx.KeyState[DIK_UP] == dx.PRESS)
	{
		pink_ghost_tu = up_pink_ghost_tu;
	}
	if (dx.KeyState[DIK_DOWN] == dx.PRESS)
	{
		pink_ghost_tu = down_pink_ghost_tu;
	}
	Draw(0, 200, 0xffffffff, pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);


	if (flamecount == 6) 
	{
		flamecount = 0;
		pink_PACMAN_tu += 0.25;
		if (pink_PACMAN_tu == 1.0f) {
			pink_PACMAN_tu = 0.0f;
		}
		pink_gauge_tu += 0.05f;
		blue_gauge_tu += 0.05f;
		if (pink_gauge_tu >= 1.0f)
		{
			pink_gauge_tu = 0.0f;
		}

		if (blue_gauge_tu >= 1.0f)
		{
			blue_gauge_tu = 0.0f;

		}
		//ピンクゴーストアニメーション
		left_pink_ghost_tu += 64.0f / 512.0f;
		right_pink_ghost_tu += 64.0f / 512.0f;
		up_pink_ghost_tu += 64.0f / 512.0f;
		down_pink_ghost_tu += 64.0f / 512.0f;
		if (left_pink_ghost_tu >= (64.0f * 2.0f) / 512.0f)
		{
			left_pink_ghost_tu = 0.0f;
		}

		if (right_pink_ghost_tu >= (64.0f * 4.0f) / 512.0f)
		{
			right_pink_ghost_tu = (64.0f * 2.0f) / 512.0f;
		}

		if (up_pink_ghost_tu >= (64.0f * 6.0f) / 512.0f)
		{
			up_pink_ghost_tu = (64.0f * 4.0f) / 512.0f;
		}

		if (down_pink_ghost_tu >= (64.0f * 8.0f) / 512.0f)
		{
			down_pink_ghost_tu = (64.0f * 6.0f) / 512.0f;
		}

		//ブルーゴーストアニメーション
		left_blue_ghost_tu += 64.0f / 512.0f;
		right_blue_ghost_tu += 64.0f / 512.0f;
		up_blue_ghost_tu += 64.0f / 512.0f;
		down_blue_ghost_tu += 64.0f / 512.0f;
		if (left_blue_ghost_tu >= (64.0f * 2.0f) / 512.0f)
		{
			left_blue_ghost_tu = 0;
		}

		if (right_blue_ghost_tu >= (64.0f * 4.0f) / 512.0f)
		{
			right_blue_ghost_tu = (64.0f * 2.0f) / 512.0f;
		}

		if (up_blue_ghost_tu >= (64.0f * 6.0f) / 512.0f)
		{
			up_blue_ghost_tu = (64.0f * 4.0f) / 512.0f;

		}

		if (down_blue_ghost_tu >= (64.0f * 8.0f) / 512.0f)
		{
			down_blue_ghost_tu = (64.0f * 6.0f) / 512.0f;
		}
		
		left_disturbed_blue_ghost_tu += 64.0f / 512.0f;
	    right_disturbed_blue_ghost_tu += 64.0f / 512.0f;
		up_disturbed_blue_ghost_tu += 64.0f / 512.0f;
		down_disturbed_blue_ghost_tu += 64.0f / 512.0f;
		if (left_disturbed_blue_ghost_tu >= (64.0f * 2.0f) / 512.0f)
		{				
			left_disturbed_blue_ghost_tu = 0.0f;
		}				

		if (right_disturbed_blue_ghost_tu >= (64.0f * 4.0f) / 512.0f)
		{				
			right_disturbed_blue_ghost_tu = (64.0f * 2.0f) / 512.0f;
		}	

		if (up_disturbed_blue_ghost_tu >= (64.0f * 6.0f) / 512.0f)
		{				
			up_disturbed_blue_ghost_tu = (64.0f * 4.0f) / 512.0f;
		}

		if (down_disturbed_blue_ghost_tu >= (64.0f * 8.0f) / 512.0f)
		{				
			down_disturbed_blue_ghost_tu = (64.0f * 6.0f) / 512.0f;
		}

		left_disturbed_pink_ghost_tu += 64.0f / 512.0f;
		right_disturbed_pink_ghost_tu += 64.0f / 512.0f;
		up_disturbed_pink_ghost_tu += 64.0f / 512.0f;
		down_disturbed_pink_ghost_tu += 64.0f / 512.0f;

		if (left_disturbed_pink_ghost_tu >= (64.0f * 2.0f) / 512.0f)
		{
			left_disturbed_pink_ghost_tu = 0.0f;
		}
		if (right_disturbed_pink_ghost_tu >= (64.0f * 4.0f) / 512.0f)
		{
			right_disturbed_pink_ghost_tu = (64.0f * 2.0f) / 512.0f;
		}
		if (up_disturbed_pink_ghost_tu >= (64.0f * 6.0f) / 512.0f)
		{
			up_disturbed_pink_ghost_tu = (64.0f * 4.0f) / 512.0f;
		}
		if (down_disturbed_pink_ghost_tu >= (64.0f * 8.0f) / 512.0f)
		{
			down_disturbed_pink_ghost_tu = (64.0f * 6.0f) / 512.0f;
		}
		
		mess_blue_ghost_tu+= 64.0f / 512.0f;
		mess_pink_ghost_tu+= 64.0f / 512.0f;
		mess_disturbed_blue_ghost_tu+= 64.0f / 512.0f;
		mess_disturbed_pink_ghost_tu+= 64.0f / 512.0f;

		if (mess_blue_ghost_tu >= (64.0f * 2.0f) / 512.0f)
		{
			mess_blue_ghost_tu = 0.0f;
		}
	
		if (mess_pink_ghost_tu >= (64.0f * 4.0f) / 512.0f)
		{
			mess_pink_ghost_tu = (64.0f * 2.0f) / 512.0f;
		}

		if (mess_disturbed_blue_ghost_tu >= (64.0f * 6.0f) / 512.0f)
		{
			mess_disturbed_blue_ghost_tu = (64.0f * 4.0f) / 512.0f;
		}

		if (mess_disturbed_pink_ghost_tu >= (64.0f * 8.0f) / 512.0f)
		{
			mess_disturbed_pink_ghost_tu = (64.0f * 6.0f) / 512.0f;
		}
	}




	if (dx.KeyState[DIK_SPACE] == dx.PRESS) {
		if (!is_get) {
			is_get = true;
		}
		else {
			is_get = false;
		}
	}
	if (flamecount_a >= 8) {
		powercookie_tu += 0.25f;
		flamecount_a = 0;
	}
	if (powercookie_tu >= 1.0f) {
		powercookie_tu = 0.25f;
	}

	if (!is_get) {
		//ブルーのパワークッキー取得
		Draw(800, 0, 0xffffffff, 0.0f, 0.0f, 50, 50, 0.25f, 0.5f, POWER_COOKIE_GAUGE);
		//ピンクのパワークッキー取得
		Draw(900, 0, 0xffffffff, 0.0f, 0.5f, 50, 50, 0.25f, 0.5f, POWER_COOKIE_GAUGE);
	}
	else {
		Draw(800, 0, 0xffffffff, powercookie_tu, 0.0f, 50, 50, 0.25f, 0.5f, POWER_COOKIE_GAUGE);
		Draw(900, 0, 0xffffffff, powercookie_tu, 0.5f, 50, 50, 0.25f, 0.5f, POWER_COOKIE_GAUGE);
	}

	flamecount_a++;
	

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
