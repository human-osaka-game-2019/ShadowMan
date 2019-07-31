#include "Input.h"


static LPDIRECTINPUT8 g_pInputInterface; // DIRECTINPUT8‚Ìƒ|ƒCƒ“ƒ^
static LPDIRECTINPUTDEVICE8 g_pKeyDevice; // DIRECTINPUTDEVICE8‚Ìƒ|ƒCƒ“ƒ^
static INPUTSTATE g_InputState; // ƒL[‚Ìî•ñ


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
		MessageBox(Window_Handle, (char*)"Error", (char*)"ì¬Ž¸”sA", MB_OK);
		return false;
	}

	// IDirectInputDevice8 Interface
	hr = g_pInputInterface->CreateDevice(GUID_SysKeyboard, &g_pKeyDevice, NULL);
	if (FAILED(hr))
	{
		MessageBox(Window_Handle, (char*)"Error", (char*)"ì¬Ž¸”sB", MB_OK);
		return false;
	}

	// Device Format Setting
	hr = g_pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
	{
		MessageBox(Window_Handle, (char*)"Error", (char*)"Device Format Ý’èŽ¸”s", MB_OK);
		return false;
	}

	// CooperativeLevel Setting
	hr = g_pKeyDevice->SetCooperativeLevel(Window_Handle, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr))
	{
		MessageBox(Window_Handle, (char*)"Error", (char*)"CooperativeLevel Ý’èŽ¸”s", MB_OK);
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

		if (KeyState[DIK_UP] & 0x80) // UP Key
		{
			g_InputState.now |= DIK_UP;	// Character Move Up
		}

		if (KeyState[DIK_DOWN] & 0x80) // DOWN Key
		{
			g_InputState.now |= DIK_DOWN; // Character Move Down
		}

		if (KeyState[DIK_LEFT] & 0x80) // LEFT Key
		{
			g_InputState.now |= DIK_LEFT; // Character Move Left
		}

		if (KeyState[DIK_RIGHT] & 0x80) // RIGHT Key
		{
			g_InputState.now |= DIK_RIGHT; // Character Move Right
		}

		if (KeyState[DIK_SPACE] & 0x80) // SPACE Key
		{
			g_InputState.now |= DIK_SPACE;
			// ƒQ[ƒ€–{•Ò‚ÖˆÚ‚é
		}

		if (KeyState[DIK_H] & 0x80) // H Key
		{
			g_InputState.now |= DIK_H;
			// ƒQ[ƒ€ƒwƒ‹ƒv‚ÖˆÚ‚é
		}

		g_InputState.pushed = (g_InputState.now & (~old)); // Push Info Get
		g_InputState.npushed = (~g_InputState.now) & old; // NonPush Info Get
	}
	else if (hr == DIERR_INPUTLOST) {
		g_pKeyDevice->Acquire();
	}

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