
// @file Input.h
// @brief ���͂Ɋւ���֐��A�萔�̐錾

#ifndef INPUT_H_
#define INPUT_H_

#include <dinput.h>
#include <Windows.h>
#include <math.h>


struct DrawObject
{
	int m_TextureId;	// �e�N�X�`���̎��
	float m_PosX;		// �`����WX
	float m_PosY;		// �`����WY
};

struct INPUTSTATE // �L�[�̏��̍\����
{
	DWORD now;
	DWORD pushed;
	DWORD npushed;
};

struct Movement
{
	float speed = 5.0f;  //�@�X�s�[�h (�ړ���)  x�ɂ͒l������ׂ�
	float vec_x = 1.0f;  //  x���� (X���W�z)   x�ɂ͒l������ׂ�
	float vec_y = 1.0f;  //  y���� (Y���W�z)	  x�ɂ͒l������ׂ�
	float length = 5.0f; //  ���� (�ړ������j	  x�ɂ͒l������ׂ�
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
	//Save Key Info

bool GetKey(DWORD key_code);


bool GetKeyDown(DWORD key_code);


bool GetKeyUp(DWORD key_code);


#endif
