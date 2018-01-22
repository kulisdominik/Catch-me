#include "Boids.h"



Boids::Boids(Entity *mEntity, vectorBoids &mBoids)
	: boids(mBoids)
{
	cPhysics = &mEntity->getComponent<CPhysics>();
	cPosition = &mEntity->getComponent<CPosition>();

	velocity = cPhysics->velocity;
}


Boids::~Boids()
{
}

bool Boids::update(float dt)
{
	vectorBoids nearby;
	for (auto& boid : boids)
	{
		sf::Vector2f pos = boid->getComponent<CPosition>().position - cPosition->position;
		if ((pos.x == 0 || pos.y == 0) &&
			(std::abs(pos.x) < 50 &&
				std::abs(pos.y) < 50))
		{
			nearby.push_back(boid);
		}
	}
	sf::Vector2f acceleration = getAllign(nearby) + getCohision(nearby) + getSeparation(nearby);

	velocity += acceleration;
	return true;
}

sf::Vector2f Boids::getAllign(vectorBoids & friends)
{
	sf::Vector2f sum{};
	float count = 0;
	for (auto &other : friends)
	{
		float distance = MyVector::distance(other->getComponent<CPosition>().position, cPosition->position);
		if (distance > 0 && distance < 50)
		{
			sum += other->getComponent<CPhysics>().velocity;
			++count;
		}
	}
	if (count > 0)
	{
		sum /= static_cast<float>(count);
		MyVector::normalize(sum);
		sum *= maxSpeed;
		sum -= cPhysics->velocity;
		MyVector::limit(sum, maxForce);
		return sum;
	}

	return sf::Vector2f(0, 0);
}

sf::Vector2f Boids::getCohision(vectorBoids & friends)
{
	sf::Vector2f sum{};
	int count{ 0 };
	for (auto &other : friends)
	{
		float distance = MyVector::distance(other->getComponent<CPosition>().position, cPosition->position);
		if (distance > 0 && distance < 50)
		{
			sum += other->getComponent<CPhysics>().velocity;
			++count;
		}
	}
	if (count > 0)
	{
		sum /= static_cast<float>(count);
		return std::move(seek(sum));
	}
	return sf::Vector2f();
}

sf::Vector2f Boids::getSeparation(vectorBoids & friends)
{
	sf::Vector2f steer{};
	int count{ 0 };
	for (auto &other : friends)
	{
		float distance = MyVector::distance(other->getComponent<CPosition>().position, cPosition->position);
		if (distance > 0 && distance < 50)
		{
			sf::Vector2f diff = cPosition->position - other->getComponent<CPosition>().position;
			MyVector::normalize(diff);
			diff /= distance;
			steer += diff;
			++count;
		}
	}
	if (count > 0)
	{
		steer /= static_cast<float>(count);
	}

	if (MyVector::length(steer) > 0)
	{
		MyVector::normalize(steer);
		steer *= maxSpeed;
		steer -= cPhysics->velocity;;
		MyVector::limit(steer, maxForce);
	}
	return std::move(steer);;
}

sf::Vector2f Boids::seek(sf::Vector2f & target)
{
	sf::Vector2f steer = target - cPosition->position;
	MyVector::normalize(target);
	steer *= maxSpeed;
	steer -= cPhysics->velocity;
	return std::move(steer);
}
