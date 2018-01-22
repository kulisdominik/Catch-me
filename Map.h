#pragma once
#include "LibsAndDeclarations.h"

class Map
{
public:
	Map();
	~Map();

	Map(const Map&) = delete;
	Map& operator=(const Map&) = delete;

	void draw(sf::RenderWindow & mWindow);

private:
	sf::Texture mapTexture;
	sf::Sprite mapSprite;
};

