#include <Windows.h>
#include "Window.h"
#include "Engine.h"
#include "Graphics.h"
#include"Texture.h"
<<<<<<< HEAD
=======
#include"Input.h"
#include "DirectSound.h"
#include<SoundsManager.h>
>>>>>>> 54e5a27a346bce836a3ececfa40ee7e4eb0d3f6f

SoundLib::SoundsManager g_SoundManager;

BOOL InitEngine(INT width, INT height, CONST CHAR* title_name, HINSTANCE hInstance)
{
	HWND hWnd;

	if (MakeWindow(width, height, title_name,&hWnd) == false)
	{
		return FALSE;
	}

	if (InitGraphics() == FALSE)
	{
		return FALSE;
	}

<<<<<<< HEAD
	InitTexture();

=======
	InitDirectInput(hInstance,hWnd);

	InitTexture();

	//
	g_SoundManager.Initialize();

>>>>>>> 54e5a27a346bce836a3ececfa40ee7e4eb0d3f6f
	return TRUE;
}

// ÉÅÉÇÉääJï˙
VOID EndEngine()
{
	EndGraphics();
}