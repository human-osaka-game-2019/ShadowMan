#ifndef TEXTURE_H
#define TEXTURE_H

#include "SceneSwitcher.h"
#include "Graphics.h"

typedef enum
{
	TitleBackGroundTexture,		// îwåi
	Title
} TitleCategoryTextureList;

typedef enum
{
	HelpTitleBackGroundTexture,		// îwåi
	HelpTitleBackGroundTextureMax,
} HelpCategoryTextureList;


CONST INT TextureCategoryTitle = SceneId::TitleScene;
CONST INT TextureCategoryHelp = SceneId::HelpScene;
CONST INT TextureCategoryGame = SceneId::GameScene;
CONST INT TextureCategoryGameClear = SceneId::GameClearScene;
CONST INT TextureCategoryGameOver = SceneId::GameOverScene;
CONST INT TextureCategoryResult = SceneId::ResultScene;
CONST INT MaxTextureCategory = SceneId::SceneIdMax;


VOID ReleaseCategoryTexture(INT category_id);


void InitTexture();


void AllReleaseTexture();


bool IsCategoryRangeCheck(int category_id, int texture_id);


bool LoadTexture(const char* file_name, int category_id, int texture_id);


Texture* GetTexture(int category_id, int texture_id);

#endif

