
#include"GameScene.h"

// �Q�[���{�҃V�[���̏�����
void InitGameScene();
// �Q�[���{�҃V�[���̃��C������
void MainGameScene();
// �Q�[���{�҃V�[���̏I��
SceneId FinishGameScene();

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

void DrawGameScene()
{
	// �`�揈��

}

void InitGameScene()
{
	// �e�N�X�`���ǂݍ���

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameScene()
{
	// �Q�[������
	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishGameScene()
{
	// �����[�X�J��

	return SceneId::GameClearScene;
}