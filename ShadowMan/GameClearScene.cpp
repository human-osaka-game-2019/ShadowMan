#include "GameClearScene.h"
#include "Texture.h"
#include"Input.h"
#include <SoundsManager.h>

// ゲームクリアシーンの初期化
void InitGameClearScene();
// ゲームクリアシーンのメイン処理
void MainGameClearScene();
// ゲームクリアシーンの終了
SceneId FinishGameClearScene();

SceneId UpdateGameClearScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitGameClearScene();
		break;
	case SceneStep::MainStep:
		MainGameClearScene();
		break;
	case SceneStep::EndStep:
		return FinishGameClearScene();
		break;
	}

	return SceneId::GameClearScene;
}

void DrawGameClearScene()
{
	// 描画処理
	DrawTexture(0.0f, 0.0f, GetTexture(TextureCategoryGameClear, GameClearBackGroundTexture));
}

void InitGameClearScene()
{
	// テクスチャ読み込み
	LoadTexture("Texture/ゲームクリア2.png", TextureCategoryGameClear, GameClearCategoryTextureList::GameClearBackGroundTexture);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameClearScene()
{
	// ゲーム処理
	if (GetKeyDown(ESCAPE) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishGameClearScene()
{
	// リリース開放
	ReleaseCategoryTexture(SceneId::GameClearScene);

	return SceneId::TitleScene;
}