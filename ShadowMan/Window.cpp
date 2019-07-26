#include <Windows.h>
#include "Window.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch ((CHAR)wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

BOOL MakeWindow(INT width, INT height, CONST CHAR* title_name)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetModuleHandle(nullptr);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = title_name;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (RegisterClassEx(&wc) == 0)
	{
		return 0;
	}

	HWND hWnd = CreateWindow(
		title_name, title_name,
		WS_OVERLAPPEDWINDOW,
		0, 0, width, height,
		NULL, NULL, GetModuleHandle(nullptr), NULL);

	RECT window;
	RECT client;

	GetWindowRect(hWnd, &window);
	GetClientRect(hWnd, &client);

	INT window_size_x = window.right - window.left;
	INT window_size_y = (window.bottom - window.top);
	INT client_size_x = (client.right - client.left);
	INT client_size_y = (client.bottom - client.top);
	INT frame_size_x = window_size_x - client_size_x;
	INT frame_size_y = window_size_y - client_size_y;

	SetWindowPos(
		hWnd,
		NULL,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		frame_size_x + width,
		frame_size_y + height,
		SWP_NOMOVE);

	if (hWnd == NULL)
	{
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

}
