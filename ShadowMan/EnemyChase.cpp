#include "Input.h"
#include "EnemyChase.h"


// 敵キャラの移動パターン　（プレイヤー追跡型）
void EnemyTypeChase(Object* enemy, Object* player, Relativity* status)
{

	// ベクトルを出す
	status->normal_x = player->x - enemy->x; // 相対距離を引いてベクトルを出す (敵 追跡型)
	status->normal_y = player->y - enemy->y;

	// ベクトルをそのまま座標に足す
	//enemy->m_PosX += vecx;
	//enemy->m_PosY += vecy;

	enemy->speed = sqrtf((enemy->x * enemy->x) + (enemy->y * enemy->y));
	status->normal_x = enemy->x / status->normal_length;
	status->normal_y = enemy->y / status->normal_length;

	enemy->x += status->normal_x; // 敵の移動
	enemy->y += status->normal_y;


}

<<<<<<< HEAD
//void Collision()
//{

	/*

	敵とプレイヤーの当たり判定

	*/

//}
=======
void Collision();
>>>>>>> 99b2d0360059fba9b128cd7d750d95ae7ddce8e9
