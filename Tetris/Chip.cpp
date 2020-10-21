#include "stdafx.h"
#include "Chip.h"

Chip::Chip(int x, int y)
{
	this->setSize(sf::Vector2f(50, 50));
	this->setFillColor(sf::Color(215, 56, 94));
	this->boardPosition.x = x;
	this->boardPosition.y = y;
}

sf::Vector2i Chip::getBoardPosition() {
	return this->boardPosition;
}

void Chip::setBoardPosition(int x, int y) {
	this->boardPosition.x = x;
	this->boardPosition.y = y;
}