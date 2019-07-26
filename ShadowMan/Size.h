#ifndef SIZE_H
#define SIZE_H

#include <Windows.h>

struct Size
{
	Size()
	{
		Width = 0.0f;
		Height = 0.0f;
	}

	Size(FLOAT width, FLOAT height)
	{
		Width = width;
		Height = height;
	}

	Size(CONST Size& size)
	{
		this->Width = size.Width;
		this->Height = size.Height;
	}

	FLOAT Width;
	FLOAT Height;
};

#endif