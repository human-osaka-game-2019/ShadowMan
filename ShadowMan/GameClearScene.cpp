#include "GameClearScene.h"

// ゲームクリアシーンの初期化
void InitGameClearScene(){}
// ゲームクリアシーンのメイン処理
void MainGameClearScene(){}
// ゲームクリアシーンの終了
SceneId FinishGameClearScene() { return SceneId::TitleScene; }

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
void DrawGameClearScene() {

}