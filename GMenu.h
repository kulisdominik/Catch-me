#pragma once
#include "GGameStage.h"

// Class represents game menu.
class GMenu : public GGameStage
{
public:
	GMenu();
	GMenu(const GMenu&) = delete;
	GMenu& operator=(const GMenu&) = delete;
	virtual ~GMenu();

private:
	sf::Font font;
	sf::Text message;

public:
	bool init(sf::RenderWindow &mWindow) override;
	bool update(float dt) override;
	void draw(sf::RenderWindow &mWindow) override;
	void release() override;
};