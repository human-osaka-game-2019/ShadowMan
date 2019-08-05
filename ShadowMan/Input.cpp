#include "Input.h"


static LPDIRECTINPUT8 g_pInputInterface; // DIRECTINPUT8のポインタ
static LPDIRECTINPUTDEVICE8 g_pKeyDevice; // DIRECTINPUTDEVICE8のポインタ
static INPUTSTATE g_InputState; // キーの情報


bool InitDirectInput(HINSTANCE Instance_Handle, HWND Window_Handle)
{
	//IDirectInput8 Interface
	HRESULT hr = DirectInput8Create(Instance_Handle,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)& g_pInputInterface,
		NULL);

	if (FAILED(hr))
	{
		MessageBox(Window_Handle, (char*)"Error", (char*)"作成失敗A", MB_OK);
		return false;
	}

	// IDirectInputDevice8 Interface
	hr = g_pInputInterface->CreateDevice(GUID_SysKeyboard, &g_pKeyDevice, NULL);
	if (FAILED(hr))
	{
		MessageBox(Window_Handle, (char*)"Error", (char*)"作成失敗B", MB_OK);
		return false;
	}

	// Device Format Setting
	hr = g_pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
	{
		MessageBox(Window_Handle, (char*)"Error", (char*)"Device Format 設定失敗", MB_OK);
		return false;
	}

	// CooperativeLevel Setting
	hr = g_pKeyDevice->SetCooperativeLevel(Window_Handle, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr))
	{
		MessageBox(Window_Handle, (char*)"Error", (char*)"CooperativeLevel 設定失敗", MB_OK);
		return false;
	}

	g_pKeyDevice->Acquire(); // Device Acquire Start

	return true;
}

void KeyUpDate()

{
	BYTE KeyState[256];
	HRESULT hr;

	hr = g_pKeyDevice->GetDeviceState(256, KeyState); // Keyboard Device Get
	if (SUCCEEDED(hr))
	{
		// 1 Prev Frame Info Get
		DWORD old = g_InputState.now;

		g_InputState.now = CLEAR;

		if (KeyState[DIK_UP] & 0x80) // UP Key
		{
			g_InputState.now |= UP;	// Character Move Up
		}

		if (KeyState[DIK_DOWN] & 0x80) // DOWN Key
		{
			g_InputState.now |= DOWN; // Character Move Down
		}

		if (KeyState[DIK_LEFT] & 0x80) // LEFT Key
		{
			g_InputState.now |= LEFT; // Character Move Left
		}

		if (KeyState[DIK_RIGHT] & 0x80) // RIGHT Key
		{
			g_InputState.now |= RIGHT; // Character Move Right
		}

		if (KeyState[DIK_H] & 0x80) // H Key
		{
			g_InputState.now |= H;
			// ゲームヘルプへ移る
		}

		if (KeyState[DIK_SPACE] & 0x80) // SPACE Key
		{
			g_InputState.now |= SPACE;
			// ゲーム本編へ移る
		}

		if (KeyState[DIK_ESCAPE] & 0x80) // ESC Key
		{
			// ゲームタイトルへ戻る
			g_InputState.now |= ESCAPE;
		}

		g_InputState.pushed = (g_InputState.now & (~old)); // Push Info Get
		g_InputState.npushed = (~g_InputState.now) & old; // NonPush Info Get
	}
	else if (hr == DIERR_INPUTLOST) {
		g_pKeyDevice->Acquire();
	}
}

// プレーヤー移動
void PlayerControl(Object* player)
{

	if (GetKey(UP) == true)
	{
		player->y -= player->speed;
	}

	else if (GetKey(DOWN) == true)
	{
		player->y += player->speed;
	}

	// 左右
	if (GetKey(LEFT) == true)
	{
		player->x -= player->speed;
	}

	else if (GetKey(RIGHT) == true)
	{
		player->x += player->speed;
	}

}


// 当たり判定
bool Collision(Object* enemy, Object* player)
{
	// 敵キャラとプレイヤーキャラの当たり判定
	float a = player->x - enemy->x;		// X座標の算出
	float b = player->y - enemy->y;		// Y座標の算出
	float c = sqrt(a * a + b * b);			// 二つの円の距離の算出

	if (c <= player->circle_radius + enemy->circle_radius)
	{
		/*
		当たってる
		プレイヤー死亡
		*/
		return true;
	}
	else
	{
		/*
		当たってない
		ゲーム続行
		*/
		return false;
	}

}

void CollisionWallP(Object* enemy, Object* player)
{
	// プレイヤーキャラと壁の当たり判定

	// Player
	player->x;
	player->y;
	player->rect_wid = 64.0f;
	player->rect_hgt = 64.0f;

	// Enemy
	enemy->x;
	enemy->y;
	enemy->rect_wid = 64.0f;
	enemy->rect_hgt = 64.0f;

	/* Wall
	wall->rect_x; //マップチップの'壁'のX座標
	float rectW_y; //マップチップの'壁'のY座標
	float rectW_wid = 64.0f;
	float rectW_hgt = 64.0f;
	

	if (player->rect_x + player->rect_wid >= rectW_x && rectP_x <= rectW_x + rectW_wid &&
		rectP_y + rectP_hgt >= rectW_y && rectP_y <= rectW_y + rectW_hgt)
	{

		// 当たってる

	}

	else
	{

		// 当たってない

	}
	*/
}

bool GetKey(DWORD key_code)
{
	return g_InputState.now& key_code;
}

bool GetKeyDown(DWORD key_code)
{
	return g_InputState.pushed& key_code;
}

bool GetKeyUp(DWORD key_code)
{
	return g_InputState.npushed& key_code;
}

void ReleaseDirectInput()
{
	g_pKeyDevice->Unacquire();
	g_pKeyDevice->Release();
	g_pInputInterface->Release();
}