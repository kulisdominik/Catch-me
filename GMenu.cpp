#include "GMenu.h"

GMenu::GMenu()
{
}

GMenu::~GMenu()
{
	release();
}

bool GMenu::init(sf::RenderWindow &mWindow)
{
	if (!font.loadFromFile("resources/sansation.ttf"))
		return false;

	message.setFont(font);
	message.setCharacterSize(40);
	message.setPosition(170.f, 150.f);
	message.setColor(sf::Color::White);
	message.setString("SFML test - Menu\nPress space to start the game");

	return true;

}

bool GMenu::update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return false;

	return true;

}

void GMenu::draw(sf::RenderWindow &mWindow)
{
	mWindow.clear(sf::Color(255, 0, 0));
	mWindow.draw(message);
}

void GMenu::release()
{
	message = sf::Text();
	font = sf::Font();
}
