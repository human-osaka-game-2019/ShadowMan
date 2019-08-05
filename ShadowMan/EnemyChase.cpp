#include "Input.h"
#include "EnemyChase.h"


// 敵キャラの移動パターン　（プレイヤー追跡型）
void EnemyTypeChase(DrawObject* enemy, DrawObject* player, Relativity* status)
{

	// ベクトルを出す
	status->normal_x = player->m_PosX - enemy->m_PosX; // 相対距離を引いてベクトルを出す (敵 追跡型)
	status->normal_y = player->m_PosY - enemy->m_PosY;

	// ベクトルをそのまま座標に足す
	//enemy->m_PosX += vecx;
	//enemy->m_PosY += vecy;

	enemy->speed = sqrtf((enemy->m_PosX * enemy->m_PosX) + (enemy->m_PosY * enemy->m_PosY));
	status->normal_x = enemy->m_PosX / status->normal_length;
	status->normal_y = enemy->m_PosY / status->normal_length;

	enemy->m_PosX += status->normal_x; // 敵の移動
	enemy->m_PosY += status->normal_y;


}

void Collision()
{

	/*

	敵とプレイヤーの当たり判定

	*/

}