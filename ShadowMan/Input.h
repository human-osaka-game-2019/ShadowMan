
// @file Input.h
// @brief 入力に関する関数、定数の宣言

#ifndef INPUT_H_
#define INPUT_H_

#include <dinput.h>
#include <Windows.h>

// プレイヤー情報
struct Player
{
	int ShadowMan;
	float m_PosX;
	float m_PosY;
};

// プレイヤー情報
struct Enemy
{
	int EnemyOne;
	float m_PosX;
	float m_PosY;
};

struct INPUTSTATE // キーの情報の構造体
{
	DWORD now;
	DWORD pushed;
	DWORD npushed;
};


// @brief キーの種類
enum KeyState
{
	CLEAR, // Key Clear
	UP,    //!<上
	LEFT,  //!<左
	RIGHT, //!<右
	DOWN,  //!<下
	H,	   //!< H キー
	SPACE, //!< Space キー
};

bool InitDirectInput(HINSTANCE Instance_Handle, HWND Window_Handle);

/*
	DirectInputの解放
		戻り値：
			なし

		引数：
			なし

		内容：
			DirectInputを解放する
*/
void ReleaseDirectInput();

/*
	キー情報の更新
		戻り値：
			なし

		引数：
			なし

		内容：
			キーの情報を更新してGetKeyシリーズの関数の取得情報を最新にする
			この処理は毎フレームの開始時に呼び出すこと
*/
void KeyUpDate();

/*
	キーを押してるかを判定
		戻り値：
			押されてる => true
			押されてない => false

		引数：
			DWORD key_code
				判断したいキーコード

		内容
			キーが押されているならtrue、押されていないならfalseを返す
*/
bool GetKey(DWORD key_code);

/*
	キーを押した瞬間を判定
		戻り値：
			押した瞬間 => true
			押した瞬間じゃない => false

		引数：
			DWORD key_code
				判断したいキーコード

		内容
			キーが押された瞬間ならtrue、押されてない瞬間ならfalse
*/
bool GetKeyDown(DWORD key_code);

/*
	キーを離した瞬間を判定
		戻り値：
			離した瞬間 => true
			離した瞬間じゃない => false

		引数：
			DWORD key_code
				判断したいキーコード

		内容
			キーが離した瞬間ならtrue、離した瞬間じゃないならfalse
*/
bool GetKeyUp(DWORD key_code);

#endif
