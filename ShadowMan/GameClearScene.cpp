#include "GameClearScene.h"

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

}

void InitGameClearScene()
{
	// テクスチャ読み込み

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameClearScene()
{
	// ゲーム処理
	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishGameClearScene()
{
	// リリース開放

	return SceneId::TitleScene;
}