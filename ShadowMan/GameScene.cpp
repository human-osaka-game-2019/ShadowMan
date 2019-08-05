#include "Graphics.h"
#include "Texture.h"
#include"GameScene.h"
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// �Q�[���{�҃V�[���̏�����
void InitGameScene();
// �Q�[���{�҃V�[���̃��C������
void MainGameScene();
// �Q�[���{�҃V�[���̏I��
SceneId FinishGameScene();

//Object player;  // �v���C���[�\���̂̎���

//Object enemy;   // �G �\���̂̎���

//Movement valueP;     // player �ړ����l�̍\���̂̎���

//Movement valueE;	 // Enemy  �ړ����l�̍\���̂̎���

//Relativity status;  // ���ΓI���l�̍\���̂̎���

static Object BigEye;
static INT bigeye_id = 0;
static INT key_check = 0;
static INT move_count = 0;

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

	BigEye.flame_count += 1.0f;
	switch (bigeye_id)
	{
	case 0:
		DrawObject(&BigEye, 448.0f, 225.0f, MapChipWidth, MapChipHeight);
		if (BigEye.flame_count >= 60)
		{
			BigEye.flame_count = 0;
			bigeye_id = 1;
		}
		break;
	case 1:
		DrawObject(&BigEye, 512.0f, 225.0f, MapChipWidth, MapChipHeight);
		if (BigEye.flame_count >= 60)
		{
			BigEye.flame_count = 0;
			bigeye_id = 0;
		}
		break;
	}
}

void InitGameScene()
{
	// �e�N�X�`���ǂݍ���
	LoadTexture("Texture/maptile.png", TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture);
	LoadTexture("Texture/�����摜.png", TextureCategoryGame, GameCategoryTextureList::IntegratedTexture);

	MapLoading("csv/�^MapChip.csv", MapChipList);

	BigEye.x = 64.0f;
	BigEye.y = 64.0f;
	BigEye.mapchip_num_row = 1;
	BigEye.mapchip_num_col = 1;
	BigEye.speed = 2.0f;
	BigEye.flame_count = 0.0f;

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameScene()
{
	// �Q�[������
	if (key_check == 0)
	{
		if (GetKeyDown(UP) == true)
		{
			key_check = 1;
		}
		else if (GetKeyDown(DOWN) == true)
		{
			key_check = 2;
		}
		else if (GetKeyDown(LEFT) == true)
		{
			key_check = 3;
		}
		else if (GetKeyDown(RIGHT) == true)
		{
			key_check = 4;
		}
	}

	switch (key_check)
	{
	case 1:
		if (MapChipList[BigEye.mapchip_num_row - 1][BigEye.mapchip_num_col] == 1)
		{
			BigEye.y -= BigEye.speed;
			move_count += BigEye.speed;
			if (move_count >= MapChipHeight)
			{
				BigEye.mapchip_num_row--;
				move_count = 0;
				key_check = 0;
			}
		}
		else
		{
			key_check = 0;
		}
		break;
	case 2:
		if (MapChipList[BigEye.mapchip_num_row + 1][BigEye.mapchip_num_col] == 1)
		{
			BigEye.y += BigEye.speed;
			move_count += BigEye.speed;
			if (move_count >= MapChipHeight)
			{
				BigEye.mapchip_num_row++;
				move_count = 0;
				key_check = 0;
			}
		}
		else
		{
			key_check = 0;
		}
		break;
	case 3:
		if (MapChipList[BigEye.mapchip_num_row][BigEye.mapchip_num_col - 1] == 1)
		{
			BigEye.x -= BigEye.speed;
			move_count += BigEye.speed;
			if (move_count >= MapChipWidth)
			{
				BigEye.mapchip_num_col--;
				move_count = 0;
				key_check = 0;
			}
		}
		else
		{
			key_check = 0;
		}
		break;
	case 4:
		if (MapChipList[BigEye.mapchip_num_row][BigEye.mapchip_num_col + 1] == 1)
		{
			BigEye.x += BigEye.speed;
			move_count += BigEye.speed;
			if (move_count >= MapChipWidth)
			{
				BigEye.mapchip_num_col++;
				move_count = 0;
				key_check = 0;
			}
		}
		else
		{
			key_check = 0;
		}
		break;
	}

	//PlayerControl();

	//EnemyTypeChase();

	//Collision();

	//CollisionWallP();

	//ChangeSceneStep(SceneStep::EndStep);

}

SceneId FinishGameScene()
{
	// �����[�X�J��

	return SceneId::GameClearScene;
}