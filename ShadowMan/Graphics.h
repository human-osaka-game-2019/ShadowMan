#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "Input.h"

typedef struct
{
	LPDIRECT3DTEXTURE9 TextureData;
	INT Width;
	INT Height;
} Texture;

#define FONT_SIZE 24

BOOL InitGraphics();

VOID EndGraphics();

BOOL DrawStart();

VOID DrawEnd();

VOID DrawTexture(FLOAT x, FLOAT y, Texture* texture_data);

VOID MapLoading(CONST CHAR* file_name, INT MapChipList[][20]);

VOID DrawMapChip(D3DXVECTOR2 draw_pos, D3DXVECTOR2 texture_pos, D3DXVECTOR2 texture_size, INT category_id, INT texture_id);

VOID DrawObject(Object* object, float tex_pos_x, float tex_pos_y, int tex_width, int tex_height);

BOOL CreateTexture(CONST CHAR* file_name, Texture* texture_data);

VOID DrawFont(float pos_x,float pos_y, const char* text);

void SetUpStencilRenderState(unsigned char ref, D3DCMPFUNC cmp_func);

void SetUpStencilMaskRenderState(unsigned char ref, D3DCMPFUNC cmp_func);

#endif
