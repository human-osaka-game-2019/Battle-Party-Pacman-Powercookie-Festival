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

	LoadTexture("Result_1p.png", RESULT_BACK_LEFT_PLAYER);
	LoadTexture("Result_logo.png", RESULT_LOGO);
	LoadTexture("Result_select_ui.png", RESULT_SELECT_UI);
	LoadTexture("Result_2p.png", RESULT_BACK_RIGHT_PLAYER);
	Phase = PROCESSING;
}

//リザルトの描画処理
void Result::Process() {

	if (one_or_two == one) {
		Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 1.0f, 1.0f, RESULT_BACK_LEFT_PLAYER);
		Draw(560, 100, 0xffffffff, one_logo_tu, 0.0f, 800, 800, 0.25f, 0.5f, RESULT_LOGO);
		Draw(100, 900, 0xffffffff, 0.5f, 0.5f, 370, 170, 0.5f, 0.5f, RESULT_SELECT_UI);
		Draw(1450, 900, 0xffffffff, 0.5f, 0.0f, 370, 170, 0.5f, 0.5f, RESULT_SELECT_UI);
	}
	if (one_or_two == two) {
		Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 1.0f, 1.0f, RESULT_BACK_RIGHT_PLAYER);
		Draw(560, 100, 0xffffffff, two_logo_tu, 0.5f, 800, 800, 0.25f, 0.5f, RESULT_LOGO);
		Draw(1450, 900, 0xffffffff, 0.0f, 0.0f, 370, 170, 0.5f, 0.5f, RESULT_SELECT_UI);
		Draw(100, 900, 0xffffffff, 0.0f, 0.5f, 370, 170, 0.5f, 0.5f, RESULT_SELECT_UI);
	}
	if (dx.KeyState[DIK_S] == dx.PRESS)
	{
		one_or_two = one;
	}
	if (dx.KeyState[DIK_K] == dx.PRESS)
	{
		one_or_two = two;

	}






	flamecount_result++;
	if (flamecount_result >= 20)
	{
		flamecount_result = 0;
		one_logo_tu += 0.25;
		two_logo_tu += 0.25;
		if (one_logo_tu >= 0.75)
		{
			one_logo_tu = 0;

		}
		if (two_logo_tu >= 0.75)
		{
			two_logo_tu = 0;

		}

	}

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
