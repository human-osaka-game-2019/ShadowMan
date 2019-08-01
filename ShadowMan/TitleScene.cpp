#include "TitleScene.h"
#include "Texture.h"
#include"Input.h"
#include <SoundsManager.h>

extern SoundLib::SoundsManager g_SoundManager;

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

	g_SoundManager.AddFile("Sound/launcher1.wav","TitleBgm");

	g_SoundManager.Start("TitleBgm",TRUE);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{
	

	

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