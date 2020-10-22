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
	//sampleRect.setOutlineThickness(1.f);
	//sampleRect.setOutlineColor(sf::Color(19, 39, 67));

	backgroundRect = sf::RectangleShape(sf::Vector2f(50, 50));
	backgroundRect.setOutlineThickness(1);
	backgroundRect.setOutlineColor(sf::Color(237, 201, 136));
	backgroundRect.setFillColor(sf::Color(248, 239, 212));

	lineCleared = sf::RectangleShape(sf::Vector2f(500, 50));
	lineCleared.setFillColor(sf::Color::White);

	linesBeingCleared = false;

	pieceFreq = 0.75;

	untilNextLevel = 10;


	hud.setPosition(975, 25);
	font.loadFromFile("font.ttf");
	hud.setFont(font);
	hud.setCharacterSize(50);

	hud.setFillColor(sf::Color::White);

	std::stringstream ss;
	ss << "Score\n" << std::setfill('0') << std::setw(5) << score;
	hud.setString(ss.str());

	hudGameOver.setPosition(220, 350);
	hudGameOver.setFont(font);
	hudGameOver.setCharacterSize(100);
	hudGameOver.setFillColor(sf::Color::White);
	std::stringstream ssGameOver;
	ssGameOver << "Game Over";
	hudGameOver.setString(ssGameOver.str());


}

void Engine::start(std::string state)
{

	if (state == "Play") {
		playState();
	}
	else if (state == "Game Over") {
		gameOverState();
	}
	
}