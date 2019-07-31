#include "TitleScene.h"
#include "Texture.h"
#include"Input.h"
#include "SoundManager.h"


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
	DrawTexture(0.0f, 0.0f, GetTexture(TextureCategoryTitle,TitleBackGroundTexture));
}

void InitTitleScene()
{
	LoadTexture("titlebackground.png",TextureCategoryTitle,TitleCategoryTextureList::TitleBackGroundTexture);

	SoundManager& soundManager = SoundManager::GetInstance();
	soundManager.Load("Sound\\launcher1.wav");

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{
	SoundManager& soundManager = SoundManager::GetInstance();

	soundManager.Play("Sound\\launcher1.wav", false);

	// �Q�[������
	if (GetKeyDown(DIK_SPACE)) 
	{
		
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishTitleScene()
{
	// �����[�X�J��

	
	return SceneId::GameScene;
}