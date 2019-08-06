#ifndef HELP_H
#define HELP_H

#include "DirectX.h"
#include "Main.h"

class Help {
public:

	void Help_Scene();

	enum SCENE_PHASE {
		LOAD,
		PROCESSING,
		RELEASES
	};

	//リザルトのフェーズの宣言
	Help::SCENE_PHASE Phase = Help::LOAD;

private:

	void Loading();
	void Process();
	void Release();
};
#endif // !HELP_H


