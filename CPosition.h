#pragma once

#include "Component.h"


class CPosition : public Component
{
public:
	sf::Vector2f position;

	CPosition() = default;
	CPosition(const sf::Vector2f& mPosition);

	inline float x() const noexcept;
	inline float y() const noexcept;
};

