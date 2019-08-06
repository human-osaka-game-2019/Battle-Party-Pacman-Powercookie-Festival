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
	TITLE_LOGO,
	TITLE_SELECT_UI,
	TITLE_PACMAN,
	GAME_BACK,
	RESULT_BACK_oneP,
	RESULT_BACK_twoP,
	RESULT_LOGO,
	RESULT_SELECT_UI,
	PINK_PACMAN,
	BLUE_PACMAN,
	COOKIE,
	POWER_COOKIE,
	POWER_COOKIE_GAUGE,
	PINK_GAUGE,
	BLUE_GAUGE,
	GHOST,
};

enum SCENE {
	TITLE,
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

void DrawTx(INT texture);

//テクスチャを読み込む
void LoadTexture(const char* file_name,int TEX);

#endif
