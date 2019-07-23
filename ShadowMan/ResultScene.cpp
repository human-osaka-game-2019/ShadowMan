#include "ResultScene.h"

// �w���v�V�[���̏�����
void InitResultScene() {}
// �w���v�V�[���̃��C��
void MainResultScene() {}
// �w���v�V�[���̏I��
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