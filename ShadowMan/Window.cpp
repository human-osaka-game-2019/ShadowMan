#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND window_handle, UINT message_id, WPARAM wparam, LPARAM lparam)
{
	switch (message_id)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(window_handle, message_id, wparam, lparam);
		break;
	}

	return 0;

}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR CmdLine, INT nCmdShow)
{
	LPCSTR pClassName = "Shadow Man";

	HWND hwnd;

	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = pClassName;

	if (!RegisterClassEx(&wc)) return FALSE;

	HWND hWindow = CreateWindow(
		pClassName, "Shadow Man",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	if (!hWindow) return FALSE;
	ShowWindow(hWindow, nCmdShow);

	MSG msg;
	//Main Loop Start
	ZeroMemory(&msg, sizeof(msg));
	timeBeginPeriod(1);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		Sleep(1);

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	}
	timeEndPeriod(1);
	//Main Loop End
	return 0;
}
