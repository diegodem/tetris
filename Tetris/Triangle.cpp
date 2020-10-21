#include "stdafx.h"
#include "Triangle.h"

Triangle::Triangle() {

	addChip(0, 3, 1);
	addChip(1, 4, 1);
	addChip(2, 4, 0);
	addChip(3, 5, 1);
	setRotationCenter(sf::Vector2f(4, 1));
}