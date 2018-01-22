#pragma once
#include "LibsAndDeclarations.h"
#include "ECSLibsAndDeclaration.h"

class Manager
{
public:
	void refresh();
	void update(float mFrameTime);
	void draw();
	void addToGroup(Entity* mEntity, Group mGroup);
	std::vector<Entity*>& getEntitiesByGroup(Group mGroup);
	Entity& addEntity();

private:
	std::vector<std::unique_ptr<Entity>> entities;
	std::array<std::vector<Entity*>, maxGroups> groupedEntities;
};

