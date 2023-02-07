#include <stdlib.h>
#include <iostream>
#include <string>
#include "GameState.hpp"
#include "Card.hpp"
#include <algorithm>
#include <random>
#include <iterator>
#include <vector>

namespace hcc
{
    GameState::GameState(GameDataRef data) :
    m_Data(data),
    isGameOver(false)
    {

    }

    void GameState::Init()
    {
        std::cout << "Working" << std::endl;
        std::string filename = "./Resources/Textures/basicCards/";
        this->m_Data->assets.LoadTexture("Card_Back", filename + "back_card.png");

        for (auto letter : { 'H', 'D', 'S', 'C' })
        {
            for (int num = 1; num < 14; num ++)
            {
                std::string marker = std::to_string(num) + letter;
                this->m_Data->assets.LoadTexture("Card_" + marker, filename + marker + "_card.png");
            }
        }

        GenerateDeck();
        ShuffleDeck();
        DealCards();
    };

    void GameState::HandleInput()
    {
        sf::Event event;

		while (this->m_Data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->m_Data->window.close();
			}
		}
    };

    void GameState::Update(float dt)
    {
        
    };

    void GameState::Draw(float dt)
    {
        
		this->m_Data->window.clear(sf::Color::Red);

		// this->m_Data->window.draw(this->m_Background);

		this->m_Data->window.display();
    };

    void GameState::GenerateDeck()
    {
        std::cout << "in GenerateDeck" << std::endl;
        
        int idx = 1;
        std::string filename = "";
        sf::Sprite backSprite = sf::Sprite();
        backSprite.setTexture(this->m_Data->assets.GetTexture("Card_Back"));

        for (auto letter : { 'H', 'D', 'S', 'C' })
        {
            for (int num = 1; num < 14; num ++)
            {
                std::string marker = std::to_string(num) + letter;
                sf::Sprite newSprite = sf::Sprite();
                newSprite.setTexture(this->m_Data->assets.GetTexture("Card_" + marker));
                m_deck.emplace_back(Card(num, newSprite, backSprite));
            }
        }
    };

    void GameState::ShuffleDeck()
    {
        std::random_device rd; 
        std::mt19937 rng(rd());
        std::shuffle(m_deck.begin(), m_deck.end(), rng);
    };

    void GameState::DealCards()
    {
        std::size_t const halfLength = m_deck.size() / 2;

        std::vector<Card> v1(m_deck.begin(), m_deck.begin() + halfLength);
        m_player1_hand = v1;
        std::vector<Card> v2(m_deck.begin() + halfLength, m_deck.end());
        m_player2_hand = v2;
    };
}