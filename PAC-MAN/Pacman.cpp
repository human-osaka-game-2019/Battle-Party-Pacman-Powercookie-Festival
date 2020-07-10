#include "Pacman.h"

void Pacman::Init(float X,float Y)
{

	x = X;
	y = Y;

}

void Pacman::Update()
{
	Move();

	switch(next_movekey)
	{
	case KEY::UP:
		y -= 2;
		break;
	case KEY::DOWN:
		y += 2;
		break;
	case KEY::LEFT:
		x -= 2;
		break;
	case KEY::RIGHT:
		x += 2;
		break;
	case KEY::STOP:
		break;
	default:
		break;
	}
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




