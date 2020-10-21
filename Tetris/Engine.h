#pragma once
#include <SFML/Graphics.hpp>
#include "Line.h";
#include "Gamma.h";
#include "Alpha.h";
#include "Square.h";
#include "Saw.h";
#include "Triangle.h";
#include "Zaw.h";
#include "Board.h";



class Engine
{
private:

	// A regular RenderWindow
	sf::RenderWindow m_Window;

	// Declare a sprite and a Texture for the background
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	Board m_Board;

	// An instance of Piece
	Piece m_Piece;

	sf::RectangleShape rectangle;
	sf::RectangleShape sampleRect;
	sf::RectangleShape lineCleared;

	sf::Event event;

	bool leftPressed;
	bool rightPressed;
	bool downPressed;
	bool spacePressed;

	bool linesBeingCleared;
	float lineCounter;
	float pieceCounter;
	float pieceFreq;

	int untilNextLevel;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	// The Engine constructor
	Engine();

	// start will call all the private functions
	void start();

};