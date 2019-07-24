#include "GameOverScene.h"

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

}

void InitGameOverScene()
{
	// テクスチャ読み込み

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameOverScene()
{
	// ゲーム処理
	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishGameOverScene()
{
	// リリース開放

	return SceneId::TitleScene;
}