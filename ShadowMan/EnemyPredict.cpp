#include "Input.h"
#include "Object/EnemyAi.h"


// �G�L�����̈ړ��p�^�[���@�i��ǂ݌^�j
void EnemyTypePredict(DrawObject* enemy, DrawObject* player, Relativity* status)
{
	// �v���C���[�̈ړ���(Speed) - �G�̈ړ���(Speed)�@= Vr (���Α��x)
	// �v���C���[���W - �G���W = Sr (���΋���)
	// Tc(�ڋߎ���) = |Sr| / |Vr|  ����ŁA�G���v���C���[�̍��W��\��
	// �v���C���[���W + �v���C���[�ړ��x�N�g�� * Tc �Œǌ��|�C���g�l��

	status->Vr = player->speed - enemy->speed;

	// ���΋����@�i�G�A�v���C���[�Ԃ̋����Z�o�j
	status->Sr = sqrt(pow(enemy->m_PosX - player->m_PosX, 2) + pow(enemy->m_PosY - player->m_PosY, 2));
	// Tc(�ڋߎ���) = | Sr| / |Vr |
	status->Tc = fabsf(status->Sr) / fabsf(status->Vr);

	enemy->m_PosX = (player->m_PosX + player->speed) * status->Tc; // �ǌ��|�C���g�� X���W
	enemy->m_PosY = (player->m_PosY + player->speed) * status->Tc; // �ǌ��|�C���g�� Y���W
}
