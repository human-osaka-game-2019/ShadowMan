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

}