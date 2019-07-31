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


// プレイヤー構造体の実体
DrawObject player;
// 敵 構造体の実体
DrawObject enemy;
// 移動数値の構造体の実体
Movement value;
// プレイヤーキャラクタの操作
void PlayerControl(DrawObject* player, Movement* value);
// 敵 キャラクタの操作
void EnemyControl(DrawObject* player, DrawObject* Enemy, Movement* value);


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
	LoadTexture("TEST.png", TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameScene()
{

	// ゲーム処理

	PlayerControl(&player,&value);

	EnemyControl(&enemy,&player,&value);

	//ChangeSceneStep(SceneStep::EndStep);

}

void PlayerControl(DrawObject* player , Movement* value)
{

	if (GetKey(DIK_UP) == true)
	{
		value->vec_y =- value->speed;
	}

	else if (GetKey(DIK_DOWN) == true)
	{
		value->vec_y = value->speed;
	}

	// 左右
	if (GetKey(DIK_LEFT) == true)
	{
		value->vec_x =- value->speed;
	}

	else if (GetKey(DIK_RIGHT) == true)
	{
		value->vec_x = value->speed;
	}

	if (value->vec_x != 0.0f || value->vec_y != 0.0f)
	{
		// ベクトルの距離を出す
		value->length = sqrt(value->vec_x * value->vec_x + value->vec_y * value->vec_y);

		float normal_x = value->vec_x / value->length;
		float normal_y = value->vec_y / value->length;

		float normal_length = sqrt(normal_x * normal_x + normal_y * normal_y);

		// 単位ベクトルに移動量を反映する
		normal_x *= value->speed;
		normal_y *= value->speed;

		// 移動量の照明（式）
		float move_length = sqrt(normal_x * normal_x + normal_y * normal_y);

		// 移動量を座標に加算
		player->m_PosX += normal_x; // プレイヤーの移動
		player->m_PosY += normal_y;

	}

}

	// 敵キャラの移動パターン　（プレイヤー追跡型）
void EnemyControl(DrawObject* enemy, DrawObject* player, Movement* value)
{

	// ベクトルを出す
	value->vec_x = player->m_PosX - enemy->m_PosX; // 相対距離を引いてベクトルを出す (敵 追跡型)
	value->vec_y = player->m_PosY - enemy->m_PosY;

	// ベクトルをそのまま座標に足す
	//enemy->m_PosX += vecx;
	//enemy->m_PosY += vecy;

	value->length = sqrtf((value->vec_x * value->vec_x) + (value->vec_y * value->vec_y));
	float normal_x = value->vec_x / value->length;
	float normal_y = value->vec_y / value->length;

	enemy->m_PosX += normal_x; // 敵の移動
	enemy->m_PosY += normal_y;

}

	

SceneId FinishGameScene()
{
	// リリース開放

	return SceneId::GameClearScene;
}