#include "HelpScene.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"

// ヘルプシーンの初期化
void InitHelpScene();
// ヘルプシーンのメイン
void MainHelpScene();
// ヘルプシーンの終了
SceneId FinishHelpScene();

SceneId UpdateHelpScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitHelpScene();
		break;
	case SceneStep::MainStep:
		MainHelpScene();
		break;
	case SceneStep::EndStep:
		return FinishHelpScene();
		break;
	}

	return SceneId::HelpScene;
}

void DrawHelpScene()
{
	// 描画処理
	DrawTexture(0.0f, 0.0f, GetTexture(TextureCategoryHelp, HelpCategoryTextureList::HelpBackGroundTexture));
}

void InitHelpScene()
{
	// テクスチャ読み込み
	LoadTexture("Texture/asobikata.png", TextureCategoryHelp, HelpCategoryTextureList::HelpBackGroundTexture);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainHelpScene()
{
	// ゲーム処理
	if (GetKeyDown(ESCAPE) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishHelpScene()
{
	// リリース開放
	ReleaseCategoryTexture(SceneId::HelpScene);

	return SceneId::TitleScene;
}