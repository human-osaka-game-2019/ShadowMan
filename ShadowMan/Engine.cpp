#include <Windows.h>
#include "Window.h"
#include "Engine.h"
#include "Graphics.h"
#include"Texture.h"
#include"Input.h"
#include "DirectSound.h"
#include<SoundsManager.h>

SoundLib::SoundsManager g_SoundManager;

BOOL InitEngine(INT width, INT height, CONST CHAR* title_name, HINSTANCE hInstance)
{
	HWND hWnd;

	if (MakeWindow(width, height, title_name, &hWnd) == false)
	{
		return FALSE;
	}

	if (InitGraphics() == FALSE)
	{
		return FALSE;
	}

	InitDirectInput(hInstance,hWnd);

	InitTexture();

	g_SoundManager.Initialize();

	return TRUE;
}

// ÉÅÉÇÉääJï˙
VOID EndEngine()
{
	EndGraphics();
}