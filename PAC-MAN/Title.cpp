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
	
	



	/*for (int i = 0; i < 15; i++)
	{
		map.b[i] = map.a[i];
	}

	int** c = Mp.mapchip("Test_CSV.csv",15,14,map.b);*/



	/*map.DrawMapChip(MAP_SIZE_WIDTH,MAP_SIZE_HEIGHT,TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT,0.0f,0.0f);

	map.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 448.f + 100.f, 0.0f);
*/
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
