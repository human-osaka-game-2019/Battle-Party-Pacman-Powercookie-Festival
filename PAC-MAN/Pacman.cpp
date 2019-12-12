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
			pacman[].next_movekey = KEY::UP;
			//左ステージのkey入力による当たり判定の方向
			pacman[LEFT_CHAR].forward_row = -1;
			pacman[LEFT_CHAR].forward_col = 0;
		}
		else if (dx.KeyState[DIK_S] == dx.PRESS) {
			pacman[LEFT_CHAR].next_movekey =KEY DOWN;
			//左ステージのkey入力による当たり判定の方向
			pacman[LEFT_CHAR].forward_row = 1;
			pacman[LEFT_CHAR].forward_col= 0;
		}
		else if (dx.KeyState[DIK_A] == dx.PRESS) {
			pacman[LEFT_CHAR].next_movekey = KEY::LEFT;
			//左ステージのkey入力による当たり判定の方向
			pacman[LEFT_CHAR].forward_row = 0;
			pacman[LEFT_CHAR].forward_col = -1;
		}
		else if (dx.KeyState[DIK_D] == dx.PRESS) {
			pacman[LEFT_CHAR].next_movekey = KEY::RIGHT;
			//左ステージのkey入力による当たり判定の方向
			pacman[LEFT_CHAR].forward_row = 0;
			pacman[LEFT_CHAR].forward_col = 1;
		}
	
		//右パックマンのkey入力
		if (dx.KeyState[DIK_UP] == dx.PRESS) {
			pacman[RIGHT_CHAR].next_movekey = KEY::UP;
			//右ステージのkey入力による当たり判定の方向
			pacman[RIGHT_CHAR].forward_row = -1;
			pacman[RIGHT_CHAR].forward_col = 0;
		}
		else if (dx.KeyState[DIK_DOWN] == dx.PRESS) {
			pacman[RIGHT_CHAR].next_movekey = KEY::DOWN;
			//右ステージのkey入力による当たり判定の方向
			pacman[RIGHT_CHAR].forward_row = 1;
			pacman[RIGHT_CHAR].forward_col = 0;
		}
		else if (dx.KeyState[DIK_LEFT] == dx.PRESS) {
			pacman[RIGHT_CHAR].next_movekey = KEY::LEFT;
			//右ステージのkey入力による当たり判定の方向
			pacman[RIGHT_CHAR].forward_row = 0;
			pacman[RIGHT_CHAR].forward_col = -1;
		}
		else if (dx.KeyState[DIK_RIGHT] == dx.PRESS) {
			pacman[RIGHT_CHAR].next_movekey = KEY::RIGHT;
			//右ステージのkey入力による当たり判定の方向
			pacman[RIGHT_CHAR].forward_row = 0;
			pacman[RIGHT_CHAR].forward_col = 1;
		}
	
		//左のパワークッキー
		if (cookie[LEFT_CHAR].powercookie == 1 && dx.KeyState[DIK_E] == dx.PRESS) {
			cookie[LEFT_CHAR].count = 60 * 8;
			cookie[LEFT_CHAR].powercookie = 0;
		}
		//右のパワークッキー
		if (cookie[RIGHT_CHAR].powercookie == 1 && dx.KeyState[DIK_END] == dx.PRESS) {
			cookie[RIGHT_CHAR].count = 60 * 8;
			cookie[RIGHT_CHAR].powercookie = 0;
		}
}




