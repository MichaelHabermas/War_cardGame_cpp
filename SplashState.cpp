#include <sstream>
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace hcc
{
	SplashState::SplashState(GameDataRef data) : m_Data(data)
	{

	}

	void SplashState::Init()
	{
		this->m_Data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		m_Background.setTexture(this->m_Data->assets.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (this->m_Data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->m_Data->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (this->m_Clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// Switch To Main Menu
			this->m_Data->machine.AddState(StateRef(new MainMenuState(m_Data)), true);
		}
	}

	void SplashState::Draw(float dt)
	{
		this->m_Data->window.clear(sf::Color::Red);

		this->m_Data->window.draw( this->m_Background );

		this->m_Data->window.display();
	}
}