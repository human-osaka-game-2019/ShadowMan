#include "Input.h"
#include "EnemyChase.h"


// �G�L�����̈ړ��p�^�[���@�i�v���C���[�ǐՌ^�j
void EnemyTypeChase(Object* enemy, Object* player, Relativity* status)
{

	// �x�N�g�����o��
	status->normal_x = player->x - enemy->x; // ���΋����������ăx�N�g�����o�� (�G �ǐՌ^)
	status->normal_y = player->y - enemy->y;

	// �x�N�g�������̂܂܍��W�ɑ���
	//enemy->m_PosX += vecx;
	//enemy->m_PosY += vecy;

	enemy->speed = sqrtf((enemy->x * enemy->x) + (enemy->y * enemy->y));
	status->normal_x = enemy->x / status->normal_length;
	status->normal_y = enemy->y / status->normal_length;

	enemy->x += status->normal_x; // �G�̈ړ�
	enemy->y += status->normal_y;


}

<<<<<<< HEAD
//void Collision()
//{

	/*

	�G�ƃv���C���[�̓����蔻��

	*/

//}
=======
void Collision();
>>>>>>> 99b2d0360059fba9b128cd7d750d95ae7ddce8e9
