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

	//�G�L�����ƃv���C���[�L�����̓����蔻��(�~�Ɖ~)
	float circle_pos_xE = enemy->m_PosX;  //�GX���W
	float circle_pos_yE = enemy->m_PosY;  //�GY���W
	float circle_radiusE = 32.0f;		  //�G�e�N�X�`���̉~�`�͈�

	float circle_pos_xP = player->m_PosX; //�v���C���[X���W
	float circle_pos_yP = player->m_PosY; //�v���C���[Y���W
	float circle_radiusP = 32.0f;		  //�v���C���[�e�N�X�`���̉~�`�͈�

	float a = circle_pos_xE - circle_pos_xP; // X���W�̎Z�o
	float b = circle_pos_yE - circle_pos_yP; // Y���W�̎Z�o
	float c = sqrt(a * a + b * b);			 // ��̉~�̋����̎Z�o

	if (c <= circle_radiusE + circle_radiusP)
	{
		/*
		�������Ă�
		�v���C���[���S
		*/
	}
	else
	{
		/*
		�������ĂȂ�
		�Q�[�����s
		*/
	}

	//�G�L�����ƕǂ̓����蔻��(��`�Ƌ�`)


}