#pragma once
#include "Entity.h"
#include "MyVector.hpp"

#include "CPosition.h"
#include "CCircle.h"


namespace Collision
{
	bool CircleVsCircle(Entity& mPlayerCenter, Entity &mEnemyCenter);
}
