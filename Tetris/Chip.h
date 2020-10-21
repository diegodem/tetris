#pragma once
#include <SFML/Graphics.hpp>

#pragma once
#include <SFML/Graphics.hpp>

class Chip: public sf::RectangleShape
{
private:
	sf::Vector2i boardPosition;
public:
	Chip(int x = 0, int y = 0);
	void setBoardPosition(int x, int y);
	sf::Vector2i getBoardPosition();
};