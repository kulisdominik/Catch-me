#pragma once
#include "LibsAndDeclarations.h"
#include "Component.h"
#include "Boids.h"

#include "CCircle.h"
#include "CPhysics.h"

class CEnemyControl : public Component
{
private:
	Manager& manager;
	std::unique_ptr<Boids> boid;

	CPhysics* cPhysics{ nullptr };
	CCircle* cCircle{ nullptr };
public:
	CEnemyControl(Manager& mManager);
	~CEnemyControl();

	void init() override;
	void update(float mFT) override;

private:
	inline float x() const noexcept;
	inline float y() const noexcept;
	inline float left() const noexcept;
	inline float right() const noexcept;
	inline float top() const noexcept;
	inline float bottom() const noexcept;
};

