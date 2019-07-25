#include <d3dx9.h>
#include <stdlib.h>
#include "Texture.h"

// カテゴリごとのテクスチャ保存用配列
static Texture** g_TextureList[MaxTextureCategory] = { nullptr };

// カテゴリのテクスチャ最大サイズの配列
/*INT TextureCategorySize[] =
{

}*/

VOID ReleaseCategoryTexture(INT release_category)
{
	if (g_TextureList[release_category] == nullptr)
	{
		return;
	}

	//for(INT i = 0; i < TextureCategory)
}