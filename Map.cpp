#include "Map.h"



Map::Map()
{
	if (!mapTexture.loadFromFile("resources/map.png"))
	{
		std::cout << "ERROR WITH MAP FILE" << std::endl;
		exit(0);
	}
	mapTexture.setRepeated(true);
	mapSprite.setTexture(mapTexture);
	mapSprite.setTextureRect(sf::IntRect(0, 0, mapWidth, mapHeight));
}


Map::~Map()
{
}

void Map::draw(sf::RenderWindow & mWindow)
{
	mWindow.draw(mapSprite);
}
