#include "Input.h"
#include "Object/EnemyAi.h"


// �G�L�����̈ړ��p�^�[���@�i�v���C���[�ǐՌ^�j
void EnemyTypeChase(DrawObject* enemy, DrawObject* player, Movement* valueE, Relativity* status)
{

	// �x�N�g�����o��
	valueE->vec_x = player->m_PosX - enemy->m_PosX; // ���΋����������ăx�N�g�����o�� (�G �ǐՌ^)
	valueE->vec_y = player->m_PosY - enemy->m_PosY;

	// �x�N�g�������̂܂܍��W�ɑ���
	//enemy->m_PosX += vecx;
	//enemy->m_PosY += vecy;

	valueE->length = sqrtf((valueE->vec_x * valueE->vec_x) + (valueE->vec_y * valueE->vec_y));
	status->normal_x = valueE->vec_x / valueE->length;
	status->normal_y = valueE->vec_y / valueE->length;

	enemy->m_PosX += status->normal_x; // �G�̈ړ�
	enemy->m_PosY += status->normal_y;

}