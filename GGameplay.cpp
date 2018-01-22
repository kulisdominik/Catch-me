#include "GGameplay.h"



GGameplay::GGameplay()
{
}


GGameplay::~GGameplay()
{
}

void GGameplay::updateCamera()
{
	// Get player position and then set camera position in the center
	auto& player(manager.getEntitiesByGroup(AgarioGroup::GCirclePlayer));

	auto position{ player[0]->getComponent<CPosition>() };

	camera.reset(sf::FloatRect(	position.position.x - cameraWidth / 2,
								position.position.y - cameraHeight / 2,
								static_cast<float>(cameraWidth),
								static_cast<float>(cameraHeight)));
}

bool GGameplay::init(sf::RenderWindow & mWindow)
{
	// Create character installations:
	{
		// Player:
		createCirclePlayer(10.f, mWindow);

		// Enemy
		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937_64 generator(seed);

		for (int i = 0; i < 100; ++i)
		{
			
			createCircleEnemy(	static_cast<float>(generator() % mapWidth - sizeCircle / 2),
								static_cast<float>(generator() % mapHeight - sizeCircle / 2),
								sizeCircle, mWindow);
		}
	}
// Init camera
	camera.reset(sf::FloatRect(0, 0, static_cast<float>(cameraWidth), static_cast<float>(cameraHeight)));

	return true;
}

bool GGameplay::update(float dt)
{
	updateCamera();
	manager.refresh();
	manager.update(dt);

	auto& player(manager.getEntitiesByGroup(AgarioGroup::GCirclePlayer));
	auto& enemys(manager.getEntitiesByGroup(AgarioGroup::GCircleEnemy));

	for (auto& e : enemys)
	{
		for (auto& p : player)
			if (Collision::CircleVsCircle(*p, *e))
				p->getComponent<CCircle>().shape.setRadius(p->getComponent<CCircle>().shape.getRadius() + 1);
	}

	return true;
}

void GGameplay::draw(sf::RenderWindow & mWindow)
{
	mWindow.setView(camera);

	map.draw(mWindow);
	manager.draw();

	mWindow.setView(mWindow.getDefaultView());
}

void GGameplay::release()
{
}

Entity & GGameplay::createCirclePlayer(float mR, sf::RenderWindow & mWindow)
{
	auto& entity(manager.addEntity());

	entity.addComponent<CPosition>(sf::Vector2f{ mapWidth / 2, mapHeight / 2 });
	entity.addComponent<CPhysics>(sf::Vector2f{ 0, 0 });
	entity.addComponent<CCircle>(mWindow, sf::Color::Blue, sizeCircle);
	entity.addComponent<CPlayerControl>(sf::Vector2f{ sizeCircle, sizeCircle });

	entity.addGroup(AgarioGroup::GCirclePlayer);
	return entity;
}

Entity & GGameplay::createCircleEnemy(float x, float y, float mR, sf::RenderWindow & mWindow)
{
	auto& entity(manager.addEntity());


	entity.addComponent<CPosition>(sf::Vector2f{ x, y });
	{
		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937_64 generator(seed);

		entity.addComponent<CPhysics>(sf::Vector2f{ static_cast<float>(generator() % 100) - 50.f,
													static_cast<float>(generator() % 100) - 50.f, });
	}
	entity.addComponent<CCircle>(mWindow, sf::Color::Red, 10);
	entity.addComponent<CEnemyControl>(manager);

	entity.addGroup(AgarioGroup::GCircleEnemy);
	return entity;
}
