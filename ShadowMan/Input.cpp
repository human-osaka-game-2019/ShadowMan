#include "Input.h"
#include <Windows.h>
#include <dinput.h>
#include "Window.h"
#include <time.h>
#include <d3dx9.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

static LPDIRECTINPUT8 g_InputInterface; // DIRECTINPUT8のポインタ
static LPDIRECTINPUTDEVICE8 g_KeyboardDevice; // DIRECTINPUTDEVICE8のポインタ

bool CreateInputInterface(); //入力インターフェースの作成

bool CreateKeyboardDevice(); //キーボードデバイスの作成

HRESULT InitDinput(HWND hInst);

LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);


bool InitInput()
{
	if (CreateInputInterface() == false)
	{
		return false;
	}

	if (CreateKeyboardDevice() == false)
	{
		EndInput();
		return false;
	}

	return true;
}

void EndInput()
{
	if (g_KeyboardDevice != nullptr)
	{
		g_KeyboardDevice->Release();
		g_KeyboardDevice = nullptr;
	}

	if (g_InputInterface != nullptr)
	{
		g_InputInterface->Release();
		g_InputInterface = nullptr;
	}
}

void UpdateInput()
{
	UpdateKeyState();

	HRESULT hr = g_KeyboardDevice->GetDeviceState(sizeof(KeyState),NULL);
	if (FAILED(hr))
	{
		g_KeyboardDevice->Acquire();
		hr = g_KeyboardDevice->GetDeviceState(sizeof(KeyState),NULL);
	}
}

bool OnKeyDown() // キーが押されてる時
{
	UpdateKeyState();
	if (GetKeyState(DIK_SPACE)) {
		// ゲーム本編へ移る
	}
	if (GetKeyState(DIK_H)) {
		// ゲームヘルプへ移る
	}
	if (GetKeyState(DIK_UP)) {  // プレイヤーキャラクターの移動（縦）
		.y -= 1.0f;
	}
	if (GetKeyState(DIK_DOWN)) {
		.y += 1.0f;
	}
	if (GetKeyState(DIK_LEFT)) {  // プレイヤーキャラクターの移動（横）
		.x -= 1.0f;
	}
	if (GetKeyState(DIK_RIGHT)) {
		.x += 1.0f;
	}


}