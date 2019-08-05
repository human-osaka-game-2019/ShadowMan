#include "Graphics.h"
#include "Texture.h"
#include"GameScene.h"
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
static DWORD SyncPrev, SyncCurr;

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

	SyncCurr = timeGetTime();
	if (SyncCurr - SyncPrev >= 0)
	{
		DrawMapChip(
			D3DXVECTOR2(MapChipWidth * 1, MapChipHeight * 1),
			D3DXVECTOR2(448.0f, 225.0f),
			D3DXVECTOR2(MapChipWidth, MapChipWidth),
			TextureCategoryGame,
			GameCategoryTextureList::IntegratedTexture
		);
		if (SyncCurr - SyncPrev >= 500)
		{
			DrawMapChip(
				D3DXVECTOR2(MapChipWidth * 1, MapChipHeight * 1),
				D3DXVECTOR2(512.0f, 225.0f),
				D3DXVECTOR2(MapChipWidth, MapChipWidth),
				TextureCategoryGame,
				GameCategoryTextureList::IntegratedTexture
			);
			if (SyncCurr - SyncPrev >= 1000)
			{
				SyncPrev = SyncCurr;
			}
		}
	}
}

void InitGameScene()
{
	// テクスチャ読み込み
	LoadTexture("Texture/maptile.png", TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture);
	LoadTexture("Texture/統合画像.png", TextureCategoryGame, GameCategoryTextureList::IntegratedTexture);

	MapLoading("csv/真MapChip.csv", MapChipList);

	SyncPrev = timeGetTime();

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

SceneId FinishGameScene()
{
	// リリース開放

	return SceneId::GameClearScene;
}