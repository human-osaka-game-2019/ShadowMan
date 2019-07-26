#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

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

VOID DrawMapChip(D3DXVECTOR2 draw_pos, D3DXVECTOR2 texture_pos, D3DXVECTOR2 texture_size);

BOOL CreateTexture(CONST CHAR* file_name, Texture* texture_data);

#endif
