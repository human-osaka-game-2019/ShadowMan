
// @file Input.h
// @brief ���͂Ɋւ���֐��A�萔�̐錾

#ifndef INPUT_H_
#define INPUT_H_

#include <dinput.h>
#include <Windows.h>
#include <math.h>


struct Object
{
	int m_TextureId;	// �e�N�X�`���̎��
	float x;		// �`����WX
	float y;		// �`����WY
	int mapchip_num_row;	// ���s��
	int mapchip_num_col;		// �����
	float speed; // �X�s�[�h
	float rect_wid;
	float rect_hgt;
	float circle_radius;
	int flame_count;
	int mode;
};

struct INPUTSTATE // �L�[�̏��̍\����
{
	DWORD now;
	DWORD pushed;
	DWORD npushed;
};

struct Relativity
{
	float Sr;			 // �v���C���[���W - �G���W = Sr (���΋���)
	float Vr;		     // �v���C���[�̈ړ���(Speed) - �G�̈ړ���(Speed) = Vr(���Α��x)
	float Tc;			 // Tc(�ڋߎ���) = |Sr| / |Vr|  ����ŁA�G���v���C���[�̍��W��\��
	float normal_x;		 //= vec_x / length;
	float normal_y;		 //= vec_y / length;
	float normal_length; //= sqrt(normal_x * normal_x + normal_y * normal_y);
	float move_length;   //= sqrt(normal_x * normal_x + normal_y * normal_y);
};

// �v���[���[�ړ�
void PlayerControl(Object* player);

// �����蔻��
bool Collision(Object* enemy, Object* player);

void CollisionWallP();

// @brief �L�[�̎��
enum KeyState
{
	CLEAR = 0x0000,		// Key Clear
	UP = 0x0002,		//!<��
	LEFT = 0x0004,		//!<��
	RIGHT = 0x0008,		//!<�E
	DOWN = 0x0010,		//!<��
	H = 0x0020,		//!< H �L�[
	SPACE = 0x0040,		//!< Space �L�[
	ESCAPE = 0x0080,		//!< Escape �L�[
};

bool InitDirectInput(HINSTANCE Instance_Handle, HWND Window_Handle);

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
