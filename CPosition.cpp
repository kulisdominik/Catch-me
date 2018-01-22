#include "CPosition.h"


CPosition::CPosition(const sf::Vector2f & mPosition)
	:position {	mPosition} 
{
}

inline float CPosition::x() const noexcept
{
	return position.x; 
}

inline float CPosition::y() const noexcept
{
	return position.y;
}

