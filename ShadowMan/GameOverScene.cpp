#include "GameOverScene.h"
#include "Texture.h"
#include"Input.h"
#include <SoundsManager.h>

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
	DrawTexture(0.0f, 0.0f, GetTexture(TextureCategoryGameOver, GameOverBackGroundTexture));
}

void InitGameOverScene()
{
	// �e�N�X�`���ǂݍ���
	LoadTexture("Texture/�Q�[���I�[�o�[.png", TextureCategoryGameOver, GameOverCategoryTextureList::GameOverBackGroundTexture);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameOverScene()
{
	// �Q�[������
	if (GetKeyDown(ESCAPE) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishGameOverScene()
{
	// �����[�X�J��
	ReleaseCategoryTexture(SceneId::GameOverScene);

	return SceneId::TitleScene;
}