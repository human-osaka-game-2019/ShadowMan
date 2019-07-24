#include "GameOverScene.h"

// �Q�[���I�[�o�[�V�[���̏�����
void InitGameOverScene();
// �Q�[���I�[�o�[�V�[���̃��C��
void MainGameOverScene();
// �Q�[���I�[�o�[�V�[���̏I��
SceneId FinishGameOverScene();

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

void DrawGameOverScene()
{
	// �`�揈��

}

void InitGameOverScene()
{
	// �e�N�X�`���ǂݍ���

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameOverScene()
{
	// �Q�[������
	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishGameOverScene()
{
	// �����[�X�J��

	return SceneId::TitleScene;
}