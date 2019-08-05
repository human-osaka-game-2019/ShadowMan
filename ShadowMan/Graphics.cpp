#include <d3d9.h>
#include <d3dx9.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graphics.h"
#include "Window.h"
#include "Texture.h"
#include "Size.h"

typedef struct
{
	FLOAT x;
	FLOAT y;
	FLOAT z;
	FLOAT rhw;

	FLOAT tu;
	FLOAT tv;
} CustomVertex;

static LPDIRECT3D9 g_D3DInterface;
static LPDIRECT3DDEVICE9 g_D3DDevice;
static LPD3DXFONT g_FontDevice;

BOOL CreateGraphicsInterface();

BOOL CreateGraphicsDevice(D3DPRESENT_PARAMETERS* present_param);

BOOL SetUpViewPort(D3DPRESENT_PARAMETERS* present_param);

BOOL InitGraphics()
{
	D3DPRESENT_PARAMETERS present_param;
	ZeroMemory(&present_param, sizeof(D3DPRESENT_PARAMETERS));

	if (CreateGraphicsInterface() == FALSE)
	{
		return FALSE;
	}

	if (CreateGraphicsDevice(&present_param) == FALSE)
	{
		return FALSE;
	}

	if (SetUpViewPort(&present_param) == FALSE)
	{
		return FALSE;
	}

	return TRUE;
}

VOID EndGraphics()
{
	g_D3DDevice->Release();
	g_D3DInterface->Release();
}

BOOL DrawStart()
{
	g_D3DDevice->Clear(
		0,
		nullptr,
		D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER,	
		D3DCOLOR_ARGB(255, 0, 0, 0),							
		1.0f,													
		0);														


	g_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_D3DDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	g_D3DDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
	g_D3DDevice->SetRenderState(D3DRS_ALPHAREF, 0x0ff);

	if (D3D_OK == g_D3DDevice->BeginScene())
	{
		return TRUE;
	}

	return FALSE;
}

VOID DrawEnd()
{
	g_D3DDevice->EndScene();
	g_D3DDevice->Present(NULL, NULL, NULL, NULL);
}

VOID DrawTexture(FLOAT x, FLOAT y, Texture* texture_data)
{
	CustomVertex vertex[4] =
	{
		{ x, y, 0.0f, 1.0f, 0.0f, 0.0f },
		{ x + texture_data->Width, y, 0.0f, 1.0f, 1.0f, 0.0f },
		{ x + texture_data->Width, y + texture_data->Height, 0.0f, 1.0f, 1.0f, 1.0f },
		{ x, y + texture_data->Height, 0.0f, 1.0f, 0.0f, 1.0f },
	};

	// 頂点構造の指定
	g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);

	g_D3DDevice->SetTexture(0, texture_data->TextureData);

	g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CustomVertex));

}

VOID MapLoading(CONST CHAR* file_name, INT List[][20])
{
	FILE* fp = nullptr;

	fopen_s(&fp, file_name, "r");

	if (fp != nullptr)
	{
		CHAR buffer[1024] = { 0 };
		CHAR utf_check[] = { 0xEF, 0xBB, 0xBF, 0 };

		CHAR* p = buffer;
		INT row = 0;
		INT col = 0;

		if (fgets(buffer, 4, fp) == nullptr)
		{
			return;
		}

		if (strstr(buffer, utf_check) == nullptr)
		{
			fseek(fp, 0, SEEK_SET);
		}

		while (fgets(buffer, 1024, fp))
		{

			CHAR* p = buffer;
			col = 0;

			while (TRUE)
			{
				List[row][col] = atoi(p);

				p = strchr(p, ',');

				if (p == nullptr)
				{
					break;
				}
				p++;
				col++;
			}
			row++;
		}

		fclose(fp);
	}
}

VOID DrawMapChip(D3DXVECTOR2 draw_pos, D3DXVECTOR2 texture_pos, D3DXVECTOR2 sprite_size, INT category_id, INT texture_id)
{
	D3DXVECTOR2 uv = D3DXVECTOR2(texture_pos.x / GetTexture(category_id, texture_id)->Width, texture_pos.y / GetTexture(category_id, texture_id)->Height);
	D3DXVECTOR2 uv_size = D3DXVECTOR2(sprite_size.x / GetTexture(category_id, texture_id)->Width, sprite_size.y / GetTexture(category_id, texture_id)->Height);

	CustomVertex sprite[] =
	{
		{ draw_pos.x, draw_pos.y, 0.0f, 1.0f, uv.x, uv.y },
		{ draw_pos.x + sprite_size.x, draw_pos.y, 0.0f, 1.0f, uv.x + uv_size.x, uv.y },
		{ draw_pos.x + sprite_size.x, draw_pos.y + sprite_size.y, 0.0f, 1.0f, uv.x + uv_size.x, uv.y + uv_size.y },
		{ draw_pos.x, draw_pos.y + sprite_size.y, 0.0f, 1.0f, uv.x, uv.y + uv_size.y },
	};

	g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);

	g_D3DDevice->SetTexture(0, GetTexture(category_id, texture_id)->TextureData);

	g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, sprite, sizeof(CustomVertex));
}

VOID DrawObject(Object* object, float tex_pos_x, float tex_pos_y, int tex_width, int tex_height)
{
	DrawMapChip(
		D3DXVECTOR2(object->x, object->y),
		D3DXVECTOR2(tex_pos_x, tex_pos_y),
		D3DXVECTOR2(tex_width, tex_height),
		TextureCategoryGame,
		GameCategoryTextureList::IntegratedTexture
	);
}

