#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace hcc
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef m_Data;

		sf::Clock m_Clock;

		sf::Texture m__BackgroundTexture;
		sf::Sprite m_Background;
	};
}