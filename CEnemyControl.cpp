#include "CEnemyControl.h"



CEnemyControl::CEnemyControl(Manager & mManager)
	: manager(mManager)
{
}

CEnemyControl::~CEnemyControl()
{
}

void CEnemyControl::init()
{
	cPhysics = &entity->getComponent<CPhysics>();
	cCircle = &entity->getComponent<CCircle>();
	boid = std::make_unique<Boids>(entity, manager.getEntitiesByGroup(AgarioGroup::GCircleEnemy));
}

void CEnemyControl::update(float mFT)
{
	boid->update(mFT);

	auto& velocity = boid->velocity;

	if (velocity.x <= 0)
		cPhysics->velocity.x = -maxSpeedCircle;
	else if(velocity.x > 0)
		cPhysics->velocity.x = maxSpeedCircle;

	if (velocity.y <= 0)
		cPhysics->velocity.y = -maxSpeedCircle;
	else if (velocity.y > 0)
		cPhysics->velocity.y = maxSpeedCircle;

	if (left() < 0)
	{
		cPhysics->velocity.x = -cPhysics->velocity.x;
		velocity.x = -velocity.x;
	}
	else if (right() > mapWidth)
	{
		cPhysics->velocity.x = -cPhysics->velocity.x;
		velocity.x = -velocity.x;
	}

	if (top() < 0)
	{
		cPhysics->velocity.y = -cPhysics->velocity.y;
		velocity.y = -velocity.y;
	}
	else if (bottom() > mapWidth)
	{
		cPhysics->velocity.y = -cPhysics->velocity.y;
		velocity.y = -velocity.y;
	}
}

float CEnemyControl::x() const noexcept
{
	return cPhysics->cPosition->position.x;
}

float CEnemyControl::y() const noexcept
{
	return cPhysics->cPosition->position.y;
}

float CEnemyControl::left() const noexcept
{
	return x() - cCircle->radius;
}

float CEnemyControl::right() const noexcept
{
	return x() + cCircle->radius;
}

float CEnemyControl::top() const noexcept
{
	return y() - cCircle->radius;
}

float CEnemyControl::bottom() const noexcept
{
	return y() + cCircle->radius;
}