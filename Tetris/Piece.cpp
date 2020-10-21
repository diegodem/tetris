#include "stdafx.h"
#include "Piece.h"

Piece::Piece() {
	translations = { {
		{ sf::Vector2f(0, 0), sf::Vector2f(-1, 0), sf::Vector2f(-1, -1), sf::Vector2f(0, 2), sf::Vector2f(-1, 2) },
		{ sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(1, 1), sf::Vector2f(0, -2), sf::Vector2f(1, -2) },
		{ sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(1, -1), sf::Vector2f(0, 2), sf::Vector2f(1, 2) },
		{ sf::Vector2f(0, 0), sf::Vector2f(-1, 0), sf::Vector2f(-1, 1), sf::Vector2f(0, -2), sf::Vector2f(-1, -2) }
	} };
}

void Piece::moveDown() {
	for (int i = 0; i < 4; i++) {
		sf::Vector2i boardPosition = chips[i].getBoardPosition();
		chips[i].setBoardPosition(boardPosition.x, boardPosition.y + 1);
	}
	rotationCenter = sf::Vector2f(rotationCenter.x, rotationCenter.y + 1);
}

void Piece::moveLeft() {
	for (int i = 0; i < 4; i++) {
		sf::Vector2i boardPosition = chips[i].getBoardPosition();
		chips[i].setBoardPosition(boardPosition.x - 1, boardPosition.y);
	}
	rotationCenter = sf::Vector2f(rotationCenter.x - 1, rotationCenter.y);
}

void Piece::moveRight() {
	for (int i = 0; i < 4; i++) {
		sf::Vector2i boardPosition = chips[i].getBoardPosition();
		chips[i].setBoardPosition(boardPosition.x + 1, boardPosition.y);
	}
	rotationCenter = sf::Vector2f(rotationCenter.x + 1, rotationCenter.y);
}

void Piece::allWayDown() {

}

void Piece::rotate(int round) {
	oldChips = chips;
	oldRotationCenter = rotationCenter;
	int phase = 0;
	switch (chips[1].getBoardPosition().x - chips[0].getBoardPosition().x + 2*(chips[1].getBoardPosition().y - chips[0].getBoardPosition().y) )
	{
	case -1:
		phase = 2;
		break;
	case 2:
		phase = 1;
		break;
	case 1:
		phase = 0;
		break;
	case -2:
		phase = 3;
		break;
	}
	for (int i = 0; i < 4; i++) {
		sf::Vector2f boardPosition = sf::Vector2f(chips[i].getBoardPosition());
		sf::Vector2f difference = boardPosition - rotationCenter;
		chips[i].setBoardPosition(rotationCenter.x - difference.y + translations[phase][round].x, rotationCenter.y + difference.x + translations[phase][round].y);

	}
	rotationCenter = rotationCenter + translations[phase][round];

}

void Piece::unrotate() {
	chips = oldChips;
	rotationCenter = oldRotationCenter;
}

void Piece::addChip(int num, int x, int y) {
	chips[num] = Chip(x, y);
}

std::array<Chip, 4> Piece::getChips() {
	return chips;
}

void Piece::setRotationCenter(sf::Vector2f rotationCenter) {
	this->rotationCenter = rotationCenter;
}

void Piece::update(float elapsedTime) {
	for (int i = 0; i < 4; i++) {
		sf::Vector2i boardPosition = chips[i].getBoardPosition();
		chips[i].setPosition(sf::Vector2f(390 + boardPosition.x * 50, 12 + boardPosition.y * 50));
	}
}