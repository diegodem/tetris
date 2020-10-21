#include "stdafx.h"
#include "Square.h"

Square::Square() {
	addChip(0, 4, 0);
	addChip(1, 5, 0);
	addChip(2, 4, 1);
	addChip(3, 5, 1);
	setRotationCenter(sf::Vector2f(4.5f, 0.5f));
}