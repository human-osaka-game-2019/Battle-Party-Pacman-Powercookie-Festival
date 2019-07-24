﻿#ifndef RESULT_H
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

	FLOAT window_width = 1920;
	FLOAT window_height = 1080;


	void Loading();
	void Process();
	void Release();
};
#endif
