#pragma once
#include <array>
#include <SFML/Graphics.hpp>
#include "Chip.h";

class Piece
{
private:
	//Chip chips[4];
	//Chip oldChips[4];
	std::array<Chip, 4> chips;
	std::array<Chip, 4> oldChips;
	sf::Vector2f rotationCenter;
	sf::Vector2f oldRotationCenter;
	
public:
	std::array<std::array<sf::Vector2f, 5>, 4> translations;
	Piece();
	void moveDown();
	void moveLeft();
	void moveRight();
	void allWayDown();
	void rotate(int round);
	void unrotate();
	void addChip(int num, int x, int y);
	std::array<Chip, 4> getChips();
	void setRotationCenter(sf::Vector2f rotationCenter);
	void update(float elapsedTime);
};
