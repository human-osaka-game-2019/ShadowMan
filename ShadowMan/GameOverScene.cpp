#include "GameOverScene.h"

// ゲームオーバーシーンの初期化
void InitGameOverScene(){}
// ゲームオーバーシーンのメイン
void MainGameOverScene(){}
// ゲームオーバーシーンの終了
SceneId FinishGameOverScene() { return SceneId::TitleScene; }

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
void DrawGameOverScene() {

}