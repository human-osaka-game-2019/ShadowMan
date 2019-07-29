#include "Graphics.h"
#include "Texture.h"
#include"GameScene.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	FILE* fp = nullptr;

	fopen_s(&fp, "Map.csv", "r");

	INT MapChipList[MapSizeHeight][MapSizeWidth] = { 0 };

	if (fp != nullptr)
	{
		CHAR buffer[1024] = { 0 };
		CHAR utf_check[] = { 0xEF, 0xBB, 0xBF, 0 };

		CHAR* p = buffer;
		INT row = 0;
		INT col = 0;

		if (fgets(buffer, 4, fp) == nullptr)
		{
			return;
		}

		if (strstr(buffer, utf_check) == nullptr)
		{
			fseek(fp, 0, SEEK_SET);
		}

		while (fgets(buffer, 1024, fp))
		{
			CHAR* p = buffer;
			col = 0;

			while (TRUE)
			{
				MapChipList[row][col] = atoi(p);

				p = strchr(p, ',');

				if (p == nullptr)
				{
					break;
				}
				p++;
				col++;
			}
			row++;
		}

		fclose(fp);
	}


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
	//ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishGameScene()
{
	// リリース開放

	return SceneId::GameClearScene;
}