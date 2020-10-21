#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
	leftPressed = false;
	rightPressed = false;
	downPressed = false;
	spacePressed = false;
	while (m_Window.pollEvent(event))
	{
		// check the type of the event...
		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			m_Window.close();
			break;

			// key pressed
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Down)
			{
				downPressed = true;
			}else if (event.key.code == sf::Keyboard::Right)
			{
				rightPressed = true;
			}else if (event.key.code == sf::Keyboard::Left)
			{
				leftPressed = true;
			}else if (event.key.code == sf::Keyboard::Space)
			{
				spacePressed = true;
			}

			break;

			// we don't process other types of events
		default:
			break;
		}
	}

}