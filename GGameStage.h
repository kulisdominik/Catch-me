#pragma once
#include "LibsAndDeclarations.h"

// Let's define base class for diffrent game states.
class GGameStage
{
public:
	GGameStage();
	GGameStage(const GGameStage&) = delete;
	GGameStage& operator=(const GGameStage&) = delete;
	virtual ~GGameStage();

	virtual bool init(sf::RenderWindow &mWindow) = 0;
	virtual bool update(float dt) = 0;
	virtual void draw(sf::RenderWindow &mWindow) = 0;
	virtual void release() = 0;
};


