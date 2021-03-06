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
	sf::RectangleShape backgroundRect;
	sf::RectangleShape lineCleared;

	sf::Event event;

	bool leftPressed;
	bool rightPressed;
	bool downPressed;
	bool spacePressed;
	bool upPressed;

	bool linesBeingCleared;
	float lineCounter;
	float pieceCounter;
	float pieceFreq;

	int untilNextLevel;

	int score;
	int level;

	int scoreByLines[4] = { 40, 100, 300, 1200 };

	sf::Text hud;
	sf::Text hudGameOver;
	sf::Text hudPressEnter;

	sf::Font font;

	bool gameIsOver;
	bool startPlaying;

	// Private functions for internal use only
	void playState();
	void input();
	void update(float dtAsSeconds);
	void draw();
	void gameOverState();


public:
	// The Engine constructor
	Engine();

	// start will call all the private functions
	void start(std::string state);

};