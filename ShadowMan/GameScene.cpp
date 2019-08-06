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

static Object Light;
static Object ShadowMan;
static INT light_id = 0;
static INT shineman_id = 0;
static INT shadow_man_id = 0;
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

	// 光の描画
	if (Light.live_flag == true)
	{
		Light.flame_count += 1.0f;
		switch (light_id)
		{
		case 0:
			DrawObject(Light.x, Light.y, 576.0f, 225.0f, MapChipWidth, MapChipHeight);
			ChengeTextureId(&ShadowMan, &light_id, 30);
			break;
		case 1:
			DrawObject(Light.x, Light.y, 640.0f, 225.0f, MapChipWidth, MapChipHeight);
			ChengeTextureId(&ShadowMan, &light_id, 30);
			break;
		case 2:
			DrawObject(Light.x, Light.y, 704.0f, 225.0f, MapChipWidth, MapChipHeight);
			ChengeTextureId(&ShadowMan, &light_id, 30);
			break;
		case 3:
			DrawObject(Light.x, Light.y, 768.0f, 225.0f, MapChipWidth, MapChipHeight);
			if (Light.flame_count >= 30)
			{
				Light.flame_count = 0;
				light_id = 0;
			}
			break;
		}
	}

	// シャドウマンの描画
	if (ShadowMan.live_flag == true)
	{
		ShadowMan.flame_count += 1.0f;
		switch (shadow_man_id)
		{
		case 0:
			DrawObject(ShadowMan.x, ShadowMan.y, 0.0f, 225.0f, MapChipWidth, MapChipHeight);
			ChengeTextureId(&ShadowMan, &shadow_man_id, 30);
			break;
		case 1:
			DrawObject(ShadowMan.x, ShadowMan.y, 64.0f, 225.0f, MapChipWidth, MapChipHeight);
			if (ShadowMan.flame_count >= 30)
			{
				ShadowMan.flame_count = 0;
				shadow_man_id = 0;
			}
			break;
		}
	}

	// 光っているシャドウマンの描画
	if (ShadowMan.live_flag == false)
	{
		ShadowMan.flame_count += 1.0f;
		switch (shineman_id)
		{
		case 0:
			DrawObject(ShadowMan.x - 32, ShadowMan.y  - 32, 384.0f, 360.0f, 128, 128);
			ChengeTextureId(&ShadowMan, &shineman_id, 30);
			break;
		case 1:
			DrawObject(ShadowMan.x - 32, ShadowMan.y - 32, 896.0f, 360.0f, 128, 128);
			ChengeTextureId(&ShadowMan, &shineman_id, 30);
			break;
		case 2:
			DrawObject(ShadowMan.x - 32, ShadowMan.y - 32, 256.0f, 360.0f, 128, 128);
			ChengeTextureId(&ShadowMan, &shineman_id, 30);
			break;
		case 3:
			DrawObject(ShadowMan.x - 32, ShadowMan.y - 32, 768.0f, 360.0f, 128, 128);
			ChengeTextureId(&ShadowMan, &shineman_id, 30);
			break;
		case 4:
			DrawObject(ShadowMan.x - 32, ShadowMan.y - 32, 128.0f, 360.0f, 128, 128);
			ChengeTextureId(&ShadowMan, &shineman_id, 30);
			break;
		case 5:
			DrawObject(ShadowMan.x - 32, ShadowMan.y - 32, 640.0f, 360.0f, 128, 128);
			ChengeTextureId(&ShadowMan, &shineman_id, 30);
			break;
		case 6:
			DrawObject(ShadowMan.x - 32, ShadowMan.y - 32, 0.0f, 360.0f, 128, 128);
			ChengeTextureId(&ShadowMan, &shineman_id, 30);
			break;
		case 7:
			DrawObject(ShadowMan.x - 32, ShadowMan.y - 32, 512.0f, 360.0f, 128, 128);
			if (ShadowMan.flame_count >= 30)
			{
				ShadowMan.flame_count = 0;
				shineman_id = 0;
			}
			break;
		}
	}
}

void InitGameScene()
{
	// テクスチャ読み込み
	LoadTexture("Texture/maptile.png", TextureCategoryGame, GameCategoryTextureList::GameBackGroundTexture);
	LoadTexture("Texture/統合画像.png", TextureCategoryGame, GameCategoryTextureList::IntegratedTexture);

	MapLoading("csv/New_MapChip.csv", MapChipList);

	Light.x = 128.0f;
	Light.y = 64.0f;
	Light.circle_radius = 8.0f;
	Light.flame_count = 0.0f;
	Light.live_flag = true;

	ShadowMan.x = 64.0f;
	ShadowMan.y = 64.0f;
	ShadowMan.mapchip_num_row = 1;
	ShadowMan.mapchip_num_col = 1;
	ShadowMan.speed = 2.0f;
	ShadowMan.circle_radius = 16.0f;
	ShadowMan.flame_count = 0.0f;
	ShadowMan.live_flag = true;

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameScene()
{
	// ゲーム処理
	if (key_check == 0)
	{
		if (GetKey(UP) == true)
		{
			key_check = 1;
		}
		else if (GetKey(DOWN) == true)
		{
			key_check = 2;
		}
		else if (GetKey(LEFT) == true)
		{
			key_check = 3;
		}
		else if (GetKey(RIGHT) == true)
		{
			key_check = 4;
		}
	}

	switch (key_check)
	{
	case 1:
		if (MapChipList[ShadowMan.mapchip_num_row - 1][ShadowMan.mapchip_num_col] == 1)
		{
			ShadowMan.y -= ShadowMan.speed;
			move_count += ShadowMan.speed;
			if (move_count >= MapChipHeight)
			{
				ShadowMan.mapchip_num_row--;
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
		if (MapChipList[ShadowMan.mapchip_num_row + 1][ShadowMan.mapchip_num_col] == 1)
		{
			ShadowMan.y += ShadowMan.speed;
			move_count += ShadowMan.speed;
			if (move_count >= MapChipHeight)
			{
				ShadowMan.mapchip_num_row++;
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
		if (MapChipList[ShadowMan.mapchip_num_row][ShadowMan.mapchip_num_col - 1] == 1)
		{
			ShadowMan.x -= ShadowMan.speed;
			move_count += ShadowMan.speed;
			if (move_count >= MapChipWidth)
			{
				ShadowMan.mapchip_num_col--;
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
		if (MapChipList[ShadowMan.mapchip_num_row][ShadowMan.mapchip_num_col + 1] == 1)
		{
			ShadowMan.x += ShadowMan.speed;
			move_count += ShadowMan.speed;
			if (move_count >= MapChipWidth)
			{
				ShadowMan.mapchip_num_col++;
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

	if (Collision(&Light, &ShadowMan) == true)
	{
		Light.live_flag = false;
		ShadowMan.live_flag = false;
	}
}

SceneId FinishGameScene()
{
	// リリース開放

	return SceneId::GameClearScene;
}