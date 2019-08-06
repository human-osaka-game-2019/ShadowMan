#include "Input.h"
#include "WaitEnemy.h"
#include <time.h>

void WaitEnemy(INT MapChipList[][20], Object WaitEnemy, Object Player)
{
	srand(time(NULL));//�P�񂾂��Ăяo���΂�������ꏊ�ς���

	static int ramdom;

	ramdom = rand() % 4 + 1;

	switch (ramdom) //���͂P
	{
	case 1:
		if (MapChipList[WaitEnemy.mapchip_num_col++][WaitEnemy.mapchip_num_row] == 1
			||
			MapChipList[Player.mapchip_num_col][Player.mapchip_num_row])
		{
			MapChipList[WaitEnemy.mapchip_num_col++][WaitEnemy.mapchip_num_row];
			break;
		}

	case 2:
		if (MapChipList[WaitEnemy.mapchip_num_col--][WaitEnemy.mapchip_num_row] == 1
			||
			MapChipList[Player.mapchip_num_col][Player.mapchip_num_row])
		{
			MapChipList[WaitEnemy.mapchip_num_col--][WaitEnemy.mapchip_num_row];
			break;
		}
	case 3:
		if (MapChipList[WaitEnemy.mapchip_num_col][WaitEnemy.mapchip_num_row++] == 1
			||
			MapChipList[Player.mapchip_num_col][Player.mapchip_num_row])
		{
			MapChipList[WaitEnemy.mapchip_num_col][WaitEnemy.mapchip_num_row++];
			break;
		}

	case 4:
		if (MapChipList[WaitEnemy.mapchip_num_col][WaitEnemy.mapchip_num_row--] == 1
			||
			MapChipList[Player.mapchip_num_col][Player.mapchip_num_row])
		{
			MapChipList[WaitEnemy.mapchip_num_col][WaitEnemy.mapchip_num_row--];
			break;
		}
	default:
		break;
	}
	/*
	if (MapChipList[Player.mapchip_num_col][Player.mapchip_num_row]
		==
		MapChipList[WaitEnemy.mapchip_num_col][WaitEnemy.mapchip_num_row])
	{
		//�c�@���炷����
	}
	*/
}


/*
void EnemyTypeWait(Object* enemy, Object* player, Relativity* status)
{

	enemy->x;  //�GX���W
	enemy->y;  //�GY���W
	enemy->circle_radius = 192.0f;		  //�G�e�N�X�`���̉~�`�͈�(3�}�X��)

	player->x; //�v���C���[X���W
	player->y; //�v���C���[Y���W
	player->circle_radius = 192.0f;		  //�v���C���[�e�N�X�`���̉~�`�͈�(3�}�X��)

	float a = player->x - enemy->x; // X���W�̎Z�o
	float b = player->y - enemy->y; // Y���W�̎Z�o
	float c = sqrt(a * a + b * b);			 // ��̉~�̋����̎Z�o

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

	if (c <= player->circle_radius + enemy->circle_radius)
	{
		//�@�͈͂��������Ă�
		//�@Chase���[�h���̂܂�
		//  ���͂��̂܂�
	}

	else
	{
		//�@�͈͂��������ĂȂ�
		//�@�v���C���[�̍��W���X�V����邱�Ƃɂ���Ă��̍��W��ړI�_�Ƃ��Đݒ�
		//  ���͏���UP
		//  �ړ����A5~10�b�Ԃ��̂܂܂̏ꏊ�őҋ@ / sleep(5000)
	}

}

void Collision();
*/