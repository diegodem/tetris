#include "stdafx.h"
#include "Board.h"

Board::Board() {
	squares.fill({});
}

bool Board::isFilledSquare(int x, int y) {
	return squares[y][x];
}

void Board::fillSquare(int x, int y) {
	squares[y][x] = true;
}

int Board::checkLines() {
	int lines = 0;
	for (int i = 19; i >= 0; i--) {
		for (int j = 0; j < 10; j++) {
			if (!squares[i][j]) {
				break;
			}
			else if (j == 9) {
				lines++;
				clearedLines.push_back(i);
			}
		}
		
	}
	return lines;
}

std::vector<int> Board::linesBeingCleared() {
	return clearedLines;
}

void Board::removeClearedLines() {
	int lines = 0;
	int n;
	for (int i = 19; i >= 0; i--) {
		n = i;
		if (std::find(clearedLines.begin(), clearedLines.end(), n) != clearedLines.end()) {
			lines++;
		}
		while ((std::find(clearedLines.begin(), clearedLines.end(), n - 1) != clearedLines.end()) && (lines > 0)) {
			n--;
		}
		if (lines == 2) {
			if ((std::find(clearedLines.begin(), clearedLines.end(), n - 2) != clearedLines.end()) && (lines > 0)) {
				n--;
			}
		}

		
		if ((n - lines) >= 0) {
			squares[i] = squares[n - lines];
		}
		else {
			squares[i].fill({});
		}
	
	}
	clearedLines.clear();
}