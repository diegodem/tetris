#include "stdafx.h"
#include "Zaw.h"

Zaw::Zaw() {
	addChip(0, 3, 0);
	addChip(1, 4, 0);
	addChip(2, 4, 1);
	addChip(3, 5, 1);
	setRotationCenter(sf::Vector2f(4, 1));
}