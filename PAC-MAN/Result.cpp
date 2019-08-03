#include "Result.h"

//リザルトのフェーズの移動
void Result::Result_Scene() {

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

//リザルトのテクスチャの読み込み
void Result::Loading() {

	LoadTexture("Result_Back.png", RESULT);

	Phase = PROCESSING;
}

//リザルトの描画処理
void Result::Process() {

	Draw(0, 0, 0xffffffff, 0.0f, 0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 1.0f, 1.0f, HELP_BACK);

	//エンターでタイトルへ
	if (dx.KeyState[DIK_RETURN] == dx.PRESS) {
		Phase = RELEASES;
	}
}

//リザルトのテクスチャの解放
void Result::Release() {

	for (int i = 0; i < TEX_MAX; i++) {
		if (dx.pTexture[i] != nullptr) {
			dx.pTexture[i]->Release();
			dx.pTexture[i] = nullptr;
		}
	}
	scene = TITLE;
}
