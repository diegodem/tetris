#include "stdafx.h"
#include "Chip.h"

Chip::Chip(int x, int y)
{
	setSize(sf::Vector2f(50, 50));
	setFillColor(sf::Color(215, 56, 94));
	//setOutlineThickness(1.f);
	//setOutlineColor(sf::Color(19, 39, 67));
	boardPosition.x = x;
	boardPosition.y = y;
}

sf::Vector2i Chip::getBoardPosition() {
	return boardPosition;
}

void Chip::setBoardPosition(int x, int y) {
	boardPosition.x = x;
	boardPosition.y = y;
}