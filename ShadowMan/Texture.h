#ifndef TEXTURE_H
#define TEXTURE_H

#include "SceneSwitcher.h"
#include "Graphics.h"

typedef enum
{
	TitleBackGroundTexture,		// title背景
	TitelMenuGoGameTex,			// Game遷移
	TitelMenuGoHlepTex,			// Help遷移
	TitelFontTexture,			//「題名」背景と一緒になっていた場合削除
	TitleTextureMax,
} TitleCategoryTextureList;

typedef enum
{
	HelpBackGroundTexture,		// Help背景
	HelpTextureMax,
} HelpCategoryTextureList;

typedef enum
{
	GameBackGroundTexture,			// Game背景
	IntegratedTexture,						// 統合画像
	GameMaskTexture,				//ステンシル用マスクテクスチャ
	GameTextureMax,
}GameCategoryTextureList;

typedef enum 
{
	GameClearBackGroundTexture,		//背景
	GameClearFontTexture,			//「Spaceキーでタイトルに」Tex
	GameClearTextureMax,			
}GameClearCategoryTextureList;

typedef enum 
{
	GameOverBackGroundTexture,		//背景
	GameOverFontTexture,			//「Spaceキーでタイトルに」Tex
	GameOverTextureMax,				
}GameOverCategoryTextureList;


CONST INT TextureCategoryTitle = SceneId::TitleScene;
CONST INT TextureCategoryHelp = SceneId::HelpScene;
CONST INT TextureCategoryGame = SceneId::GameScene;
CONST INT TextureCategoryGameClear = SceneId::GameClearScene;
CONST INT TextureCategoryGameOver = SceneId::GameOverScene;
CONST INT MaxTextureCategory = SceneId::SceneIdMax;


VOID ReleaseCategoryTexture(INT category_id);


void InitTexture();


void AllReleaseTexture();


bool IsCategoryRangeCheck(int category_id, int texture_id);


bool LoadTexture(const char* file_name, int category_id, int texture_id);


Texture* GetTexture(int category_id, int texture_id);

#endif

