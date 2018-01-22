#include "CCircle.h"

CCircle::CCircle(sf::RenderWindow& mWindow, sf::Color mColor, float mRadius)
	: mWindow{ mWindow }, radius{ mRadius } , color(std::move(mColor))
{
}

void CCircle::init()
{
	cPosition = &entity->getComponent<CPosition>();

	shape.setRadius(radius);
	shape.setFillColor(color);
	shape.setOrigin(radius, radius);
}

void CCircle::update(float mDT)
{
	shape.setPosition(cPosition->position);
}

void CCircle::draw()
{
	mWindow.draw(shape);
}