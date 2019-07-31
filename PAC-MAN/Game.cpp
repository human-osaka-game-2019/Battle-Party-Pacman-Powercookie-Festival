#include "Game.h"
#include "Mapchip.h"

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
	LoadTexture("Ghost.png", GHOST);

	Phase = PROCESSING;
}

//ゲームの描画と動き
void Game::Process() {

	map.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, 0.0f);

	map.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 448.f + 100.f, 0.0f);





	flamecount++;



	//ピンクゴースト
	Draw(0, 200, 0xffffffff, a_pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(0, 300, 0xffffffff, b_pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(100, 200, 0xffffffff, c_pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(100, 300, 0xffffffff, d_pink_ghost_tu, 0.0f, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	//ブルーゴースト
	Draw(200, 200, 0xffffffff, a_blue_ghost_tu, blue_ghost_tv, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(200, 300, 0xffffffff, b_blue_ghost_tu, blue_ghost_tv, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(300, 200, 0xffffffff, c_blue_ghost_tu, blue_ghost_tv, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);
	Draw(300, 300, 0xffffffff, d_blue_ghost_tu, blue_ghost_tv, 100, 100, 64.0f / 512.0f, 64.0f / 512.0f, GHOST);

	//ピンクゴーストアニメーション
	a_pink_ghost_tu += 64.0f / 512.0f;
	b_pink_ghost_tu += 64.0f / 512.0f;
	c_pink_ghost_tu += 64.0f / 512.0f;
	d_pink_ghost_tu += 64.0f / 512.0f;
	if (a_pink_ghost_tu >= (64.0f * 2.0f) / 512.0f)
	{
		a_pink_ghost_tu = 0.0f;
	}
	if (b_pink_ghost_tu >= (64.0f * 4.0f) / 512.0f)
	{
		b_pink_ghost_tu = (64.0f * 2.0f) / 512.0f;
	}
	if (c_pink_ghost_tu >= (64.0f * 6.0f) / 512.0f)
	{
		c_pink_ghost_tu = (64.0f * 4.0f) / 512.0f;
	}
	if (d_pink_ghost_tu >= (64.0f * 8.0f) / 512.0f)
	{
		d_pink_ghost_tu = (64.0f * 6.0f) / 512.0f;
	}
	//ブルーゴーストアニメーション
	a_blue_ghost_tu += 64.0f / 512.0f;
	b_blue_ghost_tu += 64.0f / 512.0f;
	c_blue_ghost_tu += 64.0f / 512.0f;
	d_blue_ghost_tu += 64.0f / 512.0f;
	if (a_blue_ghost_tu >= (64.0f * 2.0f) / 512.0f)
	{
		a_blue_ghost_tu = 0;
	}
	if (b_blue_ghost_tu >= (64.0f * 4.0f) / 512.0f)
	{
		b_blue_ghost_tu = (64.0f * 2.0f) / 512.0f;
	}
	if (c_blue_ghost_tu >= (64.0f * 6.0f) / 512.0f)
	{
		c_blue_ghost_tu = (64.0f * 4.0f) / 512.0f;
	}
	if (d_blue_ghost_tu >= (64.0f * 8.0f) / 512.0f)
	{
		d_blue_ghost_tu = (64.0f * 6.0f) / 512.0f;
	}
	



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

	if (dx.KeyState[DIK_UP] == dx.PRESS) {
		
	}
	if (dx.KeyState[DIK_DOWN] == dx.PRESS) {
		
	}
	if (dx.KeyState[DIK_LEFT] == dx.PRESS) {
		
	}
	if (dx.KeyState[DIK_RIGHT] == dx.PRESS) {
		
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


void JudgeCollision() {





}

void Rotate(float x) {






}