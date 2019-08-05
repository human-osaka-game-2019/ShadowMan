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

// �����蔻��
void PlayerCollision();


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

	//EnemyTypePredict();

	//ChangeSceneStep(SceneStep::EndStep);

}

void PlayerControl(DrawObject* enemy, DrawObject* player, Movement* valueP, Relativity* status)
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

// �����蔻��
void PlayerCollision(DrawObject* enemy, DrawObject* player)
{
	// �G�L�����ƃv���C���[�L�����̓����蔻��
	float circle_pos_xE = enemy->m_PosX;  //�GX���W
	float circle_pos_yE = enemy->m_PosY;  //�GY���W
	float circle_radiusE = 32.0f;		  //�G�e�N�X�`���̉~�`�͈�

	float circle_pos_xP = player->m_PosX; //�v���C���[X���W
	float circle_pos_yP = player->m_PosY; //�v���C���[Y���W
	float circle_radiusP = 32.0f;		  //�v���C���[�e�N�X�`���̉~�`�͈�

	float a = circle_pos_xP - circle_pos_xE; // X���W�̎Z�o
	float b = circle_pos_yP - circle_pos_yE; // Y���W�̎Z�o
	float c = sqrt(a * a + b * b);			 // ��̉~�̋����̎Z�o

	if (c <= circle_radiusP + circle_radiusE)
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

	// �v���C���[�L�����ƕǂ̓����蔻��

	// Player
	float rectP_x = player->m_PosX;
	float rectP_y = player->m_PosY;
	float rectP_wid = 64.0f;
	float rectP_hgt = 64.0f;

	// Wall
	float rectW_x; //�}�b�v�`�b�v��'��'��X���W
	float rectW_y; //�}�b�v�`�b�v��'��'��Y���W
	float rectW_wid = 64.0f;
	float rectW_hgt = 64.0f;

	if (rectP_x + rectP_wid >= rectW_x && rectP_x <= rectW_x + rectW_wid &&
		rectP_y + rectP_hgt >= rectW_y && rectP_y <= rectW_y + rectW_hgt)
	{

		// �������Ă�

	}

	else
	{

		// �������ĂȂ�

	}

}
	

SceneId FinishGameScene()
{
	// �����[�X�J��

	return SceneId::GameClearScene;
}