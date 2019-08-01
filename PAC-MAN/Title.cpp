#include "Title.h"
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

	

	Phase = PROCESSING;
}

//タイトルの描画処理
void Title::Process() {
	
	


	//エンターでゲームへ
	if (dx.KeyState[DIK_RETURN] == dx.PRESS) {
		Phase = RELEASES;
		nextseen = GAME;
	}
	if (dx.KeyState[DIK_SPACE] == dx.PRESS) {
		Phase = RELEASES;
		nextseen = HELP;
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
	if (nextseen == GAME) {
		scene = GAME;
	}
	if (nextseen == HELP) {
		scene = HELP;
	}
}
