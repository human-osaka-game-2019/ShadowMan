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

// ゲーム本編シーンの初期化
void InitGameScene();
// ゲーム本編シーンのメイン処理
void MainGameScene();
// ゲーム本編シーンの終了
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
	// テクスチャ読み込み
	LoadTexture("TEST.png", TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameScene()
{
	// ゲーム処理
	void PlayerMovement(DrawObject * Player)
	{
		float speed = x.xf;  //　スピード xには値を入れるべき
		float vec_x = x.xf;  //  x成分	 xには値を入れるべき
		float vec_y = x.xf;  //  y成分	 xには値を入れるべき
		float length = x.xf; //  長さ	 xには値を入れるべき


		if (vec_x != 0.0f || vec_y != 0.0f)
		{
			// ベクトルの距離を出す
			length = sqrt(vec_x * vec_x + vec_y * vec_y);

			float normal_x = vec_x / length;
			float normal_y = vec_y / length;

			float normal_length = sqrt(normal_x * normal_x + normal_y * normal_y);

			// 単位ベクトルに移動量を反映する
			normal_x *= speed;
			normal_y *= speed;

			// 移動量の照明（式）
			float move_length = sqrt(normal_x * normal_x + normal_y * normal_y);

			// 移動量を座標に加算
			*Player->m_PosX += normal_x; // プレイヤーの移動
			*Player->m_PosY += normal_y;

		}
	}

	void EnemyControl(DrawObject* enemy, DrawObject* player);
	{
		// ベクトルを出す
		float vecx = Player->m_PosX - Enemy->m_PosX;
		float vecy = Player->m_PosY - Enemy->m_PosY;

		// ベクトルをそのまま座標に足す
		//enemy->m_PosX += vecx;
		//enemy->m_PosY += vecy;

		float length = sqrtf((vecx * vecx) + (vecy * vecy));
		float normal_x = vecx / length;
		float normal_y = vecy / length;

		Enemy->m_PosX += normal_x;
		Enemy->m_PosY += normal_y;
	}

	// 敵キャラの移動パターン　（プレイヤー追跡型）
	void EnemyMovement(DrawObject* Enemy, DrawObject* Player)
	{
		float vecx = Player->m_PosX - Enemy->m_PosX; // 相対距離を引いてベクトルを出す (敵 追跡型)
		float vecy = Player->m_PosY - Enemy->m_PosY;

		float length = sqrtf((vecx * vecx) + (vecy * vecy));
		float normal_x = vecx / length;
		float normal_y = vecy / length;

		Enemy->m_PosX += normal_x; // 敵の移動
		Enemy->m_PosY += normal_y;
	}

	//ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishGameScene()
{
	// リリース開放

	return SceneId::GameClearScene;
}