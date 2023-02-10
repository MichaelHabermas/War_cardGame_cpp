#pragma once

#include <SFML/Graphics.hpp>
#include "EndGameState.hpp"
#include "Game.hpp"

namespace hcc
{
	class WinGameState : public EndGameState
	{
        public:
            WinGameState(GameDataRef data);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

        private:
		    GameDataRef m_Data;
	};
}