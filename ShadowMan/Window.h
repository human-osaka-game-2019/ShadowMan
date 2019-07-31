#ifndef WINDOW_H_
#define WINDOW_H_

#include <Windows.h>

#define WINDOW_CLASS_NAME "Shadow Man"

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

BOOL MakeWindow(INT width, INT height, CONST CHAR* title_name, HWND* hWnd);

#endif
