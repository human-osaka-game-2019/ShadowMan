#include "TitleScene.h"
#include "Texture.h"
#include"Input.h"
#include <SoundsManager.h>

extern SoundLib::SoundsManager g_SoundManager;

// タイトルシーンの初期化
void InitTitleScene();
// タイトルシーンのメイン処理
void MainTitleScene();
// タイトルシーンの終了
SceneId FinishTitleScene();

int scene_check;

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
	// 描画処理
 	DrawTexture(0.0f, 0.0f, GetTexture(TextureCategoryTitle,TitleBackGroundTexture));
}

void InitTitleScene()
{
	LoadTexture("Texture/title_bg.png",TextureCategoryTitle,TitleCategoryTextureList::TitleBackGroundTexture);
	
	g_SoundManager.AddFile("Sound/launcher1.wav","TitleBgm");
	g_SoundManager.Start("TitleBgm",TRUE);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{

	// ゲーム処理
	if (GetKeyDown(H) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
		scene_check = 0;
	}
	else if (GetKeyDown(SPACE) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
		scene_check = 1;
	}
}

SceneId FinishTitleScene()
{
	// リリース開放
	ReleaseCategoryTexture(SceneId::TitleScene);

	//音を止める処理


	//開放は.hがやってくれる
	
	switch (scene_check)
	{
	case 0:
		return SceneId::HelpScene;
		break;
	case 1:
		return SceneId::GameScene;
		break;
	}
}