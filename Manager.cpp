#include "Manager.h"

void Manager::refresh()
{
	for (auto i(0u); i < maxGroups; ++i)
	{
		auto& v(groupedEntities[i]);

		v.erase(std::remove_if(std::begin(v), std::end(v),
			[i](Entity* mEntity)
		{
			return !mEntity->isAlive() ||
				!mEntity->hasGroup(i);
		}),
			std::end(v));
	}

	// Clean dead entities
	entities.erase
	(
		std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity)
	{
		return !mEntity->isAlive();
	}),
		std::end(entities)
		);
}

void Manager::update(float mFrameTime)
{
	for (auto& e : entities) e->update(mFrameTime);
}

void Manager::draw()
{
	for (auto& e : entities) e->draw();
}

void Manager::addToGroup(Entity * mEntity, Group mGroup)
{
	groupedEntities[mGroup].emplace_back(mEntity);
}

std::vector<Entity*>& Manager::getEntitiesByGroup(Group mGroup)
{
	return groupedEntities[mGroup];
}

Entity & Manager::addEntity()
{
	Entity* e{ new Entity(*this) };
	std::unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(std::move(uPtr));
	return *e;
}
