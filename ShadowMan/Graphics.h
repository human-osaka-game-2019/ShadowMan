#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <Windows.h>
#include <d3d9.h>

typedef struct
{
	LPDIRECT3DTEXTURE9 TextureData;
	INT Width;
	INT Height;
} Texture;

BOOL InitGraphics();

VOID EndGraphics();

BOOL DrawStart();

VOID DrawEnd();

VOID DrawTexture(FLOAT x, FLOAT y, Texture* texture_data);

#endif
