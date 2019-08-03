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


static CONST INT MapSizeWidth = 10;
static CONST INT MapSizeHeight = 5;
static CONST INT MapChipWidth = 128;
static CONST INT MapChipHeight = 128;

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

			//どこに貼り付けるか
			INT width_num = GetTexture(TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture)->Width / MapChipWidth;
			INT height_num = GetTexture(TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture)->Height / MapChipHeight;

			FLOAT chip_pos_x = (FLOAT)(chip_id % width_num) * MapChipWidth;
			FLOAT chip_pos_y = (FLOAT)(chip_id / height_num) * MapChipHeight;
			//何を貼り付けたいか
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
	// テクスチャ読み込み
	LoadTexture("Texture/統合画像.png", TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameScene()
{

	// ゲーム処理

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

	// 左右
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
		// ベクトルの距離を出す
		valueP->length = sqrt(valueP->vec_x * valueP->vec_x + valueP->vec_y * valueP->vec_y);

		status->normal_x = valueP->vec_x / valueP->length;
		status->normal_y = valueP->vec_y / valueP->length;

		status->normal_length = sqrt(status->normal_x * status->normal_x + status->normal_y * status->normal_y);

		// 単位ベクトルに移動量を反映する
		status->normal_x *= valueP->speed;
		status->normal_y *= valueP->speed;

		// 移動量の照明（式）
		status->move_length = sqrt(status->normal_x * status->normal_x + status->normal_y * status->normal_y);

		// 移動量を座標に加算
		player->m_PosX += status->normal_x; // プレイヤーの移動
		player->m_PosY += status->normal_y;

		// 敵キャラとプレイヤーキャラの当たり判定
		float circle_pos_xE = enemy->m_PosX;  //敵X座標
		float circle_pos_yE = enemy->m_PosY;  //敵Y座標
		float circle_radiusE = 32.0f;		  //敵テクスチャの円形範囲

		float circle_pos_xP = player->m_PosX; //プレイヤーX座標
		float circle_pos_yP = player->m_PosY; //プレイヤーY座標
		float circle_radiusP = 32.0f;		  //プレイヤーテクスチャの円形範囲

		float a = circle_pos_xP - circle_pos_xE; // X座標の算出
		float b = circle_pos_yP - circle_pos_yE; // Y座標の算出
		float c = sqrt(a * a + b * b);			 // 二つの円の距離の算出

		if (c <= circle_radiusP + circle_radiusE)
		{
			/*
			当たってる
			プレイヤー死亡
			*/
		}
		else
		{
			/*
			当たってない
			ゲーム続行
			*/
		}

	}

}

	


	

SceneId FinishGameScene()
{
	// リリース開放

	return SceneId::GameClearScene;
}