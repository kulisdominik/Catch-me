#pragma once
#include "Component.h"
#include "CPhysics.h"
class CPlayerControl : public Component
{
public:
	CPhysics* cPhysics{ nullptr };
	sf::Vector2f halfSize;
	CWay::Horizontally horizontally{};
	CWay::Vertically vertically{};
	
	CPlayerControl(const sf::Vector2f &mHalfSize);

	void init() override;
	void update(float mDT) override;

private:
	inline float x() const noexcept;
	inline float y() const noexcept;
	inline float left() const noexcept;
	inline float right() const noexcept;
	inline float top() const noexcept;
	inline float bottom() const noexcept;
};
