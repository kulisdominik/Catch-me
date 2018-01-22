#include "CPlayerControl.h"

CPlayerControl::CPlayerControl(const sf::Vector2f &mHalfSize)
	: halfSize(mHalfSize)
{

}

void CPlayerControl::init()
{
	cPhysics = &entity->getComponent<CPhysics>();
}

void CPlayerControl::update(float mDT)
{
	// Lets set way direction of the player
	// If player goes out of the map, player will slow down the movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && left() >= 0)
		this->horizontally = CWay::Horizontally::Left;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && right() <= mapWidth)
		this->horizontally = CWay::Horizontally::Right;
	else
		this->horizontally = CWay::Horizontally::Any;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && top() >= 0)
		this->vertically = CWay::Vertically::Up;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && bottom() <= mapWidth)
		this->vertically = CWay::Vertically::Down;
	else
		this->vertically = CWay::Vertically::Any;

	cPhysics->velocity.x = static_cast<float>(horizontally);
	cPhysics->velocity.y = static_cast<float>(vertically);
}

float CPlayerControl::x() const noexcept
{
	return cPhysics->cPosition->position.x;
}

float CPlayerControl::y() const noexcept
{
	return cPhysics->cPosition->position.y;
}

float CPlayerControl::left() const noexcept
{
	return x() - halfSize.x;
}

float CPlayerControl::right() const noexcept
{
	return x() + halfSize.x;
}

float CPlayerControl::top() const noexcept
{
	return y() - halfSize.y;
}

float CPlayerControl::bottom() const noexcept
{
	return y() + halfSize.y;
}
