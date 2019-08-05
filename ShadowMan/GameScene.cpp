#include "Graphics.h"
#include "Texture.h"
#include"GameScene.h"
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Object/EnemyAi.h"


// ゲーム本編シーンの初期化
void InitGameScene();
// ゲーム本編シーンのメイン処理
void MainGameScene();
// ゲーム本編シーンの終了
SceneId FinishGameScene();

//DrawObject player;  // プレイヤー構造体の実体

//DrawObject enemy;   // 敵 構造体の実体

//Movement valueP;     // player 移動数値の構造体の実体

//Movement valueE;	 // Enemy  移動数値の構造体の実体

//Relativity status;  // 相対的数値の構造体の実体

// プレイヤーキャラクタの操作
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
	// 描画処理
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

			//どこに貼り付けるか

			FLOAT chip_pos_x = (FLOAT)(chip_id % width_num) * MapChipWidth;
			FLOAT chip_pos_y = (FLOAT)(chip_id / width_num) * MapChipHeight;
			//何を貼り付けたいか
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
	// テクスチャ読み込み
	LoadTexture("Texture/maptile.png", TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture);

	MapLoading("MapChip.csv", MapChipList);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameScene()
{

	// ゲーム処理

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

	// 左右
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
	// リリース開放

	return SceneId::GameClearScene;
}