
// @file Input.h
// @brief ���͂Ɋւ���֐��A�萔�̐錾

#include <dinput.h>

#ifndef INPUT_H_
#define INPUT_H_

HRESULT DirectInputCreate(HINSTANCE hInst, DWORD DIRECTINPUT8, 
						  LPDIRECTINPUT8* lplpDirectInput, LPUNKNOWN punkOuter);
HRESULT CreateDevice(REFGUID GUID_SysKeyboard, 
					 LPDIRECTINPUTDEVICE* lplpDIDev, LPUNKNOWN UnkOuter);
HRESULT SetCooperativeLevel(HWND hWnd, DWORD dwFlags);
HRESULT SetDataFormat(LPDIDATAFORMAT c_dfDIKeyboard);
HRESULT Acquire();
HRESULT GetKeyState(WORD [256], LPVOID lpvData);

BYTE KeyState[256];

// @brief �L�[�̎��
enum KeyState
{
	Up,    //!<��
	Left,  //!<��
	Right, //!<�E
	Down,  //!<��
	H,	   //!< H �L�[
	Space, //!< Space �L�[
};

/* 
	@brief Input�@�\�������֐�@n
	�f�o�C�X�̓��͎擾�ɕK�v�ȏ��������s��
	InitEngine�Ŏ��s�����̂ŊJ���������s����K�v�͂Ȃ�
	@return ����������(������true)
*/
bool InitInput();

/*
	@brief Input�@�\�I���֐�@n
	Input�@�\���I��������@n
	EndEngine�Ŏ��s�����̂ŊJ���������s����K�v�͂Ȃ�
*/
void EndInput();

/*
	@brief ���͏��̍X�V@n
	�f�o�C�X�̓��͏��̍X�V���s��@n
	���t���[���ɂP�x�K�����s����K�v������
*/
void UpdateKeyState();

/*
	@brief ���͂��ꂽ�u�Ԕ���֐�@n
	�w�肵���L�[�{�[�h�̃L�[�����͂��ꂽ�u�Ԃ��ǂ����𔻒肷��
	@return ���茋��(�����ꂽ�u�ԂȂ�true)
	@param[in] button_type ���肵�����L�[�̎��
*/



bool GetKeyState();


#endif