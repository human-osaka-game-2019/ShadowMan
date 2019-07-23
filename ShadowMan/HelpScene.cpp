#include "HelpScene.h"

// �w���v�V�[���̏�����
void InitHelpScene(){}
// �w���v�V�[���̃��C��
void MainHelpScene(){}
// �w���v�V�[���̏I��
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