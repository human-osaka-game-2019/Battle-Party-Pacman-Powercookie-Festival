﻿#ifndef MAIN_H
#define MAIN_H

#include <windows.h>
#include <d3d9.h>

#include "DirectX.h"


//カスタムバーテックス
struct CUSTOMVERTEX {
	FLOAT x, y, z, rhw;
	DWORD color;
	FLOAT tu, tv;
};

enum TEX {
	TITLE_BACK,
	TITLE_LOGO,
	TITLE_SELECT_UI,
	TITLE_PACMAN,
	HELP_BACK,
	GAME_BACK,
	RESULT_BACK,
	PACMAN,
	GHOST_,
	COOKIE,
	POWER_COOKIE,
	GAUGE,
	BLUE_MAPCHIP,
	PINK_MAPCHIP,
	RESULT_BACK_RIGHT_PLAYER,
	RESULT_SELECT_UI,
	RESULT_LOGO,
	RESULT_BACK_LEFT_PLAYER,
	COUNTDOWN_BLUE,
	COUNTDOWN_PINK,
	COUNTDOWN,
	TEXTURE,
};

enum SCENE {
	TITLE,
	HELP,
	GAME,
	RESULT,
	RESULT_1P,
	RESULT_2P,
	EXIT,
};

extern DirectX dx;
extern SCENE scene;



//WinMain関数
INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdline, _In_ int nCmdShow);

//ウィンドプロシージャの生成
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//window作成
HWND GenerateWindow(HWND* hWnd, HINSTANCE* hInstance, const TCHAR* API_NAME);

//メインループ
void Mainloop(MSG* msg);

//描画関数
void Draw(FLOAT x, FLOAT y, DWORD color,FLOAT tu, FLOAT tv, FLOAT width, FLOAT height, FLOAT tu_width, FLOAT tv_height, INT texture,DOUBLE degree = 0.0f, FLOAT scall_x = 0.0f, FLOAT scall_y = 0.0f, FLOAT origin_x = 0.0f, FLOAT origin_y = 0.0f);

//テクスチャを読み込む
void LoadTexture(const char* file_name,int TEX);

DWORD WINAPI Thread(HWND hWnd, LPVOID* data);

VOID Load();


#endif
