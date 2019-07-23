
#include"GameScene.h"

// ゲーム本編シーンの初期化
void InitGameScene(){}
// ゲーム本編シーンのメイン処理
void MainGameScene(){}
// ゲーム本編シーンの終了
SceneId FinishGameScene() { return SceneId::GameClearScene; }

static SceneId NextSceneId;

SceneId UpdateGameScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitGameScene();
		break;
	case SceneStep::MainStep:
		MainGameScene();
		break;
	case SceneStep::EndStep:
		return FinishGameScene();
		break;
	}

	return SceneId::GameScene;
}
void DrawGameScene(){

}