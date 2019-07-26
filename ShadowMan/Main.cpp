#include <Windows.h>
#include"Engine.h"
#include "SceneSwitcher.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR CmdLine, INT nCmdShow)
{
	if (InitEngine(1280, 640, "Shadow Man") == FALSE)
	{
		return 0;
	}

	while (TRUE)
	{
		MSG msg;
		//	�Q�[�����[�v
		ZeroMemory(&msg, sizeof(msg));

		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				UpdateScene();
			}

		}
	
		return 0;
	}
}

