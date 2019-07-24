#include "TitleScene.h"

// �^�C�g���V�[���̏�����
void InitTitleScene();
// �^�C�g���V�[���̃��C������
void MainTitleScene();
// �^�C�g���V�[���̏I��
SceneId FinishTitleScene();

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

void DrawTitleScene()
{
	// �`�揈��

}

void InitTitleScene()
{
	// �e�N�X�`���ǂݍ���

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{
	// �Q�[������
	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishTitleScene()
{
	// �����[�X�J��

	
	return SceneId::GameScene;
}