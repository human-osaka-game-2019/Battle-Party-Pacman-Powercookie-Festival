#ifndef GAME_H
#define GAME_H

#include "DirectX.h"
#include "Main.h"
#include "Mapchip.h"
#include "Pacman.h"
#include "Enemy.h"

#include <time.h>
#include <vector>




class Game {
public:

	void Game_Scene();

	enum SCENE_PAHSE 
	{
		LOAD,
		PROCESSING,
		RELEASES
	};

	enum CHAR
	{
		LEFT_CHAR,
		RIGHT_CHAR
	};


	struct COOKIE 
	{
		int cookie;
		int powercookie;
		int count;
	};
	

	

	Pacman pacman[2];

	std::vector<Enemy> ghost;

	COOKIE cookie[2];

	int fc_pacman = 0;
	int fc_countdown = 0;
	
	int repop_cookie_time = 0;

	int eating_cookie[100][2];
	int eating_cookie_Val = 0;
	int eating_cookie_Num = 0;

	int eating_power_cookie[4][2];
	int eating_power_cookie_Val = 0;
	int eating_power_cookie_Num = 0;

	int repop_cookie_count[100];
	int repop_power_cookie_count[20];
	int** pcookie;
	

	float countdown_tu = 0.0f;
	float countdown_tv = 0.0f;
	
	int flamecount_b = 0;


	char buf[256];


	Game::SCENE_PAHSE Phase = Game::LOAD;

	void Loading();
	void Process();
	void Release();

	////当たり判定
	//void JudgeCollision(PACMAN* pacman, float start_x, float start_y, int** map);
	////ゴーストが動けるかどうか
	//void CanMoveGhost(GHOST* ghost, float start_x, float start_y, int** map);
	////パックマンが死ぬ処理
	//void Die(float player_x, float player_y, float player_width, float player_height, float enemy_x, float enemy_y, float enemy_width, float enemy_hieght, int pacman_life);

	//void Right_Kill(float player_x, float player_y, float player_width, float player_height, float* enemy_x, float* enemy_y, float enemy_width, float enemy_hieght, float start_x, int* enemy_pop);

	//void Left_Kill(float player_x, float player_y, float player_width, float player_height, float* enemy_x, float* enemy_y, float enemy_width, float enemy_hieght, float start_x, int* enemy_pop);


	//void Eat(int** map, float ghost_x, float ghost_y, int* cookie, int* power_cookie);

	//void Pop(float enemy_x, float* enemy_y, int* enemy_pop);

	///*void Repop(int** map, int cookie);*/

	//void CountDown(float* tu, float* tv, int* flamecount);

	//void InputKey(PACMAN* pacman, COOKIE* cookie);

};
#endif