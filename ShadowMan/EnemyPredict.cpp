#include "Input.h"
#include "Object/EnemyAi.h"


// 敵キャラの移動パターン　（先読み型）
void EnemyTypePredict(DrawObject* enemy, DrawObject* player, Relativity* status)
{
	// プレイヤーの移動量(Speed) - 敵の移動量(Speed)　= Vr (相対速度)
	// プレイヤー座標 - 敵座標 = Sr (相対距離)
	// Tc(接近時間) = |Sr| / |Vr|  これで、敵がプレイヤーの座標を予測
	// プレイヤー座標 + プレイヤー移動ベクトル * Tc で追撃ポイント獲得

	status->Vr = player->speed - enemy->speed;

	// 相対距離　（敵、プレイヤー間の距離算出）
	status->Sr = sqrt(pow(enemy->m_PosX - player->m_PosX, 2) + pow(enemy->m_PosY - player->m_PosY, 2));
	// Tc(接近時間) = | Sr| / |Vr |
	status->Tc = fabsf(status->Sr) / fabsf(status->Vr);

	enemy->m_PosX = (player->m_PosX + player->speed) * status->Tc; // 追撃ポイントの X座標
	enemy->m_PosY = (player->m_PosY + player->speed) * status->Tc; // 追撃ポイントの Y座標
}
