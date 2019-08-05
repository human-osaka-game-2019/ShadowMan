#include "Input.h"


static LPDIRECTINPUT8 g_pInputInterface; // DIRECTINPUT8�̃|�C���^
static LPDIRECTINPUTDEVICE8 g_pKeyDevice; // DIRECTINPUTDEVICE8�̃|�C���^
static INPUTSTATE g_InputState; // �L�[�̏��


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
		MessageBox(Window_Handle, (char*)"Error", (char*)"�쐬���sA", MB_OK);
		return false;
	}

	// IDirectInputDevice8 Interface
	hr = g_pInputInterface->CreateDevice(GUID_SysKeyboard, &g_pKeyDevice, NULL);
	if (FAILED(hr))
	{
		MessageBox(Window_Handle, (char*)"Error", (char*)"�쐬���sB", MB_OK);
		return false;
	}

	// Device Format Setting
	hr = g_pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
	{
		MessageBox(Window_Handle, (char*)"Error", (char*)"Device Format �ݒ莸�s", MB_OK);
		return false;
	}

	// CooperativeLevel Setting
	hr = g_pKeyDevice->SetCooperativeLevel(Window_Handle, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr))
	{
		MessageBox(Window_Handle, (char*)"Error", (char*)"CooperativeLevel �ݒ莸�s", MB_OK);
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
			// �Q�[���w���v�ֈڂ�
		}

		if (KeyState[DIK_SPACE] & 0x80) // SPACE Key
		{
			g_InputState.now |= SPACE;
			// �Q�[���{�҂ֈڂ�
		}

		if (KeyState[DIK_ESCAPE] & 0x80) // ESC Key
		{
			// �Q�[���^�C�g���֖߂�
			g_InputState.now |= ESCAPE;
		}

		g_InputState.pushed = (g_InputState.now & (~old)); // Push Info Get
		g_InputState.npushed = (~g_InputState.now) & old; // NonPush Info Get
	}
	else if (hr == DIERR_INPUTLOST) {
		g_pKeyDevice->Acquire();
	}
}

// �v���[���[�ړ�
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

	// ���E
	if (GetKey(LEFT) == true)
	{
		player->x -= player->speed;
	}

	else if (GetKey(RIGHT) == true)
	{
		player->x += player->speed;
	}

}


// �����蔻��
bool Collision(Object* enemy, Object* player)
{
	// �G�L�����ƃv���C���[�L�����̓����蔻��
	float a = player->x - enemy->x;		// X���W�̎Z�o
	float b = player->y - enemy->y;		// Y���W�̎Z�o
	float c = sqrt(a * a + b * b);			// ��̉~�̋����̎Z�o

	if (c <= player->circle_radius + enemy->circle_radius)
	{
		/*
		�������Ă�
		�v���C���[���S
		*/
		return true;
	}
	else
	{
		/*
		�������ĂȂ�
		�Q�[�����s
		*/
		return false;
	}

}

void CollisionWallP(Object* enemy, Object* player)
{
	// �v���C���[�L�����ƕǂ̓����蔻��

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
	wall->rect_x; //�}�b�v�`�b�v��'��'��X���W
	float rectW_y; //�}�b�v�`�b�v��'��'��Y���W
	float rectW_wid = 64.0f;
	float rectW_hgt = 64.0f;
	

	if (player->rect_x + player->rect_wid >= rectW_x && rectP_x <= rectW_x + rectW_wid &&
		rectP_y + rectP_hgt >= rectW_y && rectP_y <= rectW_y + rectW_hgt)
	{

		// �������Ă�

	}

	else
	{

		// �������ĂȂ�

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