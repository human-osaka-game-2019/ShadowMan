#include <d3dx9.h>
#include <stdlib.h>
#include "Texture.h"

// �J�e�S�����Ƃ̃e�N�X�`���ۑ��p�z��
static Texture** g_TextureList[MaxTextureCategory] = { nullptr };

// �J�e�S���̃e�N�X�`���ő�T�C�Y�̔z��
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