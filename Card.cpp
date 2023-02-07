#include "Card.hpp"

namespace hcc
{
    Card::Card(int value, sf::Sprite face, sf::Sprite back) : 
        m_value(value),
        m_face(face),
        m_back(back),
        m_isFaceUp(false)
    {
        
    };

    int Card::value() const
    {
        return m_value;
    };

    bool Card::isFaceUp() const
    {
        return m_isFaceUp;
    };

    bool& Card::isFaceUp()
    {
        return m_isFaceUp;
    };

    sf::Sprite Card::face() const
    {
        return m_face;
    };
    sf::Sprite Card::back() const
    {
        return m_back;
    };
}