BOOL CreateTexture(CONST CHAR* file_name, Texture* texture_data)
{
	Size size;
	D3DXIMAGE_INFO info;

	D3DXGetImageInfoFromFileA(file_name, &info);

	if (FAILED(D3DXCreateTextureFromFileExA(g_D3DDevice,
		file_name,
		info.Width,
		info.Height,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0x0000ff00,
		nullptr,
		nullptr,
		&texture_data->TextureData)))
	{
		return FALSE;
	}
	else
	{
		D3DSURFACE_DESC desc;

		if (FAILED(texture_data->TextureData->GetLevelDesc(0, &desc)))
		{
			texture_data->TextureData->Release();
			return FALSE;
		}
		texture_data->Width = desc.Width;
		texture_data->Height = desc.Height;
	}

	return TRUE;
}

BOOL CreateGraphicsInterface()
{
	// インターフェース作成
	g_D3DInterface = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_D3DInterface == NULL)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CreateGraphicsDevice(D3DPRESENT_PARAMETERS* present_param)
{
	// バックバッファの数
	present_param->BackBufferCount = 1;
	// バックバッファのフォーマット
	present_param->BackBufferFormat = D3DFMT_X8R8G8B8;
	// ウィンドウモードの設定
	present_param->Windowed = TRUE;
	// スワップエフェクト
	present_param->SwapEffect = D3DSWAPEFFECT_DISCARD;
	// 深度バッファの有無
	present_param->EnableAutoDepthStencil = TRUE; 
	// 深度バッファのフォーマット
	present_param->AutoDepthStencilFormat = D3DFMT_D24S8;

	// DirectDeviceの作成
	if (FAILED(g_D3DInterface->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		FindWindowA(WINDOW_CLASS_NAME, nullptr),
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
		present_param,
		&g_D3DDevice)))
	{
		return FALSE;
	}

	return TRUE;
}

BOOL SetUpViewPort(D3DPRESENT_PARAMETERS* present_param)
{
	// ビューポートパラメータ
	D3DVIEWPORT9 view_port;

	// 左上座標
	view_port.X = 0;
	view_port.Y = 0;
	// 幅
	view_port.Width = present_param->BackBufferWidth;
	// 高さ
	view_port.Height = present_param->BackBufferHeight;
	// 深度設定
	view_port.MinZ = 0.0f;
	view_port.MaxZ = 1.0f;

	// ビューポート設定
	if (FAILED(g_D3DDevice->SetViewport(&view_port)))
	{
		return FALSE;
	}

	return TRUE;
}

bool CrateFontDeivce()
{
	if (FAILED(D3DXCreateFont(g_D3DDevice,	//デバイス
		FONT_SIZE,				//文字の高さ
		FONT_SIZE / 2,			//文字幅
		FW_REGULAR,					//フォントの太さ
		NULL,						//MIPMAPのレベル
		FALSE,						//イタリックか
		DEFAULT_CHARSET,			//文字セット
		OUT_DEFAULT_PRECIS,			//出力精度
		PROOF_QUALITY,				//出力品質
		FIXED_PITCH | FF_SCRIPT,	//フォントピッチとファミリ
		TEXT("ＭＳ　Ｐゴシック"),	//フォント名
		&g_FontDevice)))			//Direct3DFontへのポインタへのアドレス
	{
		return FALSE;
	}
	return TRUE;
}

void DrawFont(float pos_x, float pos_y, const char* text)
{
	RECT rect =
	{
		(long)pos_x,
		(long)pos_y,
		(long)pos_x + 10000,	//はみ出した分消える
		(long)pos_y + 20000,
	};

	int r, g, b;
	r = g = b = 255;

	g_FontDevice->DrawTextA( //呼び出してるだけ
		NULL,
		text,
		-1,
		&rect,
		DT_LEFT,
		D3DCOLOR_XRGB(r, g, b)
	);
}


void SetUpStencilRenderState(unsigned char ref, D3DCMPFUNC cmp_func)
{
	// Zバッファ設定 => 有効
	g_D3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	// ZBUFFER比較設定変更 => (参照値 <= バッファ値)
	g_D3DDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	// ステンシルバッファ => 有効
	g_D3DDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);
	// ステンシルバッファと比較する参照値設定 => ref
	g_D3DDevice->SetRenderState(D3DRS_STENCILREF, ref);
	// ステンシルバッファの値に対してのマスク設定 => 0xff(全て真)
	g_D3DDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);
	// ステンシルテストの比較方法設定 => 
	//		この描画での参照値 >= ステンシルバッファの参照値なら合格
	g_D3DDevice->SetRenderState(D3DRS_STENCILFUNC, cmp_func);
	// ステンシルテストの結果に対しての反映設定
	g_D3DDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
	g_D3DDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
	g_D3DDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
}


void SetUpStencilMaskRenderState(unsigned char ref, D3DCMPFUNC cmp_func)
{
	// ステンシルバッファ設定 => 有効
	g_D3DDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);

	// ステンシルバッファへ描き込む参照値設定
	g_D3DDevice->SetRenderState(D3DRS_STENCILREF, ref);

	// マスク設定 => 0xff(全て真)
	g_D3DDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);

	// ステンシルテスト比較設定 => 必ず成功する
	g_D3DDevice->SetRenderState(D3DRS_STENCILFUNC, cmp_func);

	// ステンシルテストのテスト設定
	g_D3DDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
	g_D3DDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_REPLACE);
	g_D3DDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);

	// Zバッファ設定 => 有効
	g_D3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	// ZBUFFER比較設定変更 => 必ず失敗する
	g_D3DDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
}
