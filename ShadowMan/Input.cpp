#include "Input.h"
#include <Windows.h>
#include <dinput.h>
#include "Window.h"
#include <time.h>
#include <d3dx9.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

static LPDIRECTINPUT8 g_InputInterface; // DIRECTINPUT8�̃|�C���^
static LPDIRECTINPUTDEVICE8 g_KeyboardDevice; // DIRECTINPUTDEVICE8�̃|�C���^

bool CreateInputInterface(); //���̓C���^�[�t�F�[�X�̍쐬

bool CreateKeyboardDevice(); //�L�[�{�[�h�f�o�C�X�̍쐬

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

bool OnKeyDown() // �L�[��������Ă鎞
{
	UpdateKeyState();
	if (GetKeyState(DIK_SPACE)) {
		// �Q�[���{�҂ֈڂ�
	}
	if (GetKeyState(DIK_H)) {
		// �Q�[���w���v�ֈڂ�
	}
	if (GetKeyState(DIK_UP)) {  // �v���C���[�L�����N�^�[�̈ړ��i�c�j
		.y -= 1.0f;
	}
	if (GetKeyState(DIK_DOWN)) {
		.y += 1.0f;
	}
	if (GetKeyState(DIK_LEFT)) {  // �v���C���[�L�����N�^�[�̈ړ��i���j
		.x -= 1.0f;
	}
	if (GetKeyState(DIK_RIGHT)) {
		.x += 1.0f;
	}


}