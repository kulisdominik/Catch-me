#include "Entity.h"

Entity::Entity(Manager & mManager)
	: manager(mManager)
{
}

void Entity::update(float mFrameTime)
{
	for (auto& c : components)
		c->update(mFrameTime);
}

void Entity::draw()
{
	for (auto& c : components)
		c->draw();
}

bool Entity::isAlive() const
{
	return alive;
}

void Entity::destroy()
{
	alive = false;
}

bool Entity::hasGroup(Group mGroup) const noexcept
{
	return groupBitset[mGroup];
}

void Entity::addGroup(Group mGroup) noexcept
{
	groupBitset[mGroup] = true;
	manager.addToGroup(this, mGroup);
}

void Entity::delGroup(Group mGroup) noexcept
{
	groupBitset[mGroup] = false;
}
