#include <math.h>
#include "input.h"


//　先読み型の敵
void ContectTime(); // 接近時間を算出する関数

/*

 Player Speed - Enemy Speed = Vr (相対速度)
 Player Position - Enemy Position = Sr (相対距離)
 Tc(接近時間) = |Sr| / |Vr|

*/

