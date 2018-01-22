#pragma once

#include "Component.h"
#include "CPosition.h"

class CCircle : public Component
{
public:
	sf::RenderWindow& mWindow;
	CPosition* cPosition{ nullptr };
	sf::CircleShape shape;
	sf::Color color;
	float radius;

	CCircle(sf::RenderWindow& mWindow, sf::Color mColor, float mRadius);

	void init() override;
	void update(float mDT) override;
	void draw() override;
};
