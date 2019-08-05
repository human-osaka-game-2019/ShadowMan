#ifndef TEXTURE_H
#define TEXTURE_H

#include "SceneSwitcher.h"
#include "Graphics.h"

typedef enum
{
	TitleBackGroundTexture,		// title”wŒi
	TitelMenuGoGameTex,			// Game‘JˆÚ
	TitelMenuGoHlepTex,			// Help‘JˆÚ
	TitelFontTexture,			//u‘è–¼v”wŒi‚Æˆê‚É‚È‚Á‚Ä‚¢‚½ê‡íœ
	TitleTextureMax,
} TitleCategoryTextureList;

typedef enum
{
	HelpBackGroundTexture,		// Help”wŒi
	HelpTextureMax,
} HelpCategoryTextureList;

typedef enum
{
	GameBackGroundTexture,			// Game”wŒi
	IntegratedTexture,						// “‡‰æ‘œ
	GameTextureMax,
}GameCategoryTextureList;

typedef enum 
{
	GameClearBackGroundTexture,		//”wŒi
	GameClearFontTexture,			//uSpaceƒL[‚Åƒ^ƒCƒgƒ‹‚ÉvTex
	GameClearTextureMax,			
}GameClearCategoryTextureList;

typedef enum 
{
	GameOverBackGroundTexture,		//”wŒi
	GameOverFontTexture,			//uSpaceƒL[‚Åƒ^ƒCƒgƒ‹‚ÉvTex
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

