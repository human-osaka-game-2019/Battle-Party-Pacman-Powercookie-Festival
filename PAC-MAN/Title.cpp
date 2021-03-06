﻿#include "Title.h"
#include"Mapchip.h"

//タイトルのフェーズの宣言
Title::SCENE_PHASE Phase = Title::LOAD;
//
//MapchipLoading Mp;
//DrawMap map;

//タイトルのフェーズの移動
void Title::Title_Scene() {

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

//タイトルのテクスチャの読み込み
void Title::Loading() {

	LoadTexture("titleback.jpg", TITLE_BACK);
	LoadTexture("title_logo.png", TITLE_LOGO);
	LoadTexture("select_title_ui.png", TITLE_SELECT_UI);
	LoadTexture("yellow_pacman.png", TITLE_PACMAN);

	// 選択UIをリセット
	currentID = select_ui_start;
	pacman_y = 795;
	title_select_ui_tu_a = 0.5f;
	title_select_ui_tu_b = 0.0f;
	title_select_ui_tu_c = 0.0f;
	nextscene = GAME;

	Phase = PROCESSING;

}

//タイトルの描画処理
void Title::Process() {
	
	flamecount_title_logo++;
	flamecount_pacman++;
	//タイトルの描画
	Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 1.0f, 1.0f, TITLE_BACK);

	Draw(510, -40.0, 0xffffffff, title_logo_tu, 0.0f, 900, 900, 0.25f, 1.0f, TITLE_LOGO);

	//4:1
	Draw(750, 780, 0xffffffff, title_select_ui_tu_a, 0.0f, 320, 80, 0.5f, 0.25f, TITLE_SELECT_UI);
	Draw(750, 850, 0xffffffff, title_select_ui_tu_b, 0.25f, 320, 80, 0.5f, 0.25f, TITLE_SELECT_UI);
	Draw(750, 920, 0xffffffff, title_select_ui_tu_c, 0.5f, 320, 80, 0.5f, 0.25f, TITLE_SELECT_UI);
	Draw(770, pacman_y, 0xffffffff, title_pacman_tu, 0.0f, 50, 50, 0.25f, 1.0f, TITLE_PACMAN);

	Draw(0, 600, 0xffffff,0.0f, 0.0f, 800, 200, 1 / 20, 1 / 2, GAUGE);

	Draw(960, 600, 0xffffff, 0.0f, 0.5f, 800, 200, 1 / 20, 1 / 2, GAUGE);

	if (flamecount_pacman >= 6)
	{
		title_pacman_tu += 0.25f;
		flamecount_pacman = 0;
		if (title_pacman_tu >= 1.0f)
		{
			title_pacman_tu = 0.0f;
		}
	}

	if (flamecount_title_logo >= 20)
	{
		title_logo_tu += 0.25;
		if (title_logo_tu >= 0.75f)
		{
			title_logo_tu = 0;
		}

		flamecount_title_logo = 0;

	}

	if (dx.KeyState[DIK_DOWN] == dx.PRESS)
	{
		// ボタンを押されたら選択UIをいったんリセット
		title_select_ui_tu_a = 0.0f;
		title_select_ui_tu_b = 0.0f;
		title_select_ui_tu_c = 0.0f;

		//idに数字を持たせる
		//割り切れるかで選択されているかの判断

		switch (currentID)
		{
		case select_ui_start:
			pacman_y = 865;
			currentID = select_ui_help;
			title_select_ui_tu_b += 0.5f;
			nextscene = HELP;
			break;
		case select_ui_help:
			pacman_y = 936;
			currentID = select_ui_exit;
			title_select_ui_tu_c += 0.5f;
			nextscene = EXIT;
			break;
		case select_ui_exit:
			pacman_y = 795;
			currentID = select_ui_start;
			title_select_ui_tu_a += 0.5f;
			nextscene = GAME;
			break;
		default:
			break;
		}

	}
	//エンターでゲームへ
	if (dx.KeyState[DIK_RETURN] == dx.PRESS) {
			Phase = RELEASES;

	}
}

//タイトルのテクスチャの解放
void Title::Release() {

	for (int i = 0; i < TEX_MAX; i++) {
		if (dx.pTexture[i] != nullptr) {
			dx.pTexture[i]->Release();
			dx.pTexture[i] = nullptr;
		}
	}

	if (nextscene == GAME) {
		scene = GAME;
	}
	if (nextscene == HELP) {
		scene = HELP;
	}
	if (nextscene == EXIT) {
		PostQuitMessage(0);
	}
}
