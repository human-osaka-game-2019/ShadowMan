#include "TitleScene.h"


// タイトルシーンの初期化
void InitTitleScene(){}
// タイトルシーンのメイン処理
void MainTitleScene(){}
// タイトルシーンの終了
SceneId FinishTitleScene() { return SceneId::GameScene; }

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

void DrawTitleScene() {

}