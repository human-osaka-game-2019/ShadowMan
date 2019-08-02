#include "AI.h"
#include "Input.h"



//struct DrawObject player;
//struct DrawObject enemy;

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

// �G�L�����̈ړ��p�^�[���@�i��ǂ݌^�j
void EnemyTypePredict(DrawObject* enemy, DrawObject* player, Movement* valueE, Movement* valueP, Relativity* status)
{
	// �v���C���[�̈ړ���(Speed) - �G�̈ړ���(Speed)�@= Vr (���Α��x)
	// �v���C���[���W - �G���W = Sr (���΋���)
	// Tc(�ڋߎ���) = |Sr| / |Vr|  ����ŁA�G���v���C���[�̍��W��\��
	// �v���C���[���W + �v���C���[�ړ��x�N�g�� * Tc �Œǌ��|�C���g�l��

	status->Vr = valueP->speed - valueE->speed;

	// ���΋����@�i�G�A�v���C���[�Ԃ̋����Z�o�j
	status->Sr = sqrt(pow(enemy->m_PosX - player->m_PosX, 2) + pow(enemy->m_PosY - player->m_PosY, 2));
	// Tc(�ڋߎ���) = | Sr| / |Vr |
	status->Tc = fabsf(status->Sr) / fabsf(status->Vr);

	enemy->m_PosX = (player->m_PosX + valueP->vec_x) * status->Tc; // �ǌ��|�C���g�� X���W
	enemy->m_PosY = (player->m_PosY + valueP->vec_y) * status->Tc; // �ǌ��|�C���g�� Y���W
}


void EnemyTypeFlee()
{

}

void EnemyTypePatrol()
{

}