
// @file Input.h
// @brief 入力に関する関数、定数の宣言

#ifndef INPUT_H_
#define INPUT_H_

#include <dinput.h>
#include <Windows.h>
#include <math.h>


struct DrawObject
{
	int m_TextureId;	// テクスチャの種類
	float m_PosX;		// 描画座標X
	float m_PosY;		// 描画座標Y
};

struct INPUTSTATE // キーの情報の構造体
{
	DWORD now;
	DWORD pushed;
	DWORD npushed;
};

struct Movement
{
	float speed = 5.0f;  //　スピード (移動量)  xには値を入れるべき
	float vec_x = 1.0f;  //  x成分 (X座標築)   xには値を入れるべき
	float vec_y = 1.0f;  //  y成分 (Y座標築)	  xには値を入れるべき
	float length = 5.0f; //  長さ (移動距離）	  xには値を入れるべき
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
	//Save Key Info

bool GetKey(DWORD key_code);


bool GetKeyDown(DWORD key_code);


bool GetKeyUp(DWORD key_code);


#endif
