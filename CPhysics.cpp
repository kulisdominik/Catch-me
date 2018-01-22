#include "CPhysics.h"


CPhysics::CPhysics(const sf::Vector2f & mVelocity)
	: velocity{ mVelocity }
{
}

void CPhysics::init()
{
	cPosition = &entity->getComponent<CPosition>();
}

void CPhysics::update(float mDT)
{
	cPosition->position += velocity * mDT;
}
