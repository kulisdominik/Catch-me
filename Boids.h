#pragma once
#include "LibsAndDeclarations.h"

#include "CPosition.h"
#include "CPhysics.h"

#include "Entity.h"

#include "MyVector.hpp"
using vectorBoids = std::vector<Entity*>;
class Boids
{
	const float maxSpeed{ playerVelocity };
	const float maxForce{ 0.3f };
	CPhysics* cPhysics{ nullptr };
	CPosition* cPosition{ nullptr };
public:
	Boids(Entity *mEntity, vectorBoids &mBoids);
	~Boids();

	bool update(float dt);

	sf::Vector2f velocity;
private:
	vectorBoids &boids;


	sf::Vector2f getAllign(vectorBoids& friends);
	sf::Vector2f getCohision(vectorBoids& friends);
	sf::Vector2f getSeparation(vectorBoids& friends);
	sf::Vector2f seek(sf::Vector2f& target);
};

