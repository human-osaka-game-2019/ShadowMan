
// @file Input.h
// @brief ���͂Ɋւ���֐��A�萔�̐錾

#ifndef INPUT_H_
#define INPUT_H_

#include <dinput.h>
#include <Windows.h>

// �v���C���[���
struct Player
{
	int ShadowMan;
	float m_PosX;
	float m_PosY;
};

// �v���C���[���
struct Enemy
{
	int EnemyOne;
	float m_PosX;
	float m_PosY;
};

struct INPUTSTATE // �L�[�̏��̍\����
{
	DWORD now;
	DWORD pushed;
	DWORD npushed;
};


// @brief �L�[�̎��
enum KeyState
{
	CLEAR, // Key Clear
	UP,    //!<��
	LEFT,  //!<��
	RIGHT, //!<�E
	DOWN,  //!<��
	H,	   //!< H �L�[
	SPACE, //!< Space �L�[
};

bool InitDirectInput(HINSTANCE Instance_Handle, HWND Window_Handle);

/*
	DirectInput�̉��
		�߂�l�F
			�Ȃ�

		�����F
			�Ȃ�

		���e�F
			DirectInput���������
*/
void ReleaseDirectInput();

/*
	�L�[���̍X�V
		�߂�l�F
			�Ȃ�

		�����F
			�Ȃ�

		���e�F
			�L�[�̏����X�V����GetKey�V���[�Y�̊֐��̎擾�����ŐV�ɂ���
			���̏����͖��t���[���̊J�n���ɌĂяo������
*/
void KeyUpDate();

/*
	�L�[�������Ă邩�𔻒�
		�߂�l�F
			������Ă� => true
			������ĂȂ� => false

		�����F
			DWORD key_code
				���f�������L�[�R�[�h

		���e
			�L�[��������Ă���Ȃ�true�A������Ă��Ȃ��Ȃ�false��Ԃ�
*/
bool GetKey(DWORD key_code);

/*
	�L�[���������u�Ԃ𔻒�
		�߂�l�F
			�������u�� => true
			�������u�Ԃ���Ȃ� => false

		�����F
			DWORD key_code
				���f�������L�[�R�[�h

		���e
			�L�[�������ꂽ�u�ԂȂ�true�A������ĂȂ��u�ԂȂ�false
*/
bool GetKeyDown(DWORD key_code);

/*
	�L�[�𗣂����u�Ԃ𔻒�
		�߂�l�F
			�������u�� => true
			�������u�Ԃ���Ȃ� => false

		�����F
			DWORD key_code
				���f�������L�[�R�[�h

		���e
			�L�[���������u�ԂȂ�true�A�������u�Ԃ���Ȃ��Ȃ�false
*/
bool GetKeyUp(DWORD key_code);

#endif
