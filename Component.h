#pragma once
#include "LibsAndDeclarations.h"
#include "Entity.h"

// Class will be the base of our componet elmenets. 
// Every componets must inherit from this class.

class Component
{
public:
	Entity *entity{ nullptr };

	virtual void init();
	virtual void update(float mDT);
	virtual void draw();
	virtual ~Component();
};
