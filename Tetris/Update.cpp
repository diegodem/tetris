#include "stdafx.h"
#include "Engine.h"


using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (spacePressed) {
		bool movementObstaculized;
		for (int i = 0; i < 5; i++) {
			movementObstaculized = false;
			m_Piece.rotate(i);
			std::array<Chip, 4> chips = m_Piece.getChips();
			for (int i = 0; i < 4; i++) {
				if ((chips[i].getBoardPosition().x < 0) || (chips[i].getBoardPosition().x > 9) || (chips[i].getBoardPosition().y > 19)) {
					movementObstaculized = true;
				}
				else if (m_Board.isFilledSquare(chips[i].getBoardPosition().x, chips[i].getBoardPosition().y)) {
					movementObstaculized = true;
				}
			}
			if (!movementObstaculized) {
				break;
			}
			else {
				m_Piece.unrotate();
			}
		}
		

		
		
	}
	if (leftPressed) {
		bool movementObstaculized = false;
		std::array<Chip, 4> chips = m_Piece.getChips();
		for (int i = 0; i < 4; i++) {
			if (chips[i].getBoardPosition().x == 0) {
				movementObstaculized = true;
			}
			else if (m_Board.isFilledSquare(chips[i].getBoardPosition().x - 1, chips[i].getBoardPosition().y)) {
				movementObstaculized = true;
			}
		}

		if (!movementObstaculized) {
			m_Piece.moveLeft();
		}
		
	}
	if (rightPressed) {
		bool movementObstaculized = false;
		std::array<Chip, 4> chips = m_Piece.getChips();
		for (int i = 0; i < 4; i++) {
			if (chips[i].getBoardPosition().x == 9) {
				movementObstaculized = true;
			}
			else if (m_Board.isFilledSquare(chips[i].getBoardPosition().x + 1, chips[i].getBoardPosition().y)) {
				movementObstaculized = true;
			}
		}

		if (!movementObstaculized) {
			m_Piece.moveRight();
		}

	}
	if (downPressed || pieceCounter > pieceFreq) {
		bool movementObstaculized = false;
		std::array<Chip, 4> chips = m_Piece.getChips();
		for (int i = 0; i < 4; i++) {
			if (chips[i].getBoardPosition().y == 19) {
				movementObstaculized = true;
			}
			else if (m_Board.isFilledSquare(chips[i].getBoardPosition().x, chips[i].getBoardPosition().y + 1)) {
				movementObstaculized = true;
			}
		}

		if (!movementObstaculized) {
			m_Piece.moveDown();
		}
		else {
			std::array<Chip, 4> chips = m_Piece.getChips();
			for (int i = 0; i < 4; i++) {
				m_Board.fillSquare(chips[i].getBoardPosition().x, chips[i].getBoardPosition().y);
			}
			
			switch (rand() % 7) {
			case 0:
				m_Piece = Line();
				break;
			case 1:
				m_Piece = Gamma();
				break;
			case 2:
				m_Piece = Alpha();
				break;
			case 3:
				m_Piece = Square();
				break;
			case 4:
				m_Piece = Saw();
				break;
			case 5:
				m_Piece = Triangle();
				break;
			case 6:
				m_Piece = Zaw();
			}

			if (int n = m_Board.checkLines() > 0) {
				linesBeingCleared = true;
				lineCounter = 0;
				untilNextLevel -= n;
				if (untilNextLevel <= 0) {
					pieceFreq = pieceFreq * 0.6;
					untilNextLevel += 10;
				}
			}
		}


	}

	if (pieceCounter > pieceFreq) {
		pieceCounter -= pieceFreq;
	}
	pieceCounter += dtAsSeconds;

	if (linesBeingCleared) {
		if (lineCounter < 0.5) {
			lineCounter += dtAsSeconds;
		}
		else {
			m_Board.removeClearedLines();
			linesBeingCleared = false;
		}
	}
	m_Piece.update(dtAsSeconds);
}