#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace hcc
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef m_Data;

		sf::Sprite m_Background;

		sf::Sprite m_PlayButton;

		sf::Sprite m_Title;
	};
}