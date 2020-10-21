#pragma once
#include <array>
#include <SFML/Graphics.hpp>

class Board
{
private:
	std::array<std::array<bool, 10>, 20> squares;
	std::vector<int> clearedLines;
public:
	Board();
	int checkLines();
	bool isFilledSquare(int x, int y);
	void fillSquare(int x, int y);
	std::vector<int> linesBeingCleared();
	void removeClearedLines();
};
