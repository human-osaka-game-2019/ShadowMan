#include <math.h>
#include "input.h"

void EnemyTypeChase();  // �ǐՌ^�̓G


void EnemyTypePredict();// ��ǂ݌^�̓G

	// �v���C���[�̈ړ���(Speed) - �G�̈ړ���(Speed)�@= Vr (���Α��x)
	// �v���C���[���W - �G���W = Sr (���΋���)
	// Tc(�ڋߎ���) = |Sr| / |Vr|  ����ŁA�G���v���C���[�̍��W��\��


void EnemyTypeFlee(); // �����^�̓G
/*

 �v���C���[�̍��W + �G���W�@= �Ƃ�����W�_

 ||�Ƃ�����W|| * �ړ���

*/

void EnemyTypePatrol(); // ����^�̓G
/*



*/