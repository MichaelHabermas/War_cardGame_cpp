#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace hcc
{
	class EndGameState : public State
	{
	public:
		EndGameState(GameDataRef data);
		EndGameState() {}

		// void Init();

		// void HandleInput();
		// void Update(float dt);
		// void Draw(float dt);

	protected:
		// GameDataRef m_Data;

		sf::Sprite m_Background;

		sf::Sprite m_GoToMainButton;
		sf::Sprite m_RestartGameButton;

		sf::Sprite m_Title;
	};
}