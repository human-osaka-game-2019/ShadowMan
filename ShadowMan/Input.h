
// @file Input.h
// @brief 入力に関する関数、定数の宣言

#include <dinput.h>

#ifndef INPUT_H_
#define INPUT_H_

HRESULT DirectInputCreate(HINSTANCE hInst, DWORD DIRECTINPUT8, 
						  LPDIRECTINPUT8* lplpDirectInput, LPUNKNOWN punkOuter);
HRESULT CreateDevice(REFGUID GUID_SysKeyboard, 
					 LPDIRECTINPUTDEVICE* lplpDIDev, LPUNKNOWN UnkOuter);
HRESULT SetCooperativeLevel(HWND hWnd, DWORD dwFlags);
HRESULT SetDataFormat(LPDIDATAFORMAT c_dfDIKeyboard);
HRESULT Acquire();
HRESULT GetKeyState(WORD [256], LPVOID lpvData);

BYTE KeyState[256];

// @brief キーの種類
enum KeyState
{
	Up,    //!<上
	Left,  //!<左
	Right, //!<右
	Down,  //!<下
	H,	   //!< H キー
	Space, //!< Space キー
};

/* 
	@brief Input機能初期化関数@n
	デバイスの入力取得に必要な初期化を行う
	InitEngineで実行されるので開発側が実行する必要はない
	@return 初期化結果(成功はtrue)
*/
bool InitInput();

/*
	@brief Input機能終了関数@n
	Input機能を終了させる@n
	EndEngineで実行されるので開発側が実行する必要はない
*/
void EndInput();

/*
	@brief 入力情報の更新@n
	デバイスの入力情報の更新を行う@n
	毎フレームに１度必ず実行する必要がある
*/
void UpdateKeyState();

/*
	@brief 入力された瞬間判定関数@n
	指定したキーボードのキーが入力された瞬間かどうかを判定する
	@return 判定結果(押された瞬間ならtrue)
	@param[in] button_type 判定したいキーの種類
*/



bool GetKeyState();


#endif