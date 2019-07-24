#include "TitleScene.h"

// タイトルシーンの初期化
void InitTitleScene();
// タイトルシーンのメイン処理
void MainTitleScene();
// タイトルシーンの終了
SceneId FinishTitleScene();

SceneId UpdateTitleScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitTitleScene();
		break;
	case SceneStep::MainStep:
		MainTitleScene();
		break;
	case SceneStep::EndStep:
		return FinishTitleScene();
		break;
	}

	return SceneId::TitleScene;
}

void DrawTitleScene()
{
	// 描画処理

}

void InitTitleScene()
{
	// テクスチャ読み込み

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{
	// ゲーム処理
	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishTitleScene()
{
	// リリース開放

	
	return SceneId::GameScene;
}