
// @file Input.h
// @brief 入力に関する関数、定数の宣言

#ifndef INPUT_H_
#define INPUT_H_

#include <dinput.h>
#include <Windows.h>
#include <math.h>


struct Object
{
	int m_TextureId;	// テクスチャの種類
	float x;		// 描画座標X
	float y;		// 描画座標Y
	int mapchip_num_row;	// 何行目
	int mapchip_num_col;		// 何列目
	float speed; // スピード
	float rect_wid;
	float rect_hgt;
	float circle_radius;
	int flame_count;
	int mode;
};

struct INPUTSTATE // キーの情報の構造体
{
	DWORD now;
	DWORD pushed;
	DWORD npushed;
};

struct Relativity
{
	float Sr;			 // プレイヤー座標 - 敵座標 = Sr (相対距離)
	float Vr;		     // プレイヤーの移動量(Speed) - 敵の移動量(Speed) = Vr(相対速度)
	float Tc;			 // Tc(接近時間) = |Sr| / |Vr|  これで、敵がプレイヤーの座標を予測
	float normal_x;		 //= vec_x / length;
	float normal_y;		 //= vec_y / length;
	float normal_length; //= sqrt(normal_x * normal_x + normal_y * normal_y);
	float move_length;   //= sqrt(normal_x * normal_x + normal_y * normal_y);
};

// プレーヤー移動
void PlayerControl(Object* player);

// 当たり判定
bool Collision(Object* enemy, Object* player);

void CollisionWallP();

// @brief キーの種類
enum KeyState
{
	CLEAR = 0x0000,		// Key Clear
	UP = 0x0002,		//!<上
	LEFT = 0x0004,		//!<左
	RIGHT = 0x0008,		//!<右
	DOWN = 0x0010,		//!<下
	H = 0x0020,		//!< H キー
	SPACE = 0x0040,		//!< Space キー
	ESCAPE = 0x0080,		//!< Escape キー
};

bool InitDirectInput(HINSTANCE Instance_Handle, HWND Window_Handle);

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
