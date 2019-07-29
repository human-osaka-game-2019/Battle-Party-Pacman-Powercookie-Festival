#ifndef MAIN_H
#define MAIN_H

#include <windows.h>
#include <d3d9.h>

#include "DirectX.h"


//カスタムバーテックス
struct CustomVertex {
	FLOAT x, y, z, rhw;
	DWORD color;
	FLOAT tu, tv;
};

enum TEX {
	TITLE_BACK,
	HELP_BACK,
	GAME_BACK,
	RESULT_BACK,
	PACMAN,
	PINK_PACMAN,
	BLUE_PACMAN,
	PINK_GHOST,
	BLUE_GHOST,
	MESS_WIDTH_GHOST,
	COOKIE,
	POWER_COOKIE,
	PINK_GAUGE,
	BLUE_GAUGE,
	TEST_MAPCHIP,
};

enum SCENE {
	TITLE,
	HELP,
	GAME,
	RESULT
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
void Draw(FLOAT x, FLOAT y, DWORD color,FLOAT tu, FLOAT tv, FLOAT width, FLOAT height, FLOAT tu_width, FLOAT tv_height, INT texture);

//テクスチャを読み込む
void LoadTexture(const char* file_name,int TEX);

#endif
