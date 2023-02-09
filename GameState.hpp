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

            void PlayHand();

        private:
            GameDataRef m_Data;

            sf::Sprite m_Background;

            std::vector<Card> m_deck;
            std::vector<Card> m_player1_hand;
            std::vector<Card> m_player2_hand;
            Card m_player1_card;
            Card m_player2_card;

            bool m_isGameOver;
            int m_p1_score;
            int m_p2_score;
		
            sf::Sprite m_player1_deck_sprite;
            sf::Sprite m_player2_deck_sprite;
            sf::Sprite m_player1_card_sprite;
            sf::Sprite m_player2_card_sprite;
    };
}