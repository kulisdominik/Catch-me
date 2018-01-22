#pragma once
#include "LibsAndDeclarations.h"
#include "GGameStage.h"
#include "Manager.h"

#include "Collision.h"
#include "Map.h"

#include "CCircle.h"
#include "CPlayerControl.h"
#include "CPosition.h"
#include "CEnemyControl.h"


// Class represents gameplay.
class GGameplay : public GGameStage
{
public:
	GGameplay();
	GGameplay(const GGameplay&) = delete;
	GGameplay& operator=(const GGameplay&) = delete;
	virtual ~GGameplay();

private:
	sf::View camera;
	void updateCamera();
	bool running{ false };

	Manager manager;

	Map map;
public:
	bool init(sf::RenderWindow &mWindow) override;
	bool update(float dt) override;
	void draw(sf::RenderWindow &mWindow) override;
	void release() override;

private:
// Definition character installations
	Entity &createCirclePlayer(float mR, sf::RenderWindow &mWindow);
	Entity &createCircleEnemy(float x, float y, float mR, sf::RenderWindow &mWindow);
};

