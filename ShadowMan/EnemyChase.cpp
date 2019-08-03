#include "Input.h"
#include "Object/EnemyAi.h"


// 敵キャラの移動パターン　（プレイヤー追跡型）
void EnemyTypeChase(DrawObject* enemy, DrawObject* player, Movement* valueE, Relativity* status)
{

	// ベクトルを出す
	valueE->vec_x = player->m_PosX - enemy->m_PosX; // 相対距離を引いてベクトルを出す (敵 追跡型)
	valueE->vec_y = player->m_PosY - enemy->m_PosY;

	// ベクトルをそのまま座標に足す
	//enemy->m_PosX += vecx;
	//enemy->m_PosY += vecy;

	valueE->length = sqrtf((valueE->vec_x * valueE->vec_x) + (valueE->vec_y * valueE->vec_y));
	status->normal_x = valueE->vec_x / valueE->length;
	status->normal_y = valueE->vec_y / valueE->length;

	enemy->m_PosX += status->normal_x; // 敵の移動
	enemy->m_PosY += status->normal_y;

	//敵キャラとプレイヤーキャラの当たり判定(円と円)
	float circle_pos_xE = enemy->m_PosX;  //敵X座標
	float circle_pos_yE = enemy->m_PosY;  //敵Y座標
	float circle_radiusE = 32.0f;		  //敵テクスチャの円形範囲

	float circle_pos_xP = player->m_PosX; //プレイヤーX座標
	float circle_pos_yP = player->m_PosY; //プレイヤーY座標
	float circle_radiusP = 32.0f;		  //プレイヤーテクスチャの円形範囲

	float a = circle_pos_xE - circle_pos_xP; // X座標の算出
	float b = circle_pos_yE - circle_pos_yP; // Y座標の算出
	float c = sqrt(a * a + b * b);			 // 二つの円の距離の算出

	if (c <= circle_radiusE + circle_radiusP)
	{
		/*
		当たってる
		プレイヤー死亡
		*/
	}
	else
	{
		/*
		当たってない
		ゲーム続行
		*/
	}

	//敵キャラと壁の当たり判定(矩形と矩形)


}