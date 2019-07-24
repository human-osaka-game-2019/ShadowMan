#include "HelpScene.h"

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

}

void InitHelpScene()
{
	// テクスチャ読み込み

	ChangeSceneStep(SceneStep::MainStep);
}

void MainHelpScene()
{
	// ゲーム処理
	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishHelpScene()
{
	// リリース開放

	return SceneId::GameScene;
}