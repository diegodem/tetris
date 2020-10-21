#include "stdafx.h"
#include "Engine.h"
#include <time.h>
#include <sstream>
#include <iomanip>
#include <iostream>

Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	sf::Vector2f resolution;
	resolution.x = 1280;
	resolution.y = 1024;

	m_Window.create(sf::VideoMode(resolution.x, resolution.y), "Tetris");

	// Load the background into the texture
	// Be sure to scale this image to your screen size

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	rectangle.setOutlineThickness(12.f);
	rectangle.setOutlineColor(sf::Color(237, 201, 136));
	rectangle.setFillColor(sf::Color(248,239,212));
	rectangle.setPosition(390, 12);
	rectangle.setSize(sf::Vector2f(500, 1000));

	sampleRect = sf::RectangleShape(sf::Vector2f(50, 50));
	sampleRect.setFillColor(sf::Color(190, 87, 111));

	lineCleared = sf::RectangleShape(sf::Vector2f(500, 50));
	lineCleared.setFillColor(sf::Color::White);

	linesBeingCleared = false;

	pieceFreq = 0.75;

	untilNextLevel = 10;

	score = 0;
	level = 1;

	hud.setPosition(975, 25);
	font.loadFromFile("font.ttf");
	hud.setFont(font);
	hud.setCharacterSize(50);

	hud.setFillColor(sf::Color::White);

	std::stringstream ss;
	ss << "Score\n" << std::setfill('0') << std::setw(5) << score;
	hud.setString(ss.str());


}

void Engine::start()
{
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

	

	while (m_Window.isOpen())
	{
		// Restart the clock and save the elapsed time into dt
		sf::Time dt = clock.restart();

		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}