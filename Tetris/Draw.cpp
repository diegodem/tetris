#include "stdafx.h"
#include "Engine.h"


void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(sf::Color(19,39,67));

	// Draw the background
	/*m_Window.draw(m_BackgroundSprite);
	m_Window.draw(m_Bob.getSprite());*/
	m_Window.draw(rectangle);


	std::array<Chip, 4> chips = m_Piece.getChips();
	for (int i = 0; i < 4; i++) {
		m_Window.draw(chips[i]);
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			if (m_Board.isFilledSquare(i, j)) {
				sampleRect.setPosition(390 + i * 50, 12 + j * 50);
				m_Window.draw(sampleRect);
			}
		}
	}

	if (linesBeingCleared) {
		std::vector<int> lines = m_Board.linesBeingCleared();
		for (int i = 0; i < lines.size(); i++) {
			lineCleared.setPosition(390, 12 + lines[i] * 50);
			m_Window.draw(lineCleared);
		}
	}

	m_Window.draw(hud);

	// Show everything we have just drawn
	m_Window.display();
}