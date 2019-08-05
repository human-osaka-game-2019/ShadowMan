#include "Graphics.h"
#include "Texture.h"
#include"GameScene.h"
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Object/EnemyAi.h"


// �Q�[���{�҃V�[���̏�����
void InitGameScene();
// �Q�[���{�҃V�[���̃��C������
void MainGameScene();
// �Q�[���{�҃V�[���̏I��
SceneId FinishGameScene();

//DrawObject player;  // �v���C���[�\���̂̎���

//DrawObject enemy;   // �G �\���̂̎���

//Movement valueP;     // player �ړ����l�̍\���̂̎���

//Movement valueE;	 // Enemy  �ړ����l�̍\���̂̎���

//Relativity status;  // ���ΓI���l�̍\���̂̎���

// �v���C���[�L�����N�^�̑���
void PlayerControl();

static CONST INT MapSizeWidth = 20;
static CONST INT MapSizeHeight = 15;
static CONST INT MapChipWidth = 64;
static CONST INT MapChipHeight = 64;
static INT MapChipList[MapSizeHeight][MapSizeWidth];

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
	INT width_num = GetTexture(TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture)->Width / MapChipWidth;
	INT height_num = GetTexture(TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture)->Height / MapChipHeight;

	for (INT i = 0; i < MapSizeHeight; i++)
	{
		for (INT j = 0; j < MapSizeWidth; j++)
		{
			INT chip_id = MapChipList[i][j];

			if (chip_id == 0)
			{
				continue;
			}

			//�ǂ��ɓ\��t���邩

			FLOAT chip_pos_x = (FLOAT)(chip_id % width_num) * MapChipWidth;
			FLOAT chip_pos_y = (FLOAT)(chip_id / width_num) * MapChipHeight;
			//����\��t��������
			DrawMapChip(
				D3DXVECTOR2(MapChipWidth * j, MapChipHeight * i),
				D3DXVECTOR2(chip_pos_x, chip_pos_y),
				D3DXVECTOR2(MapChipWidth, MapChipHeight),
				TextureCategoryGame,
				GameCategoryTextureList::GameBackGroundTexture
			);
		}
	}
}

void InitGameScene()
{
	// �e�N�X�`���ǂݍ���
	LoadTexture("Texture/maptile.png", TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture);

	MapLoading("MapChip.csv", MapChipList);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameScene()
{

	// �Q�[������

	//PlayerControl();

	//EnemyTypeChase();

	//Collision();

	//CollisionWallP();

	//ChangeSceneStep(SceneStep::EndStep);

}

void PlayerControl(DrawObject* player)
{

	if (GetKey(UP) == true)
	{
		player->m_PosY -= player->speed;
	}

	else if (GetKey(DOWN) == true)
	{
		player->m_PosY += player->speed;
	}

	// ���E
	if (GetKey(LEFT) == true)
	{
		player->m_PosX -= player->speed;
	}

	else if (GetKey(RIGHT) == true)
	{
		player->m_PosX += player->speed;
	}

}


	

SceneId FinishGameScene()
{
	// �����[�X�J��

	return SceneId::GameClearScene;
}