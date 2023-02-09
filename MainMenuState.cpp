#include <sstream>
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace hcc
{
	MainMenuState::MainMenuState(GameDataRef data) : m_Data(data)
	{

	}

	void MainMenuState::Init()
	{
		this->m_Data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->m_Data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
		this->m_Data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

		this->m_Background.setTexture(this->m_Data->assets.GetTexture("Background"));
		this->m_PlayButton.setTexture(this->m_Data->assets.GetTexture("Play Button"));
		this->m_Title.setTexture(this->m_Data->assets.GetTexture("Game Title"));

		this->m_Title.setPosition((SCREEN_WIDTH / 2) - (this->m_Title.getGlobalBounds().width / 2), this->m_Title.getGlobalBounds().height * 0.1);
		this->m_PlayButton.setPosition((SCREEN_WIDTH / 2) - (this->m_PlayButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->m_PlayButton.getGlobalBounds().height / 2));	
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->m_Data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->m_Data->window.close();
			}

			if (this->m_Data->input.IsSpriteClicked(this->m_PlayButton, sf::Mouse::Left, this->m_Data->window))
			{
				// Switch To Game State
			this->m_Data->machine.AddState(StateRef(new GameState(m_Data)), true);
			}
		}
	}

	void MainMenuState::Update(float dt)
	{

	}

	void MainMenuState::Draw(float dt)
	{
		this->m_Data->window.clear(sf::Color::Red);

		this->m_Data->window.draw(this->m_Background);
		this->m_Data->window.draw(this->m_PlayButton);
		this->m_Data->window.draw(this->m_Title);

		this->m_Data->window.display();
	}
}