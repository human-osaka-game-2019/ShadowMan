#include "ResultScene.h"

// ヘルプシーンの初期化
void InitResultScene() {}
// ヘルプシーンのメイン
void MainResultScene() {}
// ヘルプシーンの終了
SceneId FinishResultScene() { return SceneId::TitleScene; }

SceneId UpdateResultScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitResultScene();
		break;
	case SceneStep::MainStep:
		MainResultScene();
		break;
	case SceneStep::EndStep:
		return FinishResultScene();
		break;
	}

	return SceneId::ResultScene;
}

void DrawResultScene() {

}