#include <d3d9.h>
#include <d3dx9.h>
#include "Window.h"
#include "Graphics.h"

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

BOOL CreateGraphicsInterface();

BOOL CreateGraphicsDevice(D3DPRESENT_PARAMETERS* present_param);

BOOL SetUpViewPort(D3DPRESENT_PARAMETERS* present_param);

BOOL CreateFontDevice();

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
	g_D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 0.0f, 0);

	g_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

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

BOOL CreateTexture(CONST CHAR* file_name, Texture* texture_data)
{
}

BOOL CreateGraphicsInterface()
{
	// インターフェース作成
	if (NULL == (g_D3DInterface = Direct3DCreate9(D3D_SDK_VERSION)));
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
	present_param->BackBufferFormat = D3DFMT_UNKNOWN;
	// ウィンドウモードの設定
	present_param->Windowed = TRUE;
	// スワップエフェクト
	present_param->SwapEffect = D3DSWAPEFFECT_DISCARD;

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
