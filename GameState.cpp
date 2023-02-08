#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>
#include <vector>
#include <string>

#include "GameState.hpp"
#include "Card.hpp"
#include "DEFINITIONS.hpp"

namespace hcc
{
    GameState::GameState(GameDataRef data) :
    m_Data(data),
    m_isGameOver(false),
    m_player1_card(),
    m_player2_card(),
    m_p1_score(0),
    m_p2_score(0)
    {

    }

    // FC
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
        PlayHand();
    };

    void GameState::PlayHand()
    {
        this->m_Data->assets.LoadTexture("Player1 Deck", Card_Back);
		this->m_player1_deck_sprite.setTexture(this->m_Data->assets.GetTexture("Player1 Deck"));
		this->m_player1_deck_sprite.setPosition((SCREEN_WIDTH / 2) - (this->m_player1_deck_sprite.getGlobalBounds().width / 2), (SCREEN_HEIGHT) - (this->m_player1_deck_sprite.getGlobalBounds().height * 2));	

        this->m_Data->assets.LoadTexture("Player2 Deck", Card_Back);
		this->m_player2_deck_sprite.setTexture(this->m_Data->assets.GetTexture("Player2 Deck"));
		this->m_player2_deck_sprite.setPosition((SCREEN_WIDTH / 2) - (this->m_player2_deck_sprite.getGlobalBounds().width / 2), this->m_player2_deck_sprite.getGlobalBounds().height);	
	
        this->m_player1_card = this->m_player1_hand.back();
        this->m_player1_hand.pop_back();
        this->m_player1_card_sprite = this->m_player1_card.face();
        this->m_player1_card_sprite.setPosition((SCREEN_WIDTH / 2) - (this->m_player1_card_sprite.getGlobalBounds().width * 2), (SCREEN_HEIGHT / 2) - (this->m_player1_card_sprite.getGlobalBounds().height / 2));	

        this->m_player2_card = this->m_player2_hand.back();
        this->m_player2_hand.pop_back();
        this->m_player2_card_sprite = this->m_player2_card.face();
        this->m_player2_card_sprite.setPosition((SCREEN_WIDTH / 2) + (this->m_player2_card_sprite.getGlobalBounds().width), (SCREEN_HEIGHT / 2) - (this->m_player2_card_sprite.getGlobalBounds().height / 2));	


        if (this->m_player1_card.value() > this->m_player2_card.value())
        {
            this->m_p1_score++;
            std::cout << "Player one wins!" << std::endl;
        }
        else if (this->m_player1_card.value() < this->m_player2_card.value())
        {
            this->m_p2_score++;
            std::cout << "Player two wins!" << std::endl;
        }
        else
        {
            std::cout << "Tie!" << std::endl;
        }
        std::cout << this->m_p1_score << " : " << this->m_p2_score << std::endl;
    }

    void GameState::HandleInput()
    {
        sf::Event event;

		while (this->m_Data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->m_Data->window.close();
			}

            if (this->m_Data->input.IsSpriteClicked(this->m_player1_deck_sprite, sf::Mouse::Left, this->m_Data->window))
            {
                if (!this->m_player1_hand.empty() && !this->m_player2_hand.empty())
                {
                    PlayHand();
                }
                else
                {
                    std::cout << "Game Over" << std::endl;
                }
            }
		}
    };

    void GameState::Update(float dt)
    {
        
    };

    void GameState::Draw(float dt)
    {
        
		this->m_Data->window.clear(sf::Color::Red);

        this->m_Data->window.draw(this->m_player1_card_sprite);
        this->m_Data->window.draw(this->m_player2_card_sprite);

        if (!this->m_player1_hand.empty())
        {
            this->m_Data->window.draw(this->m_player1_deck_sprite);
        }
        if (!this->m_player2_hand.empty())
        {
            this->m_Data->window.draw(this->m_player2_deck_sprite);
        }

		this->m_Data->window.display();
    };

    // FC
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

    // FC
    void GameState::ShuffleDeck()
    {
        std::random_device rd; 
        std::mt19937 rng(rd());
        std::shuffle(m_deck.begin(), m_deck.end(), rng);
    };

    // FC
    void GameState::DealCards()
    {
        std::size_t const halfLength = m_deck.size() / 2;

        std::vector<Card> v1(m_deck.begin(), m_deck.begin() + halfLength);
        m_player1_hand = v1;
        std::vector<Card> v2(m_deck.begin() + halfLength, m_deck.end());
        m_player2_hand = v2;
    };
}