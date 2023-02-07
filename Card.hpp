#pragma once

#include <SFML/Graphics.hpp>

namespace hcc
{
    class Card
    {
        public:
            Card(int m_value, sf::Sprite m_face);

            int value() const;

            bool isFaceUp() const;
            bool& isFaceUp();

            sf::Sprite face() const;
            sf::Sprite back() const;

        private:
            int m_value;
            sf::Sprite m_face;
            sf::Sprite m_back;
            bool m_isFaceUp;
    };
}
