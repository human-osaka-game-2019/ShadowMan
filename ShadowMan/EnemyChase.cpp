#include "Input.h"
#include "EnemyChase.h"


// �G�L�����̈ړ��p�^�[���@�i�v���C���[�ǐՌ^�j
void EnemyTypeChase(DrawObject* enemy, DrawObject* player, Relativity* status)
{

	// �x�N�g�����o��
	status->normal_x = player->m_PosX - enemy->m_PosX; // ���΋����������ăx�N�g�����o�� (�G �ǐՌ^)
	status->normal_y = player->m_PosY - enemy->m_PosY;

	// �x�N�g�������̂܂܍��W�ɑ���
	//enemy->m_PosX += vecx;
	//enemy->m_PosY += vecy;

	enemy->speed = sqrtf((enemy->m_PosX * enemy->m_PosX) + (enemy->m_PosY * enemy->m_PosY));
	status->normal_x = enemy->m_PosX / status->normal_length;
	status->normal_y = enemy->m_PosY / status->normal_length;

	enemy->m_PosX += status->normal_x; // �G�̈ړ�
	enemy->m_PosY += status->normal_y;


}

void Collision()
{

	/*

	�G�ƃv���C���[�̓����蔻��

	*/

}