#pragma once
#include "Component.h"
#include "CPosition.h"


class CPhysics : public Component
{
public:
	CPosition* cPosition{ nullptr };
	sf::Vector2f velocity; 

	CPhysics(const sf::Vector2f& mVelocity);

	void init() override;
	void update(float mDT) override;
};

