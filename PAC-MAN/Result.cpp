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
	LoadTexture("select_result_ui.png", RESULT_SELECT_UI);
	LoadTexture("Result_2p.png", RESULT_BACK_RIGHT_PLAYER);

	int flamecount_result = 0;
	float one_logo_tu = 0.0f;
	float two_logo_tu = 0.0f;
	float result_select_ui_tu_a = 0.5f;
	float result_select_ui_tu_b = 0.5f;

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
	if (one_or_two == one) {
		Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 1.0f, 1.0f, RESULT_BACK_LEFT_PLAYER);
		Draw(560, 100, 0xffffffff, one_logo_tu, 0.0f, 800, 800, 0.25f, 0.5f, RESULT_LOGO);
		Draw(100, 900, 0xffffffff, result_select_ui_tu_a, 0.5f, 370, 170, 0.5f, 0.5f, RESULT_SELECT_UI);
		Draw(1450, 900, 0xffffffff, result_select_ui_tu_b, 0.0f, 370, 170, 0.5f, 0.5f, RESULT_SELECT_UI);
	}
	if (one_or_two == two) {
		Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 1.0f, 1.0f, RESULT_BACK_RIGHT_PLAYER);
		Draw(560, 100, 0xffffffff, two_logo_tu, 0.5f, 800, 800, 0.25f, 0.5f, RESULT_LOGO);
		Draw(100, 900, 0xffffffff, result_select_ui_tu_a, 0.5f, 370, 170, 0.5f, 0.5f, RESULT_SELECT_UI);
		Draw(1450, 900, 0xffffffff, result_select_ui_tu_b, 0.0f, 370, 170, 0.5f, 0.5f, RESULT_SELECT_UI);
	}
	if (dx.win == 1)
	{
		one_or_two = one;
	}
	if (dx.win == 2)
	{
		one_or_two = two;

	}

	if (dx.KeyState[DIK_RIGHT] == dx.PRESS)
	{
		switch (Result_ID)
		{
		case select_ui_retry:
			Result_ID = select_ui_title;
			result_select_ui_tu_b -= 0.5f;
			result_select_ui_tu_a = 0.5f;
			break;
		default:
			break;
		}


	}

	
	if (dx.KeyState[DIK_LEFT] == dx.PRESS)
		switch (Result_ID)
		{
		case select_ui_title:
			Result_ID = select_ui_retry;
			result_select_ui_tu_a -= 0.5f;
			result_select_ui_tu_b = 0.5f;
			break;
		default:
			break;
		}
	if (dx.KeyState[DIK_RETURN] == dx.PRESS)
		switch (Result_ID)
		{
		case select_ui_title:
			scene = TITLE;
			break;
		case select_ui_retry:
			scene = GAME;
		default:
			break;
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
	Phase = LOAD;
	scene = TITLE;
}
