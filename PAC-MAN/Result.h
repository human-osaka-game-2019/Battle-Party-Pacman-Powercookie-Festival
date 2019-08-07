#ifndef RESULT_H
#define RESULT_H

#include "DirectX.h"
#include "Main.h"

class Result {
public:

	void Result_Scene();

	enum SCENE_PHASE {
		LOAD,
		PROCESSING,
		RELEASES
	};

	//リザルトのフェーズの宣言
	Result::SCENE_PHASE Phase = Result::LOAD;


	

private:

	enum oneORtwo {

		one,
		two,
	};

	void Loading();
	void Process();
	void Release();

	enum Result_SelectUI_ID
	{
		select_ui_retry,
		select_ui_title,

	};

	Result_SelectUI_ID Result_ID;


	int flamecount_result = 0;
	float one_logo_tu = 0.0f;
	float two_logo_tu = 0.0f;
	float result_select_ui_tu_a = 0.5f;
	float result_select_ui_tu_b = 0.5f;

	oneORtwo one_or_two;
	
};
#endif
