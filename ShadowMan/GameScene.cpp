
#include"GameScene.h"

// �Q�[���{�҃V�[���̏�����
void InitGameScene(){}
// �Q�[���{�҃V�[���̃��C������
void MainGameScene(){}
// �Q�[���{�҃V�[���̏I��
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