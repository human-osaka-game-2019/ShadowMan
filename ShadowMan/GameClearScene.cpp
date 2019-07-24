#include "GameClearScene.h"

// �Q�[���N���A�V�[���̏�����
void InitGameClearScene();
// �Q�[���N���A�V�[���̃��C������
void MainGameClearScene();
// �Q�[���N���A�V�[���̏I��
SceneId FinishGameClearScene();

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

void DrawGameClearScene()
{
	// �`�揈��

}

void InitGameClearScene()
{
	// �e�N�X�`���ǂݍ���

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameClearScene()
{
	// �Q�[������
	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishGameClearScene()
{
	// �����[�X�J��

	return SceneId::TitleScene;
}