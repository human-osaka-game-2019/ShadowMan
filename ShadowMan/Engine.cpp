#include <Windows.h>
#include "Window.h"
#include "Engine.h"
#include "Graphics.h"

BOOL InitEngine(INT width, INT height, CONST CHAR* title_name)
{
	if (MakeWindow(width, height, title_name) == false)
	{
		return FALSE;
	}

	if (InitGraphics() == FALSE)
	{
		return FALSE;
	}
}