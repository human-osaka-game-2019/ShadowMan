#include <d3dx9.h>
#include <stdlib.h>
#include "Texture.h"

// カテゴリごとのテクスチャ保存用配列
static Texture** g_TextureList[MaxTextureCategory] = { nullptr };

// カテゴリのテクスチャ最大サイズの配列
INT TextureCategorySize[] =
{
	HelpCategoryTextureList::HelpTitleTextureMax,
};

VOID ReleaseCategoryTexture(INT release_category)
{
	if (g_TextureList[release_category] == nullptr)
	{
		return;
	}

	for (INT i = 0; i < TextureCategorySize[release_category]; i++) 
	{
		if (g_TextureList[release_category][i]->TextureData == nullptr)
		{
			continue;
		}
		g_TextureList[release_category][i]->TextureData->Release();
		g_TextureList[release_category][i]->TextureData = nullptr;
	}
}

void AllReleaseTexture()
{
	for (int i = 0; i < MaxTextureCategory; i++) {
		ReleaseCategoryTexture(i);

		free(g_TextureList[i]);
		g_TextureList[i] = nullptr;
	}
}

void InitTexture()
{
	AllReleaseTexture();

	for (int i = 0; i < MaxTextureCategory; i++)
	{
		g_TextureList[i] = (Texture * *)malloc(sizeof(Texture*) * TextureCategorySize[i]);

		for (int j = 0; j < TextureCategorySize[i]; j++)
		{
			g_TextureList[i][j] = (Texture*)malloc(sizeof(Texture));
			g_TextureList[i][j]->TextureData = nullptr;
		}
	}
}

bool IsCategoryRangeCheck(int category_id, int texture_id)
{
	if (category_id <= -1 ||
		category_id >= MaxTextureCategory)
	{
		return false;
	}

	if (texture_id <= -1 ||
		texture_id >= TextureCategorySize[category_id])
	{
		return false;
	}

	return true;
}

bool LoadTexture(const char* file_name, int id, int texture_id)
{
	if (IsCategoryRangeCheck(id, texture_id) == false)
	{
		return false;
	}

	return CreateTexture(file_name, g_TextureList[id][texture_id]);
}

Texture* GetTexture(int category_id, int texture_id)
{
	if (IsCategoryRangeCheck(category_id, texture_id) == false)
	{
		return nullptr;
	}
	return g_TextureList[category_id][texture_id];
}