﻿
#include "Main.h"
#include "DirectX.h"

#include "Title.h"
#include "Help.h"
#include "Game.h"
#include "Result.h"

//ここ出来ればなくしたい
DirectX dx;
Title title;
Help help;
Game game;
Result result;

SCENE scene = TITLE;

//メイン
INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdline, _In_ int nCmdShow) {
	HWND hWnd = NULL;
	const TCHAR API_NAME[] = _T("PAC-MAN");
	//メッセージ
	MSG msg;
	hWnd = GenerateWindow(&hWnd, &hInstance, API_NAME);
	dx.BuildDxDevice(hWnd, _T("Blank.jpg"));

	Mainloop(&msg);


	//ウィンドウ情報をみて更新
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	dx.All_Release();

	return (int)msg.wParam;
}

//ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	//メッセージ別の処理
	switch (msg)
	{
		//ウィンドウが破壊されたときのメッセージ
	case WM_DESTROY:
		//閉じるメッセージを送る
		PostQuitMessage(0);
		return 0;
		//ユーザーがメニューかALTキーと何かを押したとき
	case WM_SYSKEYDOWN:
		switch (wp)
		{
		case VK_RETURN:
			return 0;
		case VK_F4:
			//閉じるメッセ―ジ
			PostMessage(hWnd, WM_CLOSE, 0, 0);
			return 0;
		default:
			return 0;
		}
		return 0;
	}
	//DefaultWindowProcedureを返す(デフォルト)
	return DefWindowProc(hWnd, msg, wp, lp);
}

void Rotate(CUSTOMVERTEX  original[], CUSTOMVERTEX rotatevertex[], double degree = 0.0f) {
	float center_x = (original[0].x + original[1].x) / 2.0f;
	float center_y = (original[0].y + original[3].y) / 2.0f;


	for (int i = 0; i < 4; i++) {
		original[i].x -= center_x;
		original[i].y -= center_y;

		rotatevertex[i] = original[i];

		// 回転後のx = 回転前のx・cosθ - 回転前のy・sinθ
		rotatevertex[i].x = (float)(original[i].x * cos(dx.to_Rad(degree)) - original[i].y * sin(dx.to_Rad(degree)));

		// 回転後のy = 回転前のx・sinθ + 回転前のy・cosθ
		rotatevertex[i].y = (float)(original[i].x * sin(dx.to_Rad(degree)) + original[i].y * cos(dx.to_Rad(degree)));

		original[i].x += center_x;
		original[i].y += center_y;

		rotatevertex[i].x += center_x;
		rotatevertex[i].y += center_y;
	}

}

//描画関数
void Draw(FLOAT x, FLOAT y,DWORD color, FLOAT tu, FLOAT tv, FLOAT width, FLOAT height, FLOAT tu_width, FLOAT tv_height, int texture, double degree) {
	CUSTOMVERTEX customvertex[4]{
		{x        ,y         ,0,1,color,tu           ,tv            },
		{x + width,y         ,0,1,color,tu + tu_width,tv            },
		{x + width,y + height,0,1,color,tu + tu_width,tv + tv_height},
		{x        ,y + height,0,1,color,tu           ,tv + tv_height},
	};

	dx.pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	dx.pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	dx.pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	dx.pD3Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	CUSTOMVERTEX vertex[4];
	Rotate(customvertex,vertex,degree);

	dx.pD3Device->SetTexture(0, dx.pTexture[texture]);
	dx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));
}





void LoadTexture(const char* file_name,int TEX) {
	
	D3DXCreateTextureFromFileEx(
	dx.pD3Device,
	_T(file_name),
		0,
		0,
		1,0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0x00000000,
		nullptr,
		nullptr,
		&dx.pTexture[TEX]);
}
//
HWND GenerateWindow(HWND* hWnd, HINSTANCE* hInstance, const TCHAR* API_NAME) {
	//ウィンドウクラス
	WNDCLASS Wndclass;
	Wndclass.style = CS_HREDRAW | CS_VREDRAW; //ウィンドウスタイル
	Wndclass.lpfnWndProc = WndProc; //ウィンドウプロシージャ
	Wndclass.cbClsExtra = 0; //メモリ確保
	Wndclass.cbWndExtra = 0; //メモリ確保
	Wndclass.hInstance = *hInstance;	//ハンドルインスタンス
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //アイコン
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);	//カーソル
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); //背景のブラシ,色
	Wndclass.lpszMenuName = NULL; //メニュー画面の名前
	Wndclass.lpszClassName = API_NAME; //アプリケーションの名前

	//ウィンドウクラスの登録
	RegisterClass(&Wndclass);

	//ウィンドウハンドルにcreatewindow関数で作った情報を代入
	return *hWnd = CreateWindow(
		API_NAME,							//クラスの名前
		API_NAME,							//アプリケーションのタイトル
		WS_VISIBLE | WS_POPUP,	//ウィンドウのスタイル
		0,		            				//Xの位置
		0,		            				//Yの位置
		WINDOW_WIDTH,								//幅
		WINDOW_HEIGHT,								//高さ
		NULL,								//親ウィンドウのハンドル
		NULL,								//メニューのハンドル
		*hInstance,							//インスタンスハンドル
		NULL								//メッセージに渡されるパラメータ
	);
}

//メインループ
void Mainloop(MSG* msg) {

	DWORD Prev = timeGetTime();
	DWORD Curr;

	timeBeginPeriod(1);


	ZeroMemory(msg, sizeof(msg));
	while (msg->message != WM_QUIT) {
		if (PeekMessage(msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(msg);
			DispatchMessage(msg);
		}
		else {
			Curr = timeGetTime();
			if (Curr - Prev >= 1000 / 60) {

				dx.pD3Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);

				dx.pD3Device->BeginScene();

				dx.UpdateKeyState();

				//ここからゲーム処理
				switch (scene) {
				case TITLE:
					title.Title_Scene();
					break;
				case HELP:
					help.Help_Scene();
					break;
				case GAME:
					game.Game_Scene();
					break;
				case RESULT:
					result.Result_Scene();
					break;
				default:
					MessageBox(0, _T("シーン設定がされていません"), NULL, MB_OK);
				}
				dx.pD3Device->EndScene();
				dx.pD3Device->Present(NULL, NULL, NULL, NULL);

				Prev = Curr;

				if (dx.KeyState[DIK_ESCAPE] == dx.PRESS) {
					PostQuitMessage(0);
				}
			}
		}
		Sleep(1);
	}
	timeEndPeriod(1);
}
