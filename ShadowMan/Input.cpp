#include <Windows.h>
#include <dinput.h>
#include "Input.h"

struct INPUTSTATE // キーの情報の構造体
{
	DWORD now;
	DWORD pushed;
	DWORD npushed;
};

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

void ReleaseDirectInput()
{
	g_pKeyDevice->Unacquire();
	g_pKeyDevice->Release();
	g_pInputInterface->Release();
}

void KeyUpDate()
{
	//Save Key Info
	BYTE KeyState[256];
	HRESULT hr;

	hr = g_pKeyDevice->GetDeviceState(256, KeyState); // Keyboard Device Get
	if (SUCCEEDED(hr))
	{
		// 1 Prev Frame Info Get
		DWORD old = g_InputState.now;

		if (KeyState[DIK_UP] & 0x80) // UP Key
		{
			g_InputState.now |= DIK_UP;
			.y -= 1.0f;				 // Character Move Up
		}

		if (KeyState[DIK_DOWN] & 0x80) // DOWN Key
		{
			g_InputState.now |= DIK_DOWN;
			.y += 1.0f;				// Character Move Down
		}

		if (KeyState[DIK_LEFT] & 0x80) // LEFT Key
		{
			g_InputState.now |= DIK_LEFT;
			.x -= 1.0f;				// Character Move Left
		}

		if (KeyState[DIK_RIGHT] & 0x80) // RIGHT Key
		{
			g_InputState.now |= DIK_RIGHT;
			.x += 1.0f;				// Character Move Right
		}

		if (KeyState[DIK_SPACE] & 0x80) // SPACE Key
		{
			g_InputState.now |= DIK_SPACE;
			// ゲーム本編へ移る
		}

		if (KeyState[DIK_H] & 0x80) // H Key
		{
			g_InputState.now |= DIK_H;
			// ゲームヘルプへ移る
		}

		g_InputState.pushed = (g_InputState.now & (~old)); // Push Info Get
		g_InputState.npushed = (~g_InputState.now) & old; // NonPush Info Get
	} else if (hr == DIERR_INPUTLOST) {
		g_pKeyDevice->Acquire();
	}

	void EnemyControl();
	{
		// ベクトルを出す
		float vecx = player->m_PosX - enemy->m_PosX;
		float vecy = player->m_PosY - enemy->m_PosY;

		// ベクトルをそのまま座標に足す
		//enemy->m_PosX += vecx;
		//enemy->m_PosY += vecy;

		float length = sqrtf((vecx * vecx) + (vecy * vecy));
		float normal_x = vecx / length;
		float normal_y = vecy / length;

		enemy->m_PosX += normal_x;
		enemy->m_PosY += normal_y;
	}

}
