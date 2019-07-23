#include "HelpScene.h"

// ヘルプシーンの初期化
void InitHelpScene(){}
// ヘルプシーンのメイン
void MainHelpScene(){}
// ヘルプシーンの終了
SceneId FinishHelpScene() { return SceneId::TitleScene; }

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

void DrawHelpScene() {

}