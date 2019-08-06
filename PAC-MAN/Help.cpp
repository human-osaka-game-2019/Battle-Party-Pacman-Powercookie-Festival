#include "Help.h"

//ヘルプのフェーズの移動
void Help::Help_Scene() {

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

//ヘルプのテクスチャの読み込み
void Help::Loading() {

	LoadTexture("Help_Back.png", HELP_BACK);

	Phase = PROCESSING;
}

//ヘルプの描画処理
void Help::Process() {

	Draw(0,0,0xffffffff,0.0f,0.0f,WINDOW_WIDTH,WINDOW_HEIGHT,1.0f,1.0f,HELP_BACK);

	//エンターでタイトルへ
	if (dx.KeyState[DIK_RETURN] == dx.PRESS || dx.KeyState[DIK_BACK] == dx.PRESS || dx.KeyState[DIK_Z] == dx.PRESS || dx.KeyState[DIK_X] == dx.PRESS) {
		Phase = RELEASES;
	}
}

//ヘルプのテクスチャの解放
void Help::Release() {

	for (int i = 0; i < TEX_MAX; i++) {
		if (dx.pTexture[i] != nullptr) {
			dx.pTexture[i]->Release();
			dx.pTexture[i] = nullptr;
		}
	}
	scene = TITLE;
}
