#include "GameOverScene.h"
#include "Texture.h"
#include"Input.h"
#include <SoundsManager.h>

// ゲームオーバーシーンの初期化
void InitGameOverScene();
// ゲームオーバーシーンのメイン
void MainGameOverScene();
// ゲームオーバーシーンの終了
SceneId FinishGameOverScene();

SceneId UpdateGameOverScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitGameOverScene();
		break;
	case SceneStep::MainStep:
		MainGameOverScene();
		break;
	case SceneStep::EndStep:
		return FinishGameOverScene();
		break;
	}

	return SceneId::GameOverScene;
}

void DrawGameOverScene()
{
	// 描画処理
	DrawTexture(0.0f, 0.0f, GetTexture(TextureCategoryGameOver, GameOverBackGroundTexture));
}

void InitGameOverScene()
{
	// テクスチャ読み込み
	LoadTexture("Texture/ゲームオーバー.png", TextureCategoryGameOver, GameOverCategoryTextureList::GameOverBackGroundTexture);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameOverScene()
{
	// ゲーム処理
	if (GetKeyDown(ESCAPE) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishGameOverScene()
{
	// リリース開放
	ReleaseCategoryTexture(SceneId::GameOverScene);

	return SceneId::TitleScene;
}