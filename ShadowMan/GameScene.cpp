#include "Graphics.h"
#include "Texture.h"
#include"GameScene.h"
<<<<<<< HEAD
#include "Input.h"
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
>>>>>>> 9558851511c6e66ffde9bc2599f7cf33fbcd62cd

// �Q�[���{�҃V�[���̏�����
void InitGameScene();
// �Q�[���{�҃V�[���̃��C������
void MainGameScene();
// �Q�[���{�҃V�[���̏I��
SceneId FinishGameScene();

static CONST INT MapSizeWidth = 20;
static CONST INT MapSizeHeight = 10;
static CONST INT MapChipWidth = 64;
static CONST INT MapChipHeight = 64;

static SceneId NextSceneId;

SceneId UpdateGameScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitGameScene();
		break;
	case SceneStep::MainStep:
		MainGameScene();
		break;
	case SceneStep::EndStep:
		return FinishGameScene();
		break;
	}

	return SceneId::GameScene;
}

void DrawGameScene()
{
	// �`�揈��
	INT MapChipList[MapSizeHeight][MapSizeWidth];

	MapLoading("Map.csv", MapChipList);

	for (INT i = 0; i < MapSizeHeight; i++)
	{
		for (INT j = 0; j < MapSizeWidth; j++)
		{
			INT chip_id = MapChipList[i][j];

			if (chip_id == 0)
			{
				continue;
			}

			INT width_num = GetTexture(TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture)->Width / MapChipWidth;
			INT height_num = GetTexture(TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture)->Height / MapChipHeight;

			FLOAT chip_pos_x = (FLOAT)(chip_id % width_num) * MapChipWidth;
			FLOAT chip_pos_y = (FLOAT)(chip_id / height_num) * MapChipHeight;

			DrawMapChip(
				D3DXVECTOR2(MapChipWidth * j, MapChipHeight * i),
				D3DXVECTOR2(chip_pos_x, chip_pos_y),
				D3DXVECTOR2(MapChipWidth, MapChipHeight)
			);
		}
	}
}

void InitGameScene()
{
	// �e�N�X�`���ǂݍ���
	LoadTexture("TEST.png", TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameScene()
{
	// �Q�[������
	void PlayerMovement(DrawObject * Player)
	{
		float speed = x.xf;  //�@�X�s�[�h x�ɂ͒l������ׂ�
		float vec_x = x.xf;  //  x����	 x�ɂ͒l������ׂ�
		float vec_y = x.xf;  //  y����	 x�ɂ͒l������ׂ�
		float length = x.xf; //  ����	 x�ɂ͒l������ׂ�


		if (vec_x != 0.0f || vec_y != 0.0f)
		{
			// �x�N�g���̋������o��
			length = sqrt(vec_x * vec_x + vec_y * vec_y);

			float normal_x = vec_x / length;
			float normal_y = vec_y / length;

			float normal_length = sqrt(normal_x * normal_x + normal_y * normal_y);

			// �P�ʃx�N�g���Ɉړ��ʂ𔽉f����
			normal_x *= speed;
			normal_y *= speed;

			// �ړ��ʂ̏Ɩ��i���j
			float move_length = sqrt(normal_x * normal_x + normal_y * normal_y);

			// �ړ��ʂ����W�ɉ��Z
			*Player->m_PosX += normal_x; // �v���C���[�̈ړ�
			*Player->m_PosY += normal_y;

		}
	}

	void EnemyControl(DrawObject* enemy, DrawObject* player);
	{
		// �x�N�g�����o��
		float vecx = Player->m_PosX - Enemy->m_PosX;
		float vecy = Player->m_PosY - Enemy->m_PosY;

		// �x�N�g�������̂܂܍��W�ɑ���
		//enemy->m_PosX += vecx;
		//enemy->m_PosY += vecy;

		float length = sqrtf((vecx * vecx) + (vecy * vecy));
		float normal_x = vecx / length;
		float normal_y = vecy / length;

		Enemy->m_PosX += normal_x;
		Enemy->m_PosY += normal_y;
	}

	// �G�L�����̈ړ��p�^�[���@�i�v���C���[�ǐՌ^�j
	void EnemyMovement(DrawObject* Enemy, DrawObject* Player)
	{
		float vecx = Player->m_PosX - Enemy->m_PosX; // ���΋����������ăx�N�g�����o�� (�G �ǐՌ^)
		float vecy = Player->m_PosY - Enemy->m_PosY;

		float length = sqrtf((vecx * vecx) + (vecy * vecy));
		float normal_x = vecx / length;
		float normal_y = vecy / length;

		Enemy->m_PosX += normal_x; // �G�̈ړ�
		Enemy->m_PosY += normal_y;
	}

	//ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishGameScene()
{
	// �����[�X�J��

	return SceneId::GameClearScene;
}