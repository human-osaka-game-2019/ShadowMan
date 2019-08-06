#include "HelpScene.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"

// �w���v�V�[���̏�����
void InitHelpScene();
// �w���v�V�[���̃��C��
void MainHelpScene();
// �w���v�V�[���̏I��
SceneId FinishHelpScene();

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

void DrawHelpScene()
{
	// �`�揈��
	DrawTexture(0.0f, 0.0f, GetTexture(TextureCategoryHelp, HelpCategoryTextureList::HelpBackGroundTexture));
}

void InitHelpScene()
{
	// �e�N�X�`���ǂݍ���
	LoadTexture("Texture/asobikata.png", TextureCategoryHelp, HelpCategoryTextureList::HelpBackGroundTexture);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainHelpScene()
{
	// �Q�[������
	if (GetKeyDown(ESCAPE) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishHelpScene()
{
	// �����[�X�J��
	ReleaseCategoryTexture(SceneId::HelpScene);

	return SceneId::TitleScene;
}