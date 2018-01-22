#pragma once
// TEMPLATES FOR SF::VECTOR
namespace MyVector
{
	// Distance between two Vector
	template<typename T>
	T distance(sf::Vector2<T>&other_1, sf::Vector2<T> &other_2)
	{
		return static_cast<T>(std::sqrt(std::pow(other_1.x - other_2.x, 2) +
			std::pow(other_1.y - other_2.y, 2)));
	}

	template<typename T>
	T length(sf::Vector2<T> & param)
	{
		return static_cast<T>(std::sqrt(param.x * param.x + param.y * param.y));
	}

	template<typename T>
	void normalize(sf::Vector2<T> & param)
	{
		T temp = length(param);
		if (0 != temp)
		{
			param.x /= temp;
			param.y /= temp;
		}
	}
	template<typename T>
	void limit(sf::Vector2<T> & param, T max)
	{
		T length = param.x*param.x + param.y*param.y;

		if (length > max * max && length > 0)
		{
			T ratio = max / std::sqrtf(length);
			param.x *= ratio;
			param.y *= ratio;
		}

	}
}