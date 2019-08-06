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


	int flamecount_result = 0;
	float one_logo_tu = 0.0f;
	float two_logo_tu = 0.0f;

	oneORtwo one_or_two;
	
};
#endif
