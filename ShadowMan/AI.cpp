#include "AI.h"
#include "Input.h"



//struct DrawObject player;
//struct DrawObject enemy;

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

// 敵キャラの移動パターン　（先読み型）
void EnemyTypePredict(DrawObject* enemy, DrawObject* player, Movement* valueE, Movement* valueP, Relativity* status)
{
	// プレイヤーの移動量(Speed) - 敵の移動量(Speed)　= Vr (相対速度)
	// プレイヤー座標 - 敵座標 = Sr (相対距離)
	// Tc(接近時間) = |Sr| / |Vr|  これで、敵がプレイヤーの座標を予測
	// プレイヤー座標 + プレイヤー移動ベクトル * Tc で追撃ポイント獲得

	status->Vr = valueP->speed - valueE->speed;

	// 相対距離　（敵、プレイヤー間の距離算出）
	status->Sr = sqrt(pow(enemy->m_PosX - player->m_PosX, 2) + pow(enemy->m_PosY - player->m_PosY, 2));
	// Tc(接近時間) = | Sr| / |Vr |
	status->Tc = fabsf(status->Sr) / fabsf(status->Vr);

	enemy->m_PosX = (player->m_PosX + valueP->vec_x) * status->Tc; // 追撃ポイントの X座標
	enemy->m_PosY = (player->m_PosY + valueP->vec_y) * status->Tc; // 追撃ポイントの Y座標
}


void EnemyTypeFlee()
{

}

void EnemyTypePatrol()
{

}