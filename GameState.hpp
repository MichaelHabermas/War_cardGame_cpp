#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "State.hpp"
#include "Game.hpp"
#include "Card.hpp"

namespace hcc
{
    class GameState : public State
    {
        public:
            GameState(GameDataRef data);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

            void GenerateDeck();

            void ShuffleDeck();

            void DealCards();

        private:
            GameDataRef m_Data;

            sf::Sprite m_Background;

            std::vector<Card> m_deck;
            std::vector<Card> m_player1_hand;
            std::vector<Card> m_player2_hand;

            bool isGameOver;

    };
}