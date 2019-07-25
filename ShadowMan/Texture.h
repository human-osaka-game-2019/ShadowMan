#ifndef TEXTURE_H
#define TEXTURE_H

#include "SceneSwitcher.h"
#include "Graphics.h"

typedef enum
{
	TitleBackGroundTexture,		// title�w�i
	TitelMenuGoGameTex,			// Game�J��
	TitelMenuGoHlepTex,			// Help�J��
	TitelFontTexture,			//�u�薼�v�w�i�ƈꏏ�ɂȂ��Ă����ꍇ�폜
	TitleTextureMax,
} TitleCategoryTextureList;

typedef enum
{
	HelpTitleBackGroundTexture,		// Help�w�i
	HelpTitleTextureMax,
} HelpCategoryTextureList;

typedef enum
{
	GameBackGroundTexture,			//Game�w�i
	GameBlockTexture,				//�u���b�N
	GameLighTexture,				//��
	GameTrapTexture,				//�g���b�v
	GamePlayerTexture,				//��l��
	GameRemainingHP,				//�̗͎c�@
	GameTextureMax,
}GameCategoryTextureList;

typedef enum 
{
	GameClearBackGroundTexture,		//�w�i
	GameClearFontTexture,			//�uSpace�L�[�Ń^�C�g���ɁvTex
	GameClearTextureMax,			
}GameClearCategoryTextureList;

typedef enum 
{
	GameOverbackGroundTexture,		//�w�i
	GameOverFontTexture,			//�uSpace�L�[�Ń^�C�g���ɁvTex
	GameOverTextureMax,				
}GameOverCategoryTextureList;


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

