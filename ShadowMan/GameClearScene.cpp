#include "GameClearScene.h"
#include "Texture.h"
#include"Input.h"
#include <SoundsManager.h>

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
	DrawTexture(0.0f, 0.0f, GetTexture(TextureCategoryGameClear, GameClearBackGroundTexture));
}

void InitGameClearScene()
{
	// �e�N�X�`���ǂݍ���
	LoadTexture("Texture/�Q�[���N���A2.png", TextureCategoryGameClear, GameClearCategoryTextureList::GameClearBackGroundTexture);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameClearScene()
{
	// �Q�[������
	if (GetKeyDown(ESCAPE) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishGameClearScene()
{
	// �����[�X�J��
	ReleaseCategoryTexture(SceneId::GameClearScene);

	return SceneId::TitleScene;
}