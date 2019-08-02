#include "Graphics.h"
#include "Texture.h"
#include"GameScene.h"
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "AI.h"


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

			//�ǂ��ɓ\��t���邩
			INT width_num = GetTexture(TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture)->Width / MapChipWidth;
			INT height_num = GetTexture(TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture)->Height / MapChipHeight;

			FLOAT chip_pos_x = (FLOAT)(chip_id % width_num) * MapChipWidth;
			FLOAT chip_pos_y = (FLOAT)(chip_id / height_num) * MapChipHeight;
			//����\��t��������
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

	PlayerControl();

	EnemyTypeChase();

	EnemyTypePredict();

	//ChangeSceneStep(SceneStep::EndStep);

}

void PlayerControl(DrawObject* player, Movement* valueP, Relativity* status)
{

	if (GetKey(DIK_UP) == true)
	{
		valueP->vec_y =- valueP->speed;
	}

	else if (GetKey(DIK_DOWN) == true)
	{
		valueP->vec_y = valueP->speed;
	}

	// ���E
	if (GetKey(DIK_LEFT) == true)
	{
		valueP->vec_x =- valueP->speed;
	}

	else if (GetKey(DIK_RIGHT) == true)
	{
		valueP->vec_x = valueP->speed;
	}

	if (valueP->vec_x != 0.0f || valueP->vec_y != 0.0f)
	{
		// �x�N�g���̋������o��
		valueP->length = sqrt(valueP->vec_x * valueP->vec_x + valueP->vec_y * valueP->vec_y);

		status->normal_x = valueP->vec_x / valueP->length;
		status->normal_y = valueP->vec_y / valueP->length;

		status->normal_length = sqrt(status->normal_x * status->normal_x + status->normal_y * status->normal_y);

		// �P�ʃx�N�g���Ɉړ��ʂ𔽉f����
		status->normal_x *= valueP->speed;
		status->normal_y *= valueP->speed;

		// �ړ��ʂ̏Ɩ��i���j
		status->move_length = sqrt(status->normal_x * status->normal_x + status->normal_y * status->normal_y);

		// �ړ��ʂ����W�ɉ��Z
		player->m_PosX += status->normal_x; // �v���C���[�̈ړ�
		player->m_PosY += status->normal_y;

	}

}

	


	

SceneId FinishGameScene()
{
	// �����[�X�J��

	return SceneId::GameClearScene;
}