#include "Pacman.h"

void Pacman::Init()
{





	//パックマン初期化
	/*	416.0f + (960 * i),
		736.0f,
		0.0f,
		0.0f,
		0,
		0,
		90,
		KEY::STOP,
		KEY::STOP,
		1,*/
}

void Pacman::Update()
{
	Move();
}

void Pacman::Move()
{

	if (dx.KeyState[DIK_W] == dx.PRESS) {
		next_movekey = KEY::UP;
		//左ステージのkey入力による当たり判定の方向
		forward_row = -1;
		forward_col = 0;
	}
	else if (dx.KeyState[DIK_S] == dx.PRESS) {
		next_movekey =KEY::DOWN;
		//左ステージのkey入力による当たり判定の方向
		forward_row = 1;
		forward_col= 0;
	}
	else if (dx.KeyState[DIK_A] == dx.PRESS) {
		next_movekey = KEY::LEFT;
		//左ステージのkey入力による当たり判定の方向
		forward_row = 0;
		forward_col = -1;
	}
	else if (dx.KeyState[DIK_D] == dx.PRESS) {
		next_movekey = KEY::RIGHT;
		//左ステージのkey入力による当たり判定の方向
		forward_row = 0;
		forward_col = 1;
	}
}




