#include "stdafx.h"
#include "Engine.h"


void Engine::gameOverState()
{

	startPlaying = false;
	
	while (m_Window.isOpen() && !startPlaying)
	{


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
				if (event.key.code == sf::Keyboard::Enter)
				{
					startPlaying = true;
				}

				break;

				// we don't process other types of events
			default:
				break;
			}
		}


		// Rub out the last frame
		m_Window.clear(sf::Color(19, 39, 67));

		m_Window.draw(hudGameOver);

		m_Window.draw(hudPressEnter);

		// Show everything we have just drawn
		m_Window.display();


	}

	if (startPlaying) {
		start("Play");
	}
}