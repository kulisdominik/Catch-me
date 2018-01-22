#include "Collision.h"

bool Collision::CircleVsCircle(Entity & mPlayerCenter, Entity & mEnemyCenter)
{
	float distance = MyVector::distance<float>(mPlayerCenter.getComponent<CPosition>().position,
		mEnemyCenter.getComponent<CPosition>().position);
	if (distance >= mPlayerCenter.getComponent<CCircle>().radius + mEnemyCenter.getComponent<CCircle>().radius)
		return false;

	mEnemyCenter.destroy();
	return true;
}
