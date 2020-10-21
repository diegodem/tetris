#include "stdafx.h"
#include "Line.h"

Line::Line() {
	addChip(0, 3, 1);
	addChip(1, 4, 1);
	addChip(2, 5, 1);
	addChip(3, 6, 1);
	setRotationCenter(sf::Vector2f(4.5f, 1.5f));
	translations = { {
		{ sf::Vector2f(0, 0), sf::Vector2f(-2, 0), sf::Vector2f(1, 0), sf::Vector2f(-2, 1), sf::Vector2f(1, -2) },
		{ sf::Vector2f(0, 0), sf::Vector2f(-1, 0), sf::Vector2f(2, 0), sf::Vector2f(-1, -2), sf::Vector2f(2, 1) },
		{ sf::Vector2f(0, 0), sf::Vector2f(2, 0), sf::Vector2f(-1, 0), sf::Vector2f(2, -1), sf::Vector2f(-1, 2) },
		{ sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(-2, 0), sf::Vector2f(1, 2), sf::Vector2f(-2, -1) }
	} };
}