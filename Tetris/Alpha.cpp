#include "stdafx.h"
#include "Alpha.h"

Alpha::Alpha() {
	
	addChip(0, 3, 1);
	addChip(1, 4, 1);
	addChip(2, 5, 1);
	addChip(3, 5, 0);
	setRotationCenter(sf::Vector2f(4, 1));
}