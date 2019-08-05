#include <Windows.h>
#include"Engine.h"
#include "SceneSwitcher.h"
#include"Input.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR CmdLine, INT nCmdShow)
{
	if (InitEngine(1280, 960, "Shadow Man",hInstance) == FALSE)
	{
		return 0;
	}

	while (TRUE)
	{
		MSG msg;
		//	ゲームループ
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
				KeyUpDate();
				UpdateScene();
			}

		}
	
		return 0;
	}
}

