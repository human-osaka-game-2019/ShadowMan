#include "Input.h"
#include "WaitEnemy.h"
#include <time.h>

void WaitEnemy(INT MapChipList[][20], Object WaitEnemy, Object Player)
{
	srand(time(NULL));//１回だけ呼び出せばいいから場所変える

	static int ramdom;

	ramdom = rand() % 4 + 1;

	switch (ramdom) //道は１
	{
	case 1:
		if (MapChipList[WaitEnemy.mapchip_num_col++][WaitEnemy.mapchip_num_row] == 1
			||
			MapChipList[Player.mapchip_num_col][Player.mapchip_num_row])
		{
			MapChipList[WaitEnemy.mapchip_num_col++][WaitEnemy.mapchip_num_row];
			break;
		}

	case 2:
		if (MapChipList[WaitEnemy.mapchip_num_col--][WaitEnemy.mapchip_num_row] == 1
			||
			MapChipList[Player.mapchip_num_col][Player.mapchip_num_row])
		{
			MapChipList[WaitEnemy.mapchip_num_col--][WaitEnemy.mapchip_num_row];
			break;
		}
	case 3:
		if (MapChipList[WaitEnemy.mapchip_num_col][WaitEnemy.mapchip_num_row++] == 1
			||
			MapChipList[Player.mapchip_num_col][Player.mapchip_num_row])
		{
			MapChipList[WaitEnemy.mapchip_num_col][WaitEnemy.mapchip_num_row++];
			break;
		}

	case 4:
		if (MapChipList[WaitEnemy.mapchip_num_col][WaitEnemy.mapchip_num_row--] == 1
			||
			MapChipList[Player.mapchip_num_col][Player.mapchip_num_row])
		{
			MapChipList[WaitEnemy.mapchip_num_col][WaitEnemy.mapchip_num_row--];
			break;
		}
	default:
		break;
	}
	/*
	if (MapChipList[Player.mapchip_num_col][Player.mapchip_num_row]
		==
		MapChipList[WaitEnemy.mapchip_num_col][WaitEnemy.mapchip_num_row])
	{
		//残機減らす処理
	}
	*/
}


/*
void EnemyTypeWait(Object* enemy, Object* player, Relativity* status)
{

	enemy->x;  //敵X座標
	enemy->y;  //敵Y座標
	enemy->circle_radius = 192.0f;		  //敵テクスチャの円形範囲(3マス分)

	player->x; //プレイヤーX座標
	player->y; //プレイヤーY座標
	player->circle_radius = 192.0f;		  //プレイヤーテクスチャの円形範囲(3マス分)

	float a = player->x - enemy->x; // X座標の算出
	float b = player->y - enemy->y; // Y座標の算出
	float c = sqrt(a * a + b * b);			 // 二つの円の距離の算出

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

	if (c <= player->circle_radius + enemy->circle_radius)
	{
		//　範囲が当たってる
		//　Chaseモードそのまま
		//  速力そのまま
	}

	else
	{
		//　範囲が当たってない
		//　プレイヤーの座標が更新されることによってその座標を目的点として設定
		//  速力少しUP
		//  移動中、5~10秒間そのままの場所で待機 / sleep(5000)
	}

}

void Collision();
*/