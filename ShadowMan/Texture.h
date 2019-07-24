#ifndef TEXTURE_H
#define TEXTURE_H

#include"SceneSwitcher.h"

CONST INT TextureCategoryTitle = SceneId::TitleScene;
CONST INT TextureCategoryHelp = SceneId::HelpScene;
CONST INT TextureCategoryGame = SceneId::GameScene;
CONST INT TextureCategoryGameClear = SceneId::GameClearScene;
CONST INT TextureCategoryGameOver = SceneId::GameOverScene;
CONST INT TextureCategoryResult = SceneId::ResultScene;
CONST INT MaxTextureCategory = SceneId::SceneIdMax;


void ReleaseCategoryTexture(int category_id);

#endif
