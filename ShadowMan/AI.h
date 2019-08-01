#include <math.h>
#include "input.h"

void EnemyTypeChase();  // 追跡型の敵


void EnemyTypePredict();// 先読み型の敵

	// プレイヤーの移動量(Speed) - 敵の移動量(Speed)　= Vr (相対速度)
	// プレイヤー座標 - 敵座標 = Sr (相対距離)
	// Tc(接近時間) = |Sr| / |Vr|  これで、敵がプレイヤーの座標を予測


void EnemyTypeFlee(); // 逃走型の敵
/*

 プレイヤーの座標 + 敵座標　= とある座標点

 ||とある座標|| * 移動量

*/

void EnemyTypePatrol(); // 巡回型の敵
/*



*/