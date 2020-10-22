#include "stdafx.h"
#include "Engine.h"
#include <sstream>
#include <iomanip>
#include <iostream>

void Engine::playState() {
	gameIsOver = false;

	score = 0;
	level = 1;

	m_Board.clear();

	pieceFreq = 0.75;

	untilNextLevel = 10;

	std::stringstream ss;
	ss << "Score\n" << std::setfill('0') << std::setw(5) << score;
	hud.setString(ss.str());

	// Timing
	sf::Clock clock;

	srand(time(NULL));

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



	while (m_Window.isOpen() && !gameIsOver)
	{
		// Restart the clock and save the elapsed time into dt
		sf::Time dt = clock.restart();

		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();


	}

	if (gameIsOver) {
		start("Game Over");
	}
}