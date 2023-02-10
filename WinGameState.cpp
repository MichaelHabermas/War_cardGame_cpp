#include <sstream>
#include "WinGameState.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace hcc
{
	WinGameState::WinGameState(GameDataRef data)
	{
        this->m_Data = data;
	}

	void WinGameState::Init()
	{
		this->m_Data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->m_Data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
		this->m_Data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

		this->m_Background.setTexture(this->m_Data->assets.GetTexture("Background"));
		this->m_GoToMainButton.setTexture(this->m_Data->assets.GetTexture("Play Button"));
		this->m_RestartGameButton.setTexture(this->m_Data->assets.GetTexture("Play Button"));
		this->m_Title.setTexture(this->m_Data->assets.GetTexture("Game Title"));

		this->m_Title.setPosition((SCREEN_WIDTH / 2) - (this->m_Title.getGlobalBounds().width / 2), this->m_Title.getGlobalBounds().height * 0.1);
		this->m_GoToMainButton.setPosition((SCREEN_WIDTH / 2) - (this->m_GoToMainButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->m_RestartGameButton.getGlobalBounds().height / 2));	
		this->m_RestartGameButton.setPosition((SCREEN_WIDTH / 2) - (this->m_RestartGameButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT) - (this->m_RestartGameButton.getGlobalBounds().height));	
	}

	void WinGameState::HandleInput()
	{
		sf::Event event;

		while (this->m_Data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->m_Data->window.close();
			}

			if (this->m_Data->input.IsSpriteClicked(this->m_GoToMainButton, sf::Mouse::Left, this->m_Data->window))
			{
				// Switch To Main Menu
			    this->m_Data->machine.AddState(StateRef(new MainMenuState(m_Data)), true);
			}

			if (this->m_Data->input.IsSpriteClicked(this->m_RestartGameButton, sf::Mouse::Left, this->m_Data->window))
			{
				// Switch To Game State and restart Game
			    this->m_Data->machine.AddState(StateRef(new GameState(m_Data)), true);
			}
		}
	}

	void WinGameState::Update(float dt)
	{

	}

	void WinGameState::Draw(float dt)
	{
		this->m_Data->window.clear(sf::Color::Red);

		this->m_Data->window.draw(this->m_Background);
		this->m_Data->window.draw(this->m_GoToMainButton);
		this->m_Data->window.draw(this->m_RestartGameButton);
		this->m_Data->window.draw(this->m_Title);

		this->m_Data->window.display();
	}
}