#pragma once
#include "LibsAndDeclarations.h"
#include "ECSLibsAndDeclaration.h"
#include "ECSID.hpp"
using ComponentArray = std::array<Component*, maxComponents>;

class Entity
{
public:
	Entity(Manager& mManager);
	void update(float mFrameTime);
	void draw();
	bool isAlive() const;
	void destroy();

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs);

	template <typename T>
	bool hasComponent() const;

	template <typename T>
	T& getComponent() const;

	bool hasGroup(Group mGroup) const noexcept;
	void addGroup(Group mGroup) noexcept;
	void delGroup(Group mGroup) noexcept;
private:
	Manager& manager;

	bool alive{ true };
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitset componentBitset;
	GroupBitset groupBitset;
};

template<typename T, typename ...TArgs>
inline T & Entity::addComponent(TArgs && ...mArgs)
{
	assert(!hasComponent<T>());

	T* c(new T(std::forward<TArgs>(mArgs)...));
	c->entity = this;
	std::unique_ptr<Component> uPtr{ c };
	components.emplace_back(std::move(uPtr));

	componentArray[ECSID::getComponentTypeID<T>()] = c;
	componentBitset[ECSID::getComponentTypeID<T>()] = true;

	c->init();
	return *c;
}

template<typename T>
inline bool Entity::hasComponent() const
{
	return componentBitset[ECSID::getComponentTypeID<T>()];
}

template<typename T>
inline T & Entity::getComponent() const
{
	assert(hasComponent<T>());
	auto ptr(componentArray[ECSID::getComponentTypeID<T>()]);
	return *reinterpret_cast<T*>(ptr);
}


